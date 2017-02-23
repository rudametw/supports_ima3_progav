void myfun()
{
  // Empty here
}

int main(void)
{
  void (*ptr)(void) = &myfun;
  ptr();
  return 0;
}
