#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp2(const void *x, const void *y){
    int a = *(const int *)x;
    int b = *(const int *)y;
    return a > b ? -1 : (a < b);
}

int cmp(const void *x, const void *y){
    int a = *(const int *)x;
    int b = *(const int *)y;
	return a < b ? -1 : (a > b);
}

void swap(void *a, void *b, size_t type_size) {
    void *tmp = malloc(type_size);
    memcpy(tmp, a, type_size);
    memcpy(a,   b, type_size);
    memcpy(b, tmp, type_size);
    free(tmp);
}

void bubbleSort(void *base, size_t length, size_t type_size, int (*compar)(const void*, const void*)) {
    unsigned int i, j;
    for (i = 0; i < length - 1; ++i) {
        for (j = i+1; j < length; ++j){
            char *data_i = (char*)base + type_size * i;
            char *data_j = (char*)base + type_size * j;
            if(compar(data_i, data_j) > 0)
                swap(data_i, data_j, type_size);
        }
    }
}

int main() {
    int vet[] = {1, 2, 5, 7, 6, 1, 3, 2, 9, 15, 14, 20};
    bubbleSort(vet, sizeof(vet)/sizeof(*vet), sizeof(*vet), cmp);

	for (unsigned int i = 0; i < sizeof(vet)/sizeof(*vet); i++) {
        printf("%d\n", vet[i]);
    }


	printf("\nReverse sort \n");
    bubbleSort(vet, sizeof(vet)/sizeof(*vet), sizeof(*vet), cmp2);

	for (unsigned int i = 0; i < sizeof(vet)/sizeof(*vet); i++) {
        printf("%d\n", vet[i]);
    }

    return 0;
}
