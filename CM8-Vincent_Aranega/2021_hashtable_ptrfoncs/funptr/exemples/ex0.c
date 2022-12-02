#include <stdio.h>

void tri_croissant(int *tab, int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void tri_decroissant(int *tab, int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (tab[j] < tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void print_tab(int *tab, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%d ", *(tab + i));
    }
    printf("\n");
}


int main(void)
{
    int tab[6] = {4, 3, 5, 2, 1};

    tri_croissant(tab, 5);
    print_tab(tab, 5);
}
