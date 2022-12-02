#include <stdio.h>

#define MAX 20

struct tas {
	int tab[MAX];
	int dernier;
};

int index_fils_gauche(int index) { return 2*index+1; }
int index_fils_droite(int index) { return 2*index+2; }
int index_parent(int index) { return (index-1)/2; }
int tas_vide(struct tas *t) { return t->dernier == -1;}
int tas_plein(struct tas *t){return t->dernier==MAX-1;}

int has_fils_gauche(struct tas *t, int index) {
	return index_fils_gauche(index) < t->dernier;
}
int has_fils_droite(struct tas *t, int index) {
	return index_fils_droite(index) < t->dernier;
}
int has_parent(int index) {
	return index_parent(index) >= 0;
}

void swap_tas(struct tas *t, int i, int j) {
	int tmp = t->tab[i];
	t->tab[i] = t->tab[j];
	t->tab[j] = tmp;
}

void sift_up(struct tas *t) {
	int index = t->dernier;

	while(has_parent(index) &&
	      t->tab[index_parent(index)] > t->tab[index]
	){
		swap_tas(t, index_parent(index),index);
		index = index_parent(index);
	}
}




void sift_down(struct tas *t)
{
	int index = 0; // racine

	while (has_fils_gauche(t, index)) {
		int plus_petit_fils = index_fils_gauche(index);

		if (has_fils_droite(t, index)) {
			if ( t->tab[index_fils_gauche(index)] >
			     t->tab[index_fils_droite(index)])
				plus_petit_fils =
						index_fils_droite(index);
		}
		if (t->tab[index] < t->tab[plus_petit_fils])
			return;
		else
			swap_tas(t, index, plus_petit_fils);
		index = plus_petit_fils;
	}
}

void ajouter(struct tas *t, int val)
{
	t->dernier++;
	t->tab[t->dernier] = val;
	sift_up(t);
}

int retirer(struct tas *t)
{
	int val = t->tab[0];
	t->tab[0] = t->tab[t->dernier];
	t->dernier --;
	sift_down(t);
	return val;
}

void print_tas(struct tas *t)
{
	if(t->dernier == -1) printf("vide");

	for (int i = 0; i <= t->dernier; ++i)
		printf("%d ", t->tab[i]);
	printf("\n");
}

int main()
{
	struct tas t;
	t.dernier = -1;

	print_tas(&t);
	ajouter(&t,4);
	print_tas(&t);
	ajouter(&t,3);
	print_tas(&t);
	ajouter(&t,9);
	print_tas(&t);
	ajouter(&t,5);
	print_tas(&t);
	ajouter(&t,2);
	print_tas(&t);
	ajouter(&t,1);
	print_tas(&t);
	ajouter(&t,7);
	print_tas(&t);

	printf("Vider T1\n");
	while(!tas_vide(&t)){
		printf("%d ",retirer(&t));
	}

	printf("\n\nT2\n");

	struct tas t2;
	t2.dernier = -1;
	print_tas(&t2);
	ajouter(&t2,8);
	print_tas(&t2);
	ajouter(&t2,6);
	print_tas(&t2);
	ajouter(&t2,3);
	print_tas(&t2);
	ajouter(&t2,10);
	print_tas(&t2);
	ajouter(&t2,5);
	print_tas(&t2);
	ajouter(&t2,4);
	print_tas(&t2);
	ajouter(&t2,9);
	print_tas(&t2);

	printf("Vider T2\n");
	while(!tas_vide(&t2)){
		printf("retiré %d \n",retirer(&t2));
		print_tas(&t2);
	}
	printf("\n");
	// print_tas(array, size);
	// deleteRoot(t, 4);
	//printf("After deleting an element: ");
	// printt(array, size);
}


//===================================================

// Function to swap the the position of two elements
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Code not converted to struct tas
void heapify_old(int arr[], int n, int i)
{
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify_old(arr, n, largest);
	}
}
// Main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_old(arr, n, i);

	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at root again
		heapify_old(arr, i, 0);
	}
}

// Driver code
int main2()
{
	int arr[] = {1, 12, 9, 5, 6, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	printf("Sorted array is \n");
	//printArray(arr, n);

	return 0;
}

//void deleteRoot(int array[], int num)
//{
//  int i;
//  for (i = 0; i < size; i++)
//  {
//    if (num == array[i])
//      break;
//  }

//  swap(&array[i], &array[size - 1]);
//  size -= 1;
//  for (int i = size / 2 - 1; i >= 0; i--)
//  {
//    heapify(array, size, i);
//  }
//}
