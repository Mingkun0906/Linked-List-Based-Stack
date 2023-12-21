#include "catch_amalgamated.hpp"
#include "postfixCalc.hpp"
#include "LLStack.hpp"
#include <unordered_map>
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{


// And some tests for the linked list based stack and the associated calculator.
    // VERY IMPORTANT:  if your LLStack is not templated, or if 
    //      it is not linked-list based, your score for this project
    //      will be zero.  Be sure your LLStack compiles and runs 
    //      with non-numeric data types.  A char is a numeric type.
    // 

TEST_CASE("RequiredStackTest1", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    REQUIRE( a.top() == 5 );
}

TEST_CASE("RequiredStackTest2", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    a.push(3);
    REQUIRE( a.top() == 3 );
}


TEST_CASE("RequiredStackTest3", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    a.push(3);
    a.pop();
    REQUIRE( a.top() == 5 );
}


TEST_CASE("RequiredStackTest4", "[Required]")
{
    LLStack<int> a;
    REQUIRE_THROWS_AS( a.top(), StackEmptyException );
}


TEST_CASE("RequiredStackTest5", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    REQUIRE( a.isEmpty() == false);
}


TEST_CASE("RequiredStackTest6", "[Required]")
{
    LLStack<int> a;
    REQUIRE( a.isEmpty() == true);
}


TEST_CASE("RequiredStackTest7", "[Required]")
{
    LLStack<int> myStack;
    myStack.push(5);
    LLStack<int> newStack = myStack;
    REQUIRE(newStack.isEmpty() == false);
    REQUIRE(newStack.top() == 5);
    newStack.pop();
    REQUIRE(newStack.isEmpty() == true);
    REQUIRE(myStack.top() == 5);
}


TEST_CASE("RequiredStackTest8", "[Required]")
{
    LLStack<int> myStack;
    myStack.push(5);
    LLStack<int> newStack;
    newStack = myStack;
    REQUIRE(newStack.top() == 5);
    newStack.pop();
    REQUIRE(newStack.isEmpty() == true);
    REQUIRE(myStack.top() == 5);
}


TEST_CASE("RequiredStackTest9", "[Required]")
{
    LLStack<int> myStack;
    myStack.push(5);
    myStack.push(6);
    LLStack<int> newStack;
    newStack.push(2);
    newStack = myStack;
    REQUIRE(newStack.top() == 6);
    newStack.pop();
    REQUIRE(newStack.top() == 5);
    REQUIRE(myStack.top() == 6);
}


TEST_CASE("RequiredStackTest10", "[Required]")
{
    LLStack<int> myStack;
    myStack.push(5);
    myStack.push(6);
    LLStack<int> newStack;
    newStack = myStack;
    REQUIRE(newStack.top() == 6);
    REQUIRE(newStack.size() == 2);
    newStack.pop();
    REQUIRE(newStack.top() == 5);
    REQUIRE(myStack.top() == 6);
    REQUIRE(myStack.size() == 2);
}

// YOU SHOULD ADD ADDITIONAL TEST_CASE "ERE" H"[CASES]"!! 



TEST_CASE("RequiredCalcTest1", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 15);
}

TEST_CASE("RequiredCalcTest2", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "2", "-", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 5);
    
}

TEST_CASE("RequiredCalcTest3", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "2", "-"
    };
    REQUIRE_THROWS( postfixCalculator(EXPRESSION) );
    
}

// You can fail this test and still get partial credit from others that pass. 
// Of course, I would recommend you get this one to pass, too...
// Note that the group name is "CalcTest" and not "Required."
TEST_CASE("AdditionalTest4", "[CalcTest]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "*", "20", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 300);
}


TEST_CASE("AdditionalTest5", "[CalcTest]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "4", "*", "2", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 40);
}

TEST_CASE("AdditionalTest6", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "-"
    };
    REQUIRE_THROWS( postfixCalculator(EXPRESSION) );
}

TEST_CASE("AdditionalTest7", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "2", "@"
    };
    REQUIRE_THROWS( postfixCalculator(EXPRESSION) );
}

TEST_CASE("AdditionalTest8", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "0", "/"
    };
    REQUIRE_THROWS( postfixCalculator(EXPRESSION) );
}

TEST_CASE("AdditionalTest9", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "0", "5", "/"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 0);
}

TEST_CASE("AdditionalTest10", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "2", "*", "*", "1", "+"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 31);
}

TEST_CASE("AdditionalTest11", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "0", "2", "*", "*", "1", "+"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 1);
}

TEST_CASE("AdditionalTest12", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "0", "+"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 5);
}

} // end namespace
