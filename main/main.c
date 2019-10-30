#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>
#include "Init.h"
#include "convNum.h"
#include "stringConv.h"


void choice1(char* hexInput){

	int* tabDec = Init(12);
	int* tabBin = Init(128);
	int* csF = Init(11);
	int* cs = Init(7);
	int** bin= InitTab(11,11);

	char *binC=(char*)malloc(sizeof(char)*128);

	char** resultChar = (char**)malloc(12 * sizeof(char*));
	for (int i = 0; i < 12; i++) {
		resultChar[i] = (char*)malloc(sizeWordMax * sizeof(char));
	}

	printf("Hex Input: ");
	for(unsigned int i=0; i<strlen(hexInput); i++){
		printf("%c",hexInput[i]);
	}
	printf("\n\n");

	tabBin = HexToBin(hexInput);

	printf("Convert binary : ");

	display(tabBin, 128);

	printf("\nSplit in 11 cluster:\n");

	split(bin, tabBin, cs, 11);

	binArrayToDecArray(bin,11,11,tabDec);

	printf("\nInitial checksum :\t");

	display(cs,7);

	printf("\n");

	char *tmp = (char*)malloc(sizeof(char)*2);

	for (unsigned int i = 0; i < 128; i++){
		sprintf(tmp, "%d", tabBin[i]);
		strcat(binC, tmp );
	}

	printf("binC: %s\n", binC);

	unsigned char *d = SHA256(binC, strlen(binC), 0);
 	
 	char** string = (char**)malloc(sizeof(char*)*32);
 	for(int i =0; i<32; i++){
 		string[i] = (char*)malloc(sizeof(char)*4);
 	}

 	printf("\nhashage:");

	for (unsigned int i = 0; i < SHA256_DIGEST_LENGTH; i++){
		printf("%02x", d[i]);
	}
	putchar('\n');

	for (unsigned int i = 0; i < SHA256_DIGEST_LENGTH; i++){
		sprintf(string[i],"%x",d[i]);
	}

	int* h = (int*)malloc(sizeof(int)*4);

	h=HexToBinC(string[0][0]);
	printf("\n");
	cpyTab(csF, h,4);
	cpyTab(&csF[4], cs, 7);

	printf("Checksum :");

	display(csF, 11);

	tabDec[11] = binToDec(csF,11);
	printf("\nDecimal Array: ");
	display(tabDec, 12);

	resultChar = findWord(tabDec,"wordlist.txt", resultChar); 


}



int main(int argc, char** argv) {

	printf("\n\n============ PROJECT SECURE BIP39 ============\n");
	printf("Choose :\n");
	printf("(1)---> entropy to mnemonic/seed\n(2)---> mnemonic to entropy/seed\n(3)---> mnemonic/seed validation\n\n\n");

	char* hexInput= (char*)malloc(sizeof(char)*32);

	hexInput = "9e885d952ad362caeb4efe34a8e91bd2";

	choice1(hexInput);


	return 0;
}

/*
void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

void entropyChoice() {
	

	while (*ch != 'q') {

		printf("choose 1 or 2 :\n1) binary\nor\n2) hexa\n");
		fgets(choiceEntropy, 2, stdin);
		switch (*choiceEntropy) {
		case '1':
			viderBuffer();
			printf("enter entropy:\n");
			fgets(entropy, 128, stdin);
			//findWord(/*fonction qui converti binaire en entiers, cheminFichier,);
			break;
		case '2':
			viderBuffer();
			printf("enter entropy:\n");
			fgets(entropy, 32, stdin);
			//findWord(/*fonction qui converti hexa en entiers, cheminFichier);s
			break;
		default:
			printf("Choose 1 or 2 please\n");
			break;
		}
	}
	free(entropy);
	free(choiceEntropy);
}

int main(void) {
	char *choice = (char)malloc(sizeof(char) * 3);
	char *mnemonic = (char)malloc(500 * sizeof(char));
	char *seed = (char)malloc(300 * sizeof(char));
	char* entropy = (char)malloc(130 * sizeof(char));
	char* choiceEntropy = (char)malloc(sizeof(char));
	int* resultInt = (int*)malloc(12 * sizeof(int));
	char** resultChar = (char**)malloc(12 * sizeof(char*));
	for (int i = 0; i < 12; i++) {
		resultChar[i] = (char*)malloc(sizeWordMax * sizeof(char));
	}

	printf("What do you want to enter ? (Choose 1, 2 or 3)\n1) Entropy\n2) Mnemonic\n3) Mnemonic + seed\n");
	while (*ch != 'q') {
		fgets(choice, 2, stdin);
		switch (*choice) {
		case '1':
			viderBuffer();
			printf("type of entropy :\n");
			while (*ch != 'q') {

				printf("choose 1 or 2 :\n1) binary\nor\n2) hexa\n");
				fgets(choiceEntropy, 2, stdin);
				switch (*choiceEntropy) {
				case '1':
					viderBuffer();
					printf("enter entropy:\n");
					fgets(entropy, 128, stdin);
					//resultChar = findWord(/*fonction qui converti binaire en entiers*/, /*cheminFichier, result);
					break;
				case '2':
					viderBuffer();
					printf("enter entropy:\n");
					fgets(entropy, 32, stdin);
					//resultChar = findWord(/*fonction qui converti hexa en entiers*/, /*cheminFichier);s
					break;
				default:
					printf("Choose 1 or 2 please\n");
					break;
				}
			}			
			break;
		case '2':
			viderBuffer();
			printf("enter mnemonic :\n");
			fgets(mnemonic, 500, stdin);
			break;
		case '3':
			viderBuffer();
			printf("enter mnemonic :\n");
			fgets(mnemonic, 500, stdin);
			printf("enter seed");
			fgets(seed, 257, stdin);
			break;
		case 'q':
			return 0;
			break;
		default:
			printf("It is not 1, 2, 3 or q to quit !\n");
		}

	}

	free(choice);
	free(mnemonic);
	free(seed);
	free(resultChar);
	free(resultInt);

	return -1;
}*/
