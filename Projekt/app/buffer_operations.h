#ifndef PROJV2_BUFFER_OPERATIONS_H
#define PROJV2_BUFFER_OPERATIONS_H
#include "data_structures.h"

//----------------------------------------
//FUNKCJE OBSLUGI BUFOROW NA SKLADOWE LIST
//----------------------------------------

//Funkcje obslugi bufora danych listy faktur
/*Funkcje setInvoiceParameters, setSellerParameters, setBuyerParameters
 *@Opis:
 * Funkcje dzialaja podobnie. Interpretuja otrzymany ciag znakow.
 * W zaleznosci od parametru invPar skojarzonego
 * z konkretna skladowa elementu listy faktur
 * ustawiaja wartosc okreslonego pola bufora parametrow faktury (ewentualnie konwertujac na inny typ).
 * - funkcje setSellerParameters oraz setBuyerParameters ustawiaja odpowiednie
 *   dane personalne (odpowiednio sprzedawcy oraz nabywcy)
 * - funkcja setInvoiceParameters ustawia pozostale skladowe faktury
 *@Parametry:
 * -InvoiceParameters* buff- wskaznik na bufor parametrow faktury, do ktoreg zapisywane sa odczytane dane
 * -char* data - wskaznik na interpretowany ciag znakow
 * -InvParName invPar - parametr (enum), z ktorym skojarzona jest konkretna skladowa faktury
 *@Zwraca:
 * - void
*/
void setInvoiceParameters(InvoiceParameters* buff,char* data,InvParName invPar);
void setSellerParameters(InvoiceParameters* buff,char* data,InvParName invPar);
void setBuyerParameters(InvoiceParameters* buff,char* data,InvParName invPar);
/*Funkcja setInvBuffParams
 *@Opis:
 * Funkcja wywoluje funkcje setInvoiceParameters, setSellerParameters, setBuyerParameters
 * w celu ustawienia danych bufora parametrow faktury.
 * Funkcja interpretuje parametr invPar i w zaleznosci od niego wywoluje jedna z powyzszych funkcji.
 *@Parametry:
 * -InvoiceParameters* buff- wskaznik na bufor parametrow faktury, do ktoreg zapisywane sa odczytane dane
 * -InvParName invPar - parametr (enum), z ktorym skojarzona jest konkretna skladowa faktury
 * -char* data - wskaznik na interpretowany ciag znakow
 * -void (*setData)(InvoiceParameters *, char *, InvParName) - wskaznik na funkcje (jedna z trzech wymienionych)
 *                                                             domyslnie przekazuje sie NULL, dopiero w czasie
 *                                                             wykonywania funkcji wartosc wskaznika jest ustawiana
 *@Zwraca:
 * - void
*/
void setInvBuffParams(InvoiceParameters *buff, InvParName invPar, char *data, void (*setData)(InvoiceParameters *, char *, InvParName));
/*Funkcja freeInvoiceBuffer
 *@Opis:
 * Funkcja zwalnia pamiec zaalokowana na skadowe przekazanego bufora parametrow faktury.
 *@Parametry:
 * -InvoiceParameters* buff- wskaznik na bufor parametrow faktury
 *@Zwraca:
 * - void
*/
void freeInvoiceBuffer(InvoiceParameters* buff);

//Funkcje obslugi bufora danych listy produktow
/*Funkcje setProdBuffParams, setProdBuffFromConsole
 *@Opis:
 * Funkcje dzialaja podobnie. Interpretuja otrzymany ciag znakow.
 * W zaleznosci od parametru prodPar skojarzonego
 * z konkretna dana charakteryzujaca element listy produktow
 * ustawiaja wartosc okreslonej skladowej listy (ewentualnie konwerujac na inny typ).
 * - funkcja setProdBuffParams interpretuje dane czytane z pliku
 * - funkcja setProdBuffFromConsole interpretuje dane czytane z konsoli
 *@Parametry:
 * -ProductParameters* buff- wskaznik na bufor parametrow produktu, do ktoreg zapisywane sa odczytane dane
 * -char* data - wskaznik na interpretowany ciag znakow
 * -InvProdName prodPar - parametr (enum), z ktorym skojarzona jest konkretna skladowa produktu
 *@Zwraca:
 * - void
*/
void setProdBuffParams(ProductParameters* buff, ProdParName prodPar, char *data);
void setProdBuffFromConsole(ProductParameters* buff, ProdParName prodPar, char *data);
/*Funkcja freeProductBuffer
 *@Opis:
 * Funkcja zwalnia pamiec zaalokowana na skadowe przekazanego bufora parametrow produktu.
 *@Parametry:
 * -ProductParameters* buff- wskaznik na bufor parametrow produktu
 *@Zwraca:
 * - void
*/
void freeProductBuffer(ProductParameters* buff);
#endif
