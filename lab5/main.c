#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//rozmiar bufora na tekst
#define BUFFER_SIZE 64
//rozmiar bufora na tekst logow
#define LOG_BUFFER_SIZE 32
//liczba mozliwych wartosci
//reprezentowanych przez znaki rzymskie
#define NUM_OF_VALUES 13

//nadanie nazwy buforowi na logi
typedef struct LOG_BUFF logBuffer;

/*struktura LOG_BUFF
 *reprezentuje bufor
 *przechowuje treść logów w postaci lancuchow znakow:
 * - char convertFrom[] - liczba konwertowana
 * - char convertTo[] - liczba po konwersji
 * - char *currentTimeStr - aktualny czas
 */
struct LOG_BUFF{
    char convertFrom[LOG_BUFFER_SIZE];
    char convertTo[LOG_BUFFER_SIZE];
    char *currentTimeStr;
};
/*Funkcja IsRomanSign
 *Sprawdza, czy otrzymany znak jest znakiem rzymskim.
 *Parametry:
 * - char sign - sprawdzany znak
 *Zwraca:
 * - wartosc calkowita: - 1 w przypadku odczytu znaku rzymskiego
 *                      - 0 w innym przypadku
 */
int IsRomanSign(char sign){
    if(sign == 'I' || sign == 'C' || sign == 'X' || sign == 'D' || sign == 'V' || sign == 'M' || sign == 'L')
        return 1;
    else
        return 0;
}
/*funkcja ValueOfSign
 * Zamienia otrzymany znak rzymski na wartosc liczbowa
 *parametry:
 * - char sign - znak
 *funkcja zwraca:
 * - liczba calkowita - wartosc liczbowa otrzymanego znaku
 */
int ValueOfSign(char sign){
    if(sign == 'I')
        return 1;
    else if(sign == 'V')
        return 5;
    else if(sign == 'X')
        return 10;
    else if(sign == 'L')
        return 50;
    else if(sign == 'C')
        return 100;
    else if(sign == 'D')
        return 500;
    else if(sign == 'M')
        return 1000;
    else
        return 0;
}
/*Funkcja ConvertToDigit
 *Konwertuje otrzymana w ciagu str liczbe rzymska na dziesietna.
 *Kluczowe jest wykorzystanie funkcji ValueOfSign
 *Parametry:
 * - char *str - ciag znakow reprezentujacy liczbe rzymska
 *Zwraca:
 * - int valueTotal - obliczona wartosc w zapisie dziesietnym
 */
int ConvertToDigit(char *str){
    char *strTmp = str;//zmienna tymczasowa sluzoca do iteracji po str
    char signBuffer = *strTmp;//bufor na kolejne znaki z str
    int position = 0;//zmienna przechowujaca liczbe znakow w str

    //zliczanie lizcby znakow str
    while(signBuffer != '\0'){
        position++;
        strTmp++;
        signBuffer = *strTmp;
    }
    strTmp--;

    int max = 0;//aktualna wartosc maksymalna liczby
    int valueTmp = 0;//wartosc zwrocona przez funkcje ValueOfSign
    int valueTotal = 0;//calkowita wartosc

    //petla przechodzaca przez wszystkie znaki str
    while(position > 0){
        //odczytanie wartosci ze znaku
        valueTmp = ValueOfSign(*strTmp);

        /*jezeli odczytana wartosc jes wieksza lub rowna najwiekszej
         *jest dodawana do sumy calkowitej
         *jezeli jest mniejsza- jest odejmowana
         *
         */
        if(valueTmp >= max){
            max = valueTmp;
            valueTotal += valueTmp;
        }else{
            valueTotal -= valueTmp;
        }
        strTmp--;
        position--;
    }

    return valueTotal;
}
/*Funkcja SignOfValue
 * Dla otrzymanej wartości liczbowej
 * Przyporzadkowuje znak rzymski o najwiekszej mozliwej wartosci
 * Nastepnie odejmuje przyporzadkowana wartosc od wartosci otrzymanej
 *Parametry:
 * - char *str - wskaznik na ciag znakow, w ktorym przechowywany
 *               jest aktualny ciag liczb rzymskich, znaleziona wartosc
 *               jest dodawana na koniec lancucha
 * - char *value - wskaznik na wartosc - dla niej funkcja znajduje
 *                 najwiekszy odpowienik w zapisie rzymskim i odejmuje
 *                 go od wartosci tego parametru
 *Zwraca:
 * - void
 */
