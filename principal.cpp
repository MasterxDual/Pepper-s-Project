/* Librerias */
#include <iostream>
#include "library.h"
using namespace std;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacioon de variables */
    char op = 0;

    do // ciclo do-while para menu de opciones
    {
        op = menu(); // invocacion funcion menu
        switch(op)
        {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                break;
            case 'i':
                printf("\nCerrando...\n");
                break;
            default:
                printf("\nCaracter invalido. Intente nuevamente.\n");
                break;
        } //Switch
    } while(op!='i'); //Do-while

    return 0;
} //Main
