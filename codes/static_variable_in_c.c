#include <stdio.h>

void func() {
	static int x = 0;
	/* x is initialized only once across five calls of func() and
	  the variable will get incremented five
	  times after these calls. The final value of x will be 5. */
	x++;
	printf("%d\n", x); // outputs the value of x
}

int main() { //int argc, char *argv[] inside the main is optional in the particular program
	func(); // prints 1
	func(); // prints 2
	func(); // prints 3
	func(); // prints 4
	func(); // prints 5
	return 0;
}
