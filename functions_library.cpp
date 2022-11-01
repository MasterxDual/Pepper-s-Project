#include "library.h"
#include <iostream>
#include <string.h>
Province::Province()
{
    head = NULL;
    temp = NULL;
    newNode = NULL;
}//Province::constructor
Province::~Province()
{
	while(head != NULL)
	{
		temp=head;
	    head = temp->next;
		free(temp);
        //printf("\nFree node");
	}//while
}//Province::destructor
void Province::apped(read_t *read)
{
    newNode =(city_t *)malloc(sizeof(city_t));
    if(newNode == NULL)
    {
        printf("\nNot memory");
        exit(1);
    }//if
    //Set new node data
    newNode->cityId = read->cityId;
    newNode->m.hum = read->hum;
    newNode->m.temp = read->temp;
    newNode->m.time.mm= read->mm;
    newNode->m.time.hh= read->hh;
    newNode->m.time.day= read->day;
    newNode->m.time.month= read->month;
    strncpy(newNode->cityName,read->cityName,CHAR_MAX);
    newNode->next=NULL;
    if(head == NULL)
    {
        head=newNode;
    }//if
    else
    {
        temp=head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }//while
        temp->next = newNode;
        
    }//else
}//Province::apped
void Province::printList()
{
 
    temp = head;
    while (temp != NULL)
    {
        printf("\nCity Name: %s"
        "\ncityId: %d"
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
    }//while
    
}//Province::printList

DataSetRead::DataSetRead()
{
    file = fopen(ROUTE,"r");
    if(file == NULL)
    {
        printf("\nFILE ERROR");
        exit(1);
    }
}//DataSetRead::constructor
DataSetRead::~DataSetRead()
{
    fclose(file);
}//DataSetRead::destructor
void DataSetRead::RegainDataSetLine()
{
    fscanf(file,"%d %d %s %f %f %d %d %d %d",
            &DataSetLine.cityId,
            &DataSetLine.provCode,
            DataSetLine.cityName,
            &DataSetLine.temp,
            &DataSetLine.hum,
            &DataSetLine.hh,
            &DataSetLine.mm,
            &DataSetLine.day,
            &DataSetLine.month);
}
read_t DataSetRead::GetDataSetLine()
{
    return DataSetLine;
}
int DataSetRead::DataSetEnd()
{
    if(feof(file))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char menu(void)
{
    /* Declaracion e inicializacioon de variables */
    char op = 0;

    /* Menu de opciones */
    printf("Ingrese una letra segun lo que quiera mostrar:\n"
            "a. Total de las muestras almacenadas en las listas pertenecientes a cada provincia.\n"
            "b. Temperatura promedio de cada provincia.\n"
            "c. Temperatura promedio de cada ciudad.\n"
            "d. Ciudad mas calida de cada provincia.\n"
            "e. Ciudad mas fria de cada provincia.\n"
            "f. Dia mas frio de cada provincia.\n"
            "g. Dia mas calido de cada provincia.\n"
            "h. Mejor provincia para el cultivo de pimientos(temperatura promedio cercana a 23 grados centigrados).\n"
            "i. Cerrar menu.\n"
            "Ingrese una opcion: ");
    scanf(" %c", &op);
    op = tolower(op); // convierte cualquier caracter a minusculas
    return op;
} // menu