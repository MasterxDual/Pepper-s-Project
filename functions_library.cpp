#include "library.h"
#include <iostream>
#include <string.h>
#include <math.h>

Province::Province()
{
    head=NULL;
    temp=NULL;
    newNode=NULL;
} // constructor clase Province

Province::~Province()
{
	while(head!=NULL)
	{
		temp=head;
	    head=temp->next;
		free(temp);
	} // while
} // destructor clase Province

void Province::append(read_t *read)
{
    /* Crear memoria para el nuevo nodo */
    newNode =(city_t *)malloc(sizeof(city_t));
    if(newNode==NULL) // verificamos si hay memoria suficiente
    {
        printf("\nNot memory\n");
        exit(1); // finaliza la ejecucion del programa
    } // if

    // Set new node data
    newNode->cityId = read->cityId;
    newNode->m.hum = read->hum;
    newNode->m.temp = read->temp;
    newNode->m.time.mm= read->mm;
    newNode->m.time.hh= read->hh;
    newNode->m.time.day= read->day;
    newNode->m.time.month= read->month;
    strcpy(newNode->cityName, read->cityName);
    newNode->next=NULL;

    if(head==NULL)
        head=newNode;
    else
    {
        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        } // while
        temp->next=newNode;
    } // else
}// Province::append

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
    }// while
}// Province::printList

int Province::countProvinces(void)
{
    int count=0; // contador

    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    } // while

    return count;
} // Province::countProvinces

float Province::averageTempProv(void)
{
    int count=0;
    float sum=0;

    temp=head;
    while(temp!=NULL)
    {
        sum+=temp->m.temp;
        count++;
        temp=temp->next;
    } // while

    return ((float)sum/count);
} // Province::averageTempProv

void Province::coldestDayProv(void)
{
    float lowestTemp=0;
    // int coldestDay=0, coldestMonth=0;
    int firstFlag=0;

    temp=head;
    while(temp!=NULL)
    {
        if(lowestTemp>temp->m.temp || firstFlag==0)
        {
            firstFlag=1;
            lowestTemp=temp->m.temp;
        } // if
        temp=temp->next;
    } // while
    temp=head;
    while (temp!=NULL)
    {
        if (lowestTemp==temp->m.temp)
            printf("%d / %d\t", temp->m.time.day, temp->m.time.month);
        temp = temp->next;
    }
    printf("\n");
} // Province::coldestDayProv

int Province::searchCityName(int *cityId)
{
    int flag=0;
    char name[TAM_STRINGS]={0};

    temp=head;
    while(temp!=NULL && flag!=1)
    {
        if(temp->cityId==*cityId)
        {
            flag=1;
            strcpy(name, temp->cityName);
        } // if
        temp=temp->next;
    } // while

    if(flag!=1)
    {
        printf("\nCodigo de ciudad invalido\n");
        return 0;
    } // if
    else
    {
        printf("\nCiudad: %s\n", name);
        return 1;
    } // if
} // Province::searchCityName

float Province::averageTempCity(int *cityId)
{
    float tot=0, prom=0;
    int count=0;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->cityId==*cityId)
        {
            tot+=temp->m.temp;
            count++;
        } // if
        temp=temp->next;
    } // while
    prom=(float)(tot/count);

    return prom;
} // Province::averageTempCity

void Province::warmestDayCity(int *cityId)
{
    float warmestTemp=0;
    int warmestDay=0, warmestMonth=0;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->cityId==*cityId)
        {
            if(warmestTemp<temp->m.temp)
            {
                warmestTemp=temp->m.temp;
                warmestDay=temp->m.time.day;
                warmestMonth=temp->m.time.month;
            } // if
        } // if
        temp=temp->next;
    } // while
    printf("%d / %d\n", warmestDay, warmestMonth);
} // Province::warmestDayCity

void Province::searchWarmestCity(void)
{
    float warmestTemp=0;
    char name[TAM_STRINGS]={0};

    temp=head;
    while(temp!=NULL)
    {
        if(warmestTemp<temp->m.temp)
            warmestTemp=temp->m.temp;
        temp=temp->next;
    } // while

    temp=head;
    while (temp!=NULL)
    {
        if (warmestTemp==temp->m.temp)
            printf("\t%s", temp->cityName);
        temp=temp->next;
    }
    printf("\n");
    printf("Con una temperatura de: %.2f\n", warmestTemp);
} // Province::searchWarmestCityId

