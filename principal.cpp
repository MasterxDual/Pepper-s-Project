/* Librerias */
#include <iostream>
#include "library.h"
using namespace std;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char op = 0;
    int provinceCode=0;
    read_t read;
    /* Instanciacion de objetos */
    DataSetRead dataset;
    Province Cordoba, SantaFe, Mendoza;

    /* Lectura del archivo y carga de Listas */
    while(dataset.DataSetEnd())
    {
        dataset.RegainDataSetLine();
        read = dataset.GetDataSetLine();
        switch (read.provCode)
        {
        case 1:
            Cordoba.append(&read);
            break;
        case 2:
            SantaFe.append(&read);
            break;
        case 3:
            Mendoza.append(&read);
            break;
        default:
            printf("\nCodigo de provincia invalido\n");
            break;
        }
    }
    
    do // ciclo do-while para menu de opciones
    {
        menu(&op); // invocacion funcion menu
        switch(op)
        {
            case 'a':
                printf("Cordoba: %d muestras.\n", Cordoba.countProvinces());
                printf("Santa Fe: %d muestras.\n", SantaFe.countProvinces());
                printf("Mendoza: %d muestras.\n", Mendoza.countProvinces());
                break;
            case 'b':
                printf("Temperatura promedio de Cordoba: %.2f\n", Cordoba.averageTempProv());
                printf("Temperatura promedio de Santa Fe: %.2f\n", SantaFe.averageTempProv());
                printf("Temperatura promedio de Mendoza: %.2f\n", Mendoza.averageTempProv());
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
        } // switch
    } while(op!='i'); // do-while

    return 0;
} // main
