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
  void (*funs[4])(void) = {&a, &b, &c, &d};
  int choice = -1;
  scanf("%d", &choice);
  if (choice < 0 || choice > 4) {
    fail();
    return 1;
  }
  funs[choice]();
  return 0;
}
