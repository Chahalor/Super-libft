#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "mmanager.h"

#define _START	printf("== STARTING TESTS FOR MEMORY MANAGER ==\n");
#define _END	printf("== ENDING TESTS FOR MEMORY MANAGER   ==\n");

#ifndef AS
# define AS		13	/* alloc size */
#endif

int	main(void)
{
	_START

	register int		i = -1;
	while (++i < 1000)
	{
		mm_alloc(AS);
	}

	char *ptr = mm_alloc(AS);
	strcpy(ptr, "Hello World\n");
	printf("Allocated %s\n", ptr);
	ptr = mm_realloc(ptr, AS * 2 - 1, AS);
	strcpy(ptr, "Hello WorldHello World\n");
	printf("Reallocated %s\n", ptr);
	mm_free(ptr);

	mm_destroy();

	_END
	return (0);
}
