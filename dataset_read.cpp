/*programa para realizar lecturas del
 archivo data_set.txt, lee los 8000 datos y
 los imprime*/
#include <iostream>
#define ROUTE "./data_set.txt"
using namespace std;
struct lectura
{
    int cityCode;
    int provCode;
    char cityName[30];
    float temp;
    float hum;
    int hs;
    int min;
    int dd;
    int mm;
};
typedef struct lectura lectura_t;
int main(int argc, char const *argv[])
{
    lectura_t l;
    FILE *file = NULL;
    file= fopen(ROUTE,"r");
    while(!feof(file))
    {
        fscanf(file,"%d %d %s %f %f %d %d %d %d",&l.cityCode,
            &l.provCode,
            l.cityName,
            &l.temp,
            &l.hum,
            &l.hs,
            &l.min,
            &l.dd,
            &l.mm);
        printf("\n%d %d %s %.2f %.2f %d %d %d %d",l.cityCode,
            l.provCode,
            l.cityName,
            l.temp,
            l.hum,
            l.hs,
            l.min,
            l.dd,
            l.mm);
    }
    fclose(file);
    return 0;
}
