#include <stdio.h>

void a()
{
  // Stuff
  printf("You choose 0\n");
}

void b()
{
  // Stuff
  printf("You choose 1\n");
}

void c()
{
  // Stuff
  printf("You choose 2\n");
}

void d()
{
  // Stuff
  printf("You choose 3\n");
}

void fail()
{
  // Stuff
  printf("You suck\n");
}

int main(void)
{
    int choice = -1;
    scanf("%d", &choice);
    switch (choice) {
      case 0:
        a();
        break;
      case 1:
        b();
        break;
      case 2:
        c();
        break;
      case 3:
        d();
        break;
      default:
        fail();
    }
    return 0;
}
