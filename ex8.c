#include <stdio.h>

int main(int argc, char* argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "gravity";
  char full_name[] = {'g', 'r', 'a', 'v', 'i', 't', 'y', '\0'};

  //%ld might have to be %u for unsigned?
  printf("size of yo int: %ld\n", sizeof(int));

  return 0;
}
