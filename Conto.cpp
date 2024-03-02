#include <algorithm>
#include "Conto.h"

bool Conto::aggiungiTransazione(const Transazioni & transazione) {
    if(transazione.getTipoOperazione()=="Bonifico" || transazione.getTipoOperazione()=="Prelievo" || transazione.getTipoOperazione()=="Acquisto" ){
        if(transazione.getImporto()<=saldo){
            saldo=saldo-transazione.getImporto();
            vectorTransazione.push_back(transazione);
            return true;
        }
        else{
            return false;
        }
    }
    else{
        saldo=saldo+transazione.getImporto();
        vectorTransazione.push_back(transazione);
        return true;
    }

}

void Conto::creaContoFile() {
    ofstream file(name + "_"+ surname+Banca+".txt");
    if(file.is_open()){
        file<<"Titolare conto : "<<name<<" "<<surname<<endl;
        file<<"Numero di conto: "<<numero_Conto<<endl;
        file<<"Saldo :"<<saldo<<endl;
        file.close();
    }

}

void Conto::readContoFile() const {
    ifstream readfile(name + "_"+ surname+Banca+".txt");
    if(readfile.is_open()){
        string linea;
        while(getline(readfile,linea)){
            cout<<linea<<endl;
        }
        readfile.close();
    }

}
bool Conto::operator==(const Conto& other )  const {
    if(Banca==other.Banca && numero_Conto==other.numero_Conto) {
        return true;
    }else{
        return false;
    }
}

const string &Conto::getName() const {
    return name;
}

void Conto::setName(const string &name) {
    Conto::name = name;
}

const string &Conto::getSurname() const {
    return surname;
}

void Conto::setSurname(const string &surname) {
    Conto::surname = surname;
}

int Conto::getNumeroConto() const {
    return numero_Conto;
}

void Conto::setNumeroConto(int numeroConto) {
    numero_Conto = numeroConto;
}

double Conto::getSaldo() const {
    return saldo;
}

void Conto::setSaldo(double saldo) {
    Conto::saldo = saldo;
}

void Conto::stampaTutteTransazioni() {
    for(auto it:vectorTransazione){
        it.readFile();
    }

}

const string &Conto::getBanca() const {
    return Banca;
}

void Conto::setBanca(const string &banca) {
    Banca = banca;
}

const vector<Transazioni> &Conto::getVectorTransazione() const {
    return vectorTransazione;
}
