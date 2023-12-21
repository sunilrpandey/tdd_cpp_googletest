#include <iostream>
#include "gtest/gtest.h"

using namespace std;

int Factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

class example
{
    public:
    int foo()
    {
        return 1;
    }
};



TEST(ExampleTest, test1) {
    example ex;
    ASSERT_EQ(1,ex.foo());
}
TEST(ExampleTest, test2) {
    example ex;
    ASSERT_NE(0,ex.foo());
}


class testFixture : public testing::Test
{
    protected:
    void SetUp() override
    {
        pEx = new example();
    }
    void TearDown()override
    {
        delete pEx;
    }

    example * pEx;
};
TEST_F(testFixture, test1){
    EXPECT_EQ(1,pEx->foo());
}
TEST_F(testFixture, test2){
    EXPECT_NE(0,pEx->foo());
}

TEST(FactorialTest, HandleZeroInput) {
	EXPECT_EQ(Factorial(0), 1);
}
TEST(FactorialTest, HandlePositiveInput) {
	EXPECT_EQ(Factorial(1), 1);
	EXPECT_EQ(Factorial(2), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}