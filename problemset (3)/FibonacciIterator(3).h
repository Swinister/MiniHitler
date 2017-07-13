
// COS30008, Problem Set 3, 2017

#pragma once

class FibonacciIterator
{
private:
    long fMaxN;         // maximum n
    long fCurrentN;     // current n
    long fPrevious;     // previous Fibonacci number
    long fCurrent;      // current Fibonacci number
    
public:
    
    // Default constructor to set up Fibonacci sequence
    FibonacciIterator( long aMaxN );
    
    // iterator methods
    
    const long& operator*() const;              // return current Fibonacci number
    FibonacciIterator& operator++();            // prefix, next Fibonacci number
    FibonacciIterator operator++( int );        // postfix (extra unused argument)
    bool operator==( const FibonacciIterator& aOther ) const;
    bool operator!=( const FibonacciIterator& aOther) const;
    
    // auxiliaries
    FibonacciIterator begin() const;    // return new iterator positioned at n==0
    FibonacciIterator end() const;      // return new iterator positioned at n+1
};
