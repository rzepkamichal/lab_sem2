#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <math.h>
#include "funkcje.h"

void filltab(const int *tab, int size){
    int i;
    for(i=0;i<size;i++){
        printf("Podaj wartosc elementu %d \n",i+1);
        scanf("%d",&tab[i]);
    }
}

void writetab(const int *tab,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d, \t",tab[i]);
    }
    printf("\n");
}

int find_parameter(const int *tab, int parameter, int size){

    for(int i=0;i<size;i++){
        if(tab[i]==parameter){
            return i;
        }
    }
    return -2;
}

int find_parameter_using_pointers(const int *tab, int parameter, int size){

    for(int i=0;i<size;i++){
        if(*(tab+i)==parameter){
            return i;
        }
    }
    return -2;
}

int poteguj (int podstawa, int wykladnik){
    if(wykladnik==0){
        return 1;
    }

    int i=0;
    int potega = podstawa;
    for(i;i < wykladnik-1;i++){
        potega *= podstawa;
    }
    return potega;
}

void readIBAN(char *iban){
    printf("Prosze podac IBAN: \n");
    scanf("%s",iban);
}

int check_account_number(char *iban){

    size_t length = strlen(iban);   //dlugosc wczytanego lancucha znakow
    int lengthPL = 28;              //poprawna dlugosc polskiego iban
    int calculateConst = 55;        //stala przeliczania kodu liter na cyfry kontrolne
    int P = 80, L = 76;             //kody ascii liter P i L
    char replacedIban[30];          //przechowuje iban z czterema pierwszymi znakami przekonwertowanymi na liczby
                                    //i przeniesionymi na koniec

    //sprawdzenie, czy wczytany iban ma odpowiednia ilosc znakow
    //jezeli nie - zwracana wart: 0 - iban niepoprawny
    if(length == lengthPL){

        //sprawdzenie, czy pierwsze dwa znaki to "PL" oraz czy dwa kolejne znaki to cyfry
        //jezeli nie - zwracana wart: 0 - iban niepoprawny
        if(iban[0] == P && iban[1] == L && isdigit(iban[2]) && isdigit(iban[3])) {

            //konwersja liter na odpowiadajace im cyfry, utworzenie ciagu cyfr kontrolnych
            P = P-calculateConst;
            L = L-calculateConst;
            char controls[6] = {'0'+P/10,'0'+P%10,'0'+L/10,'0'+L%10,iban[2],iban[3]};

            //przeniesienie pozostałego ciagu cyfr na poczatek
            //sprawdzenie, czy kolejne znaki to cyfry
            int i;//iterator
            for(i=4; i<length; i++){
                if(isdigit(*(iban+i))){
                    replacedIban[i-4] = iban[i];
                }else{
                    return 0;
                }
            }

            //dodanie 6 cyfr sumy konrolnej na koniec
            for(i=0; i<6; i++){
                replacedIban[length+i-4] = controls[i];
            }

            //ciag znakow jest przygotowany do konwersji na wartosci liczbowe

            int sequanceLen = 9;    //dlugosc kolejno wczytywanych podciagow
            int digitSeq[9];        //tablica przechowująca kolejne podciagi cyfr w postaci wartosci liczbowych
            int buffer = 0;         //przechowuje wartosci liczb, obliczane na podstawie cyfr tablicy digitSeq
            int modulo;             //przechowuje obliczona reszte z dzielenia
            int position = 0;       //przechowuje informacje, na ktorej cyfrze nr-u iban obecnie sie znajdujemy
            int modTranspose = 0;   //przechowuje informacje o przesunieciu w iteracji
                                    //z powodu dodania cyfr obliczonego modulo na poczatek
            int endPosition = 30;   //ostatnia pozycja nr-u iban zwiekszona o 1
            char moduloBuffer[2];   //przechowuje obliczana wartosc modulo w postaci ciagu znakow
                                    //sluzy do dodawania obliczonego modulo na poczatek kolejnego podciagu cyfr

            while(position < endPosition){

                // interpretacja cyfr zapisanych w postaci ciagu znakow jako wartosci liczowych
                for(i = 0 + modTranspose; i < sequanceLen; i++){
                    digitSeq[i] = replacedIban[position]-'0';
                    position++;
                }

                //przporzadkowanie ciagowi cyfr konkretnej wartosci liczbowej
                //wykorzystanie funkcji potegujacej, parametr pierwszy - podstawa, parametr drugi - wykladnik
                for(i = 0; i < sequanceLen; i++){
                   buffer += digitSeq[i]*poteguj(10,sequanceLen-1-i);
                }

                //obliczenie reszty z dzielenia uzyskanej liczby przez 97
                modulo = buffer % 97;

                //jezeli znajdujemy sie na ostatniej pozycji && modulo jest rowne 1
                // - iban jest poprawny, zwracana wart: 1
                //jezeli znajdujemy sie na ostatniej pozycji, ale modulo jest rozne od 1
                // - iban jest niepoprawny, zwracana wart: 0
                //w innym przypadku, obliczenia sa kontynuowane
                if(position == endPosition && modulo == 1){
                    return 1;
                }else  if(position == endPosition){
                    return 0;
                }

                //zapisz obliczone modulo jako ciag znakow
                sprintf(moduloBuffer, "%d", modulo);

                //dodaj modulo w postaci znakowej na poczatek kolejnego podciagu cyfr
                if (modulo > 9){
                    digitSeq[0] = moduloBuffer[0] - '0';
                    digitSeq[1] = moduloBuffer[1] - '0';
                    modTranspose = 2;
                }else{
                    digitSeq[0] = moduloBuffer[0] - '0';
                    modTranspose = 1;
                }

                // wyzeruj wartosc, by przechowac nowa zmienna
                buffer = 0;
            }
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}


