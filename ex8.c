#include <stdio.h>

int main(int argc, char* argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "gravity";
  char full_name[] = {'g', 'r', 'a', 'v', 'i', 't', 'y', '\0'};

  //%ld might have to be %u for unsigned?
  printf("size of yo int: %u\n", sizeof(int));
  printf("size of yo areas (int[]): %u\n", sizeof(areas));
  printf("number of ints in yo areas: %u\n", sizeof(areas) / sizeof(int));

  printf("size of yo char: %u\n", sizeof(char));
  printf("size of yo name (char[]): %u\n", sizeof(name));
  printf("number of yo chars: %u\n", sizeof(name) / (sizeof(char)));
  
  printf("size of yo full_name (char[]): %u\n", sizeof(full_name));
  printf("number of yo chars: %u\n", sizeof(full_name) / sizeof(char));
  
  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

  return 0;
}
