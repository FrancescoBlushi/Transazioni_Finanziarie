
#ifndef TRANSAZIONI_FINANZIARIE_CLIENTE_H
#define TRANSAZIONI_FINANZIARIE_CLIENTE_H
using namespace std;
#include <iostream>
#include "Conto.h"


class Cliente {
public:
    Cliente(string nome="Unknown",string cognome="Unknown"): Name(nome),Surname(cognome)
    {
        Creafile();
    }
    void insertConto(const Conto& inserisciconto);
    void StampainfoConto(const Conto& stampaconto);
    void cancellaConto(Conto& conto);
    void Creafile();

    
    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const vector<Conto> &getConti() const;
private:
    string Name;
    string Surname;
    vector<Conto>Conti;



};


#endif //TRANSAZIONI_FINANZIARIE_CLIENTE_H
