#include "include.h"

int isprime(int i)
{
	for(int j=2;j<=sqrt(i);j++)
	{
		if(i%j==0) return 0;
	}
	return 1;
}
