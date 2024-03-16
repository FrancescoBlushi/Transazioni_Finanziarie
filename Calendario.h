
#ifndef TRANSAZIONI_FINANZIARIE_CALENDARIO_H
#define TRANSAZIONI_FINANZIARIE_CALENDARIO_H

#include <vector>
#include <stdexcept>
using namespace std;


class Calendario {
public:
    Calendario(int day=1,int month=1,int year=2000) : giorno(day),mese(month),anno(year) {
        if(!controllodata(day,month,year)){
            throw invalid_argument("Data non Valida");
        }
    }


    int getGiorno() const;

    void setGiorno(int giorno);

    int getMese() const;

    void setMese(int mese);

    int getAnno() const;

    void setAnno(int anno);



private:
    const bool bisestile (int y) const;
    bool controllodata(int d, int m, int y) ;
    int giorno;
    int mese;
    int anno;
    vector<int>data={0,31,28,31,30,31,30,31,31,30,31,30,31};

};


#endif //TRANSAZIONI_FINANZIARIE_CALENDARIO_H
