#include "menu_handler.h"

//Wyswietlanie komunikatow ogolnych
void writeErrMessage(){
    puts("_________________________________________________________");
    puts("Bledne dane wejsciowe! Prosze sprobowac ponownie.");
    puts("_________________________________________________________");
}
void writeMainMenuText(){
    puts("_________________________________________________________");
    puts("MENU:");
    puts("1 - Dodaj nowa fakture");
    puts("2 - Wyszukaj fakture");
    puts("3 - Usun fakture");
    puts("4 - Wyswietl wszystkie faktury");
    puts("5 - Nadpisz baze faktur i zakoncz");
    puts("6 - Zakoncz bez zapisywania");
    puts("_________________________________________________________");
}
void writeWelcomeMessagePositive(){
    puts("_________________________________________________________");
    puts("Wczytano baze faktur.");
    puts("Prosze wybrac jedna z ponizszych opcji.");
}
void writeWelcomeMessageNegative(){
    puts("_________________________________________________________");
    puts("Nie odczytano bazy faktur. Baza jest pusta lub zawiera bledne dane.");
    puts("Prosze wybrac jedna z ponizszych opcji.");
}

//Wyswietlanie komunikatow zwiazanych z dodawaniem nowej faktury
void writeSellerInputInstrucions(InvParName param){

    switch(param){
        case SName:
            puts("Sprzedawca - Imie:");
            break;
        case SSurename:
            puts("Sprzedawca - Nazwisko:");
            break;
        case SStreet:
            puts("Sprzedawca - Nazwa ulicy:");
            break;
        case SHouse:
            puts("Sprzedawca - Nr domu:");
            break;
        case SCity:
            puts("Sprzedawca - Miasto:");
            break;
        case SCode:
            puts("Sprzedawca - Kod pocztowy:");
            break;
        case SMail:
            puts("Sprzedawca - Mail");
            break;
        case SNip:
            puts("Sprzedawca - NIP:");
            break;
        case SAccount:
            puts("Sprzedawca - Nr konta:");
            break;
        default: break;
    }
}
void writeBuyerInputInstructions(InvParName param){
    switch(param){
        case BName:
            puts("Kupujacy - Imie:");
            break;
        case BSurename:
            puts("Kupujacy - Nazwisko:");
            break;
        case BStreet:
            puts("Kupujacy - Nazwa ulicy:");
            break;
        case BHouse:
            puts("Kupujacy - Nr domu:");
            break;
        case BCity:
            puts("Kupujacy - Miasto:");
            break;
        case BCode:
            puts("Kupujacy - Kod pocztowy:");
            break;
        case BMail:
            puts("Kupujacy - Mail");
            break;
        case BNip:
            puts("Kupujacy - NIP:");
            break;
        case BAccount:
            puts("Kupujacy - Nr konta:");
            break;
        default: break;
    }
}
void writeRemainingInputInstructions(InvParName param){
    switch(param){
        case PType:
            puts("Rodzaj platnosci: (karta/gotowka/przelew)");
            break;
        case State:
            puts("Status oplacenia faktury: (tak/nie)");
            break;
        case ExecutionDate:
            puts("Data sprzedazy/wykonania: (DD.MM.RRRR)");
            break;
        case DeadlineDate:
            puts("Termin platnosci:(DD.MM.RRRR)");
            break;
        default: break;
    }
}
void writeInstructions(InvParName param){

    if(param >= SName && param <= SAccount){
        writeSellerInputInstrucions(param);
    }else if(param >= BName && param <= BAccount){
        writeBuyerInputInstructions(param);
    }else{
        writeRemainingInputInstructions(param);
    }
}
void writeProductInputInstructions(ProdParName param){

    switch(param){
        case Name:
            puts("Nazwa produktu:");
            break;
        case Amount:
            puts("Ilosc:");
            break;
        case ProdNetto:
            puts("Cena Netto/szt.:");
            break;
        case ProdTaxRate:
            puts("Stawka podatku [w %]:");
            break;
        default: break;
    }
}

