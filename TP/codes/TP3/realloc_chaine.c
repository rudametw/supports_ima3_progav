#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	c = getchar();

	while (! isspace(c))
	{
		putchar(c);
		c = getchar();
	}
	putchar('\n');

	return 0;
}
