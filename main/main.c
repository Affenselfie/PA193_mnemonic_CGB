#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "Init.h"
#include "convNum.h"
#include "stringConv.h"


void choice1(char* hexInput){

	int* tabDec = Init(12);
	int* tabBin = Init(132);
	int** bin= InitTab(12,11);

	char *binC=(char*)malloc(sizeof(char)*132);

	char** resultChar = (char**)malloc(12 * sizeof(char*));
	for (int i = 0; i < 12; i++) {
		resultChar[i] = (char*)malloc(sizeWordMax * sizeof(char));
	}

	printf("Hex Input: ");
	for(unsigned int i=0; i<strlen(hexInput); i++){
		printf("%c",hexInput[i]);
	}
	printf("\n\n");



	printf("Convert binary : ");

	tabBin = HexToBin(hexInput);

	display(tabBin, 128);



	printf("\nConvert To String : ");

	char *tmp = (char*)malloc(sizeof(char)*2);

	for (unsigned int i = 0; i < 128; i++){
		sprintf(tmp, "%d", tabBin[i]);
		strcat(binC, tmp );
	}

	printf("%s\n", binC);


	printf("\n####hashage####");


	unsigned char *d = SHA256(binC, strlen(binC), 0);
 	
 	char** string = (char**)malloc(sizeof(char*)*32);
 	for(int i =0; i<32; i++){
 		string[i] = (char*)malloc(sizeof(char)*4);
 	}

 	printf("\nhashage : ");

	for (unsigned int i = 0; i < SHA256_DIGEST_LENGTH; i++){
		printf("%02x", d[i]);
	}
	putchar('\n');

	for (unsigned int i = 0; i < SHA256_DIGEST_LENGTH; i++){
		sprintf(string[i],"%x",d[i]);
	}

	int* h = (int*)malloc(sizeof(int)*4);

	printf("\nConvert the first Hex carac : ");

	h=HexToBinC(string[0][0]);
	printf("\n");

	display(h,4);

	printf("\nChecksum :");
	
	cpyTab(&tabBin[128], h,4);

	display(tabBin, 132);

	printf("\nSplit in 11 parts:\n");

	split(bin,tabBin,12,11);
	displayBin(bin,12,11);

	binArrayToDecArray(bin,12,11,tabDec);
	
	printf("\nDecimal Array: ");
	display(tabDec, 12);
	printf("\n");

	resultChar = findWord(tabDec,"wordlist.txt", resultChar); 


}

void choice2(char ** mnemonic){

	int ** binArray = InitTab(12,11);
	int ** hexArray = InitTab(32,4);
	int * decArray = Init(12);
	int *bin=Init(132);
	int *hexBin=Init(128);

	decArray = StringToInt("wordlist.txt",mnemonic,decArray);
	printf("\nDisplay dec : ");
	display(decArray, 12);
	printf("\nConvert to Bin :");
	decArrayToBinArray(decArray,12,binArray);
	displayBin(binArray, 12, 11);
	printf("\n\nDisplay Row :");
	unsplit(bin, binArray, 12);
	printf("\n\nRemove last 4 bits : ");
	cpyTab(hexBin,bin,128);
	display(hexBin,128);
	printf("\n\nSplit in 32 parts : ");
	split(hexArray,hexBin,32,4);
	displayBin(hexArray,32,4);
	printf("\n\nConvert To Hex : ");
	binToHex(hexBin,128);

}

int main(int argc, char** argv) {

	printf("\n\n============ PROJECT SECURE BIP39 ============\n");
	printf("Choose :\n");
	printf("(1)---> entropy to mnemonic/seed\n(2)---> mnemonic to entropy/seed\n(3)---> mnemonic/seed validation\n\n\n");

	char* hexInput= (char*)malloc(sizeof(char)*32);

	hexInput = "063679ca1b28b5cfda9c186b367e271e";

	choice1(hexInput);
	
	printf("\n\nMnemonic :\n");

	char** mnemonic = (char**)malloc(12 * sizeof(char*));
	for (int i = 0; i < 12; i++) {
		mnemonic[i] = (char*)malloc(sizeWordMax * sizeof(char));
		scanf("%s", mnemonic[i]);
	}
	choice2(mnemonic);


	return 0;
}
