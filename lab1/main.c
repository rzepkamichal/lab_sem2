#include <stdio.h>
#include "funkcje.h"

int main() {
    // program do zad. 1

    /*const int size = 20;
    const int tab[size];

    int i;
    for(i=0;i<size;i++){
        printf("Podaj wartosc elementu %d \n",i+1);
        scanf("%d",&tab[i]);
    }

    for(i=0;i<size;i++){
        printf("%d,\t",tab[i]);
    }*/

    // program do zad. 2, 3

    const int size = 15;
    const int tab[] = {2,5,34,63,46,24,35,57,235,46,36,45,95,5246,623};
    int parametr;
    printf("Prosze podac liczbe, ktorej indeks ma byc wyszukany\n");
    scanf("%d",&parametr);

    printf("Zwrocona wartosc: %d\n", find_parameter(tab, parametr, size));

    return 0;

}


