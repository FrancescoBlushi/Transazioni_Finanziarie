
#ifndef TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
#define TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
#include <iostream>
#include <fstream>
#include <exception>
#include <utility>
#include <vector>
#include "Calendario.h"
using namespace std;
enum class OperazioniFinanziarie{
    Bonifico,
    Versamento,
    Prelievo,
    PagamentoBollette,
    PagamentoCarta,
    Investimento,
    Stipendio,
    BonificoEntrata

};



class Transazioni {
public:
    Transazioni (OperazioniFinanziarie operazione=OperazioniFinanziarie::Prelievo,double import=1,int NrConto=0,string Destinatario="me",int giorno=1,int mese=1,int anno=1970) :
    tipoOperazione(operazione),importo(import),numeroConto(NrConto),
    destinatario(std::move(Destinatario)),giorno(giorno),mese(mese),anno(anno){
        C.setGiorno(giorno);
        C.setMese(mese);
        C.setAnno(anno);
        if(import<=0){
            throw invalid_argument("Importo sbagliato");
        }
        createFile();
    }

    void createFile() ;
    void readFile() ;
    bool operator==(const Transazioni& other ) const;
    bool controllaoperazione(OperazioniFinanziarie op) const ;// Usata per distinguere le operazioni di entrata e uscita
    static string tipoOperazionistring(OperazioniFinanziarie op);// trasforma le istanze di enumerazione in stringhe, necessario per la creazione del file

    //Set e Get
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
    OperazioniFinanziarie getTipoOperazione() const;
    void setTipoOperazione(OperazioniFinanziarie tipoOperazione);

private:
    int giorno;
    int mese;
    int anno;
    OperazioniFinanziarie tipoOperazione;
    double  importo;
    int numeroConto;
    string destinatario;
    Calendario C;
};


#endif //TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
