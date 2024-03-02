
#ifndef TRANSAZIONI_FINANZIARIE_CONTO_H
#define TRANSAZIONI_FINANZIARIE_CONTO_H
#include <vector>
#include "Transazioni.h"


class Conto {
public:
    Conto(string nome,string cognome,string banca,int numero_conto,double saldo=0) : name(nome),surname(cognome),numero_Conto(numero_conto),
    saldo(saldo),Banca(banca) {
        creaContoFile();
    }

    bool aggiungiTransazione(const Transazioni& transazione);
    void creaContoFile();
    void readContoFile()const;
    void stampaTutteTransazioni();
    bool operator==(const Conto& other ) const;


    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    int getNumeroConto() const;

    void setNumeroConto(int numeroConto);

    double getSaldo() const;

    void setSaldo(double saldo);



    const vector<Transazioni> &getVectorTransazione() const;

    const string &getBanca() const;

    void setBanca(const string &banca);

private:
    string name;
    string Banca;
    string surname;
    int numero_Conto;
    double saldo;
    vector<Transazioni>vectorTransazione;

};


#endif //TRANSAZIONI_FINANZIARIE_CONTO_H
