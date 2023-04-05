#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
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
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int ppiv = izq;
    int i=izq+1,j=der;
    while(i<=j){
        if(a[i]<=a[ppiv]){
            i++;
        }else if(a[j]>=a[ppiv]){
            j--;
        }else{
            swap(a,i,j);
        }
    }
    swap(a,ppiv,j);
    ppiv=j;
    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
    if(der>izq){
        unsigned int ppiv = partition(a,izq,der);
        if(ppiv>izq){
            quick_sort_rec(a,izq,ppiv-1);
        }
        if(ppiv<der){
            quick_sort_rec(a,ppiv+1,der);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
