
// COS30008, Problem set 1, 2017

#include "Polynomial.h"

#include <cmath>

using namespace std;

double Polynomial::operator()( double aX ) const
{
	double Result = 0.0;											// 3

	for ( int i = 0; i <= fDegree; i++ )							// 5
	{
		Result += fCoeffs[i] * pow( aX,i );							// 7
	}

	return Result;													// 1/16
}

Polynomial Polynomial::buildIndefiniteIntegral() const
{
	Polynomial Result;												// 2

	Result.fDegree = fDegree + 1;									// 2

	for ( int i = fDegree; i >= 0; i-- )							// 5
	{
		Result.fCoeffs[i+1] = fCoeffs[i]/(i+1);						// 6
	}

	return Result;													// 1/16
}


double Polynomial::buildDefiniteIntegral( double aXLow, double aXHigh ) const
{
	Polynomial lTemp = buildIndefiniteIntegral();					// 4

	return lTemp( aXHigh ) - lTemp( aXLow );                        // 4/8
}
