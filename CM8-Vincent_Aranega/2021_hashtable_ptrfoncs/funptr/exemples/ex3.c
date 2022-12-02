void myfun()
{
  // Empty here
}

int main(void)
{
  void (*ptr)(void) = &myfun;
  ptr(); // Equivalent to: (*ptr)();
  return 0;
}
