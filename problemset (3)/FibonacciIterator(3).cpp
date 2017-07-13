
// COS30008, Problem Set 3, 2017

#include "FibonacciIterator.h"

FibonacciIterator::FibonacciIterator( long aMaxN )
{
    fMaxN = aMaxN;                                                              // 1
    fCurrentN = 1;                                                              // 1
    fPrevious = 0;                                                              // 1
    fCurrent = 1;                                                               // 1/4
}

const long& FibonacciIterator::operator*() const
{
    return fCurrent;                                                            // 2
}

FibonacciIterator& FibonacciIterator::operator++()
{
    // following the dynamic programming approach
    
    long lNext = fCurrent + fPrevious;                                          // 3

    fPrevious = fCurrent;                                                       // 2
    fCurrent = lNext;                                                           // 2

    fCurrentN++;                                                                // 2
    
    return *this;                                                               // 1/10
}

FibonacciIterator FibonacciIterator::operator++( int )
{
    FibonacciIterator temp = *this;                                             // 2
    
    ++(*this);                                                                  // 2
    
    return temp;                                                                // 1/5
}

bool FibonacciIterator::operator==( const FibonacciIterator& aOther ) const
{
    return (fMaxN == aOther.fMaxN) && (fCurrentN == aOther.fCurrentN);          // 6
}

bool FibonacciIterator::operator!=( const FibonacciIterator& aOther) const
{
    return !(*this == aOther);                                                  // 4
}

FibonacciIterator FibonacciIterator::begin() const
{
    return FibonacciIterator( fMaxN );                                          // 6
}

FibonacciIterator FibonacciIterator::end() const
{
    FibonacciIterator temp = *this;                                             // 2

    temp.fCurrentN = fMaxN + 1;                                                 // 2
    
    return temp;                                                                // 1/5
}
