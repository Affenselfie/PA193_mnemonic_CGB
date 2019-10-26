/** PROJECT SECURE CODING BIP39

AUTHORS: DE BAILLIENCOURT Evann / HAMAILI Stéphane


**/

#include <stdlib.h>
#include <stdio.h>

#define NB_BITS 11
#define NB_SPLIT 11



int main(int argc, char** argv) {
	printf("============ PROJECT SECURE BIP39 ============\n");
	printf("Choose :\n");
	printf("(1)---> entropy to mnemonic/seed\n(2)---> mnemonic to entropy/seed\n(3)--->mnemonic/seed validation\n\n\n");

	int ret = 0;
	int ret1 = 0;

	int* tabDec = (int*)malloc(sizeof(int) * 11);

	int** bin = (int**)malloc(sizeof(int*) * 11);
	for (int i = 0; i < 11; i++) {
		bin[i] = (int*)malloc(sizeof(int) * 11);
		memset(bin[i], 0, sizeof(bin[i]));
	}

	setRandBin(bin, 11);
	displayBin(bin, 11, 11);
	binArrayToDecArray(bin, 11, tabDec);
	display(tabDec, 11);

	/*setRandDec(tabDec, 11);
	display(tabDec, 11);
	decArrayToBinArray(tabDec, 11, bin);
	displayBin(bin, 11,11);*/





	return 0;
}