#include <iostream>
#include <gtest/gtest.h>

using namespace std;


class SampleClass
{
    public:
    int sampleFunc()
    {
        return 1;
    }
};

int Factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

//Simple Test
TEST(FactorialTest, HandleZeroInput) {
    EXPECT_EQ(Factorial(0), 1);
}

// TestFixture
class TestFixtureDemo : public testing::Test
{
    public:
    TestFixtureDemo(){
        cout << "\nConstructed" << endl;
    }
    ~TestFixtureDemo(){
        cout << "\nDestructed" << endl;
    }
    protected:
    void SetUp() override
    {
        cout << "\nSetUp" << endl;
        pEx = new SampleClass();
    }
    void TearDown()override
    {
        cout << "\nTearDown" << endl;
        delete pEx;
    }

    SampleClass * pEx;
};
TEST_F(TestFixtureDemo, test1){
    EXPECT_EQ(1,pEx->sampleFunc());
}
TEST_F(TestFixtureDemo, test2){
    EXPECT_NE(0,pEx->sampleFunc());
}

#ifndef GTEST_MAIN_INIT_IN_CMAKE
int main(int argc, char* argv[])
{
    cout << "\n\n\n\n*****\n\nPopulating tests from gtest main\n\n\n\n" << endl;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#endif 