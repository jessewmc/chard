#include <stdio.h>

int main(int argc, char* argv[])
{
  int i = 0;

  if(argc == 1)
  {
    printf("yo has only one arg\n");
  }
  else if(argc > 1 && argc < 4)
  {
    printf("yo args:\n");

    for(i = 0; i < argc; i++)
    {
      printf("%s ", argv[i]);
    }
    printf("\n");
  }
  else
  {
    printf("yo has too many args\n");
  }
  return 0;
}
