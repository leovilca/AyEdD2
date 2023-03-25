#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    //
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;

    for(unsigned int i=0; i<length; i++){
    	if(value > arr[i]){
    		res.is_lowerbound = false;
		}else if(value < arr[i]){
			res.is_upperbound = false;
		}
		if(value == arr[i]){
			res.exists = true;
			res.where = i;
		}
	}
    
    //
    return res;
}

int main(void) {

    // TODO: COMPLETAR - Pedir entrada al usuario
        
        int length,value;
        printf("Ingrese el numero de elementos: "); // Pido el tamaño del arreglo
        scanf("%d",&length);
        int a[length];

        //Solicito cada elemento

        for(int i=0; i<length; i++){
            printf("Ingrese el elemento numero %d: ",i+1); // Ingreso cada uno
            scanf("%d",&a[i]);
        }

        printf("Ingrese un numero a comparar: ");
        scanf("%d",&value);

    //
    
    
    struct bound_data result = check_bound(value, a, length);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    
    if(result.exists){

        if(result.is_upperbound){
            printf("El valor es máximo, y se encuentra en la posición %d.\n",result.where);
        }else if(result.is_lowerbound){
            printf("El valor es mínimo, y se encuentra en la posición %d.\n",result.where);
        }

    }else{

        if(result.is_upperbound){
            printf("El valor es cota superior.\n");
        }else if(result.is_lowerbound){
            printf("El valor es cota inferior.\n");
        }

    }

    return EXIT_SUCCESS;
}

