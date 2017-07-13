
// COS30008, Tutorial 6, 2017

#include "OFStream12Bits.h"
#include "IFStream12Bits.h"

#include <iostream>

using namespace std;

void write4096()
{
	cout << "Write 4096 codes" << endl;

	OFStream12Bits lWriter( "sample.lzw" );

	if ( lWriter.fail() )
	{
		cerr << "Error: Unable to open output file!" << endl;
		exit( 1 );
	}

	for ( int i = 4095; i >= 0; i-- )
	{
		lWriter << i;
	}
}

int main()
{
	write4096();

	cout << "SUCCESS" << endl;

	return 0;
}
