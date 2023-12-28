#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


using namespace std;

class Printer
{
    public:
    virtual bool setup(const string& loc, int id){
        if((loc == "test") && (id == 101)){ 
            return true;
        }
        return false;
    }

    virtual bool setup2(const string& loc, int id){
        if((loc == "test2") && (id == 101)){ 
            return true;
        }
        return false;
    }

    virtual int print(const std::string& str){
        return str.size();
    }
};

class MockPrinter : public Printer
{
    public:
    MOCK_METHOD2(setup, bool (const string& loc, int id));
    MOCK_METHOD2(setup2, bool (const string& loc, int id));
    MOCK_METHOD1(print, int (const std::string& str));
};


class Shape
{
    public:
    Shape(Printer* p):printer(p){}
    
    int initPrinter(const string& loc, int id){

        if(id%2){
            if(printer->setup(loc,id)) {
                cout << "\n\n\n\n setup called" ;
                return 1;
            }
        } else {
            if(printer->setup2(loc,id)) {
                cout << "\n\n\n\n setup 2 called" ;
                return 1;
            }
        }
        return -1;
    }
    bool create(){ return true;}
    void render(){}
    void display(){};

    private:
    Printer * printer;    
};

TEST(ShapePrintingTest, InitPrinterPass){

    //arrange
    MockPrinter mp;
    Shape shp(&mp);
    //EXPECT_CALL(mp,setup("test",101)).Times(1).WillOnce(Return(true));
    
    //for all access 
    EXPECT_CALL(mp,setup(_,_)).Times(AtLeast(1)).WillOnce(Return(true));
    //act
    int res = shp.initPrinter("test",101);
    
    //assert
    EXPECT_EQ(res,1);   
    
}
TEST(ShapePrintingTest, InitPrinterFailure){

    //arrange
    MockPrinter mp;
    Shape shp(&mp);
    //EXPECT_CALL(mp,setup("test",101)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(mp,setup(_,_)).Times(AtLeast(1)).WillOnce(Return(false));

    //Times means when you expect this function to be call Atleast or some number of times
    //WillOnce can be changed to WillRepeatedly when times is more than one and you want to 
    //return same value(false) every time

    //act
    int res = shp.initPrinter("testadsfasd",101);

    //assert
    EXPECT_EQ(res,-1);
} 
TEST(ShapePrintingTest, InitPrinterFailure_OnCallDemo){

    //arrange
    MockPrinter mp;
    Shape shp(&mp);
    ON_CALL(mp,setup(_,101)).WillByDefault(Return(false));
    ON_CALL(mp,setup2(_,100)).WillByDefault(Return(false));

    //Times means when you expect this function to be call Atleast or some number of times
    //WillOnce can be changed to WillRepeatedly when times is more than one and you want to 
    //return same value(false) every time

    //act
    int res = shp.initPrinter("testadsfasd",101);

    //assert
    EXPECT_EQ(res,-1);
} 
