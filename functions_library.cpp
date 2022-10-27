#include "library.h"
#include <iostream>

char menu(void)
{
    /* Declaracion e inicializacioon de variables */
    char op = 0;

    /* Menu de opciones */
    printf("Ingrese una letra segun lo que quiera mostrar:\n"
            "a. Total de las muestras almacenadas en las listas pertenecientes a cada provincia.\n"
            "b. Temperatura promedio de cada provincia.\n"
            "c. Temperatura promedio de cada ciudad.\n"
            "d. Ciudad mas calida de cada provincia.\n"
            "e. Ciudad mas fria de cada provincia.\n"
            "f. Dia mas frio de cada provincia.\n"
            "g. Dia mas calido de cada provincia.\n"
            "h. Mejor provincia para el cultivo de pimientos(temperatura promedio cercana a 23 grados centigrados).\n"
            "i. Cerrar menu.\n"
            "Ingrese una opcion: ");
    scanf(" %c", &op);
    op = tolower(op); // convierte cualquier caracter a minusculas
    return op;
} // menu