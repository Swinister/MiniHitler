
// COS30008, Problem Set 3, 2017

#include <iostream>
#include <cstdlib>

#include "FibonacciIterator.h"

using namespace std;

int main( int argc, char *argv[] )
{
    if ( argc < 2 )
    {
        cerr << "Missing argument!" << endl;
        cerr << "Usage: FibonacciIterator number" << endl;
        return 1;
    }
    
    cout << "Fibonacci sequence up to " << argv[1] << endl;
    
    FibonacciIterator lIterator( atoi( argv[1] ) );
    
    for ( long n = *lIterator; lIterator != lIterator.end(); )
    {
        cout << n << endl;
        n = *(++lIterator);
    }

    cout << "Once more:" << endl;

    FibonacciIterator lIterator2 = lIterator.begin();

    do
    {
        cout << *lIterator2++ << endl;
    } while ( lIterator2 != lIterator2.end() );

    return 0;
}
