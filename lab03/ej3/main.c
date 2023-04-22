#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

void sorting(int indexes[], char letters[], char sorted[], unsigned int length){
    for(unsigned int i=0; i<length; i++){
        sorted[indexes[i]] = letters[i];
    }
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){

    unsigned int res = 0;

    FILE *file = NULL;
    file = fopen(path, "r");

    if(file == NULL){
        printf("Fallo la apertura del archivo.\n");
        return 0;
    }

    while(!feof(file) && res<max_size){
        char letter;
        int index;
        fscanf(file,"%d",&index);
        fscanf(file," -> *%c*",&letter);
        indexes[res] = index;
        letters[res] = letter;
        res++;
    }

    return res-1;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[]) {

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;
    //  .----------^
    //  :s

    length = data_from_file(argv[1],indexes,letters,MAX_SIZE);
    
    /* -- completar -- */

    sorting(indexes,letters,sorted,length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}