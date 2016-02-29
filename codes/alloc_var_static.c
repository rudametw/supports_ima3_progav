#include <stdio.h>

int * f() {
	int var_static = 23 ; //allocated on the stack
	printf("var_static address is : %p\n",&var_static);
	return &var_static ;
}

int main (){
	int * ptr ;
	printf("Pointer uninitialized address is : %p\n",ptr);
	ptr = f();
	/**ptr = 27;*/
	printf("Pointer initialized address is : %p\n",ptr);
	printf("Value set to : %d\n",*ptr);
}
