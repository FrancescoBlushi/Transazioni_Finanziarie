//
// Created by franc on 16/03/2024.
//

#include "Calendario.h"

const bool Calendario::bisestile(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool Calendario::controllodata(int d, int m, int y) {
    if(d<=data[m] && !bisestile(y) && d > 0 && m <= 12 && m > 0 && y > 0){
        return true;
    } else if(bisestile(y) && d==29 && m==2){
        return true;
    }
    else if (bisestile(y) && d<=data[m] && d > 0 && m <= 12 && m > 0 && y > 0){
        return true;
    }else{
        return false;
    }
}

int Calendario::getGiorno() const {
    return giorno;
}

void Calendario::setGiorno(int giorno) {
    if(!controllodata(giorno,mese,anno)){
        throw invalid_argument("Data non Valida");
    }else {
        Calendario::giorno = giorno;
    }
}

int Calendario::getMese() const {
    return mese;
}

void Calendario::setMese(int mese) {
    if(!controllodata(giorno,mese,anno)){
        throw invalid_argument("Data non Valida");
    }else {
        Calendario::mese = mese;
    }
}

int Calendario::getAnno() const {
    return anno;
}

void Calendario::setAnno(int anno) {
    if(!controllodata(giorno,mese,anno)){
        throw invalid_argument("Data non Valida");
    }else {
        Calendario::anno = anno;
    }
}
