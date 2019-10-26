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

	int tabDec[11];

	int decimal[2];
	int bit[2][11] = { {0,1,1,0,0,1,0,1,1,0,1},
					   {0,0,0,0,0,1,1,1,0,0,0} };

	int** bin = (int**)malloc(sizeof(int*) * 11);

	for (int i = 0; i < 11; i++) {
		bin[i] = (int*)malloc(sizeof(int) * 11);
	}


	setRandDec(tabDec, 11);
	display(tabDec, 11);

	//bitArrayToDecArray(bit, 2, decimal);
	decArrayToBinArray(tabDec, 11, bin);



	return 0;
}