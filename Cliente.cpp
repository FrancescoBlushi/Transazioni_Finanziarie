

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

const vector<Conto> &Cliente::getConti() const {
    return Conti;
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
