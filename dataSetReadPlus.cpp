/* Librerias */
#include <iostream>
#include <string.h>

/* Directivas */
#define TAM_STRINGS 50
#define ROUTE "./data_set.txt"

using namespace std;

class Data
{
private:
    int cityCode;
    int provCode;
    char cityName[TAM_STRINGS];
    float temp;
    float hum;
    int hs;
    int min;
    int dd;
    int mm;
public:
    Data();
    void readData(void);
    void printData(void);
    ~Data();
};

/* Metodos de class Archivo */
void Data::readData(void)
{
    /* Por ahora no solo lee el archivo sino tambien lo imprime,
    lo ideal es crear una funcion para leer y otra para escribit,
    pero con esto ya tenemos solventado el asunto de dedicar la
    clase para leer el archivo, condicion del primer enunciado */
    FILE *file;
    file= fopen(ROUTE,"r");
    int num = 1; // codigo de provincia 1 = Cordoba

    while (!feof(file))
    {
        fscanf(file,"%d %d %s %f %f %d %d %d %d",
                &cityCode,
                &provCode,
                cityName,
                &temp,
                &hum,
                &hs,
                &min,
                &dd,
                &mm);
        if (num == provCode) // solo imprime aquellos valores con el codigo de provincia = 1
        {
            printData();
        }
    }

    fclose(file);
    printf("\nLectura exitosa!\n");
} // readData
void Data::printData(void)
{
    printf("\n%d %d %s %.2f %.2f %d %d %d %d",
        cityCode,
        provCode,
        cityName,
        temp,
        hum,
        hs,
        min,
        dd,
        mm);
} // printData


/* Constructor y Destructor */
Data::Data() {}
Data::~Data() {}

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    Data arch; // instancia arch de la clase Archivo
    arch.readData(); // invocacion del metodo readData
    return 0;
}