//Wyswietlanie komunikatow zwiazanych szukaniem faktur
void writeSeekInstructions(){

    puts("_________________________________________________________");
    puts("OPCJE WYSZUKIWANIA:");
    puts("1 - Wyszukiwanie po ID");
    puts("2 - Faktury z danego dnia");
    puts("3 - Faktury z danego miesiaca");
    puts("4 - Faktury z danego roku");
    puts("5 - Powrot do menu glownego");
    puts("_________________________________________________________");
}
void writeNoResults(){
    puts("_________________________________________________________");
    puts("Brak wynikow wyszukiwania.");
    puts("_________________________________________________________");
}

//Wyswietlanie komunikatow zwiazanych z usuwaniem faktur
void writeDeleteMessage(){
    puts("_________________________________________________________");
    puts("NARZEDZIE USUWANIA FAKTUR");
    puts("1 - wprowadzanie ID faktury do usuniecia");
    puts("2 - powrot do menu glownego");
    puts("_________________________________________________________");
}

//Realizacja sub-menu dodawania nowej faktury
void productInputHandler(ProdList** head){

    char* buffer = malloc(MAX_INPUT_LENGTH); //bufor na dane z stdin
    ProductParameters prodBuff;//bufor na parametry produktu
    int calculate = 1;//licznik petli

    //petla pobierajaca dane
    while(calculate < PROD_PARAM_AMOUNT -2){
        //wypisanie instrukcji
        writeProductInputInstructions((ProdParName) calculate);

        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        //dane poprawne
        if(checkProductInput(buffer,(ProdParName)calculate)){
            //ustawienie skladowej bufora
            setProdBuffFromConsole(&prodBuff,(ProdParName)calculate,buffer);
            calculate++;
        //dane niepoprawne
        }else{
            writeErrMessage();
            continue;
        }

    }
    //generowanie liczby porzadkowej produktu
    prodBuff.id = getLastProdId(&(*head)) + 1;
    //wyznaczenie kwoty podatku
    prodBuff.taxCost = (int)( ((float)prodBuff.taxRate)/100.00*(float)prodBuff.nettoCost);
    //wyznaczenie kwoty brutto
    prodBuff.bruttoCost = prodBuff.nettoCost + prodBuff.taxCost;

    //dodanie produktu na koniec listy
    appendProduct(&(*head),&prodBuff);
    //zwolnienie bufora produktow
    freeProductBuffer(&prodBuff);

    free(buffer);
}
int handleMenuAfterAdding(){

    char* buffer = malloc(MAX_INPUT_LENGTH);
    puts("Dodano produkt.");

    while(1) {
        puts("1 - Dodaj kolejny produkt");
        puts("2 - Zapisz i wroc");
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");
        if (checkMenuInput(buffer, 2, 1)) {
            if (atoi(buffer) == 1) {
                free(buffer);
                return 1;
            }
            else {
                free(buffer);
                return 0;
            }
        } else{
            writeErrMessage();
            continue;
        }
    }


}
void invoiceInputHandler(InvList** head){

    char* buffer = malloc(MAX_INPUT_LENGTH);;//bufor na dane z stdin
    InvoiceParameters invBuff;//bufor na parametry faktury
    int calculate = 1;//licznik petli
    int addProdFlag = 1;//flaga informujaca czy dodawany jest produkt

        //generowanie aktualnej daty
        char dateBuffer[DATE_BUFFER_LEN];
        time_t now;
        struct tm ts;
        time(&now);
        ts = *localtime(&now);
        strftime(dateBuffer, sizeof(dateBuffer), "%d.%m.%Y", &ts);

        //generowanie ID faktury na podstawie aktualnego czasu
        char idBuffer[INV_ID_LEN];
        time(&now);
        ts = *localtime(&now);
        strftime(idBuffer, sizeof(idBuffer), "%d%m%y%H%M%S", &ts);


    puts("Dodawanie faktury");
    //petla pobierajaca dane
    while(calculate < INV_PARAM_AMOUNT + 1){

        //ignorowanie parametrow, ktore zostana obliczone/wygenerowane przez program
        if((InvParName) calculate >= Netto && (InvParName) calculate <= IssueDate && (InvParName) calculate != State){
            calculate++;
            continue;

        }else{
            writeInstructions((InvParName) calculate);
            fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
            strtok(buffer,"\n");

            //dane wejsciowe poprawne
            if(checkConsoleInput(buffer,(InvParName) calculate)){

                //ustawienie odpowiedniej skladowej bufora faktury
                setInvBuffParams(&invBuff,(InvParName) calculate,buffer,NULL);
                calculate++;
                continue;
            //dane wejsciowe niepoprawne
            }else{
                writeErrMessage();
                continue;
            }
        }
    }


    //ustawienie pozostalych skladowych bufora faktur
    invBuff.id = malloc(strlen(idBuffer) +1 );
    strcpy(invBuff.id,idBuffer);
    invBuff.issueDate = malloc(strlen(dateBuffer) + 1);
    strcpy(invBuff.issueDate,dateBuffer);
    invBuff.nettoSum = 0;//poczatkowa inicjalizacja 0
    invBuff.vatSum = 0;// -"-
    invBuff.bruttoSum = 0;// -"-

    //dodanie faktury
    appendInvoice(&(*head), &invBuff);
    //zwolnienie bufora faktur
    freeInvoiceBuffer(&invBuff);

    //dodawanie produktow
    puts("Ddawanie produktu");
    while(addProdFlag){
        productInputHandler(&(getLastInv(&(*head))->headProducts));
        //krotkie menu po dodaniu produktu
        addProdFlag = handleMenuAfterAdding();
    }

    //ustawienie sum kwot na fakturze inicjalizowanych wczesniej jako 0
    setSums(&(*head));
    puts("Dodano fakutre");
    free(buffer);



}

