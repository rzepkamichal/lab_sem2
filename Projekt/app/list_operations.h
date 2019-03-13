#ifndef PROJV2_LIST_OPERATIONS_H
#define PROJV2_LIST_OPERATIONS_H
#include "data_structures.h"
#include "adjuvant_functions.h"

//--------------------
//FUNKCJE OBSLUGI LIST
//--------------------

//OBSLUGA LISTY PRODUKTOW - FUNKCJE PODSTAWOWE
/*Funkcja setProductFields
 *@Opis:
 * Danemu elementowi listy produktow ustawia parametry
 * kopiujac zawartosc przekazanego jako parametr bufora
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na element listy produktow
 * -ProductParameters* buffer - wskaznik na bufor przechowujacy parametry produktu
 *@Zwraca:
 * - void
*/
void setProductFields(ProdList** head, ProductParameters* buffer);
/*Funkcja appendProduct
 *@Opis:
 * Dodaje nowy produkt na koniec listy produktow.
 * Wywoluje funkcje serProductFields w celu ustawienia wartosci produktu
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 * -ProductParameters* buffer - wskaznik na bufor przechowujacy parametry produktu
 *@Zwraca:
 * - void
*/
void appendProduct(ProdList** head, ProductParameters* buffer);
/*Funkcja writeProductFields
 *@Opis:
 * Wypisuje na wyjscie standardowe sformatowane dane kazdego elementu
 * na otrzymanej liscie produktow poczawszy od pierwszego elementu.
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void writeProductFields(ProdList** head);
/*Funkcja freeProductFields
 *@Opis:
 * Zwalnia pamiec zaalokowana na dane produktu
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na element listy produktow
 *@Zwraca:
 * - void
*/
void freeProductFields(ProdList** head);
/*Funkcja deleteProdList
 *@Opis:
 * Usuwa liste produktow zwalniajac pamiec.
 * Wywoluje funkcje freeProductFields w celu zwolniena pamieci danych produktu.
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void deleteProdList(ProdList** head);

//OBSLUGA LISTY PRODUKTOW - FUNKCJE POMOCNICZE
/*Funkcja getLastProdId
 *@Opis:
 * Odczytuje ID ostatniego elementu na liscie produktow
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - wartosc calkowita:
 *  - ID ostatniego elementu na liscie
*/
int getLastProdId(ProdList **head);
/*Funkcje getNettoSum, getTaxSum, getBruttoSum
 *@Opis:
 * Funkcje dzialaja podobnie. Sumuja wartosci przechowywane
 * na liscie produktow pomnozone przez ilosc produktow,
 * odpowiednio: wartosc netto, podatek, brutto
 *@Parametry:
 * -ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - wartosc calkowita:
 *  - suma netto calej listy produktow dla getNettoSum
 *  - suma podatku calej listy produktow dla getTaxsum
 *  - suma brutto calej listy produktow dla getBruttoSum
*/
int getNettoSum(ProdList** head);
int getTaxSum(ProdList** head);
int getBruttoSum(ProdList** head);

