#ifndef LIBRARY_H
#define LIBRARY_H
#define CHAR_MAX 50
#define ROUTE "./data_set.txt"

void menu(char *);
void bestProvince(float, float, float);

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
    char cityName[CHAR_MAX];
};//city

struct read
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
};//read

typedef struct city city_t;
typedef struct read read_t;

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
    float AverageTempCity(int*);
    int searchCityName(int*);
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