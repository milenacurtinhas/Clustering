#ifndef STACK_H

typedef struct _stack *Stack;

Stack stack_init(int cap, int size);
void stack_push(Stack, void *);
void stack_pop(Stack, void *);
int stack_empty(Stack);
void stack_destroy(Stack);

#endif