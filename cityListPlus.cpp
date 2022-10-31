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
class Provincie
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
public:
    Provincie();
    void loadData(city_t **head);
    void printData(void);
    ~Provincie();
};

void Provincie::loadData(city_t **head)
{
    city_t *temporary = NULL; // var. temporal
    /* Creacion de Memoria para nuevo nodo */
    city_t *newNode =(city_t *)malloc(sizeof(city_t));
    if(newNode == NULL)
    {
        printf("\nNo hay memoria!\n");
        exit(1); // finaliza el programa
    }
    //Añado informacion de lectura al nodo
    newNode->cityId = cityCode;
    newNode->m.hum = hum;
    newNode->m.temp = temp;
    newNode->m.time.mm= mm;
    newNode->m.time.hh= hh;
    newNode->m.time.day= day;
    newNode->m.time.month= month;
    strncpy(newNode->cityName, cityName, TAM_STRINGS);
    newNode->next=NULL;
    //agregando
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temporary = *head;
        while (temporary->next != NULL)
            temporary = temporary->next;
        temporary->next = newNode;
    }
}

/* Constructor y Destructor */
Provincie::Provincie() {}
Provincie::~Provincie() {}

int main(int argc, char const *argv[])
{
    const int tam_array = 1;
    city_t *head = NULL;
    Provincie arch[3];
    arch[0].loadData(&head);
    return 0;
}
