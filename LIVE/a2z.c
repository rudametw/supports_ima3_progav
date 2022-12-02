#include <stdio.h>

int main() {
	for (unsigned char c = 65 ; c < 95 ; c++) {
		printf("[%d,%c]\n", c, c);
	}
}