void SignOfValue(char *str, int *value){
    //tablica mozliwych wartosci w zapisie rzymskim
    int tabOfValues[] ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    //obecna wartosci najwieksza mieszczaca sie w zmiennej value
    int maxValue = 1;

    //wyszukiwanie najwiekszej mozliwej wartosci
    for(int i=0; i<NUM_OF_VALUES; i++){
        if(*value >= tabOfValues[i]){
            maxValue = tabOfValues[i];
            continue;
        }else{
            break;
        }
    }

    /*Dodanie ciagu znakow na koniec lancucha str
     *W zaleznosci od wyznaczonej maxValue
     *Pomniejszenie wartosci value o wyznaczona wartosc
     */
    switch (maxValue){
        case 1:
            strcat(str,"I");
            *value -= maxValue;
            break;
        case 4:
            strcat(str,"IV");
            *value -= maxValue;
            break;
        case 5:
            strcat(str,"V");
            *value -= maxValue;
            break;
        case 9:
            strcat(str,"IX");
            *value -= maxValue;
            break;
        case 10:
            strcat(str,"X");
            *value -= maxValue;
            break;
        case 40:
            strcat(str,"XL");
            *value -= maxValue;
            break;
        case 50:
            strcat(str,"L");
            *value -= maxValue;
            break;
        case 90:
            strcat(str,"XC");
            *value -= maxValue;
            break;
        case 100:
            strcat(str,"C");
            *value -= maxValue;
            break;
        case 400:
            strcat(str,"CD");
            *value -= maxValue;
            break;
        case 500:
            strcat(str,"D");
            *value -= maxValue;
            break;
        case 900:
            strcat(str,"CM");
            *value -= maxValue;
            break;
        case 1000:
            strcat(str,"M");
            *value -= maxValue;
            break;
        default:
            break;
    }
}
/*Funkcja ConverToRoman
 *Podany jako parametr ciag liczb calkowitych
 *Jest zamieniany na reprezentacje w zapisie rzymskim.
 *Kluczowe jest uzycie funkcji konwerujacej SignOfValue
 *Parametry:
 * - char *str - ciag znakow przechowujacy liczbe dziesietna
 *Zwraca:
 * - void
 */
void ConvertToRoman(char *str){
    //konwersja ciagu znakow na liczbe dziesietna i zapis do zmiennej value
    int value = atoi(str);

    //zerowanie ciagu str - do niego bedzie zapisany ciag po konwersji
    memset(str,'\0',BUFFER_SIZE);

    //konwersja z wykorzystaniem funkcji SignOfValue
    while(value >0){
        SignOfValue(str, &value);
    }

}
/*Funkcja GetNumber
 *Poszukuje w lancuchu str liczb rzymskich albo dziesietnych
 *w zaleznosci od funkcji IsNumber. Odczytana liczba
 *jest zapisywana w buforze char *numberBuffer.
 *Parametry:
 * - char *str - badany ciag znakow
 * - char *numberBuffer - bufor na wynik
 * - int (*IsNumber)(char) - wskaznik na funkjce (w zamierzeniu isdigit albo IsRomanSign)
 *Zwraca:
 * - wartosc calkowita: 1 - w przypadku poprawnego odczytu
 *                      0 - jezeli nie znaleziono zadenj reprezentacji liczby
 */
int GetNumber(char *str,  char *numberBuffer, int (*IsNumber)(char)){

    char signBuffer = *str;//bufor na odczyt kolejnych znakow
    int countLoops = 0;//licznik odczytywanych znakow
    int countSigns = 0;//licznik znakow dodawanych do numberBuffer

    unsigned char numberIsBeingRead = 0;//flaga informujaca, czy aktualnie jest odczytywana liczba
    unsigned char spaceWasBefore = 0;//flaga informujaca, czy poprzednio odczytanym znakiem byla spacja

    //petla odczytujaca kolejne znaki z str

    while(signBuffer != '\0'){

        //przejscie przez kolejne warunki wynikajace z zalozen zadania
        if(numberIsBeingRead){
            if(isspace(signBuffer)){
                break;
            }else{
                if(IsNumber(signBuffer)){
                    numberBuffer[countSigns] = signBuffer;
                    countSigns++;
                    str++;
                    signBuffer = *str;
                    countLoops++;
                    continue;
                }else{
                    numberIsBeingRead = 0;
                    countSigns = 0;
                    memset(numberBuffer,'\0',BUFFER_SIZE);
                    str++;
                    signBuffer = *str;
                    countLoops++;
                    continue;
                }
            }
        }else{
            if(IsNumber(signBuffer)){
                if(spaceWasBefore){
                    numberBuffer[countSigns] = signBuffer;
                    countSigns++;
                    numberIsBeingRead = 1;
                    spaceWasBefore = 0;
                    str++;
                    signBuffer = *str;
                    countLoops++;
                    continue;
                }else{
                    if(countLoops == 0){
                        numberBuffer[countSigns] = signBuffer;
                        countSigns++;
                        numberIsBeingRead = 1;
                        spaceWasBefore = 0;
                        str++;
                        signBuffer = *str;
                        countLoops++;
                        continue;
                    }else{
                        str++;
                        signBuffer = *str;
                        countLoops++;
                        continue;
                    }
                }
            }else{
                if(isspace(signBuffer)){
                    spaceWasBefore =1;
                    str++;
                    signBuffer = *str;
                    countLoops++;
                    continue;
                }else{
                    str++;
                    signBuffer = *str;
                    countLoops++;
                    continue;
                }

            }
        }
    }
    if(IsNumber(numberBuffer[0])){
        return 1;
    }else{
        return 0;
    }
}
/*Funkcja ReadFromFile
 *Z pliku o nazwie przekazanej przez parametr
 *Odczytuje liczby rzymskie lub dziesietne,
 *konweruje je zgodnie z okreslonymi kryteriami odczytu.
 *Po udanej konwersji, do bufora logow zapisywany jest log,
 *Nastepnie stan bufora zapisywany jest do pliku "output.txt".
 *Parametry:
 * - char *fileName - ciag znakow bedacy nazwa pliku wejsciowego
 *Zwraca:
 * - void
 */
