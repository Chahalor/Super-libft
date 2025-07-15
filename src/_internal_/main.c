#include <stdio.h>
#include "memory/_memory.h"

int main(void)
{
    size_t size = 10;
    int *arr = _mem_alloc(size * sizeof(int));
    if (!arr) {
        printf("Allocation failed\n");
        return 1;
    }

    for (size_t i = 0; i < size; ++i)
        arr[i] = (int)i;

    printf("Array contents after allocation:\n");
    for (size_t i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    size_t new_size = 20;
    if (!_mem_realloc((void **)&arr, new_size * sizeof(int))) {
        printf("Reallocation failed\n");
        _mem_free(arr);
        return 1;
    }

    for (size_t i = size; i < new_size; ++i)
        arr[i] = (int)i;

    printf("Array contents after reallocation:\n");
    for (size_t i = 0; i < new_size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

	#define SIZE_TEST 4096
	void	*tkt[SIZE_TEST] = {NULL};
	for (size_t j = 0; j < SIZE_TEST; ++j)
		tkt[j] = _mem_alloc(1024);
	printf("\n");

    // _free(arr);
	_mem_destroy();
    return 0;
}