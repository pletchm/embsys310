
#ifndef STACK_H_
#define STACK_H_

#define STACK_SIZE 5

/* Function for initializing the stack internals. */
void stack_init(void);

/* Function to push an element onto the stack. */
void stack_push(int value);

/* Function to pop an element off the stack. */
int stack_pop(void);

/* Function that returns 1 if stack is empty. */
int stack_empty(void);

/* Function that returns 1 if stack is full. */
int stack_full(void);

#endif // STACK_H_

