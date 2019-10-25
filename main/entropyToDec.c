//entropyToMnemonic


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>


void display(int* aff, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\t", aff[i]);
	}
}



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

int* bitArrayToDecArray(int bitArray[], int arraySize) {
	int* decArray = (int*)malloc(sizeof(int) * 11);

	for (int i = 0; i < arraySize; i++) {
			decArray[i] = bitToDec(bitArray[i], 11);
		
	}
	return decArray;
}

