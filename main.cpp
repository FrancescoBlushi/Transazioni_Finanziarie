#include <iostream>
#include "Cliente.h"
#include "Conto.h"
#include "Transazioni.h"

int main() {
    Cliente C("Andrea","Rossi");
    Conto nr1("Andrea","Rossi","Banco Posta",123456,1000);
    C.insertConto(nr1);
    Transazioni t("Bonifico",500,123654,"Francesco Blushi",12,2,2024);
    nr1.aggiungiTransazione(t);
    nr1.readContoFile();

    return 0;
}
