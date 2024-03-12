#include "gtest/gtest.h"
#include "../Cliente.h"

TEST(Cliente,Inserimento_Conto){
    Cliente cliente;
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    cliente.insertConto(C);
    EXPECT_EQ(cliente.Numero_di_Conti(),1);

}
TEST(Cliente,Cancellazione_Conto){
    Cliente cliente;
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    Conto C1("Nicolo","Barella","Banca_Italia",121213,100.23);
    cliente.insertConto(C);
    cliente.insertConto(C1);
    EXPECT_EQ(cliente.Numero_di_Conti(),2);
    cliente.cancellaConto(C1);
    EXPECT_EQ(cliente.Numero_di_Conti(),1);
}
TEST(Cliente,Costruttore_Default){
    Cliente C;
    EXPECT_EQ(C.getName(),"Unknown");
    EXPECT_EQ(C.getSurname(),"Unknown");
    EXPECT_EQ(C.getGiorno(),1);
    EXPECT_EQ(C.getMese(),1);
    EXPECT_EQ(C.getAnno(),1991);
}
TEST(Cliente,Creazione_file){
    Cliente C;
    ifstream readfile(C.getName()+"_"+C.getSurname()+".txt");
    ASSERT_TRUE(readfile.is_open());
    readfile.close();

}
TEST(Cliente,Test_Eccezioni){
    EXPECT_THROW(Cliente C ("Andrea","Barella",1,1,2022),invalid_argument);
}
TEST(Cliente,Metodo_search){
    Cliente cliente;
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    cliente.insertConto(C);
    ASSERT_TRUE(cliente.searchConto(C));
}
TEST(Cliente,Modifica_Cliente){
    Cliente cliente;
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    cliente.insertConto(C);
    cliente.modificaConto(C,"Matteo","Darmian");

    EXPECT_EQ(C.getName(),"Matteo");
    EXPECT_EQ(C.getSurname(),"Darmian");
}