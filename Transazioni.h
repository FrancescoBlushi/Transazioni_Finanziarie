
#ifndef TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
#define TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
#include <iostream>
#include <fstream>
using namespace std;


class Transazioni {
public:
    Transazioni (string operazione="Unknown",double import=0,int NrConto=0,string Destinatario="me") : tipoOperazione(operazione),importo(import),numeroConto(NrConto),
    destinatario(Destinatario){
        createFile();
    }
    void createFile() ;
    void readFile() ;

private:
    string tipoOperazione;
    double  importo;
public:
    const string &getTipoOperazione() const;

    void setTipoOperazione(const string &tipoOperazione);

    double getImporto() const;

    void setImporto(double importo);

    int getNumeroConto() const;

    void setNumeroConto(int numeroConto);

    const string &getDestinatario() const;

    void setDestinatario(const string &destinatario);

private:
    int numeroConto;
    string destinatario;




};


#endif //TRANSAZIONI_FINANZIARIE_TRANSAZIONI_H
