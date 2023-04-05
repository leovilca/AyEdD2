#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"

static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    int i=izq+1,j=der;
    while(i<=j){
        if(goes_before(a[i],a[ppiv])){
            i++;
        }else if(!goes_before(a[j],a[ppiv]) || fstring_eq(a[j],a[ppiv])){
            j--;
        }else{
            fstring_swap(a[i],a[j]);
        }
    }
    fstring_swap(a[ppiv],a[j]);
    ppiv=j;
    return ppiv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if(der>izq){
        unsigned int ppiv = partition(a,izq,der);
        if(ppiv>izq){
            quick_sort_rec(a,izq,ppiv-1u);
        }
        if(ppiv<der){
            quick_sort_rec(a,ppiv+1u,der);
        }
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}