#include "gtest/gtest.h"
#include "../Transazioni.h"
#include <string>
#include <memory>


TEST(Transazioni,Creazionefile){
    Transazioni T1(OperazioniFinanziarie::Versamento,300,123456,"Roberto");
    ifstream file("Versamento_Roberto.txt");
    ASSERT_TRUE(file.is_open());
    file.close();

}
TEST(Transazioni,Controllo_istanza){
    Transazioni T(OperazioniFinanziarie::Versamento,300.20,123456,"Roberto",1,1,2004);
    EXPECT_EQ(T.getTipoOperazione(),OperazioniFinanziarie::Versamento);
    EXPECT_EQ(T.getDestinatario(),"Roberto");
    EXPECT_EQ(T.getImporto(),300.20);
    EXPECT_EQ(T.getNumeroConto(),123456);
    EXPECT_EQ(T.getGiorno(),1);
    EXPECT_EQ(T.getMese(),1);
    EXPECT_EQ(T.getAnno(),2004);


}
TEST(Transazioni,Controllo_memoria) {
    unique_ptr<Transazioni> Tptr(new Transazioni(OperazioniFinanziarie::Versamento, 300.20, 123456, "Roberto"));
    EXPECT_NE(Tptr, nullptr);
}

TEST(Transazioni,Controllo_ripristino_memoria){
    unique_ptr<Transazioni> Tptr(new Transazioni(OperazioniFinanziarie::Versamento, 300.20, 123456, "Roberto"));
    Tptr.reset();
    EXPECT_EQ(Tptr, nullptr);

}

TEST(Transazioni,Test_Eccezioni){
    EXPECT_THROW(Transazioni T(OperazioniFinanziarie::Versamento,300.20,123456,"Roberto",32,1,2004),invalid_argument);
    EXPECT_THROW(Transazioni T(OperazioniFinanziarie::Versamento,-31,123456,"Roberto",1,1,2004),invalid_argument);
}

