/* Librerias */
#include <iostream>
#include "library.h"
using namespace std;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    char op = 0;

    do
    {
        op = menu();
        switch(op)
        {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                break;
            case 'i':
                break;
            default:
                printf("Debe escribir una letra desde la a hasta la i\n");
                break;
        } //Switch
    } while(op!='i'); //Do-while

    return 0;
} //Main
