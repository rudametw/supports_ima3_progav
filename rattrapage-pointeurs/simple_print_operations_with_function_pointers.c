#include <stdio.h>

int add()
{
   return (100+10);
}

int sub()
{
   return (100-10);
}

void print(int x, int y, int (*func)())
{
    printf("value is : %d", (x+y+(*func)()));
}

int main()
{
    int x=100, y=200;
    print(x,y,add);
    print(x,y,sub);

    return 0;
}
