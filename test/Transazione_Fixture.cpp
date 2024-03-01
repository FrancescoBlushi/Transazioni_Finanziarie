#include "gtest/gtest.h"
#include "../Transazioni.h"
#include <string>

class SuiteTransazione : public ::testing::Test{
protected:
    void SetUp()override{

    }
    Transazioni T;


};

TEST_F(SuiteTransazione,DefaultCostructor){
    EXPECT_EQ(T.getTipoOperazione(),"Unknown");
    EXPECT_EQ(T.getDestinatario(),"me");
    EXPECT_EQ(T.getNumeroConto(),0);
    EXPECT_EQ(T.getImporto(),0);
}
