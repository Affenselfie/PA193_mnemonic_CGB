//entropyToMnemonic


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>

#define SIZE_BITS 11
#define SIZE_ARRAY 2



void setRandDec(int* decTab, size_t size) {
	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));

	for (unsigned int i = 0; i < 11; i++) {
		decTab[i] = rand() % 2048;
	}
}

void setRandBin(int** binTab, size_t size) {
	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++)
		{
			binTab[i][j] = rand() % 2;
		}
	}
}


void display(int* aff, size_t size) {
	for (int i = 0; i < size; i++) {
		printf("|\t%d\t", aff[i]);
	}
	printf("\n");
}
void displayBin(int** aff, size_t sizeh, size_t sizel) {
	for (int i = 0; i < sizeh; i++) {
		for (unsigned int j = 0; j < sizel; j++) {
			printf("|%d", aff[i][j]);
		}
		printf("\n");

	}
}

int binToDec(int* bits, size_t size) {
	int ret = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (bits[(size - 1) - i] == 1)
		{
			ret = ret * 2 + 1;
		}
		else { ret *= 2; }
	}
	return ret;
}

void binArrayToDecArray(int** binArray, size_t size, int* decArray) {

	for (int i = 0; i < size; i++) {
		decArray[i] = binToDec(binArray[i], 11);
	}

}

int* decToBin(int nbr, int* nbrBin) {
	int tab[11], i;
	memset(tab, 0, sizeof(tab));

	for (i = 0; nbr > 0; i++)
	{
		tab[i] = nbr % 2;
		nbr = nbr / 2;
	}
	//printf("\nLe nombre binaire est = ");
	for (i = i - 1; i >= 0; i--)
	{
		nbrBin[i] = tab[i];
	}

	return nbrBin;
}

void decArrayToBinArray(int* decArray, size_t size, int** binArray) {
	for (unsigned int i = 0; i < size; i++) {
		binArray[i] = decToBin(decArray[i], binArray[i]);
	}
}
