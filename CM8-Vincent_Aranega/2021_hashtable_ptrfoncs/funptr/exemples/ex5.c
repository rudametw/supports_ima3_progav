#include <stdio.h>

int inf_int(int a, int b)
{
    printf("%d < %d --> ", a, b);
    return a < b;
}

int equal_int(int a, int b)
{
    printf("%d == %d --> ", a, b);
    return a == b;
}

void fun(int comparison(int, int), int a,  int b)
{
    if (comparison(a, b)) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}

int main(void)
{
    fun(inf_int, 1, 3);
    fun(inf_int, 4, 4);
    fun(equal_int, 4, 4);
    return 0;
}
