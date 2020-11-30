#include <assert.h>
#include <stdio.h>
#include "stack.h"

int main()
{
    /* Call init; Assert is empty, not full. */
    {
        stack_init();
        assert(stack_empty() == 1);
        assert(stack_full() != 1);
    }
    /* Call push; Assert not empty, not full */
    {
        stack_init();
        stack_push(1);
        assert(stack_empty() != 1);
        assert(stack_full() != 1);
    }
    /* Call push STACK_SIZE times; assert full, not empty. */
    {
        stack_init();
        for (int i = 0; i < STACK_SIZE; i++) {
	    stack_push(i);
        }
        assert(stack_full() == 1);
        assert(stack_empty() != 1);
    }    
    /* Call push STACK_SIZE times, then pop STACK_SIZE TIMES; assert empty. */
    {
        stack_init();
        for (int i = 0; i < STACK_SIZE; i++) {
	    stack_push(i);
        }
	for (int i = STACK_SIZE - 1; i >= 0; i--) {
            int val = stack_pop();
            assert(i == val);
        }
        assert(stack_empty() == 1);
    }
    printf("ALL TEST CASES PASSED.\n");
    return 0;
}
