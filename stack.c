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
  struct entry temp = {.item = stack->prev->item, .prev = stack->prev->prev};
  struct entry* ret = stack->prev;
  ret->item = stack->item;
  ret->prev = NULL;
  stack->item = temp.item;
  stack->prev = temp.prev;
  return ret;
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

  printf("the stack\n");
  stack_print(mystack);
  printf("pop top\n");
  destroy_stack(stack_pop(mystack));
  stack_print(mystack);
  printf("pop again\n");
  destroy_stack(stack_pop(mystack));
  stack_print(mystack);
  printf("print again\n");
  stack_print(mystack);
  stack_push(mystack, new_entry(1024));
  printf("push\n");
  stack_print(mystack);
  stack_push(mystack, new_entry(192));
  printf("push\n");
  stack_print(mystack);
  destroy_stack(mystack);

  return 0;
}

