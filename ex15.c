#include <stdio.h>

void spacer(){
  printf("---\n");
}

int main(int argc, char* argv[]){
  int ages[] = {23, 43, 12, 89, 2};
  char* names[] = {"Al", "frank", "Ma", "Jo", "Lisa"};

  int count = sizeof(ages) / sizeof(int);
  int i = 0;
  char* template = "%s been around fo %d years\n";

  for(i = 0; i < count; i++){
    printf(template, names[i], ages[i]);
  }

  spacer();

  int* cur_age = ages;
  char** cur_name = names;

  for(i = 0; i < count; i++){
      printf(template, *(cur_name+i), *(cur_age+i));
      }
  
  spacer();

  for(i = 0; i < count; i++){
    printf(template, cur_name[i], cur_age[i]);
  }

  spacer();

  for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++){
    printf(template, *cur_name, *cur_age);
  }
  return 0;
}
