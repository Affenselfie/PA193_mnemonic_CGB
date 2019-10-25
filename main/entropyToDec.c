//entropyToMnemonic


#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int bitToDec(int* bits, unsigned int size) {

	int ret = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (bits[(size-1)-i] == 1)
		{
			ret = ret * 2 + 1;
		}
		else{ret *= 2;}
			
	}

	return ret;
}

