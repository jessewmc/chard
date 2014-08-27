#include <stdio.h>
#include <stdlib.h>

struct entry{
  int item;
  struct entry* prev;
};

struct entry* new_entry(int it){
  struct entry* thing = malloc(sizeof(struct entry));
  thing->item = it;
  thing->prev = NULL;
  return thing;
}

void destroy_stack(struct entry* ent){
  if(ent->prev){
    destroy_stack(ent->prev);
  }
  free(ent);
}

void stack_print(struct entry* stack){
  while(stack != NULL){
    printf("%d\n", stack->item);
    stack = stack->prev;
  }
}

void stack_push(struct entry* stack, struct entry* new_item){
  struct entry temp = {.item = stack->item, .prev = stack->prev};
  stack->item = new_item->item;
  stack->prev = new_item;
  new_item->prev = temp.prev;
  new_item->item = temp.item;
}

struct entry* stack_pop(struct entry* stack){
  return stack->prev;
}

int main(int argc, char* argv[]){
  struct entry* mystack = new_entry(10); 
  struct entry* stackadd = new_entry(-1);
  mystack->prev = stackadd;
  struct entry* stack2 = new_entry(10000);
  printf("stack before push %p\n", mystack);
  stack_push(mystack, stack2);
  printf("stack after push %p\n", mystack);

  stack_push(mystack, new_entry(15));
  stack_push(mystack, new_entry(25402));

  stack_print(mystack);
  destroy_stack(mystack);

  return 0;
}