//Realizacja sub-menu wyszukiwania faktur
void seekIdHandler(InvList** head){

    char* buffer = malloc(MAX_INPUT_LENGTH);
    while(1){
        puts("ID szukanej faktury:");
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        if(isNatural(buffer)){
            if(seekById(&(*head),buffer)){
                break;
            }else{
                writeNoResults();
            }
            break;
        }else{
            writeErrMessage();
        }
    }

    free(buffer);
}
void seekDateDMYHandler(InvList** head){
    char* buffer = malloc(MAX_INPUT_LENGTH);

    while(1){
        puts("Data wystawienia faktury (DD.MM.RRRR):");
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        if(checkDate_DMY(buffer)){
            if(seekByDate_DMY(&(*head),buffer)){
                break;
            }else{
                writeNoResults();
            }
            break;
        }else{
            writeErrMessage();
        }
    }

    free(buffer);
}
void seekDateMYHandler(InvList** head){
    char* buffer = malloc(MAX_INPUT_LENGTH);

    while(1){
        puts("Miesiac i rok wystawienia faktury (MM.RRRR):");
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        if(checkDate_MY(buffer)){
            if(seekByDate_MY(&(*head),buffer)){
                break;
            }else{
                writeNoResults();
            }
            break;
        }else{
            writeErrMessage();
        }
    }

    free(buffer);
}
void seekDateYHandler(InvList** head){
    char* buffer = malloc(MAX_INPUT_LENGTH);

    while(1){
        puts("Rok wystawienia faktury (RRRR):");
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        if(checkDate_Y(buffer)){
            if(seekByDate_Y(&(*head),buffer)){
                break;
            }else{
                writeNoResults();
            }
            break;
        }else{
            writeErrMessage();
        }
    }

    free(buffer);
}
void seekInvoiceHandler(InvList** head){

    unsigned char stayInMenu = 1;
    char* buffer = malloc(MAX_INPUT_LENGTH);

    while(stayInMenu){
        writeSeekInstructions();
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");
        int number = checkMenuInput(buffer, 5, 1);

        if(number){
            switch(number){
                case 1:
                    seekIdHandler(&(*head));
                    break;
                case 2:
                    seekDateDMYHandler(&(*head));
                    break;
                case 3:
                    seekDateMYHandler(&(*head));
                    break;
                case 4:
                    seekDateYHandler(&(*head));
                    break;
                case 5:
                    stayInMenu = 0;
                    break;
                default:
                    stayInMenu = 0;
                    break;
            }
        }else{
            writeErrMessage();
        }

    }
    free(buffer);
}

