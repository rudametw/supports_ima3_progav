#include <stdio.h>

int main(void)
{
    signed char c;
    printf("Enter characters : ");
    while((c= getchar()) != EOF){
      putchar(c);
      printf(":%d ",c);
    }
    return 0;
}