DataSetRead::DataSetRead()
{
    /* Abrir archivo para lectura */
    file=fopen(ROUTE,"r");
    if(file==NULL) // verificar si el archivo existe
        perror(ROUTE); // produce un mensaje de error por consola
}// constructor clase DataSetRead

DataSetRead::~DataSetRead()
{
    fclose(file);
}// destructor clase DataSetRead

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
} // DataSetRead::RegainDataSetLine

read_t DataSetRead::GetDataSetLine()
{
    return DataSetLine;
} // DataSetRead::GetDataSetLine

int DataSetRead::DataSetEnd()
{
    if(feof(file)) // evalua si feof(file) == 1
        return 0;
    else
    {
        return 1;
    } // else
} // DataSetRead::DataSetEnd

void bestProvince(float avTempCor, float avTempStaFe, float avTempMza)
{
    /* Declaracion e inicializacion de variables */
    const float nearTemp=23; // Guardo el valor de temperatura ideal para cultivo de pimientos
    float diffCor=0,
          diffStaFe=0,
          diffMza=0;
    float diffs[3]={0},
          idealTemp=0;
    int firstFlag=0;

        /* Calculo los valores absolutos de las diferencias entre
    la temperatura ideal y las temperaturas promedio de cada provincia,
    y dichas direncias de cada provincia se almacenan en un array*/
    diffs[0]=fabs(nearTemp-avTempCor); // Cordoba
    diffs[1]=fabs(nearTemp-avTempStaFe); // Santa Fe
    diffs[2]=fabs(nearTemp-avTempMza); // Mendoza

/*     Guardo las diferencias de cada provincia en un array
    diffs[0]=diffCor;
    diffs[1]=diffStaFe;
    diffs[2]=diffMza; */

    /* Busco la menor diferencia, esa sera la temperatura ideal para el cultivo de pimientos */
    for(int ii=0; ii<3; ii++)
    {
        if(diffs[ii]<idealTemp || firstFlag==0)
        {
            firstFlag=1;
            idealTemp=diffs[ii];
        } // if
    } // for

    /* Identifico de cual de las provincias es el idealTemp (temperatura ideal), y esa
    sera la provincia ideal para el cultivo de pimientos */
    if(idealTemp==diffs[0])
        printf("\nCordoba es la mejor provincia para el cultivo de pimientos.\n"
        "Con una temperature promedio de %.2f.\n", avTempCor);
    if(idealTemp==diffs[1])
        printf("\nSanta Fe es la mejor provincia para el cultivo de pimientos.\n"
        "Con una temperatura promedio de %.2f.\n", avTempStaFe);
    if(idealTemp==diffs[2])
        printf("\nMendoza es la mejor provincia para el cultivo de pimientos.\n"
        "Con una temperatura promedio de %.2f.\n", avTempMza);
} // bestProvince()

int CompareReads(read_t *read, read_t *prev)
{
    // si son iguales las lecturas
    if(read->day == prev->day && read->month == prev->month && read->hh == prev->hh && read->mm == prev->mm && read->cityId == prev->cityId && read->temp == prev->temp && read->hum == prev->hum && read->provCode == prev->provCode && strcmp(read->cityName,prev->cityName)==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void menu(char *op)
{
    /* Menu de opciones */
    printf("\n\nMenu de opciones:\n"
            "a. Total de las muestras almacenadas de cada provincia.\n"
            "b. Temperatura promedio de cada provincia.\n"
            "c. Temperatura promedio de cada ciudad.\n"
            "d. Ciudad mas calida de cada provincia.\n"
            "e. Ciudad mas fria de cada provincia.\n"
            "f. Dia mas frio de cada provincia.\n"
            "g. Dia mas calido de cada ciudad.\n"
            "h. Mejor provincia para el cultivo de pimientos.\n"
            "i. Cerrar menu.\n"
            "Ingrese una opcion: ");
    scanf(" %c", op);
    *op=tolower(*op); // convierte cualquier caracter a minusculas
} // menu