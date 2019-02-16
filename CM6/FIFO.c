#include <stdio.h>
#include <stdlib.h>

typedef unsigned char val_type ;

struct cellule {
	val_type val ;
	struct cellule * suiv ;
};

struct fifo {
	struct cellule * tete ;
	struct cellule * queue ;
};

void init_fifo (struct fifo * ptr_file) {
	ptr_file->tete  = NULL ;
	ptr_file->queue = NULL ;
}

val_type first (struct fifo file) {
	return file.tete->val ;
}

//UNUSED !!!
void sup_tete(struct fifo * ptr_file) {

	struct cellule * tmp = ptr_file->tete ;

	if( ptr_file->tete == ptr_file->queue) {
		ptr_file->tete  = NULL;
		ptr_file->queue = NULL;
	} else {
		ptr_file->tete = ptr_file->tete->suiv ;
	}
	free(tmp);
}

val_type get(struct fifo * ptr_file) {
	val_type v = ptr_file->tete->val ;

	struct cellule * tmp = ptr_file->tete ;

	ptr_file->tete = ptr_file->tete->suiv ;
	if (ptr_file->tete == NULL)
		ptr_file->queue = NULL ;

	free(tmp);

	return v;
}

void put(struct fifo * ptr_file, val_type val) {

	struct cellule * tmp = malloc(sizeof(struct cellule));
	tmp->val = val;
	//tmp->suiv = ptr_file->tete ; ajout_tete, mais nous on veut ajout queue!!!
	//ptr_file->tete = tmp ;
	tmp->suiv = NULL;
	if( ptr_file->tete == NULL)
		ptr_file->tete  = tmp ;
	else
		ptr_file->queue->suiv = tmp;
	ptr_file->queue = tmp ;

}

int fifo_vide(struct fifo file) {
	return (file.tete == NULL) ;
}

int fifo_pleine(struct fifo file) {
	return 0 ;
}

void print_fifo(struct fifo file) {
	struct cellule * tmp = file.tete ;

	printf("-----------\n");
	printf("fifo_pleine ? %d, fifo_vide ? %d ::::: ", fifo_pleine(file), fifo_vide(file));
	/*printf("Fifo : ");*/
	while(tmp != NULL) {
		printf("%c,",tmp->val);
		tmp = tmp->suiv ;
	}
	/*printf("\nFifo est vide ? %d, Fifo est pleine ? %d\n", fifo_vide(file), fifo_pleine(file));*/
	printf("\n-----------\n\n");
}

int main () {

	struct fifo f;
	init_fifo(&f);

	for (val_type c = 'a' ; c < 'a' + 26 ; c++) {
		print_fifo(f);
		put(&f,c);
	}

	while(!fifo_vide(f)){
		//printf("Récupéré: %c\n",get(&f));
		get(&f);
		print_fifo(f);
	}

	return 0;
}
