#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    int cont=0,i=0;
    
    while(s[i]!='\0'){
        cont++;
        i++;
    }
    return cont;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    int eq=true,i=0;
    while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0'){
        i++;
    }
    if(s1[i]!=s2[i]){
        eq=false;
    }
    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    int i=0;
    while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0'){
        i++;
    }
    bool less_eq = (s1[i]>s2[i])? false : true;
    return less_eq;

}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    /*
     * COMPLETAR
     *
     */
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
}


