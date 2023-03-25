/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

void array_dump(int a[], unsigned int length);

bool array_is_sorted(int a[], unsigned int length);