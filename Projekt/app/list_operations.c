#include "list_operations.h"

//OBSLUGA LISTY PRODUKTOW - FUNKCJE PODSTAWOWE
void setProductFields(ProdList** head, ProductParameters* buffer){

    (*head)->data.name = malloc(strlen(buffer->name) + 1);
    strcpy((*head)->data.name,buffer->name);

    (*head)->data.id = buffer->id;
    (*head)->data.amount = buffer->amount;
    (*head)->data.taxRate = buffer->taxRate;
    (*head)->data.nettoCost = buffer->nettoCost;
    (*head)->data.taxCost = buffer->taxCost;
    (*head)->data.bruttoCost = buffer->bruttoCost;
}
void appendProduct(ProdList** head, ProductParameters* buffer){

    if(!(*head)){

        *head = (ProdList*) malloc(sizeof(ProdList));
        (*head)-> next = NULL;
        setProductFields(&(*head),&(*buffer));

    }else{
        appendProduct(&((*head)-> next),&(*buffer));
    }
}
void writeProductFields(ProdList** head) {

    if (!(*head)) {
        return;
    } else {
        printf("| Lp: %d |", (*head)->data.id);
        printf("| Nazwa: %s |",(*head)->data.name);
        printf("| Ilosc: %d |", (*head)->data.amount);
        printf("| Stawka VAT: %d%% |", (*head)->data.taxRate);
        //liczby sa przechowywane w zmiennych typu int
        //ponizsze funkcje formatuja dane tak, zeby wyswietlala sie kwota w postaci liczby dziesietnej
        printf("| Netto/szt.:%d.%d |",(*head)->data.nettoCost/100,(*head)->data.nettoCost%100);
        printf("| Podatek/szt.:%d.%d |", (*head)->data.taxCost/100,(*head)->data.taxCost%100);
        printf("| Brutto/szt.:%d.%d |\n", (*head)->data.bruttoCost/100,(*head)->data.bruttoCost%100);

        writeProductFields(&((*head)->next));

    }
}
void freeProductFields(ProdList** head){
    free((*head)->data.name);
}
void deleteProdList(ProdList** head){

    if(!(*head)){
        return;
    }else{
        deleteProdList(&((*head)->next));
        freeProductFields(&(*head));
        (*head)->next = NULL;
        free(*head);
        *head = NULL;
    }
}

//OBSLUGA LISTY PRODUKTOW - FUNKCJE POMOCNICZE
int getLastProdId(ProdList **head){
    ProdList* headTmp = *head;

    if(!headTmp){
        return 0;
    }

    while(headTmp->next){
        headTmp = headTmp->next;
    }

    return headTmp->data.id;
}
int getNettoSum(ProdList** head){
    ProdList* headTmp = *head;
    int sum = 0;
    while(headTmp){

        //powiekszenie sumy o ilosc sztuk przemnozona przez kwote
        sum += ((headTmp->data.nettoCost) * (headTmp->data.amount));
        headTmp = headTmp->next;
    }

    return sum;
}
int getTaxSum(ProdList** head){
    ProdList* headTmp = *head;
    int sum = 0;
    while(headTmp){
        //powiekszenie sumy o ilosc sztuk przemnozona przez kwote
        sum += ((headTmp->data.taxCost) * (headTmp->data.amount));
        headTmp = headTmp->next;
    }

    return sum;
}
int getBruttoSum(ProdList** head){
    ProdList* headTmp = *head;
    int sum = 0;
    while(headTmp){
        //powiekszenie sumy o ilosc sztuk przemnozona przez kwote
        sum += ((headTmp->data.bruttoCost) * (headTmp->data.amount));
        headTmp = headTmp->next;
    }

    return sum;
}

