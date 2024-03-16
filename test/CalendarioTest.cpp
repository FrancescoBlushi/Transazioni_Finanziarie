#include "gtest/gtest.h"
#include "../Calendario.h"


TEST(Calendario,Test_Eccezione){
    Calendario c;
    EXPECT_EQ(c.getAnno(),2000);
    EXPECT_EQ(c.getMese(),1);
    EXPECT_EQ(c.getGiorno(),1);
    EXPECT_THROW(c.setGiorno(32), invalid_argument);
    EXPECT_THROW(c.setMese(13),invalid_argument);
    EXPECT_THROW(c.setAnno(-300),invalid_argument);
    EXPECT_THROW(Calendario C(31,2,2000),invalid_argument);

}
