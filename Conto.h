
#ifndef TRANSAZIONI_FINANZIARIE_CONTO_H
#define TRANSAZIONI_FINANZIARIE_CONTO_H
#include <vector>
#include "Transazioni.h"
#include <iostream>



class Conto {
public:
    Conto(string nome,string cognome,string banca,int numero_conto,double saldo=0) : name(nome),surname(cognome),numero_Conto(numero_conto),
    saldo(saldo),Banca(banca) {
        creaContoFile();
    }

    bool aggiungiTransazione(const Transazioni& transazione);
    void removeTransazione (Transazioni& transazione);
    bool searchTransazione(Transazioni& transazione);
    void modificaTransazione(Transazioni& transazione,int numeroconto,double nuovoimporto,string destinatario,OperazioniFinanziarie tipoOperazione);
    void creaContoFile();
    void aggTransazioniFile(const Transazioni& transazione);
    void readContoFile()const;
    void stampaTutteTransazioni();
    bool operator==(const Conto& other ) const;// L'overloading dell'operatore (==) utile per la ricerca nel vettore.
    int const conta_nr_transazioni();// Per conservare l'incapsulamento del vettore, il metodo restituisce il numero di transazioni.
    bool calcolatransazione(const Transazioni& transazione);// Utile per il calcolo del saldo, usata nelle funzioni remove, aggiungi e modifica transazione

    //Set e Get
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