//OBSLUGA LISTY FAKTUR - FUNKCJE PODSTAWOWE
void setInvoiceFields(InvList** head, InvoiceParameters* buffer){
    //ustawianie wartosci typow wyliczeniowych i liczbowych
    (*head)->data.paymentType = buffer->paymentType;
    (*head)->data.nettoSum = buffer->nettoSum;
    (*head)->data.vatSum = buffer->vatSum;
    (*head)->data.bruttoSum = buffer->bruttoSum;
    (*head)->data.state = buffer->state;

    //alokacja pamieci na ciagi znakow
    (*head)->data.id = malloc(strlen(buffer->id)+1);
    (*head)->data.seller.name = malloc(strlen(buffer->seller.name)+1);
    (*head)->data.seller.surename = malloc(strlen(buffer->seller.surename)+1);
    (*head)->data.seller.street = malloc(strlen(buffer->seller.street)+1);
    (*head)->data.seller.housNumber = malloc(strlen(buffer->seller.housNumber)+1);
    (*head)->data.seller.city = malloc(strlen(buffer->seller.city)+1);
    (*head)->data.seller.postCode = malloc(strlen(buffer->seller.postCode)+1);
    (*head)->data.seller.mail = malloc(strlen(buffer->seller.mail)+1);
    (*head)->data.seller.nipCode = malloc(strlen(buffer->seller.nipCode)+1);
    (*head)->data.seller.accountNumber = malloc(strlen(buffer->seller.accountNumber)+1);
    (*head)->data.buyer.name = malloc(strlen(buffer->buyer.name)+1);
    (*head)->data.buyer.surename = malloc(strlen(buffer->buyer.surename)+1);
    (*head)->data.buyer.street = malloc(strlen(buffer->buyer.street)+1);
    (*head)->data.buyer.housNumber = malloc(strlen(buffer->buyer.housNumber)+1);
    (*head)->data.buyer.city = malloc(strlen(buffer->buyer.city)+1);
    (*head)->data.buyer.postCode = malloc(strlen(buffer->buyer.postCode)+1);
    (*head)->data.buyer.mail = malloc(strlen(buffer->buyer.mail)+1);
    (*head)->data.buyer.nipCode = malloc(strlen(buffer->buyer.nipCode)+1);
    (*head)->data.buyer.accountNumber = malloc(strlen(buffer->buyer.accountNumber)+1);
    (*head)->data.issueDate = malloc(strlen(buffer->issueDate)+1);
    (*head)->data.executionDate = malloc(strlen(buffer->executionDate)+1);
    (*head)->data.deadlineDate = malloc(strlen(buffer->deadlineDate)+1);

    //ustawianie ciagow znakow
    strcpy((*head)->data.id,buffer->id);
    strcpy((*head)->data.seller.name,buffer->seller.name);
    strcpy((*head)->data.seller.surename,buffer->seller.surename);
    strcpy((*head)->data.seller.street,buffer->seller.street);
    strcpy((*head)->data.seller.housNumber,buffer->seller.housNumber);
    strcpy((*head)->data.seller.city,buffer->seller.city);
    strcpy((*head)->data.seller.postCode,buffer->seller.postCode);
    strcpy((*head)->data.seller.mail,buffer->seller.mail);
    strcpy((*head)->data.seller.nipCode,buffer->seller.nipCode);
    strcpy((*head)->data.seller.accountNumber,buffer->seller.accountNumber);
    strcpy((*head)->data.buyer.name,buffer->buyer.name);
    strcpy((*head)->data.buyer.surename,buffer->buyer.surename);
    strcpy((*head)->data.buyer.street,buffer->buyer.street);
    strcpy((*head)->data.buyer.housNumber,buffer->buyer.housNumber);
    strcpy((*head)->data.buyer.city,buffer->buyer.city);
    strcpy((*head)->data.buyer.postCode,buffer->buyer.postCode);
    strcpy((*head)->data.buyer.mail,buffer->buyer.mail);
    strcpy((*head)->data.buyer.nipCode,buffer->buyer.nipCode);
    strcpy((*head)->data.buyer.accountNumber,buffer->buyer.accountNumber);
    strcpy((*head)->data.issueDate,buffer->issueDate);
    strcpy((*head)->data.executionDate,buffer->executionDate);
    strcpy((*head)->data.deadlineDate,buffer->deadlineDate);
}
void appendInvoice(InvList** head, InvoiceParameters* buffer){

    if(!(*head)){

        *head = (InvList*) malloc(sizeof(InvList));
        (*head)->next = NULL;
        (*head)->headProducts = NULL;
        setInvoiceFields(&(*head),&(*buffer));

    }else{

        appendInvoice(&((*head)->next),&(*buffer));

    }

}
void writeSingleInvoice(InvList** head) {
    if (*head) {
        puts("__________________________________________________________________________________________");
        printf("ID: %s", (*head)->data.id);
        printf("%45s %s\n","data wystawienia:", (*head)->data.issueDate);
        puts("-------------------------------------");
        puts("SPRZEDAWCA:");
        printf("%s %s\n",(*head)->data.seller.name,(*head)->data.seller.surename);
        printf("%s %s\n",(*head)->data.seller.street,(*head)->data.seller.housNumber);
        printf("%s %s\n",(*head)->data.seller.postCode,(*head)->data.seller.city);
        printf("Mail: %s\n",(*head)->data.seller.mail);
        printf("NIP: %s\n",(*head)->data.seller.nipCode);
        printf("NR KONTA: %s\n",(*head)->data.seller.accountNumber);
        puts("-------------------------------------");
        puts("NABYWCA:");
        printf("%s %s\n",(*head)->data.buyer.name,(*head)->data.buyer.surename);
        printf("%s %s\n",(*head)->data.buyer.street,(*head)->data.buyer.housNumber);
        printf("%s %s\n",(*head)->data.buyer.postCode,(*head)->data.buyer.city);
        printf("Mail: %s\n",(*head)->data.buyer.mail);
        printf("NIP: %s\n",(*head)->data.buyer.nipCode);
        printf("NR KONTA: %s\n",(*head)->data.buyer.accountNumber);
        puts("------------------------------------");

        writeProductFields(&((*head)->headProducts));

        puts("------------------------------------");

        printf("SUMA NETTO: %d.%d | SUMA PODATKU: %d.%d | SUMA BRUTTO: %d.%d\n", (*head)->data.nettoSum/100,(*head)->data.nettoSum%100, (*head)->data.vatSum/100,(*head)->data.vatSum%100,
               (*head)->data.bruttoSum/100,(*head)->data.bruttoSum%100);

        if ((*head)->data.state == PAID) {
            puts("STATUS: oplacona");
        } else {
            puts("STATUS: nieoplacona");
        }

        if ((*head)->data.paymentType == CASH) {
            puts("PLATNOSC: gotowka");
        } else if ((*head)->data.paymentType == TRANSFER) {
            puts("PLATNOSC: przelew");
        } else if ((*head)->data.paymentType == CARD) {
            puts("PLATNOSC: karta");
        } else {
            puts("blad");
        }

        printf("Data wykonania/sprzedazy: %s | Termin platnosci: %s", (*head)->data.executionDate, (*head)->data.deadlineDate);
        puts("");
        puts("__________________________________________________________________________________________");
    }
}
void writeInvoiceFields(InvList** head) {

    if (!(*head)) {
        return;
    } else {
        writeSingleInvoice(&(*head));
        writeInvoiceFields(&((*head)->next));

    }
}
void freeInvoiceFields(InvList** head){

    free((*head)->data.id);
    free((*head)->data.seller.name);
    free((*head)->data.seller.surename);
    free((*head)->data.seller.street);
    free((*head)->data.seller.housNumber);
    free((*head)->data.seller.postCode);
    free((*head)->data.seller.city);
    free((*head)->data.seller.mail);
    free((*head)->data.seller.nipCode);
    free((*head)->data.seller.accountNumber);
    free((*head)->data.buyer.name);
    free((*head)->data.buyer.surename);
    free((*head)->data.buyer.street);
    free((*head)->data.buyer.housNumber);
    free((*head)->data.buyer.postCode);
    free((*head)->data.buyer.city);
    free((*head)->data.buyer.mail);
    free((*head)->data.buyer.nipCode);
    free((*head)->data.buyer.accountNumber);
    free((*head)->data.issueDate);
    free((*head)->data.executionDate);
    free((*head)->data.deadlineDate);
}
void deleteInvoiceList(InvList** head){

    if(!(*head)){
        return;
    }else{
        deleteInvoiceList(&((*head)->next));
        freeInvoiceFields(&(*head));
        deleteProdList(&((*head)->headProducts));
        (*head)->next = NULL;
        free(*head);
        *head = NULL;
    }
}

