#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include "runtimeexcept.hpp"

class StackEmptyException : public RuntimeException 
{
public:
	StackEmptyException(const std::string & err) : RuntimeException(err) {}
};

template<typename Object>
class LLStack
{
private:
	struct Node
	{
		Object data;
		Node * next;
	};
	Node * head;
	Node * tail;
	size_t stackSize;

public:

	// constructor
	LLStack();

	// copy constructor
	LLStack(const LLStack & st);

	// assignment operator
	LLStack & operator=(const LLStack & st);

	// destructor
	~LLStack();

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	Object & top();
	const Object & top() const;

	void push(const Object & elem) noexcept;
	void pop();
};

template <typename Object>
LLStack<Object>::LLStack()
{
	head = nullptr;
	tail = nullptr;
	stackSize = 0;
}

template <typename Object>
LLStack<Object>::LLStack(const LLStack & st)
{
	head = nullptr;
	tail = nullptr;
	stackSize = 0;
	LLStack<Object> tempStack;

	Node * current = st.head;
    while(current != nullptr)
    {
        tempStack.push(current->data);
        current = current->next;
    }

	while (tempStack.isEmpty() != true)
	{
		this->push(tempStack.top());
		tempStack.pop();
	}
}

template <typename Object>
LLStack<Object> & LLStack<Object>::operator=(const LLStack & st)
{
	while(head != nullptr)
	{
		Node * temp = head;
		head = head->next;
		delete temp;
		--stackSize;
	}

	LLStack<Object> tempStack;
	Node * current = st.head;
    while(current != nullptr)
    {
        tempStack.push(current->data);
        current = current->next;
    }

	while (tempStack.isEmpty() != true)
	{
		this->push(tempStack.top());
		tempStack.pop();
	}

	return *this;
}

template <typename Object>
LLStack<Object>::~LLStack()
{
	while(head != nullptr)
	{
		Node * temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename Object>
size_t LLStack<Object>::size() const noexcept
{
	return stackSize;
}

template <typename Object>
bool LLStack<Object>::isEmpty() const noexcept
{
	if (stackSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Object>
Object& LLStack<Object>::top()
{
	if (isEmpty() == true)
	{
		throw StackEmptyException("Top operation is not allowed for an empty stack");
	}
	else
	{
		return head->data;
	}
}

template <typename Object>
const Object& LLStack<Object>::top() const
{
	if (isEmpty() == true)
	{
		throw StackEmptyException("Top operation is not allowed for an empty stack");
	}
	else
	{
		return head->data;
	}
	
}

template <typename Object>
void LLStack<Object>::push(const Object& elem) noexcept
{
	Node * newNode = new Node();
	newNode->data = elem;
	newNode->next = head;
	head = newNode;
	if (tail == nullptr)
	{
		tail = newNode;
	}
	++stackSize;
}

template <typename Object>
void LLStack<Object>::pop()
{
	if (this->isEmpty() == true)
	{
		throw StackEmptyException("Pop operation is not allowed for an empty stack");
	}
	else
	{
		Node * temp = head;
		head = head->next;
		delete temp;
		--stackSize;
	}
}

#endif 
