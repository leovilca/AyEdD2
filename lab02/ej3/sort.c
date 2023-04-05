#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */

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

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */

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
    swap(a,ppiv,i);
    ppiv=i;
    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