//OBSLUGA LISTY FAKTUR - FUNKCJE POMOCNICZE
int deleteInvById(InvList** head,char* id){

    //lista jest pusta
    if(!(*head)){
        return 0;
    }

    //lista zawieta tylko jeden element
    if(!((*head)->next)){
        if(strcmp((*head)->data.id,id) == 0){
            //usuniecie listy
            deleteInvoiceList(&(*head));
            return 1;
        }else{
            return 0;
        }

    //lista zawiera wiecej elementow
    }else {

        //pierwszy element jest przeznaczony do usuniecia
        if(strcmp((*head)->data.id,id) == 0){

            freeInvoiceFields(&(*head));
            deleteProdList(&((*head)->headProducts));
            free(*head);
            (*head) = (*head)->next;
            return 1;

        //inny niz pierwszy element jest przeznaczony do usuniecia
        }else {

            InvList *headTmp = (*head)->next; //wskaznik pomocniczy umozliwiajacy poruszanie sie po liscie
            InvList *headPrev = (*head); //wskaznik pomocniczy przechowujacy poprzedni element
            int value = 0;//wartosc zwracana - ustawiona na 0 (nie usunieto elementu)

            //przejscie listy
            while (headTmp) {

                //dany element jest przeznaczony do usuniecia
                if (strcmp(headTmp->data.id, id) == 0) {
                    value = 1;//wartosc zwrocona - 1 (usunieto element listy)

                    //przyporzadkowanie odpowiedniego elementu nastepnego elementowi poprzedniemu
                    headPrev->next = headTmp->next;
                    //usuniecie wybranego elementu
                    freeInvoiceFields(&headTmp);
                    deleteProdList(&(headTmp->headProducts));
                    headTmp->next = NULL;
                    free(headTmp);
                    headTmp = NULL;
                    return value;
                }

                headPrev = headTmp;//aktualizacja wskaznika na poprzedni element
                headTmp = headTmp->next;//aktualizacja obecnej pozycj na liscie
            }
            return value;
        }

        //


    }

}
InvList* getLastInv(InvList** head){
    InvList* headTmp = *head;
    while(headTmp->next){
        headTmp = headTmp->next;
    }
    return headTmp;
}
void setSums(InvList** head){

    InvList* invHeadTmp = getLastInv(&(*head));
    ProdList* prodHeadTmp = invHeadTmp->headProducts;
    invHeadTmp->data.nettoSum = getNettoSum(&prodHeadTmp);
    invHeadTmp->data.vatSum = getTaxSum(&prodHeadTmp);
    invHeadTmp->data.bruttoSum = getBruttoSum(&prodHeadTmp);

}
int seekByDate_MY(InvList** head, char* date){

    int value = 0;
    InvList* headTmp = *head;

    while(headTmp){
        if(CompareDates_MY(headTmp->data.issueDate,date)){
            writeSingleInvoice(&headTmp);
            value = 1;
        }
        headTmp = headTmp->next;
    }

    return value;
}
int seekByDate_Y(InvList** head, char* date){
    InvList* headTmp = *head;
    int value = 0;
    while(headTmp){
        if(CompareDates_Y(headTmp->data.issueDate,date)){
            writeSingleInvoice(&headTmp);
            value = 1;
        }
        headTmp = headTmp->next;
    }

    return value;
}
int seekById(InvList** head, char* id){

    int value = 0;
    InvList* headTmp = *head;

    while(headTmp){
        if(strcmp(headTmp->data.id,id) == 0){
            writeSingleInvoice(&headTmp);
            value = 1;
        }
        headTmp = headTmp->next;
    }

    return value;

}
int seekByDate_DMY(InvList** head, char* date){
    int value = 0;
    InvList* headTmp = *head;

    while(headTmp){
        if(strcmp(headTmp->data.issueDate,date) == 0){
            writeSingleInvoice(&headTmp);
            value = 1;
        }
        headTmp = headTmp->next;
    }

    return value;
}









