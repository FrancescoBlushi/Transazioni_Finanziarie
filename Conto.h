
#ifndef TRANSAZIONI_FINANZIARIE_CONTO_H
#define TRANSAZIONI_FINANZIARIE_CONTO_H
#include <vector>
#include "Transazioni.h"


class Conto {
public:
    Conto(string nome,string cognome,int numero_conto,double saldo) : name(nome),surname(cognome),numero_Conto(numero_conto),
    saldo(saldo) {
        creaContoFile();
    }

    bool aggiungiTransazione(const Transazioni& transazione);
    void creaContoFile();
    void readContoFile();
    void stampaTutteTransazioni();
private:
    vector<Transazioni>vectorTransazione;
    string name;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    int getNumeroConto() const;

    void setNumeroConto(int numeroConto);

    double getSaldo() const;

    void setSaldo(double saldo);

private:
    string surname;
    int numero_Conto;
    double saldo;

};


#endif //TRANSAZIONI_FINANZIARIE_CONTO_H
