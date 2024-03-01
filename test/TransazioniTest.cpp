#include "gtest/gtest.h"
#include "../Transazioni.h"
#include <string>
#include <memory>


TEST(Transazioni,Creazionefile){
    Transazioni T1("Versamento",300,123456,"Roberto");
    ifstream file("Versamento_Roberto.txt");
    ASSERT_TRUE(file.is_open());
    file.close();

}
TEST(Transazioni,Controllo_istanza){
    Transazioni T("Versamento",300.20,123456,"Roberto");
    EXPECT_EQ(T.getTipoOperazione(),"Versamento");
    EXPECT_EQ(T.getDestinatario(),"Roberto");
    EXPECT_EQ(T.getImporto(),300.20);
    EXPECT_EQ(T.getNumeroConto(),123456);

}
TEST(Transazioni,Controllo_memoria) {
    unique_ptr<Transazioni> Tptr(new Transazioni("Versamento", 300.20, 123456, "Roberto"));
    EXPECT_NE(Tptr, nullptr);
}

TEST(Transazioni,Controllo_ripristino_memoria){
    unique_ptr<Transazioni> Tptr(new Transazioni("Versamento", 300.20, 123456, "Roberto"));
    Tptr.reset();
    EXPECT_EQ(Tptr, nullptr);

}
