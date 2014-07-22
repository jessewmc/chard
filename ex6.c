#include <stdio.h>

int main(int argc, char* argv[])
{
  int distance = 100;
  float power = 2.345f;
  double super_power = 56789.4532;
  char initial = 'A';
  char first_name[] = "joe";
  char last_name[] = "schmoe";

  printf("yo is %d miles away\n", distance);
  printf("yo ihave %f levels of power\n", power);
  printf("yo have %f super powers yeeezy\n", super_power);
  printf("yo have initial %c\n", initial);
  printf("yo have first name %s\n", first_name);
  printf("yo have last name %s\n", last_name);
  printf("yo whole name be %s %c %s\n", first_name, initial, last_name);

  return 0;
}
