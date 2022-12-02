#include <stdio.h>
#include <unistd.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("Bienvenue a Lille", fp);

/* /////////////////
//Si vous décommentez les lignes suivantes, le flush va vider le tampon sur "file.txt", forçant l'écriture sur disque, vous permettant pendent X seconds d'aller regarder l'état du fichier (e.g., cat ./file.txt). Vous verrez que le fichier contient la chaine "Bienvenue a Lille" qui sera ensuite modifié en utilisant `fseek` et `fputs`. Si vous n'utilisez pas flush, vous verrez que cette chaine n'a pas encore été écrit car le buffer est gardé en mémoire.

   fflush(fp);
   sleep(10);
///////////////// */

   fseek(fp, 12, SEEK_SET );
   fputs("Polytech-Lille", fp);

   fclose(fp);
   return(0);
}
