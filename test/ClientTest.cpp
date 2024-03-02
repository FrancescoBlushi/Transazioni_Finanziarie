#include "gtest/gtest.h"
#include "../Cliente.h"

TEST(Cliente,Inserimento_Conto){
    Cliente cliente;
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    cliente.insertConto(C);
    EXPECT_EQ(cliente.getConti().size(),1);
    EXPECT_EQ(cliente.getConti()[0],C);

}
TEST(Cliente,Cancellazione_Conto){
    Cliente cliente;
    Conto C ("Andrea","Barella","BancoPosta",121212,3000.30);
    Conto C1("Nicolo","Barella","Banca_Italia",121213,100.23);
    cliente.insertConto(C);
    cliente.insertConto(C1);
    EXPECT_EQ(cliente.getConti().size(),2);
    cliente.cancellaConto(C1);
    EXPECT_EQ(cliente.getConti().size(),1);
    EXPECT_EQ(cliente.getConti()[0],C);
}
TEST(Cliente,Costruttore_Default){
    Cliente C;
    EXPECT_EQ(C.getName(),"Unknown");
    EXPECT_EQ(C.getSurname(),"Unknown");
}
TEST(Cliente,Creazione_file){
    Cliente C;
    ifstream readfile(C.getName()+"_"+C.getSurname()+".txt");
    ASSERT_TRUE(readfile.is_open());
    readfile.close();

}