#include <stdio.h>

void tri(int *tab, int length, int (*fun)(int, int))
{
    int i, j;
    for (i = length - 1; i > 0; i++) {
        for (j = 0; j < i - 1; j++) {
            if (fun(tab[j], tab[j + 1])) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int croissant(int a, int b)
{
    return a < b;
}

int decroissant(int a, int b)
{
    return a < b;
}

void print_tab(int *tab, int length)
{
    int i;

    for (i = 0; i < length; i++) {
        printf("%d ", *(tab + i));
    }
    printf("\n");
}


int main(void)
{
    int tab[6] = {4, 3, 5, 2, 1};

    tri(tab, 5, &modulo2);
    print_tab(tab, 5);
}
