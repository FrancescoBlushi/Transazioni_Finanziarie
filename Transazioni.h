
#ifndef TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
#define TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
using namespace std;


class Transazioni {
public:
    Transazioni (bool operazione= true,double import=1,int NrConto=0,string Destinatario="me",int giorno=1,int mese=1,int anno=1970) :
    tipoOperazione(operazione),importo(import),numeroConto(NrConto),
    destinatario(Destinatario),giorno(giorno),mese(mese),anno(anno){

        if(!controlladata(giorno, mese, anno)){
            throw invalid_argument("Data non valida");
        }
        if(import<=0){
            throw invalid_argument("Importo sbagliato");
        }
        createFile();
    }

    void createFile() ;
    void readFile() ;
    bool operator==(const Transazioni& other ) const;
    bool bisestile(int year);
    bool controlladata(int d,int m,int y);

    //Set e Get
    bool isTipoOperazione() const;
    void setTipoOperazione1(bool tipooperazione);
    void setDestinatario(const string &destinatario);
    double getImporto() const;
    void setImporto(double importo);
    int getNumeroConto() const;
    void setNumeroConto(int numeroConto);
    const string &getDestinatario() const;
    int getGiorno() const;
    void setGiorno(int giorno);
    int getMese() const;
    void setMese(int mese);
    int getAnno() const;
    void setAnno(int anno);
private:
    int giorno;
    int mese;
    int anno;
    bool tipoOperazione;
    double  importo;
    int numeroConto;
    string destinatario;
    vector<int>data={0,31,28,31,30,31,30,31,31,30,31,30,31};
};


#endif //TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
