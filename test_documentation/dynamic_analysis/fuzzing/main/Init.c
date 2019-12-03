#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>



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
		for(unsigned int j=0; j< size; j++)
		{
			binTab[i][j] = rand() % 2;
		}		
	}
}



int* Init(size_t size){
	int* tab = (int*)malloc(sizeof(int)*size);
	memset(tab, 0, sizeof(tab));
	for(int i=0; i<size;i++) tab[i]=0;

	return tab;
}

int ** InitTab(size_t sizeH, size_t sizeL){

	int** tab= (int**)malloc(sizeof(int*)*sizeH);
	for(unsigned int i=0; i< sizeH; i++){
		tab[i] = Init(sizeL);
	}

	return tab;
}

int controlHexIn(char* hexInput){
	char* hexTable = (char*)malloc(sizeof(char)*22);

	int cmp=0;

	hexTable = "0123456789abcdefABCDEF";
for(unsigned int i=0; i<strlen(hexInput); i++){
		for(unsigned int j=0; j<strlen(hexTable);j++){
			if(hexInput[i] == hexTable[j]){
				cmp++;
			}
		}
	}

	if(cmp != strlen(hexInput)){
		printf("Error hex Input");
		exit(0);
		return -1;
	}

	return 0;
}

int controlBinIn(char* binInput){
	char* binTable = (char*)malloc(sizeof(char)*2);

	int cmp=0;

	binTable = "01";
for(unsigned int i=0; i<strlen(binInput); i++){
		for(unsigned int j=0; j<strlen(binTable);j++){
			if(binInput[i] == binTable[j]){
				cmp++;
			}
		}
	}

	if(cmp != strlen(binInput)){
		printf("Error bin Input");
		exit(0);
		return -1;
	}

	return 0;
}

void FreeMat(int** tab, size_t sizeH){
	for(int i =0; i<sizeH; i++){
		free(tab[i]);
	}
}
