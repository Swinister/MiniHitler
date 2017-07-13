
// COS30008, Problem Set 6, 2017

#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class DynamicStack
{
private:
	List<T> fElements;

public:
	bool isEmpty() const;
	int size() const;
	void push( const T& aItem );
	void pop();
	const T& top() const;
};

template<class T>
bool DynamicStack<T>::isEmpty() const
{
	return fElements.isEmpty();											// 2/2
}

template<class T>
int DynamicStack<T>::size() const
{
	return fElements.size();											// 2/2
}

template<class T>
void DynamicStack<T>::push( const T& aItem )
{
	fElements.push_front( aItem );										// 2/2
}

template<class T>
void DynamicStack<T>::pop()
{
	if ( isEmpty() )													// 2
		throw std::underflow_error( "Stack empty." );					// 1

	fElements.remove( fElements[0] );                                   // 3/6
}

template<class T>
const T& DynamicStack<T>::top() const
{
	if ( isEmpty() )													// 2
		throw std::underflow_error( "Stack empty." );					// 1

	return fElements[0];												// 2/5
}

// 2+2+2+6+5=17
