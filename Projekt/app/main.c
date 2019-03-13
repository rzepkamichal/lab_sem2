#include "data_structures.h"
#include "list_operations.h"
#include "menu_handler.h"

/*Funkcja main
 *@Opis:
 *  Funkcja realizuje program wywolujac funkcje menu glownego oraz
 *  zwalniajac pamiec po zakonczeniu pracy menu.
 *@Parametry:
 * - int argc - liczba argumentow wiersza polecen
 * - char* argv[] - argumenty wiersza polecen (pierwszy argument to wg oczekiwan sciezka
 *                  do pliku csv zawierajacego baze faktur)
 *@Zwraca:
 * - wartosc calkowita 0
 */
int main(int argc, char* argv[]) {

    InvList* head = NULL;
    startMainMenu(&head,argv[1]);
    deleteInvoiceList(&head);

    return 0;
}

