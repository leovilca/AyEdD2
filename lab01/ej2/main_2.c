/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size) {

    printf("Ingrese el tamaño del arreglo: ");
    
    scanf("%d",&max_size);

    for(int i=0;i<max_size; i++){

        printf("\nIngrese el elemento %d del arreglo: ",i+1);
        scanf("%d",&array[i]);

    }

    return max_size;

}

void array_dump(int a[], unsigned int length) {

    printf("[ %d",a[0]);
    for(int i=1; i<length; i++){
        printf(", %d",a[i]);
    }
    printf("]\n");

}


int main() {
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
