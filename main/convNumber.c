//entropyToMnemonic


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>


#define SIZE_BITS 11


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
		printf("|%d", aff[i]);
	}
	printf("\n");
}

void displayBin(int** aff, size_t sizeh, size_t sizel) {
	printf("\n");
	for (int i = 0; i < sizeh; i++) {
		for (unsigned int j = 0; j < sizel; j++) {
			printf("|%d", aff[i][j]);
		}
		printf("\n");

	}
}

int binToDec(int* bits, size_t size) {
	float puissance = 0.5;
	int ret = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		ret += bits[size - 1 - i] * 2 * puissance;
		puissance *= 2;
	}
	return ret;
}

void binArrayToDecArray(int** binArray, size_t size, size_t sizeBin, int* decArray) {

	for (int i = 0; i < size; i++) {
		decArray[i] = binToDec(binArray[i], sizeBin);
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

void cpyTab(int* dest, int* src, size_t size) {
	for (unsigned int i = 0; i < size; i++) {
		dest[i] = src[i];
	}
}

int* HexToBin(char* hexdec)
{
	int* bin = (int*)malloc(sizeof(int) * 128);
	memset(bin, 0, sizeof(bin));

	int tabHex[16][4] = {
	{0,0,0,0},
	{0,0,0,1},
	{0,0,1,0},
	{0,0,1,1},
	{0,1,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,1,1,1},
	{1,0,0,0},
	{1,0,0,1},
	{1,0,1,0},
	{1,0,1,1},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,0},
	{1,1,1,1} };

	long int i = 0;
	int  j = 0;


	for (i = 0; i < strlen(hexdec); i++)
	{

		switch (hexdec[i]) {
		case '0':
			cpyTab(&bin[j], tabHex[0], 4);
			break;
		case '1':
			cpyTab(&bin[j], tabHex[1], 4);
			break;
		case '2':
			cpyTab(&bin[j], tabHex[2], 4);
			break;
		case '3':
			cpyTab(&bin[j], tabHex[3], 4);
			break;
		case '4':
			cpyTab(&bin[j], tabHex[4], 4);
			break;
		case '5':
			cpyTab(&bin[j], tabHex[5], 4);
			break;
		case '6':
			cpyTab(&bin[j], tabHex[6], 4);
			break;
		case '7':
			cpyTab(&bin[j], tabHex[7], 4);
			break;
		case '8':
			cpyTab(&bin[j], tabHex[8], 4);
			break;
		case '9':
			cpyTab(&bin[j], tabHex[9], 4);
			break;
		case 'A':
		case 'a':
			cpyTab(&bin[j], tabHex[10], 4);
			break;
		case 'B':
		case 'b':
			cpyTab(&bin[j], tabHex[11], 4);
			break;
		case 'C':
		case 'c':
			cpyTab(&bin[j], tabHex[12], 4);
			break;
		case 'D':
		case 'd':
			cpyTab(&bin[j], tabHex[13], 4);
			break;
		case 'E':
		case 'e':
			cpyTab(&bin[j], tabHex[14], 4);
			break;
		case 'F':
		case 'f':
			cpyTab(&bin[j], tabHex[15], 4);
			break;
		default:
			printf("\nInvalid hexadecimal digit");
		}
		j = j + 4;
	}

	return bin;
}

void split(int** dest, int* src, int* cs, size_t size) {
	unsigned int j = 0;
	for (unsigned int i = 0; i < size; i++) {
		cpyTab(dest[i], &src[j], 11);
		j += 11;
	}
	cpyTab(cs, &src[j], 7);
}

void unsplit(int* dest, int** src, size_t size) {
	unsigned int j = 0;

	for (unsigned int i = 0; i < size; i++) {
		cpyTab(&dest[j], src[i], size);
		j += size;
	}
	display(dest, 128);
}

void binToHex(int* bin) {

	int tmp[4];

	for (unsigned int i = 0; i < 128; i = i + 4) {
		cpyTab(tmp, &bin[i], 4);
		printf("%x", binToDec(tmp, 4));
	}
	printf("\n");
}


