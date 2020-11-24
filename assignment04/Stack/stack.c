
#include "stack.h"

int _stack_data[STACK_SIZE];
int _top_index;

/* Function for initializing the stack internals. */
void stack_init(void)
{
    _top_index = 0;
    for (int index = 0; index < STACK_SIZE; index++) {
        _stack_data[index] = 0;
    }
}

/* Function to push an element onto the stack. */
void stack_push(int value)
{
    if (_top_index < STACK_SIZE) {
        _stack_data[_top_index] = value;
        _top_index++;
    }
}

/* Function to pop an element off the stack. */
int stack_pop(void)
{
    if (_top_index == 0) return 0;
    _top_index--;
    return _stack_data[_top_index];
}

/* Function that returns 1 if stack is empty. */
int stack_empty(void)
{
    return _top_index == 0;
}

/* Function that returns 1 if stack is full. */
int stack_full(void)
{
    return _top_index == STACK_SIZE;
}

