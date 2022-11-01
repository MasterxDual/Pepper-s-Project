#include<iostream>
#include "library.h"
using namespace std;
int main(int argc, char const *argv[])
{
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
            printf("\nEsto es cordoba");
            Cordoba.apped(&read);
            break;
        case 2:
            printf("\nEsto es SantaFe");
            SantaFe.apped(&read);
            break;
        case 3:
            printf("\nEsto es Mendoza");
            Mendoza.apped(&read);
            break;
        default:
            printf("\nCodigo de provincia invalido");
            break;
        }
    }   
    int cent=0;
        do
        {
            printf("\n\nElige una opicion:"
            "\n1. Imprimir lista Cordoba"
            "\n2. Imprimir lista SantaFE"
            "\n3. Imprimir lista Mendoza"
            "\n4.Salir\n");
            scanf("%d",&cent);
            switch (cent)
            {
            case 1:
                Cordoba.printList();
                break;
            case 2:
                SantaFe.printList();
                break;
            case 3:
                Mendoza.printList();
                break;
            default:
                break;
            }

        }while(cent != 4);
    return 0;
}
