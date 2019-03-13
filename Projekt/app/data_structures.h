#ifndef PROJV2_DATA_STRUCTURES_H
#define PROJV2_DATA_STRUCTURES_H
#include <malloc.h>
#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>

//-----------------
//DEFINICJE STALYCH
//-----------------

//ilosc parametrow faktury
#define INV_PARAM_AMOUNT 26
//ilosc parametrow produktow
#define PROD_PARAM_AMOUNT 7
//dlugosc bufora na date w formacie "dd.mm.rrrr"
#define DATE_BUFFER_LEN 11
//dlugosc bufora na generowane id faktury (na podstawie aktualnej daty i godziny)
#define INV_ID_LEN 15
//minimalny rok w dacie
#define MIN_YEAR 1950
//maksymalny rok w dacie
#define MAX_YEAR 2050
//dlugosc bufora na dane wprowadzane z wejscia standardowego
#define MAX_INPUT_LENGTH 100

//--------------------------------------------------
//DEFINICJE NAZW DLA TYPOW WYLICZENIOWYCH I STRUKTUR
//--------------------------------------------------

typedef enum PAYMENT_TYPE PayType;
typedef enum PAYMENT_STATE PayState;
typedef enum INV_PARAMETER_NAME InvParName;
typedef enum PROD_PARAMETER_NAME ProdParName;

typedef struct INVOICE InvoiceParameters;
typedef struct PERSONAL_DATA PersonalData;
typedef struct PRODUCT ProductParameters;
typedef struct PRODUCT_LIST ProdList;
typedef struct INVOICE_LIST InvList;

//------------------------------
//DEFINICJE TYPOW WYLICZENIOWYCH
//------------------------------

/*enum PAYMENT_TYPE
 * Wyliczenie reprezentujace sposob zaplaty
 */
enum PAYMENT_TYPE{
    TRANSFER,//Przelew
    CASH,//Gotowka
    CARD//Karta
};
/*enum PAYMENT_STATE
 * wyliczenie prezentujace stan faktury (nieoplacona/oplacona)
 */
enum PAYMENT_STATE{
    NPAID, //Niepolacona
    PAID //Oplacona
};
/*enum INV_PARAMETER_NAME
 * Wyliczenie reprezentujace poszczegolne skladowe faktury.
 * Ma zastosowanie w dodawaniu nowych elementow do list.
 * Przekazuje funkcjom informacje, ktora skladowa faktury
 * zostala wlasnie wprowadzona/odczytana z pliku
 * i jak w zwiazku z tym nalezy ja zinterpretowac i przyporzadkowac.
 */
enum INV_PARAMETER_NAME
{   InvId, //Id faktury
    SName, //Imie sprzedawcy
    SSurename, //Nazwisko sprzedawcy
    SStreet, //Ulica sprzedawcy
    SHouse, //Nr domu sprzedawcy
    SCity, //Miasto sprzedawcy
    SCode, //Kod pocztowy sprzedawcy
    SMail, //Adres e-mail sprzedawcy
    SNip, //NIP sprzedawcy
    SAccount, //Nr konta sprzedawcy
    BName, //Imie nabywcy
    BSurename, //Nazwisko nabywcy
    BStreet, //Ulica nabywcy
    BHouse, //Nr domu nabywcy
    BCity, //Miasto nabywcy
    BCode, //Kod pocztowy nabywcy
    BMail, //Adres e-mail nabywcy
    BNip, //NIP nabywcy
    BAccount, //Nr konta nabywcy
    PType, //Rodzaj platnosci
    Netto, //Suma netto
    Tax, //Suma podatku
    Brutto, //Suma brutto
    State, //Stan faktury
    IssueDate, //Data wystawienia
    ExecutionDate, //Data wykonania/sprzedazy
    DeadlineDate //Termin platnosci
};
/*enum PROD_PARAMETER_NAME
 * Wyliczenie reprezentujace poszczegolne parametry produktu.
 * Ma zastosowanie w dodawaniu nowych elementow do list.
 * Przekazuje funkcjom informacje, ktora skladowa produktu
 * zostala wlasnie wprowadzona/odczytana z pliku
 * i jak w zwiazku z tym nalezy ja zinterpretowac i przyporzadkowac.
 */
enum PROD_PARAMETER_NAME
{
    ProdId, //Liczba porzadkowa
    Name, //Nazwa
    Amount, //Ilosc
    ProdTaxRate, //Stawka podatku
    ProdNetto, //Kwota netto/szt.
    ProdTax, //Podatek/szt.
    ProdBrutto //Kwota brutto/szt.
};

//------------------
//DEFINICJE STRUKTUR
//------------------

/*struct PERSONAL_DATA
 * Struktura reprezentujaca dane osobowe (sprzedawcy lub nabywcy)
 */
struct PERSONAL_DATA{

    char* name; //Imie
    char* surename; //Nazwisko
    char* street; //Ulica
    char* housNumber; //Nr domu
    char* city; //Miasto
    char* postCode; //Kod pocztowy
    char* mail; //Adres e-mail
    char* nipCode; //NIP
    char* accountNumber; //Nr Konta

};
/*struct PRODUCT
 * Struktura reprezentujaca produkt
 */
struct PRODUCT{
    int id; //Liczba porzadkowa
    char* name; //Nazwa
    int amount; //Ilosc
    int taxRate; //Stawka podatku
    int nettoCost; //Kwota netto/szt.
    int taxCost; //Podatek/szt.
    int bruttoCost; //Kwota brutto/szt.
};
/*struct INVOICE
 * Struktura reprezentujaca fakture
 */
struct INVOICE{
    char* id; //Nr faktury
    PersonalData seller; //Dane sprzedawcy
    PersonalData buyer; //Dane nabywcy
    PayType paymentType; //Rodzaj platnosci

    int nettoSum; //Suma netto
    int vatSum; //Suma podatku
    int bruttoSum; //Suma brutto
    PayState state; //Stan faktury

    char* issueDate; //Data wystawienia
    char* executionDate; //Data wykonania/sprzedazy
    char* deadlineDate; //Termin platnosci
};

/*struct PRODUCT_LIST
 * Struktura reprezentujaca element listy produktow.
 */
struct PRODUCT_LIST{
    ProductParameters data; //Dane produktu
    ProdList *next; //Wskaznik na nastepny element
};

/*strutc INVOICE_LIST
 * Struktura reprezentujaca element listy faktur.
 */
struct INVOICE_LIST{
    InvoiceParameters data; //Dane produktu
    ProdList *headProducts; //Wskaznik na podwieszona liste produktow
    InvList *next; //Wskaznik na nastepny element
};

#endif
