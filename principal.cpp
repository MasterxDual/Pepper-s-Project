#include <iostream>
#include "library.h"
using namespace std;

int main(int argc, char const *argv[]) {
    char op=' ';

    do {
        op=menu();
        switch(op) {
            case 'a':
            case 'A':
                break;
            case 'b':
            case 'B':
                break;
            case 'c':
            case 'C':
                break;
            case 'd':
            case 'D':
                break;
            case 'e':
            case 'E':
                break;
            case 'f':
            case 'F':
                break;
            case 'g':
            case 'G':
                break;
            case 'h':
            case 'H':
                break;
            case 'i':
            case 'I':
                break;
            default:
                printf("Debe escribir una letra desde la a hasta la i\n");
                break;
        } //Switch
    } while(op!='i'); //Do-while

    return 0;
} //Main
