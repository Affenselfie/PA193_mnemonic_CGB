/** PROJECT SECURE CODING BIP39

AUTHORS: DE BAILLIENCOURT Evann / HAMAILI Stéphane


**/

#include <stdlib.h>
#include <stdio.h>

#define NB_BITS 11
#define NB_SPLIT 11



int main(int argc, char** argv) {
	printf("\n\n============ PROJECT SECURE BIP39 ============\n");
	printf("Choose :\n");
	printf("(1)---> entropy to mnemonic/seed\n(2)---> mnemonic to entropy/seed\n(3)---> mnemonic/seed validation\n\n\n");


	/*int* tabDec = (int*)malloc(sizeof(int) * 11);
	memset(tabDec, 0, sizeof(tabDec));

	int* tabBin = (int*)malloc(sizeof(int) * 128);
	memset(tabBin, 0, sizeof(tabBin));

	int* cs = (int*)malloc(sizeof(int) * 7);
	memset(cs, 0, sizeof(cs));


	int** bin = (int**)malloc(sizeof(int*) * 11);
	for (int i = 0; i < 11; i++) {
		bin[i] = (int*)malloc(sizeof(int) * 11);
		memset(bin[i], 0, sizeof(bin[i]));
	}


	char* hexInput = (char*)malloc(sizeof(char) * 32);

	hexInput = "9e885d952ad362caeb4efe34a8e91bd2";

	for (unsigned int i = 0; i < strlen(hexInput); i++) {
		printf("%c", hexInput[i]);
	}
	printf("\n\n");

	tabBin = HexToBin(hexInput);

	//display(tabBin, 128);

	split(bin, tabBin, cs, 11);

	displayBin(bin, 11, 11);

	printf("\n\n");

	binArrayToDecArray(bin, 11, 11, tabDec);

	display(tabDec, 11);

	printf("\nchecksum :\t");

	display(cs, 7);

	printf("\n\n");

	unsplit(tabBin, bin, 11);

	printf("\n\n");

	binToHex(tabBin);

	setRandBin(bin, 11);
	displayBin(bin, 11,11);
	binArrayToDecArray(bin, 11, tabDec);
	display(tabDec,11);

	setRandDec(tabDec, 11);
	display(tabDec, 11);
	decArrayToBinArray(tabDec, 11, bin);
	displayBin(bin, 11,11);*/


	/*
	
	
	*/
	return 0;
}