
// COS30008, PS2, 2017

#include "HexBlock.h"
#include <iomanip>

using namespace std;

HexBlock::HexBlock() : fBuffer(), fSize(16)
{}                                                                          // 4/4

istream& HexBlock::read( istream& aIStream )
{
    // read next 16 bytes, must cast to (char*)
    aIStream.read( (char*)fBuffer, 16 );                                    // 3
    fSize = aIStream.gcount();                                              // 2

    return aIStream;                                                        // 1/6
}

unsigned long HexBlock::size() const
{
    return fSize;                                                           // 1/1
}

ostream& operator<<( ostream& aOStream, const HexBlock& aObject )
{
    // output hex group
    for ( long i = 0; i < aObject.fSize; i++ )                              // 3
    {
        aOStream << " " << setw(2) << setfill('0') << hex
                 << (int)aObject.fBuffer[i];                                // 5
        if ( i == 7 )
            aOStream << " |";                                               // 2
    }
    
    // output padding, if necessary
    
    if ( aObject.fSize < 8 )
        aOStream << "  ";                                                   // 3
    
    for ( long i = aObject.fSize; i < 16; i++ )
        aOStream << "   ";                                                  // 4
    
    // output original text (converted to printable characters)
    aOStream << "  ";                                                       // 2
    
    for ( long i = 0; i < aObject.fSize; i++ )                              // 3
    {
        // a simple if-then-else suffices
        aOStream << (!isgraph(aObject.fBuffer[i]) ? '.' :
                                            (char)aObject.fBuffer[i]);      // 4
    }

    
    return aOStream;                                                        // 1/27
}

// 4+6+1+27=38
