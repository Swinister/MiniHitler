
// COS30008, Problem Set 4, 2017

#include <iostream>

#include "IFStream12Bits.h"

#include <stdexcept>											// 2

using namespace std;

void IFStream12Bits::init()
{
	fByteIndex = 0;												// 2
	fBitIndex = 8;												// 2
	fByteCount = 0;						 						// 2/6
}

void IFStream12Bits::reload()
{
	fByteIndex = 0;												// 2

	fIStream.read( fBuffer, 32 );                               // 2
	fByteCount = (int)fIStream.gcount();					    // 2/6, cast optional
}

int IFStream12Bits::readBit()
{
	int Result = 0;												// 2

	if ( fByteCount == 0 )
		reload();												// 4

	if ( eof() )
	{
		throw runtime_error( "No more bits" );					// 4
	}

	// test bit at current position
	if ( fBuffer[fByteIndex] & (1 << (fBitIndex - 1)) )			// 6
		Result = 1;												// 1

	// move bit pointer
	fBitIndex--;												// 2
	if ( fBitIndex == 0 )										// 2
	{
		fByteCount--;
		fByteIndex++;
		fBitIndex = 8;											// 4
	}

	return Result;									   			// 1/26
}

IFStream12Bits::IFStream12Bits()
{
	init();														// 2
}

IFStream12Bits::IFStream12Bits( const char* aFileName )
{
	init();														// 2
	open( aFileName );											// 2/4
}

IFStream12Bits::~IFStream12Bits()
{
	close();													// 2
}

void IFStream12Bits::open( const char* aFileName )
{
	fIStream.open( aFileName, ifstream::binary );				// 3
}

void IFStream12Bits::close()
{
	fIStream.close();											// 2
}

bool IFStream12Bits::fail()
{
	return fIStream.fail();										// 2
}

bool IFStream12Bits::eof()
{
	return fByteCount == 0;										// 2
}

IFStream12Bits& IFStream12Bits::operator>>( int& a12BitValue )
{
	a12BitValue = 0;											// 2

	for ( int i = 0; i < 12; i++ )								// 4
	{
		int lBit = readBit();									// 2

		if ( lBit == 1 )
		{
			a12BitValue = (1 << i) + a12BitValue;				// 4
		}
	}

	return *this;												// 2/14
}
                                                                // 71