//Realizacja sub-menu usuwania faktur
void deletingHandler(InvList** head){

    char* buffer = malloc(MAX_INPUT_LENGTH);
    unsigned char stayInMenu = 1;

    while(stayInMenu){
        puts("Prosze podac ID faktury do usuniecia");
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        if(isNatural(buffer)){
            if(deleteInvById(&(*head),buffer)){
                puts("_________________________________________________________");
                puts("Usunieto wybrana fakture");
                puts("_________________________________________________________");
                stayInMenu = 0;
            }else {
                writeNoResults();
                stayInMenu = 0;
            }
        }else{
            writeErrMessage();
            stayInMenu = 0;
        }

    }
    free(buffer);

}
void deletingMenu(InvList** head){

    char* buffer = malloc(MAX_INPUT_LENGTH);
    unsigned char stayInMenu = 1;

    while(stayInMenu) {
        writeDeleteMessage();
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");
        int numericValue = checkMenuInput(buffer, 2, 1);
        if(numericValue){
            switch(numericValue){
                case 1:
                    deletingHandler(&(*head));
                    break;
                case 2:
                    stayInMenu = 0;
                    break;
                default:
                    stayInMenu = 0;
                    break;
            }
        }else{
            writeErrMessage();
        }
    }

    free(buffer);

}

//Realizacja menu glownego
void startMainMenu(InvList** head,char* filePath){

    //odczytano baze
    if(ReadDataBase(filePath,&(*head))){
        writeWelcomeMessagePositive();
    //nie odczytano bazy
    }else{
        writeWelcomeMessageNegative();
    }

    unsigned short stayInMenu = 1;//flaga informujaca, czy nalezy pozostac w menu, czy tez zakonczyc program
    char* buffer = malloc(MAX_INPUT_LENGTH);//bufor na wejsci stdin (opcja menu)

    //petla pobierajaca dane
    while(stayInMenu) {
        writeMainMenuText();
        fgets(buffer,MAX_INPUT_LENGTH-1,stdin);
        strtok(buffer,"\n");

        //odczytanie i sprawdzenie wprowadzonej danej
        int number = checkMenuInput(buffer, 6, 1);

        //dana poprawna
        if (number) {
            switch(number){
                case 1:
                    //dodawanie faktury
                    invoiceInputHandler(&(*head));
                    break;
                case 2:
                    //wyszukiwanie faktury
                    seekInvoiceHandler(&(*head));
                    break;
                case 3:
                    //usuwanie faktury
                    deletingMenu(&(*head));
                    break;
                case 4:
                    //wyswietlanie bazy faktur
                    if(!(*head)){
                        writeNoResults();
                    }else {
                        writeInvoiceFields(&(*head));
                    }
                    break;
                case 5:
                    //zapisanie bazy i wyjscie
                    SaveDataBase(filePath,&(*head));
                    stayInMenu = 0;
                    break;
                case 6:
                    //wyjscie
                    stayInMenu = 0;
                    break;
                default:
                    stayInMenu = 0;
                    break;
            }
        //dana bledna
        } else {
            writeErrMessage();
        }
    }
    //zwolnienie bufora na dane
    free(buffer);
}












