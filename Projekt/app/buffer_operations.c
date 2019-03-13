#include "buffer_operations.h"

//Funkcje obslugi bufora danych listy faktur
void setInvoiceParameters(InvoiceParameters* buff,char* data,InvParName invPar){

    switch(invPar){
        case InvId:
            buff->id = malloc (strlen(data) + 1);
            strcpy(buff->id, data);
            break;
        case PType:
            if (strcmp("gotowka",data) == 0){
                buff->paymentType = CASH;
            }else if (strcmp("karta",data) == 0){
                buff->paymentType = CARD;
            }else if(strcmp("przelew",data) == 0){
                buff->paymentType = TRANSFER;
            }
            break;
        case Netto:
            buff->nettoSum =  atoi(data);
            break;
        case Tax:
            buff->vatSum = atoi(data);
            break;
        case Brutto:
            buff->bruttoSum = atoi(data);
            break;
        case State:
            if(strcmp("tak",data) == 0){
                buff->state = PAID;
            }else if(strcmp("nie",data) == 0){
                buff->state = NPAID;
            }
            break;
        case IssueDate:
            buff->issueDate = malloc (strlen(data) + 1);
            strcpy(buff->issueDate, data);
            break;
        case ExecutionDate:
            buff->executionDate = malloc (strlen(data) + 1);
            strcpy(buff->executionDate, data);
            break;
        case DeadlineDate:
            buff->deadlineDate = malloc (strlen(data) + 1);
            strcpy(buff->deadlineDate, data);
            break;
        default:
            break;
    }

}
void setSellerParameters(InvoiceParameters* buff,char* data,InvParName invPar){

    switch(invPar){
        case SName:
            buff->seller.name = malloc(strlen(data) + 1);
            strcpy(buff->seller.name,data);
            break;
        case SSurename:
            buff->seller.surename = malloc(strlen(data) + 1);
            strcpy(buff->seller.surename,data);
            break;
        case SStreet:
            buff->seller.street = malloc(strlen(data) + 1);
            strcpy(buff->seller.street,data);
            break;
        case SHouse:
            buff->seller.housNumber = malloc(strlen(data) + 1);
            strcpy(buff->seller.housNumber,data);
            break;
        case SCity:
            buff->seller.city = malloc(strlen(data) + 1);
            strcpy(buff->seller.city,data);
            break;
        case SCode:
            buff->seller.postCode = malloc(strlen(data) + 1);
            strcpy(buff->seller.postCode,data);
            break;
        case SMail:
            buff->seller.mail = malloc(strlen(data) + 1);
            strcpy(buff->seller.mail,data);
            break;
        case SNip:
            buff->seller.nipCode = malloc(strlen(data) + 1);
            strcpy(buff->seller.nipCode,data);
            break;
        case SAccount:
            buff->seller.accountNumber = malloc(strlen(data) + 1);
            strcpy(buff->seller.accountNumber,data);
            break;
        default: break;
    }
}
void setBuyerParameters(InvoiceParameters* buff,char* data,InvParName invPar){

    switch(invPar) {
        case BName:
            buff->buyer.name = malloc(strlen(data) + 1);
            strcpy(buff->buyer.name, data);
            break;
        case BSurename:
            buff->buyer.surename = malloc(strlen(data) + 1);
            strcpy(buff->buyer.surename, data);
            break;
        case BStreet:
            buff->buyer.street = malloc(strlen(data) + 1);
            strcpy(buff->buyer.street, data);
            break;
        case BHouse:
            buff->buyer.housNumber = malloc(strlen(data) + 1);
            strcpy(buff->buyer.housNumber, data);
            break;
        case BCity:
            buff->buyer.city = malloc(strlen(data) + 1);
            strcpy(buff->buyer.city, data);
            break;
        case BCode:
            buff->buyer.postCode = malloc(strlen(data) + 1);
            strcpy(buff->buyer.postCode, data);
            break;
        case BMail:
            buff->buyer.mail = malloc(strlen(data) + 1);
            strcpy(buff->buyer.mail, data);
            break;
        case BNip:
            buff->buyer.nipCode = malloc(strlen(data) + 1);
            strcpy(buff->buyer.nipCode, data);
            break;
        case BAccount:
            buff->buyer.accountNumber = malloc(strlen(data) + 1);
            strcpy(buff->buyer.accountNumber, data);
            break;
        default:
            break;
    }
}
void setInvBuffParams(InvoiceParameters *buff, InvParName invPar, char *data, void (*setData)(InvoiceParameters *, char *, InvParName)){

    //parametry faktury
    if(invPar == InvId || invPar >= PType){
        setData = setInvoiceParameters; // ustawienie wskaznika na funkcje
    //parametry faktury - dane sprzedawcy
    }else if (invPar >= SName && invPar <= SAccount){
        setData = setSellerParameters;
    //parametry faktury - dane nabywcy
    }else if(invPar >= BName && invPar <= BAccount) {
        setData = setBuyerParameters;
    }

    //wywolanie funkcji
    setData(&(*buff),data,invPar);

}
void freeInvoiceBuffer(InvoiceParameters* buff){

    free(buff->id);
    free(buff->seller.name);
    free(buff->seller.surename);
    free(buff->seller.city);
    free(buff->seller.housNumber);
    free(buff->seller.mail);
    free(buff->seller.street);
    free(buff->seller.accountNumber);
    free(buff->seller.nipCode);
    free(buff->seller.postCode);
    free(buff->buyer.name);
    free(buff->buyer.surename);
    free(buff->buyer.city);
    free(buff->buyer.housNumber);
    free(buff->buyer.mail);
    free(buff->buyer.street);
    free(buff->buyer.accountNumber);
    free(buff->buyer.nipCode);
    free(buff->buyer.postCode);
    free(buff->issueDate);
    free(buff->executionDate);
    free(buff->deadlineDate);
}

//Funkcje obslugi bufora danych listy produktow
void setProdBuffParams(ProductParameters* buff, ProdParName prodPar, char *data){

    switch(prodPar){

        case ProdId:
            buff->id = atoi(data);
            break;
        case Name:
            buff->name = malloc(strlen(data) + 1);
            strcpy(buff->name,data);
            break;
        case Amount:
            buff->amount = atoi(data);
            break;
        case ProdTax:
            buff->taxCost = atoi(data);
            break;
        case ProdTaxRate:
            buff->taxRate = atoi(data);
            break;
        case ProdNetto:
            buff->nettoCost = atoi(data);
            break;
        case ProdBrutto:
            buff->bruttoCost = atoi(data);
            break;
        default: break;
    }
}
void setProdBuffFromConsole(ProductParameters* buff, ProdParName prodPar, char *data){
    double tmp;
    switch(prodPar){
        case Name:
            buff->name = malloc(strlen(data) + 1);
            strcpy(buff->name,data);
            break;
        case Amount:
            buff->amount = atoi(data);
            break;
        case ProdTaxRate:
            buff->taxRate = atoi(data);
            break;
        case ProdNetto:
            tmp = 100*strtod(data,NULL);
            buff->nettoCost = (int) tmp;
            break;
        default: break;
    }
}
void freeProductBuffer(ProductParameters* buff){
    free(buff->name);
}




