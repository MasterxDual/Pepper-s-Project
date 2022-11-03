/* Librerias */
#include <iostream>
#include "library.h"
using namespace std;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacioon de variables */
    char op = 0;
    int provinceCode=0;
    /*Instanciacion de objetos de la clase Province*/
    read_t read;
    DataSetRead dataset;
    Province Cordoba,SantaFe,Mendoza;

    while(dataset.DataSetEnd())
    {
        dataset.RegainDataSetLine();
        read = dataset.GetDataSetLine();
        switch (read.provCode)
        {
        case 1:
            Cordoba.apped(&read);
            break;
        case 2:
            SantaFe.apped(&read);
            break;
        case 3:
            Mendoza.apped(&read);
            break;
        default:
            printf("\nCodigo de provincia invalido");
            break;
        }
    }
    
    do // ciclo do-while para menu de opciones
    {
        op = menu(); // invocacion funcion menu
        switch(op)
        {
            case 'a':
                printf("Ingrese un numero entero para imprimir las muestras segun la provincia:\n"
                "1. Cordoba\n"
                "2. Santa Fe\n"
                "3. Mendoza\n");
                scanf("%d", &provinceCode);
                switch(provinceCode)
                {
                    case 1:
                        Cordoba.countProvinces(provinceCode);
                        break;
                    case 2:
                        SantaFe.countProvinces(provinceCode);
                        break;
                    case 3:
                        Mendoza.countProvinces(provinceCode);
                        break;
                    default:   
                        printf("Numero incorrecto, vuelva a ingresar\n");
                }
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
