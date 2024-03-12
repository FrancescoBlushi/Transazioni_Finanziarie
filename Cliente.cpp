

#include "Cliente.h"
#include <algorithm>

void Cliente::insertConto(const Conto &inserisciconto) {
    Conti.push_back(inserisciconto);
}

void Cliente::StampainfoConto(const Conto &stampaconto) {
    stampaconto.readContoFile();

}

void Cliente::cancellaConto(Conto& conto ) {
   auto it= find(Conti.begin(), Conti.end(),(conto));
   if(it!=Conti.end()){
       Conti.erase(it);
   }

}



const string &Cliente::getName() const {
    return Name;
}

void Cliente::setName(const string &name) {
    Name = name;
}

const string &Cliente::getSurname() const {
    return Surname;
}

void Cliente::setSurname(const string &surname) {
    Surname = surname;
}

void Cliente::Creafile() {
    ofstream file(Name+"_"+Surname+".txt");
    if(file.is_open()){
        file<<Name<<endl;
        file<<Surname<<endl;
        file.close();
    }

}

bool Cliente::searchConto(const Conto & inserisciconto) {
    auto it= find(Conti.begin(), Conti.end(),(inserisciconto));
    if(it!=Conti.end()){
        return true;
    }
    else{
        return false;
    }


}

void Cliente::modificaConto( Conto & inserisciconto,string nome,string cognome) {
    if(searchConto(inserisciconto)){
        inserisciconto.setName(nome);
        inserisciconto.setSurname(cognome);
    }

}

bool Cliente:: bisestile(int year) {
     {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}

bool Cliente::controlladata(int d, int m, int y) {
    if(d<=data[m] && !bisestile(y) && d > 0 && m <= 12 && m > 0 && y > 0 && y<=2002){
        return true;
    } else if(bisestile(y) && d==29 && m==2 && y<=2002){
        return true;
    }
    else if (bisestile(y) && d<=data[m] && d > 0 && m <= 12 && m > 0 && y > 0 && y<=2002){
        return true;
    }else{
        return false;
    }
}

int Cliente::Numero_di_Conti() {
    return Conti.size();
}

int Cliente::getGiorno() const {
    return giorno;
}

void Cliente::setGiorno(int giorno) {
    Cliente::giorno = giorno;
}

int Cliente::getMese() const {
    return mese;
}

void Cliente::setMese(int mese) {
    Cliente::mese = mese;
}

int Cliente::getAnno() const {
    return anno;
}

void Cliente::setAnno(int anno) {
    Cliente::anno = anno;
}
