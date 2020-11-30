#include <assert.h>

void swap_pointer(int* leftPtr, int* rightPtr);

int main()
{
    int x = 82;
    int y = 14;
    int* xPtr = &x;
    int* yPtr = &y;
    swap_pointer((int*) &xPtr, (int*) &yPtr);
    assert(xPtr == &y);
    assert(yPtr == &x);
    assert(x == 82);
    assert(y == 14);
    return 0;
}

/* This function swaps 2 pointers. Make sure addresses (i.e., references of the
 * pointers are passed in, not the pointers themselves.
 */
void swap_pointer(int* leftPtr, int* rightPtr)
{
    int tempPtr = *leftPtr;
    *leftPtr = *rightPtr;
    *rightPtr = tempPtr;
}
