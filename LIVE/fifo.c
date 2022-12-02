#include <stdio.h>
#include <stdlib.h>

typedef unsigned char val_type;

struct cellule {
	val_type val;
	struct cellule *suiv;
};

struct fifo {
	struct cellule *tete;
	struct cellule *queue;
};

void init_fifo(struct fifo *ptr_file)
{
	ptr_file->tete = NULL;
	ptr_file->queue = NULL;
}

int fifo_pleine(struct fifo f)
{
	return 0;
}

int fifo_vide(struct fifo f)
{
	return (f.tete == NULL);
}

void print_fifo(struct fifo f)
{

	struct cellule *tmp;
	tmp = f.tete;

	printf("------------\n");

	printf("fifo_pleine ? %d, fifo_vide ? %d ::::: ", fifo_pleine(f), fifo_vide(f));
	while (tmp != NULL) {
		printf("%c, ", tmp->val);
		tmp = tmp->suiv;
	}

	printf("\n------------\n");
}

void put(struct fifo *ptr_file, val_type val)
{

	struct cellule *tmp;
	tmp = malloc(sizeof(struct cellule));

	tmp->val = val;
	tmp->suiv = NULL;
	// ptr_file->tete

	if (ptr_file->tete == NULL)
		ptr_file->tete = tmp;
	else
		ptr_file->queue->suiv = tmp;
	ptr_file->queue = tmp;
}

val_type get(struct fifo *ptr_file)
{
	val_type v = ptr_file->tete->val;

	struct cellule *tmp = ptr_file->tete;

	ptr_file->tete = ptr_file->tete->suiv;

	if (ptr_file->tete == NULL)
		ptr_file->queue = NULL;

	free(tmp);

	return v;
}

int main(void)
{

	struct fifo f;
	init_fifo(&f);

	print_fifo(f);

	val_type x = 'W';

	put(&f, x);
	print_fifo(f);
	put(&f, 'y');
	print_fifo(f);

	printf("Fifo vide = %d\n", fifo_vide(f));

	if (!fifo_vide(f))
		x = get(&f);
	// int res = get(&f, &x);

	return 0;
}
