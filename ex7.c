#include <stdio.h>

int main(int argc, char* argv[])
{
  int bugs = 100;
  double bug_rate = 1.2;

  printf("u have %d bugs at the imaginary rate of %f\n", bugs, bug_rate);

  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
  printf("yo universe has %ld bugs\n", universe_of_defects);
  
  double expected_bugs = bugs * bug_rate;
  printf("yo is expected to have %f bugs", expected_bugs);

  double part_of_universe = expected_bugs/ universe_of_defects;
  printf("that is only a %e portion of the universe\n", part_of_universe);

  //this is fucked
  char nul_byte = '\0';
  int care_percentage = bugs * nul_byte;
  printf("yo shuld care %d%%\n", care_percentage);

  return 0;

}
