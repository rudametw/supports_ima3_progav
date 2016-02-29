#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("Bienvenue a Lille", fp);

   fseek(fp, 12, SEEK_SET );
   fputs("Polytech-Lille", fp);
   fclose(fp);

   return(0);
}
