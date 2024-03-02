#include "gtest/gtest.h"
#include "../Conto.h"

#include "memory"


TEST(Conto,CreazionefileConto){
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    ifstream file("Andrea_Barella.txt");
    ASSERT_TRUE(file.is_open());
    file.close();
}

TEST(Conto,Controllo_Istanza){
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    EXPECT_EQ(C.getName(),"Andrea");
    EXPECT_EQ(C.getSurname(),"Barella");
    EXPECT_EQ(C.getNumeroConto(),121212);
    EXPECT_EQ(C.getSaldo(),3000.30);
}

TEST(Conto,Testmemoria){
    unique_ptr <Conto> Cptr(new Conto("Andrea","Barella","BancoPosta",121212,3000.30));
    EXPECT_NE(Cptr,nullptr);
    Cptr.reset();
    EXPECT_EQ(Cptr,nullptr);
}
TEST(Conto,TestTransazionePrelievo){
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    Transazioni T("Prelievo",300);
    EXPECT_TRUE(C.aggiungiTransazione(T));
    EXPECT_EQ(2700.30,C.getSaldo());
}
TEST(Conto,TestTransazioneVersamento){
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    Transazioni T("Versamento",500);
    EXPECT_TRUE(C.aggiungiTransazione(T));
    EXPECT_EQ(3500.30,C.getSaldo());
}
TEST(Conto,Test_Prelievo_saldo_insufficente){
    Conto C ("Andrea","Barella","BancoPosta",121212,800.30);
    Transazioni T("Bonifico",1000,121231,"UNIFI");
    EXPECT_FALSE( C.aggiungiTransazione(T));
}
TEST(Conto,Test_controllo_aggiunta_transazione_vector){
    Conto C ("Andrea","Barella","BancoPosta",121212);
    Transazioni T("Versamento",1500);
    C.aggiungiTransazione(T);
    EXPECT_EQ(C.getVectorTransazione().size(),1);

}