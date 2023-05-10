#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void foo()
{
  printf("Helllo World");
}

int main()
{
  
  void (*ptr) (void)= &foo;
  *(ptr)();
  return 0;
}