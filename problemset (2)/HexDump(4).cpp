
// COS30008, PS2, 2017

#include "HexDump.h"

#include <iostream>
#include <iomanip>

using namespace std;

bool HexDump::open( const std::string& aInputFileName )
{
	fInput.open( aInputFileName, ifstream::binary );                            // 3

	if ( fInput.fail() )                                                        // 2
	{
		cerr << "Cannot open input file: " << aInputFileName << endl;
		return false;                                                           // 2
	}

	return true;                                                                // 1/8
}

void HexDump::close()
{
	fInput.close();                                                             // 1/1
}

void HexDump::processInput()
{
	unsigned long lCount = 0L;                                                  // 2

	cout << uppercase; 	// looks better (optional)

    do                                                                          // 1
	{
        // fetch next data block
        fData.read( fInput );                                                   // 2

        // no more data
        if ( fData.size() == 0 )
			break;                                                              // 2

        // output counter (increment by 16)
		cout << setw(8) << setfill('0') << hex << lCount << ": ";               // 5
        
        // output hex data block
        cout << fData << endl;                                                  // 3

        lCount += 16L;                                                          // 1

        // stop if read less than 16 bytes
    } while ( fData.size() == 16 );                                             // 3/19
}

bool HexDump::operator()( const std::string& aInputFileName )
{
    if ( open( aInputFileName ) )                                               // 3
    {
        processInput();
        
        close();
        
        return true;                                                            // 3
    }
   
    return false;                                                               // 1/7
}

// 8+1+19+7=35
