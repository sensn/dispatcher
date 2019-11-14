// EVT_MAX 4   //DELETE


typedef enum event_type {
	/*
	 * System real-time messages.
	 */
	EVT_SYS_REALTIME_TIMING_CLOCK = 0,
	EVT_SYS_REALTIME_RESERVED_F9,
	EVT_SYS_REALTIME_SEQ_START,
	EVT_SYS_REALTIME_SEQ_CONTINUE,
	EVT_SYS_REALTIME_SEQ_STOP,
	EVT_SYS_REALTIME_RESERVED_FD,
	EVT_SYS_REALTIME_ACTIVE_SENSE,
	EVT_SYS_REALTIME_RESET,

	/*
	 * Channel messages.
	 */
	 EVT_CHAN_NOTE_OFF,
	 EVT_CHAN_NOTE_ON,
	 EVT_CHAN_POLY_AFTERTOUCH,
	 EVT_CHAN_CONTROL_CHANGE,
	 EVT_CHAN_PROGRAM_CHANGE,
	 EVT_CHAN_AFTERTOUCH,
	 EVT_CHAN_PITCH_BEND,

	 /*
	  * Placeholder whose value is equal to the total number of event types
	  * that we support above.
	  */
	  EVT_MAX
} event_type;
/*
 * Routines return a status code.
 */
typedef signed char status_t;

/*
*This library uses an event - driven paradigm for receiving data : callers
* register callback functions for events they are interested in, and these
* are invoked when events are received.
*
* For the sake of simplicity, we define one type, midi_event_callback_t for
* all callback functions.Please note that some parameters are unused in
* certain contexts : the documentation is clear on what parameters are valid
* for each event type.
*
* The caller is only obligated to register callback functions for those
* events she is interested in; other events will be dispatched to a null
* handler implements within the library.
*/
typedef void (*midi_event_callback_t)(char chan, char data1, char data2);



// Callback table.
static midi_event_callback_t g_callbacks[EVT_MAX] = { 0 };


// The null event callback is used by default for all events.
static void null_event_cb(char channel, char a, char b) {
	// Do nothing. The invoke_callback() function will properly implement the
	// global message counter.
}

void event_cb_note_on() {
	printf("Note on");

}


// Wrapper that invokes callback functions.
static inline void invoke_callback(int evt) {
	// Reject invalid events.
	if ((evt < 0) || (evt >= EVT_MAX)) {
		return;
	}

	// Increment the global event counter.
//	++g_message_counter;

	// Invoke the callback.
//	(g_callbacks[evt])(g_current_channel, g_data_byte_one, g_data_byte_two);

	// Clear data state
//	g_data_byte_one = 0;
//	g_data_byte_two = 0;
}

status_t midi_register_event_handler(event_type evt, midi_event_callback_t cb) {
	if (cb) {
		g_callbacks[evt] = cb;
	}
	else {
		g_callbacks[evt] = null_event_cb;
	}

	return 0;
}

status_t midi_init() {
	// Initialize the callback table; all events to the null callback.
	for (int i = 0; i < EVT_MAX; ++i) {
		g_callbacks[i] = null_event_cb;
	}
	return 0;
}




void dispatcher_main() {
	midi_init;
		midi_register_event_handler(EVT_CHAN_NOTE_ON, event_cb_note_on);
		invoke_callback(0);
}

