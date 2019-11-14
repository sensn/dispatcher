#include <stdio.h>


void foo3(int x, int y)
{
	printf("foo3");
}


int foo2(int c, int d){

    printf("I'm foo2\n");
	return 15;


}

int foo1(int(*foo)(int,int),int a, int b)
{
	int* y = &foo; //Adresse von Funktion
	int z = *foo; //return wert
	int x = foo; //return wert
	

	printf("foo-Wert %p\n", foo);
	printf("y-Wert %p\n", *y);
	foo(1, 1);

	//foo3(9,8);
	
	return x + a + b;
}

int main()
{

	printf("foo2 = %p\n", &foo2);

	//foo1(foo2(2,3),1,2);           // foo 2 wird sofort aufgerufen
	
	printf("----\n");
	
	printf("foo3 = %p\n", &foo3);     
	foo1(&foo3,1,2);                  // foo3 wird der variablen foo zugeordnet und ist in foo1 als foo(); aufrufbar.

	

}




