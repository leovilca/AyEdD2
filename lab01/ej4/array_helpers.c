/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {

    //your code here!!!

    FILE *fp = fopen(filepath,"r");

    fscanf(fp,"%d",&max_size);

    for(int i=0;i<max_size; i++){
        //Llenando el arreglo
        fscanf(fp,"%d",&array[i]);
    }

    fclose(fp);

    return max_size;

    //
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!

    printf("[ %d",a[0]);
    for(int i=1; i<length; i++){
        printf(", %d",a[i]);
    }
    printf("]\n");

    //

}

bool array_is_sorted(int a[], unsigned int length){

    bool res = true;

    for(int i=0;i<length-1;i++){
        if(a[i]>a[i+1]){
            res = false;
            break;
        }
    }

    return res;

}