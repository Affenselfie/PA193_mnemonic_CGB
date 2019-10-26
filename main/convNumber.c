//entropyToMnemonic


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>

#define SIZE_BITS 11
#define SIZE_ARRAY 2


void setRandDec(int* tab, size_t size) {
	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));

	for (unsigned int i = 0; i < 11; i++) {
		tab[i] = rand() % 2048;
	}
}


void display(int* aff, size_t size) {
	for (int i = 0; i < size; i++) {
		printf("|\t%d\t", aff[i]);
	}
}

int bitToDec(int* bits, size_t size) {
	int ret = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (bits[(size - 1) - i] == 1)
		{
			ret = ret * 2 + 1;
		}
		else { ret *= 2; }

		printf("\t%d\n", ret);
	}
	return ret;
}

void bitArrayToDecArray(int* tab, size_t size, int* decArray) {

	*decArray = bitToDec(tab, 11);
	printf("dec[0]= %d", *decArray);

}

int* decToBin(int nbr, int* nbrBin) {
	int tab[11], i;
	memset(tab, 0, sizeof(tab));

	for (i = 0; nbr > 0; i++)
	{
		tab[i] = nbr % 2;
		nbr = nbr / 2;
	}
	printf("\nLe nombre binaire est = ");
	for (i = i - 1; i >= 0; i--)
	{
		nbrBin[i] = tab[i];
		printf("%d", nbrBin[i]);
	}

	return nbrBin;
}

void decArrayToBinArray(int* decArray, size_t size, int** binArray) {
	for (unsigned int i = 0; i < size; i++) {
		binArray[i] = decToBin(decArray[i], binArray[i]);
	}
}