#include "library.h"
#include <iostream>

char menu(void) {
    char op=' ';

    printf("Escriba una letra segun lo que quiera mostrar:\n");
    printf("a. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n");
    printf("b. Temperatura promedio de cada provincia\n");
    printf("c. Temperatura promedio de cada ciudad\n");
    printf("d. Ciudad mas calida de cada provincia\n");
    printf("e. Ciudad mas fria de cada provincia\n");
    printf("f. Dia mas frio de cada provincia\n");
    printf("g. Dia mas calido de cada provincia\n");
    printf("h. Mejor provincia para el cultivo de pimientos(temperatura promedio cercana a 23 grados centigrados)\n");
    scanf(" %c", &op);

    return op;
}