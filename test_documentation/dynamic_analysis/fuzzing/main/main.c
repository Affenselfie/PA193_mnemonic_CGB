#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <assert.h>


#include "Init.h"
#include "convNum.h"
#include "stringConv.h"
#include "fastpbkdf2.h"
#include "hashFct.h"
#include "choice.h"

void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

int main(void) {
	char *choice = (char*)malloc(sizeof(char));
	char *mnemonic = (char*)malloc(500 * sizeof(char));
	char *seed = (char*)malloc(128 * sizeof(char));
	char* entropy = (char*)malloc(130 * sizeof(char));
	char* choiceEntropy = (char*)malloc(sizeof(char));
	int* resultInt = (int*)malloc(12 * sizeof(int));
	char** resultChar = (char**)malloc(12 * sizeof(char*));
	int ch;
	for (int i = 0; i < 12; i++) {
		resultChar[i] = (char*)malloc(sizeWordMax * sizeof(char));
	}
	printf("\n\n============ PROJECT SECURE BIP39 ============\n");
	printf("What do you want to enter ? (Choose 1, 2 or 3)\n1) Entropy\n2) Mnemonic\n3) Mnemonic + seed\n");
	while (*choice != 'q') {
		fgets(choice, 2, stdin);
		ch = *choice;
		switch (ch) {
		case '1':
			viderBuffer();
			printf("\nType of entropy :\n");
			while (*choiceEntropy != 'q') {
				printf("\nChoose 1 or 2 :\n1)  hexa\nor\n2) binary\n");
				fgets(choiceEntropy, 2, stdin);
				switch (*choiceEntropy) {
				case '1':
					viderBuffer();
					printf("\nEnter entropy(32 bits):\n");
					fgets(entropy, 32, stdin);
					if(controlHexIn(entropy) == -1){break;;}
					choice1(entropy);
					break;
				case '2':
					viderBuffer();
					printf("\nEnter entropy(128 bits):\n");
					fgets(entropy, 128, stdin);
					if(controlBinIn(entropy) == -1){break;}
					choice2(entropy);
					break;
				case 'q':
					printf("exit entropy menu\n");
					break;
				default:
					printf("\n\nChoose 1 or 2 please\n");
					break;
				}
			}			
			break;
		case '2':
			viderBuffer();
			printf("\nEnter mnemonic :\n");
			char** mnemonic = (char**)malloc(12 * sizeof(char*));
			for (int i = 0; i < 12; i++) {
				mnemonic[i] = (char*)malloc(sizeWordMax * sizeof(char));
				scanf("%s", mnemonic[i]);
			}
			choice3(mnemonic);
			break;
		case '3':
			viderBuffer();
			printf("\nEnter mnemonic :\n");
			char** mnemonic4 = (char**)malloc(12 * sizeof(char*));
			for (int i = 0; i < 12; i++) {
				mnemonic4[i] = (char*)malloc(sizeWordMax * sizeof(char));
				scanf("%s", mnemonic4[i]);
			}

			printf("\nEnter seed : ");
			
			scanf("%s", seed);
			

			choice4(mnemonic4, seed);


			break;
		case 'q':
			return 0;
			break;
		default:
			printf("\nIt is not 1, 2, 3 or q to quit !\n");
		}
	}
	free(choice);
	free(mnemonic);
	free(seed);
	free(resultChar);
	free(resultInt);
	return 0;
}

