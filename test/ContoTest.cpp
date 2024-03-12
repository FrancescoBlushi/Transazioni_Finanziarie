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
    Transazioni T(false,300);
    EXPECT_TRUE(C.aggiungiTransazione(T));
    EXPECT_EQ(2700.30,C.getSaldo());
}
TEST(Conto,TestTransazioneVersamento){
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    Transazioni T(true,500);
    EXPECT_TRUE(C.aggiungiTransazione(T));
    EXPECT_EQ(3500.30,C.getSaldo());
}
TEST(Conto,Test_Prelievo_saldo_insufficente){
    Conto C ("Andrea","Barella","BancoPosta",121212,800.30);
    Transazioni T(false,1000,121231,"UNIFI");
    EXPECT_FALSE( C.aggiungiTransazione(T));
}
TEST(Conto,Test_controllo_aggiunta_transazione_vector){
    Conto C ("Andrea","Barella","BancoPosta",121212);
    Transazioni T1(true,1500,3005,"Andrea",12,12,2004);
    C.aggiungiTransazione(T1);
    EXPECT_EQ(C.conta_nr_transazioni(),1);

}
TEST(Conto,Test_contorllo_rimovo_transazione){
    Conto C ("Andrea","Barella","BancoPosta",121212);
    Transazioni T1(true,1500,3005,"Andrea",12,12,2004);
    Transazioni T2(true,1500,3005,"Roberto",12,12,2004);
    C.aggiungiTransazione(T1);
    C.aggiungiTransazione(T2);
    C.removeTransazione(T1);

    EXPECT_EQ(C.conta_nr_transazioni(),1);

}
TEST(Conto,Testo_controllo_modifica_transazione){
    Conto C ("Andrea","Barella","BancoPosta",121212);
    Transazioni T(false,1500,3005,"Andrea",12,12,2004);
    C.aggiungiTransazione(T);
    C.modificaTransazione(T,123445,300,"Roberta");
    EXPECT_EQ(T.getNumeroConto(),123445);
    EXPECT_EQ(T.getImporto(),300);
    EXPECT_EQ(T.getDestinatario(),"Roberta");

}