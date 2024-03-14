#include <iostream>
#include "Cliente.h"
#include "Conto.h"
#include "Transazioni.h"
#include <exception>

int main() {
    try{
        Transazioni T1(OperazioniFinanziarie::Versamento,300.20,123456,"Roberto",32,1,2004);
    }
    catch (const invalid_argument& e) {
        cerr<<"Eccezione catturata : "<<e.what()<<endl;
    }
    try{
        Transazioni T2(OperazioniFinanziarie::Versamento,-31,123456,"Roberto",1,1,2004);
    }
    catch (const invalid_argument& e){
        cerr<<"Eccezione catturata: "<<e.what()<<endl;
    }
    try{
        Cliente C ("Andrea","Barella",1,1,2022);
    }
    catch (invalid_argument& e){
        cerr<<"Eccezione cattura: "<<e.what()<<endl;
    }

    return 0;
}