//OBSLUGA LISTY FAKTUR - FUNKCJE PODSTAWOWE
/*Funkcja setInvoiceields
 *@Opis:
 * Danemu elementowi listy faktur ustawia parametry
 * kopiujac zawartosc przekazanego jako parametr bufora
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na element listy faktur
 * -InvoiceParameters* buffer - wskaznik na bufor przechowujacy parametry faktury
 *@Zwraca:
 * - void
*/
void setInvoiceFields(InvList** head, InvoiceParameters *buffer);
/*Funkcja setInvoiceields
 *@Opis:
 * Dodaje na koniec listy faktur nowy element, ktorego dane
 * sa ustawiane poprzez skopiowanie danych z przekazanego bufora parametrow faktury.
 * Funkcja wywoluje funkcje setInvoiceFields w celu skopiowania zawartosci bufora.
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 * -InvoiceParameters* buffer - wskaznik na bufor przechowujacy parametry faktury
 *@Zwraca:
 * - void
*/
void appendInvoice(InvList** head, InvoiceParameters* buffer);
/*Funkcja writeSingleInvoice
 *@Opis:
 * Funkcja wypisuje na standardowe wejscie sformatowane dane
 * otrzymanego elementu listy.
 * Wywoluje funkcje writeProductFields w celu wypisania
 * listy produktow podpietej do danego elementu listy faktur
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na element listy faktur
 *@Zwraca:
 * - void
*/
void writeSingleInvoice(InvList** head);
/*Funkcja writeInvoiceFields
 *@Opis:
 * Wypisuje na standardowe wyjscie sformatowane dane
 * wszystkich elementow otrzymanej listy faktur.
 * Wywoluje funkcje writeSingleInvoice w celu
 * wypisania danych pojedynczego elementu listy.
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 *@Zwraca:
 * - void
*/
void writeInvoiceFields(InvList** head);
/*Funkcja freeInvoiceFields
 *@Opis:
 * Zwalnia pamiec zaalokowana na przechowanie danych
 * elementu listy faktur
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na element listy faktur
 *@Zwraca:
 * - void
*/
void freeInvoiceFields(InvList** head);
/*Funkcja deleteInvoiceList
 *@Opis:
 * Usuwa liste faktur zwalniajac wykorzystana pamiec.
 * Wywoluje funkcje freeInvoiceFields w celu usuniecia danych
 * poszczegolnych elementow oraz funkcje deleteProdList
 * w celu usuniecia podwieszonej listy produktow.
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 *@Zwraca:
 * - void
*/
void deleteInvoiceList(InvList** head);

//OBSLUGA LISTY FAKTUR - FUNKCJE POMOCNICZE
/*Funkcja deleteInvById
 *@Opis:
 * Usuwa element listy faktur o numerze id takim, jak przekazany przez parametr.
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 * -char* id- lancuch znakow reprezentujacy id faktury, ktora ma byc usunieta
 *@Zwraca:
 * - wartosc calkowita:
 *  1 - jesli uda sie usunac element
 *  0 - jesli lista jest pusta lub nie ma na niej elementu o okreslonym id
*/
int deleteInvById(InvList** head,char* id);
/*Funkcja getLastInv
 *@Opis:
 * Zwraca wskaznik na ostatni element listy faktur
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 *@Zwraca:
 * - InvList* - wskaznik na ostatni element listy
*/
InvList* getLastInv(InvList** head);
/*Funkcja setSums
 *@Opis:
 * Sumuje kwoty na liscie produktow dla ostatniego elementu listy faktur.
 * Ustawia wartosc dla odpowiednich skladowych przechowujacych sumy.
 * W celu sumowania wartosci wywolane sa funkcje getNettoSum, getTaxSum, getBruttoSum
 * oraz funkcja getLastInv w celu znalezienia ostatniego elementu listy faktur.
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 *@Zwraca:
 * - void
*/
void setSums(InvList** head);
/*Funkcje seekByDate_MY, seekByDate_Y, seekByDate_DMY, seekById
 *@Opis:
 * Funkcje dzialaja podobnie. Wyszukuja na liscie faktur elementy wedlug
 * zadanych kryteriow i wyswietlaja dane znalezionych faktur na wyjscie standardowe.
 * -seekByDate_DMY - wyszukuje faktury z dana data
 * -seekByDate_MY - wyszukuje faktury z danego miesiaca
 * -seekByDate_Y - wyszukuje faktury z danego roku
 * -seekByID - wyszukuje fakture z danym id
 * Wykorzystywane sa funkcje porownujace odpowiednie formaty dat oraz funkcja wypisujaca element listy faktur.
 *@Parametry:
 * -InvList** head - wskaznik na wskaznik na poczatek listy faktur
 * -char *date - wskaznik na ciag znakow reprezentujacy date w odpowiednim formacie
 * -char *id - wskaznik na ciag znakow reprezentujacy id faktury
 *@Zwraca:
 * - wartosc calkowita
 *  1 - jezeli zostanie wyszukany co najmniej jeden element
 *  0 - w przeciwnym przypadku
*/
int seekByDate_MY(InvList** head, char* date);
int seekByDate_Y(InvList** head, char* date);
int seekById(InvList** head, char* id);
int seekByDate_DMY(InvList** head, char* date);

#endif
