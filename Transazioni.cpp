

#include "Transazioni.h"

void Transazioni::createFile() {
    ofstream myfile(tipoOperazione + "_" + destinatario+ ".txt");
    if (myfile.is_open()){
        myfile<<"Tipo di Operazione : "<<tipoOperazione<<endl;
        myfile<<"Destinatario : "<<destinatario<<endl;
        myfile<<"Numero di conto : " <<numeroConto<<endl;
        myfile<<" Importo del "<<tipoOperazione<<":"<< importo<<endl;
        myfile.close();
    }
    else{
        cerr<<"Errore file is not open"<<endl;
    }


}

void Transazioni::readFile() {
    ifstream readfile(tipoOperazione + "_" + destinatario+ ".txt");
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

const string &Transazioni::getTipoOperazione() const {
    return tipoOperazione;
}

void Transazioni::setTipoOperazione(const string &tipoOperazione) {
    Transazioni::tipoOperazione = tipoOperazione;
}

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
