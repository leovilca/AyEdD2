#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    /* needs implementation */
    if(i>1){
        unsigned int j=i-1;
        while(j>0u && goes_before(a[i],a[j])){
            j--;
        }
        swap(a,i,j);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a,i-1));
        insert(a, i);
    }
}
