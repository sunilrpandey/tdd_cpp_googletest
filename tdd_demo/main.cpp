#include <gtest/gtest.h>

using namespace std;


int Factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

 TEST(FactorialTest, HandleZeroInput) {
 	EXPECT_EQ(Factorial(0), 1);
 }
// #define Init_done_in_CMake 1
// #if Init_done_in_CMake
int main(int argc, char* argv[])
{

    cout << "populating tests from gtest main" << endl;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
//#endif 