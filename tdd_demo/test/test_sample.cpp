// test_sample.cpp
#include "gtest/gtest.h"

int Factorial(int n) {
    if (n < 0) {
        ASSERT()
    }
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}


TEST(FactorialTest, HandleZeroInput) {
	EXPECT_EQ(Factorial(0), 1);
}
TEST(FactorialTest, HandlePositiveInput) {
	EXPECT_EQ(Factorial(1), 1);
	EXPECT_EQ(Factorial(2), 2);
	EXPECT_EQ(Factorial(5), 120);
	EXPECT_EQ(Factorial(8), 40320);
}

