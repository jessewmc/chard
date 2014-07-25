#include <stdio.h>

int main(int argc, char* argv[])
{
  int i = 0;
  while(i < argc)
  {
    printf("yo arg %d: %s\n", i, argv[i]);
    i++;
  }

  char* states[] = { "cali", "or", "wash", "tex" };

  int num_states = 4;
  i = 0;
  while(i < num_states)
  {
    printf("yo state %d be %s\n", i, states[i]);
    i++;
  }

  return 0;
}
