#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char* message){
  if(errno){
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

typedef int (*compare_cb)(int a, int b);

typedef int* (*sort_cb)(int* numbers, int count, compare_cb cmp);

int* merge_sort(int* numbers, int count, compare_cb cmp){
  if (sizeof(numbers) <= sizeof(int)) return numbers;

  int split = sizeof(numbers)/sizeof(int)/2;

  int i = 0;
  int* left = malloc(sizeof(int) * split);
  int* right = malloc(sizeof(int) * (sizeof(numbers)-split));

  for(i = 0; i < split; i++){
   left[i] = numbers[i];
  }
  for(i = split; i < sizeof(numbers); i++){
    right[i - split] = numbers[i];
  }

  int* leftr = merge_sort(left, split, cmp);
  int* rightr = merge_sort(right, sizeof(numbers) - split, cmp);

  free(left);
  free(right);

  int* result = merge(leftr, rightr);

  free(leftr);
  free(rightr);
  return result;
}

int* bubble_sort(int* numbers, int count, compare_cb cmp){
  int temp = 0;
  int j = 0;
  int* target = malloc(count * sizeof(int));

  if(!target) die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for(i = 0; i < count; i++){
    for(j = 0; j< count - 1; j++){
      if(cmp(target[j], target[j+1]) > 0) {
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      }
    }
  }

  return target;
}

int sorted_order(int arrdv, int b){
  return arrdv - b;
}

int reverse_order(int a, int b){
  return b - a;
}

int strange_order(int a, int b){
  if(a == 0 || b == 0){
    return 0;
  } else {
    return a % b;
  }
}

void test_sorting(int* numbers, int count, sort_cb srt, compare_cb cmp){
  int i = 0;
  int* sorted = srt(numbers, count, cmp);

  if(!sorted) die("Failed to sort as requested");

  for(i = 0; i < count; i++){
    printf("%d ", sorted[i]);
  }
  printf("\n");
  free(sorted);

  unsigned char* data = (unsigned char*) cmp;

  for(i = 0; i < 25; i++){
    printf("%02x:", data[i]);
  }

  printf("\n");
}

int main(int argc, char* argv[]){
  if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  //clever
  //moves memory location of poiter to first argument, new array
  char** inputs = argv + 1;
  
  int* numbers = malloc(count * sizeof(int));
  if(!numbers) die("Mem err");

  for(i = 0; i < count; i++){
    numbers[i] = atoi(inputs[i]);
  }

  test_sorting(numbers, count, bubble_sort, sorted_order);
  test_sorting(numbers, count, bubble_sort, reverse_order);
  test_sorting(numbers, count, bubble_sort, strange_order);

  free(numbers);

  return 0;
}
