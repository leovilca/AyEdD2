#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    /* needs implementation */
    unsigned int j=i;
    bool band=true;
    while(band){
        bool res = goes_before(a[j],a[j-1]);
        if(res){
            swap(a,j,j-1);
        }
        if(!res || j==1){
            band=false;
        }else{
            j--;
        }
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a,i));
        insert(a, i);
    }
}
