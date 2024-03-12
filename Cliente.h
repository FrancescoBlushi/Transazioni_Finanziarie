
#ifndef TRANSAZIONI_FINANZIARIE_CLIENTE_H
#define TRANSAZIONI_FINANZIARIE_CLIENTE_H
using namespace std;
#include <iostream>
#include "Conto.h"
#include <exception>


class Cliente {
public:
    Cliente(string nome="Unknown",string cognome="Unknown",int giorno=1,int mese=1,int anno=1991): Name(nome),Surname(cognome),giorno(giorno),mese(mese),anno(anno)
    {
        if(!controlladata(giorno,mese,anno)){
            throw invalid_argument("Data di nascita errata");
        }
        Creafile();
    }

    void insertConto(const Conto& inserisciconto);
    void StampainfoConto(const Conto& stampaconto);
    void cancellaConto(Conto& conto);
    void Creafile();
    bool searchConto(const Conto& inserisciconto);
    void modificaConto(Conto& inserisciconto,string nome,string cognome);
    static bool bisestile(int year);
    bool controlladata(int d,int m,int y);
    int Numero_di_Conti();

    //Set e Get
    const string & getName() const;
    void setName(const string &name);
    const string & getSurname() const;
    void setSurname(const string &surname);
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
    string Name;
    string Surname;
    vector<Conto>Conti;
    vector<int>data={0,31,28,31,30,31,30,31,31,30,31,30,31};



};


#endif //TRANSAZIONI_FINANZIARIE_CLIENTE_H
