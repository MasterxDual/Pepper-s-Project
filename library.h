#ifndef LIBRARY_H
#define LIBRARY_H
#define TAM_STRINGS 50 // maximo de caracteres permitidos en una string
#define ROUTE "./data_set.txt" // Ruta por defecto donde se encuentra el archivos de datos

void menu(char *); // Funcion para interectuar con el menu de opciones
void bestProvince(float, float, float); // Funcion para evaluar cual es la mejor provincia para el cultivo de pimientos

struct timestamp
{
    int day;
    int month;
    int hh;
    int mm;
};//timestamp

struct measurement
{
    float temp;
    float hum;
    struct timestamp time;
};//measurement

struct city
{
    struct city *next;
    struct measurement m;
    int cityId;
    char cityName[TAM_STRINGS];
};//city

struct read
{
    int cityId;
    int provCode;
    char cityName[TAM_STRINGS];
    float temp;
    float hum;
    int hh;
    int mm;
    int day;
    int month;
};//read

typedef struct city city_t;
typedef struct read read_t;

int CompareReads(read_t *,read_t *);
class Province
{
    private:
    city_t *head;
    city_t *temp;
    city_t *newNode;
    public:
    Province();
    void append(read_t *);
    void printList(void);
    int countProvinces(void);
    float averageTempProv(void);
    void coldestDayProv(void);
    float averageTempCity(int *);
    int searchCityName(int *);
    void warmestDayCity(int *);
    void searchWarmestCity(void);
    void searchColdestCity(void);
    ~Province();
};//province class

class DataSetRead
{
    private:
    read_t DataSetLine;
    FILE *file;
    public:
    DataSetRead();
    void RegainDataSetLine();
    read_t GetDataSetLine();
    
    int DataSetEnd();
    ~DataSetRead();
};//class DataSetRead

#include "functions_library.cpp"
#endif