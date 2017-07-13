
// COS30008, Problem Set 6, 2017

#pragma once

#include "DynamicStack.h"

template<class T>
class DynamicStackIterator
{
private:
  DynamicStack<T> fStack;

public:
  DynamicStackIterator( const DynamicStack<T>& aStack );

  const T& operator*() const;				// dereference
  DynamicStackIterator& operator++();		// prefix increment
  DynamicStackIterator operator++(int);		// postfix increment
  bool operator==( const DynamicStackIterator& aOtherIter ) const;
  bool operator!=( const DynamicStackIterator& aOtherIter ) const;

  DynamicStackIterator end() const; 		// new iterator (after last element)
};

template<class T>
DynamicStackIterator<T>::DynamicStackIterator( const DynamicStack<T>& aStack )
{
	fStack = aStack; 															// 2/2
}

template<class T>
const T& DynamicStackIterator<T>::operator*() const
{
	return fStack.top();														// 2/2
}

template<class T>
DynamicStackIterator<T>& DynamicStackIterator<T>::operator++()
{
	fStack.pop();																// 2
	return *this;																// 2/4
}

template<class T>
DynamicStackIterator<T> DynamicStackIterator<T>::operator++(int)
{
	DynamicStackIterator temp = *this;
	++(*this);
	return temp;
}

template<class T>
bool DynamicStackIterator<T>::operator==( const DynamicStackIterator& aOtherIter ) const
{
    // no need to compare elements
	return fStack.size() == aOtherIter.fStack.size();                           // 4/4
}

template<class T>
bool DynamicStackIterator<T>::operator!=( const DynamicStackIterator& aOtherIter ) const
{
	return !(*this == aOtherIter);												// 3/3
}

template<class T>
DynamicStackIterator<T> DynamicStackIterator<T>::end() const
{
	return DynamicStackIterator( DynamicStack<T>() );							// 3/3
}
