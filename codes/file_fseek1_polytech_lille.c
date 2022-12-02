#include <stdio.h>
#include <unistd.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("Bienvenue a Lille", fp);

/////////////////
   //fclose(fp);
   //sync();
   fflush(fp);
   sleep(3);
   //fp = fopen("file.txt","r+");
/////////////////

   fseek(fp, 12, SEEK_SET );
   fputs("Polytech-Lille", fp);

   fclose(fp);
   return(0);
}
