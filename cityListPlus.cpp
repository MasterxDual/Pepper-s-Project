/* Librerias */
#include <iostream>
#include <string.h>

/* Directivas */
#define TAM_STRINGS 50

using namespace std;

/* Estructuras */
struct timestamp // marca de tiempo
{
    int day;
    int month;
    int hh;
    int mm;
};
struct measurement // mediciones
{
    float temp;
    float hum;
    struct timestamp time;
};
/* Estructuras Dinamica */
struct city // lista
{
    struct city *next;
    struct measurement m;
    int cityId;
    char cityName[TAM_STRINGS];
};
typedef struct city city_t;

/* Clase */
class Province
{
private:
    int cityCode;
    int provCode;
    char cityName[TAM_STRINGS];
    float temp;
    float hum;
    int hh;
    int mm;
    int day;
    int month;

    city_t *head;

public:
    Province();
    void readData(void);
    void loadData(void);
    void printData(void);
    ~Province();
};

void Province::readData(void)
{
    /* completar con 'dataSetReadPlus.cpp' */
} // readData

void Province::loadData(void)
{
    city_t *temporary = NULL; // var. temporal
    /* Creacion de Memoria para nuevo nodo */
    city_t *newNode = (city_t *)malloc(sizeof(city_t));
    /* Verifica si hay memoria disponible */
    if(newNode == NULL)
    {
        printf("\nNo hay memoria!\n");
        exit(1); // finaliza el programa
    }
    /* Añado informacion de lectura al nodo */
    newNode->cityId = cityCode;
    newNode->m.hum = hum;
    newNode->m.temp = temp;
    newNode->m.time.mm= mm;
    newNode->m.time.hh= hh;
    newNode->m.time.day= day;
    newNode->m.time.month= month;
    strcpy(newNode->cityName, cityName);
    newNode->next=NULL;
    /* Si la lista esta vacia, el nuevo nodo es el primero */
    if(head == NULL)
        head = newNode;
    else // sino, sera el ultimo
    {
        temporary = head;
        while (temporary->next != NULL)
            temporary = temporary->next;
        temporary->next = newNode;
    }
}

/* Constructor y Destructor */
Province::Province()
{
    head = NULL;
}
Province::~Province() {}

int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    city_t *head = NULL; // cabeza de la lista
    Province arch[3]; // arreglo de objetos, un elemento por provincia

    /* Menu de opciones */

    /* Aqui iria un bucle for */
    arch[0].loadData();
    return 0;
}
