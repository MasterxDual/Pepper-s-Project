/*Funcionalidad de prueba, no hacer merge a la
rama principal por ningun motivo.
Esta funcionalidad permite la creacion 
de una lista enlazada, en la cual cada nodo 
contiene los datos de las mediciones.
Se hacec uso de clases.
Se debe cargar una estructura con los datos de las
mediciones a los metodos de la clase Province
Se pueden crear varios objetos provinces. Cada uno generara 
una lista independiente
Cuenta con un problema con las cadenas de texto en la
linea 97 por lo que se recurrio al uso de 
la libreria string.h.Se debe buscar una mejor solucion
a este problema pero el programa anda igualmente*/

/* Librerias */
#include <iostream>
#include <string.h>

/* Directivas */
#define CHAR_MAX 50

using namespace std;

/* Estructuras */
struct timestamp 
{
    int day;
    int month;
    int hh;
    int mm;
};
struct measurement 
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
    char cityName[CHAR_MAX];
};


struct read // estructura para leer los datos
{
    int cityId;
    int provCode;
    char cityName[CHAR_MAX];
    float temp;
    float hum;
    int hh;
    int mm;
    int day;
    int month;
};

typedef struct city city_t;
typedef struct read read_t;
/* Clase */
class Province
{
    private:
    city_t *head;
    city_t *temp;
    city_t *newNode;
    public:
    Province(); // constructor
    void apped(read_t *);
    void printList(void);
    ~Province(); // destructor
};
Province::Province()
{
    head = NULL;
    temp = NULL;
    newNode = NULL;
}
Province::~Province()
{
	while(head != NULL)
	{
		temp = head;
	    head = temp->next;
		free(temp);
	    printf("\n Nodo liberado");
	}
}
void Province::apped(read_t *read)
{
    newNode =(city_t *)malloc(sizeof(city_t));
    if(newNode == NULL)
    {
        printf("\nNo hay memoria");
        exit(1);
    }
    //Añado informacion de lectura al nodo
    newNode->cityId = read->cityId;
    newNode->m.hum = read->hum;
    newNode->m.temp = read->temp;
    newNode->m.time.mm= read->mm;
    newNode->m.time.hh= read->hh;
    newNode->m.time.day= read->day;
    newNode->m.time.month= read->month;
    //tratar de evitar este metodo
    //newNode->cityName=read->cityName;
    strncpy(newNode->cityName,read->cityName,CHAR_MAX);
    newNode->next=NULL;
    //agregando
    if(head == NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = newNode;
        
    }
}
void Province::printList()
{
 
    temp = head;
    while (temp != NULL)
    {
        printf("\nCiudad: %s"
        "cityId: %d"
        "\nTemp: %.2f"
        "\nHum: %.2f"
        "\nday: %d"
        "\nmonth: %d"
        "\nhh: %d"
        "\nmm: %d",
        temp->cityName,
        temp->cityId,
        temp->m.temp,
        temp->m.hum,
        temp->m.time.day,
        temp->m.time.month,
        temp->m.time.hh,
        temp->m.time.mm);
        temp=temp->next;
    }
    
}
int main(int argc, char const *argv[])
{
    int cont=0;
    read_t read;
    Province cordoba;

    //CARGA DE ESTRUCTURA:
    do
    {
        printf("\nCity Name: ");
        fgets(read.cityName,CHAR_MAX,stdin);
        printf("\nCityID: ");
        scanf("%d",&read.cityId);
        printf("\nTemp: ");
        scanf("%f",&read.temp);
        printf("\nHum: ");
        scanf("%f",&read.hum);
        printf("\nday: ");
        scanf("%d",&read.day);
        printf("\nmonth: ");
        scanf("%d",&read.month);
        printf("\nhh: ");
        scanf("%d",&read.hh);
        printf("\nmm: ");
        scanf("%d",&read.mm);
        cordoba.apped(&read);
        cont ++;
        setbuf(stdin,NULL);
    }while(cont < 3);
    cordoba.printList();
    return 0;
}
