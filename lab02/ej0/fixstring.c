#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    /*
     * COMPLETAR
     *
     */

    int cont=0,i=0;
    
    while(s[i]!='\0'){
        cont++;
        i++;
    }
    return cont;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    /*
     * COMPLETAR
     *
     */
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
    /*
     * COMPLETAR
     *
     */
    int i=0;
    while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0'){
        i++;
    }
    bool less_eq = (s1[i]>s2[i])? false : true;
    return less_eq;
}

