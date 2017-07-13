
// COS30008, Problem Set 6, 2017

#include "DynamicQueue.h"

template<class T>
class DynamicQueueIterator
{
private:
  DynamicQueue<T> fQueue;

public:
  DynamicQueueIterator( const DynamicQueue<T>& aQueue );

  const T& operator*();						// dereference
  DynamicQueueIterator& operator++();		// prefix increment
  DynamicQueueIterator operator++(int);		// postfix increment
  bool operator==( const DynamicQueueIterator& aOtherIter ) const;
  bool operator!=( const DynamicQueueIterator& aOtherIter ) const;

  DynamicQueueIterator end() const; 		// new iterator (after last element)
};

template<class T>
DynamicQueueIterator<T>::DynamicQueueIterator( const DynamicQueue<T>& aQueue )
{
	fQueue = aQueue; 															// 2/2
}

template<class T>
const T& DynamicQueueIterator<T>::operator*()
{
	return fQueue.top();                                                        // 2/2
}

template<class T>
DynamicQueueIterator<T>& DynamicQueueIterator<T>::operator++()
{
    fQueue.dequeue();                                                           // 2
	return *this;																// 2/4
}

template<class T>
DynamicQueueIterator<T> DynamicQueueIterator<T>::operator++(int)
{
	DynamicQueueIterator temp = *this;
    ++(*this);
	return temp;
}

template<class T>
bool DynamicQueueIterator<T>::operator==( const DynamicQueueIterator& aOtherIter ) const
{
	return fQueue.size() == aOtherIter.fQueue.size();							// 4/4
}

template<class T>
bool DynamicQueueIterator<T>::operator!=( const DynamicQueueIterator& aOtherIter ) const
{
	return !(*this == aOtherIter);												// 3/3
}

template<class T>
DynamicQueueIterator<T> DynamicQueueIterator<T>::end() const
{
	return DynamicQueueIterator( DynamicQueue<T>() );							// 3/3
}

// 2+2+4+4+3+3=18
