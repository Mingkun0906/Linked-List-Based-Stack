#include "LLStack.hpp"
#include <unordered_map>
#include <string>

namespace{

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


} // end namespace