void ReadFromFile(char *fileName){

    //deklaracja i inicjalizacja pliku wejsciowego i wyjsciowego
    FILE *iFile = fopen(fileName,"r");
    FILE *oFile = fopen("output.txt","w");

    //bufory
    char signBuff = getc(iFile);//bufor na kolejne znaki z pliku
    logBuffer logB;//bufor logow
    char tagBuffer[BUFFER_SIZE] = "\0";//bufor na ciag znakow miedzy tagami html
    char numberBuffer[BUFFER_SIZE] = "\0";//bufor na odczytana z pomiedzy tagow liczbe

    //zmienne pomocnicze
    int countSigns = 0;//zmienna zliczajaca kolejne znaki dodawane do tagBuffer
    int digitValue;//zmienna na wartosc liczbowa otrzymana z konwersji l. rzymskiej
    time_t currentTime;//przechowuje aktualny czas w celu etykietowania logow

    //flagi
    unsigned char tagReadStarted = 0;//1 - rozpoczeto odczyt miedzy znakami tagow ">" i "</"
    unsigned char tagReadEnded = 0;//1 - zakonczono odczyt, naptokano znak "</"
    unsigned char convDone = 0;//1 - zakonczono konwersje

    //petla odczytujaca kolejne znaki z pliku
    while(signBuff != EOF){

        //sprawdzanie kolejnych warunkow odczytu
        if(tagReadStarted){
            if(signBuff == '<'){
                tagReadEnded = 1;
            }else{
                tagBuffer[countSigns] = signBuff;
                countSigns++;
            }
            if(tagReadEnded){
                signBuff = getc(iFile);
                if(signBuff == EOF){
                    break;
                }else if (signBuff == '/'){

                    /*Udalo sie odczytac zawartosc miedzy tagami.
                     *Proba "wyluskania" z ciagu liczby i konwersji na inny zapis
                     *Najpierw proba konwersji dziesietny -> rzymski
                     *Potem proba konwersji rzymski -> dziesietny
                     */
                    if(GetNumber(tagBuffer,numberBuffer,isdigit)){
                        sprintf(logB.convertFrom,"%s",numberBuffer);
                        ConvertToRoman(numberBuffer);
                        sprintf(logB.convertTo,"%s",numberBuffer);
                        memset(numberBuffer,'\0',BUFFER_SIZE);
                        convDone = 1;

                    }else if(GetNumber(tagBuffer,numberBuffer,IsRomanSign)){
                        sprintf(logB.convertFrom,"%s",numberBuffer);
                        digitValue = ConvertToDigit(numberBuffer);
                        sprintf(logB.convertTo,"%d",digitValue);
                        memset(numberBuffer,'\0',BUFFER_SIZE);
                        convDone = 1;
                    }
                    /*Zapis logow do bufora a nastepnie do pliku,
                     *Jezeli konwersja byla udana
                     */
                    if(convDone){
                        convDone = 0;
                        currentTime = time(NULL);
                        logB.currentTimeStr = ctime(&currentTime);
                        fprintf(oFile,"%sKonwersja z %s na %s\n",logB.currentTimeStr,logB.convertFrom,logB.convertTo);
                    }

                    /*Zerowanie flag
                     *Zerowanie buforow
                     *Przygotowanie do dalszego odczytu
                     */
                    tagReadEnded = 0;
                    tagReadStarted = 0;
                    countSigns = 0;
                    memset(numberBuffer,'\0',BUFFER_SIZE);
                    memset(tagBuffer,'\0',BUFFER_SIZE);
                    signBuff = getc(iFile);
                    continue;
                }else{
                    tagReadEnded = 0;
                    tagBuffer[countSigns] = '<';
                    countSigns++;
                    signBuff = getc(iFile);
                    continue;
                }
            }
            signBuff = getc(iFile);
            continue;
        }else{
            if(signBuff == '>'){
                tagReadStarted = 1;
            }
            signBuff = getc(iFile);
            continue;
        }
    }
    //zamkniecie plikow
    fclose(iFile);
    fclose(oFile);
}

/*Funkcja main
 *Przyjumje parametry wiersza polecen
 *Wywoluje funkcje ReadFromFile dla pierwszego argumentu cmd
 */
int main(int argc, char *argv[]) {
    ReadFromFile(argv[1]);
    return 0;
}