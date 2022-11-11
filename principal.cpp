/* Librerias */
#include <iostream>
#include "library.h"
using namespace std;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char op = 0;
    int provinceCode=0, cityId=0;
    float avTempCor=0, avTempStaFe=0, avTempMza=0;
    read_t read;

    /* Instanciacion de objetos */
    DataSetRead dataset;
    Province Cordoba, SantaFe, Mendoza;

    /* Lectura del archivo y carga de Listas */
    while(dataset.DataSetEnd())
    {
        dataset.RegainDataSetLine();
        read = dataset.GetDataSetLine();
        /* Descartar valores de dias y meses inconrrectos */
        if ((read.month>=1&&read.month<=12)&&(read.day>=1&&read.day<=31))
        {
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
                /* Se descartan valores con Codigo de provincia invalido */
                break;
            } // switch
        }
    } // while

    /* Definiendo variables de temperaturas promedio */
    avTempCor=Cordoba.averageTempProv();
    avTempStaFe=SantaFe.averageTempProv();
    avTempMza=Mendoza.averageTempProv();

    do // ciclo do-while para menu de opciones
    {
        menu(&op); // invocacion funcion menu
        switch(op)
        {
            case 'a':
                printf("\nTotal de las muestras almacenadas en cada provincia:\n");
                printf("Cordoba: %d muestras.\n", Cordoba.countProvinces());
                printf("Santa Fe: %d muestras.\n", SantaFe.countProvinces());
                printf("Mendoza: %d muestras.\n", Mendoza.countProvinces());
                break;
            case 'b':
                printf("\nTemperaturas promedio de cada provincia:\n");
                printf("Temperatura promedio de Cordoba: %.2f\n", avTempCor);
                printf("Temperatura promedio de Santa Fe: %.2f\n", avTempStaFe);
                printf("Temperatura promedio de Mendoza: %.2f\n", avTempMza);
                break;
            case 'c':
                printf("\nIngresa el codigo de provincia: ");
                scanf("%d", &provinceCode);
                printf("y el codigo de ciudad: ");
                scanf("%d", &cityId);
                switch (provinceCode)
                {
                    case 1:
                        if(Cordoba.searchCityName(&cityId))
                            printf("\nTemp prom: %.2f", Cordoba.averageTempCity(&cityId));
                        break;
                    case 2:
                        if(SantaFe.searchCityName(&cityId))
                            printf("\nTemp prom: %.2f", SantaFe.averageTempCity(&cityId));
                        break;
                    case 3:
                        if(Mendoza.searchCityName(&cityId))
                            printf("\nTemp prom: %.2f", Mendoza.averageTempCity(&cityId));
                        break;
                    default:
                        printf("\nCodigo de provincia invalido");
                        break;
                } // switch
                break;
            case 'd':
                printf("\n* Ciudad/es mas calida/s de Cordoba:\n");
                Cordoba.searchWarmestCity();
                printf("\n* Ciudad/es mas calida/s de Santa Fe:\n");
                SantaFe.searchWarmestCity();
                printf("\n* Ciudad/es mas calida/s de Mendoza:\n");
                Mendoza.searchWarmestCity();
                break;
            case 'e':
                break;
            case 'f':
                printf("\nDias mas frios de cada provincia:\n"
                "* Dia/s y mes mas frio/s de Cordoba: ");
                Cordoba.coldestDayProv();
                printf("* Dia/s y mes mas frio/s de Santa Fe: ");
                SantaFe.coldestDayProv();
                printf("* Dia/s y mes mas frio/s de Mendoza: ");
                Mendoza.coldestDayProv();
                break;
            case 'g':
                printf("\nIngresa el codigo de provincia: ");
                scanf("%d", &provinceCode);
                printf("y el codigo de ciudad: ");
                scanf("%d", &cityId);
                switch(provinceCode)
                {
                    case 1:
                        if(Cordoba.searchCityName(&cityId)) {
                            printf("Dia y mes mas calido: ");
                            Cordoba.warmestDayCity(&cityId);
                            break;
                        } // if
                    case 2:
                        if(SantaFe.searchCityName(&cityId)) {
                            printf("Dia y mes mas calido: ");
                            SantaFe.warmestDayCity(&cityId);
                            break;
                        } // if
                    case 3:
                        if(Mendoza.searchCityName(&cityId)) {
                            printf("Dia y mes mas calido: ");
                            Mendoza.warmestDayCity(&cityId);
                            break;
                        } // if
                    default:
                        printf("\nCodigo de provincia invalido");
                        break;
                } // switch
                break;
            case 'h':
                bestProvince(avTempCor, avTempStaFe, avTempMza);
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
