#include <stdio.h>

int main(void)
{
	unsigned char c;
    /*unsigned short c;*/
    printf("Enter characters : ");
    while((c = getchar()) != EOF){
      putchar(c);
      printf(":%d ",c);
    }

    getc(stdin);

    return 0;
}
