#include "Transazioni.h"

void Transazioni::createFile() {
    ofstream myfile(tipoOperazionistring(tipoOperazione) + "_" + destinatario+ ".txt");
    if (myfile.is_open()){
        myfile<<"Tipo di Operazione : "<<controllaoperazione(getTipoOperazione())<<endl;
        myfile<<"Destinatario : "<<destinatario<<endl;
        myfile<<"Numero di conto : " <<numeroConto<<endl;
        myfile<<" Importo del "<<tipoOperazionistring(tipoOperazione)<<":"<< importo<<endl;
        myfile.close();
    }
    else{
        cerr<<"Errore file is not open"<<endl;
    }
}

void Transazioni::readFile() {
    ifstream readfile(tipoOperazionistring(tipoOperazione)+ "_" + destinatario+ ".txt");
    if(readfile.is_open()){
        string linea;
        while(getline(readfile,linea)){
            cout<<linea<<endl;
        }
        readfile.close();
    }
    else{
        cerr<<"Errore File non aperto "<<endl;
    }
}
bool Transazioni::bisestile(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Transazioni::operator==(const Transazioni &other) const {
    if(importo==other.importo && destinatario==other.destinatario && numeroConto==other.numeroConto)
        return true;
    else{
        return false;
    }
}
bool Transazioni::controlladata(int d, int m, int y) {
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

bool Transazioni::controllaoperazione(OperazioniFinanziarie op) const {
    if(op==OperazioniFinanziarie::Versamento || op==OperazioniFinanziarie::BonificoEntrata || op==OperazioniFinanziarie::Stipendio){
        return true;
    }else{
        return false;
    }

}

string Transazioni::tipoOperazionistring(OperazioniFinanziarie op) {
    switch (op) {
        case OperazioniFinanziarie::BonificoEntrata:
            return "BonificoEntrata";
        case OperazioniFinanziarie::Versamento:
            return "Versamento";
        case OperazioniFinanziarie::Prelievo:
            return "Prelievo";
        case OperazioniFinanziarie::PagamentoBollette:
            return "PagamentoBollette";
        case OperazioniFinanziarie::Investimento:
            return "Investimento";
        case OperazioniFinanziarie::Stipendio:
            return "Stipendio";
        case OperazioniFinanziarie::Bonifico:
            return "Bonifico";
        case OperazioniFinanziarie::PagamentoCarta:
            return "PagamentoCarta";
    }
}

//Set e Get
double Transazioni::getImporto() const {
    return importo;
}

void Transazioni::setImporto(double importo) {
    Transazioni::importo = importo;
}

int Transazioni::getNumeroConto() const {
    return numeroConto;
}

void Transazioni::setNumeroConto(int numeroConto) {
    Transazioni::numeroConto = numeroConto;
}

const string &Transazioni::getDestinatario() const {
    return destinatario;
}

void Transazioni::setDestinatario(const string &destinatario) {
    Transazioni::destinatario = destinatario;
}

int Transazioni::getGiorno() const {
    return giorno;
}

void Transazioni::setGiorno(int giorno) {
    Transazioni::giorno = giorno;
}

int Transazioni::getMese() const {
    return mese;
}

void Transazioni::setMese(int mese) {
    Transazioni::mese = mese;
}

int Transazioni::getAnno() const {
    return anno;
}

void Transazioni::setAnno(int anno) {
    Transazioni::anno = anno;
}


OperazioniFinanziarie Transazioni::getTipoOperazione() const {
    return tipoOperazione;
}

void Transazioni::setTipoOperazione(OperazioniFinanziarie tipoOperazione) {
    Transazioni::tipoOperazione = tipoOperazione;
}

