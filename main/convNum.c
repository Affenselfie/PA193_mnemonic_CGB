#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>

void display(int* aff, size_t size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", aff[i]);
	}
	printf("\n");
}

void displayBin(int** aff, size_t sizeh, size_t sizel) {
	printf("\n");
	for (int i = 0; i < sizeh; i++) {
		for(unsigned int j=0; j< sizel; j++){
			printf("%d ", aff[i][j]);
		}
		printf("\n");
		
	}
}

int binToDec(int* bits, size_t size) {
	float puissance = 0.5;
	int ret = 0;
	for (unsigned int i = 0; i <size; i++)
	{
		ret+= bits[size-1 - i]*2*puissance;
		puissance *=2;
	}
	return ret;
}

void binArrayToDecArray(int** binArray, size_t size, size_t sizeBin, int* decArray){

	for(int i=0; i< size; i++){
		decArray[i] = binToDec(binArray[i], sizeBin);
		}

	printf("\nInitial decimal Array:");
	display(decArray,11);
	
}

void decToBin(int nbr, int* nbrBin, size_t size) {
	int tab[11], i;

	for (i = 0; nbr > 0; i++)
	{
		tab[i] = nbr % 2;
		nbr = nbr / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		nbrBin[(size-1)-i] = tab[i];
	}
}

void decArrayToBinArray(int * decArray, size_t size, int ** binArray) {
	for (unsigned int i = 0; i < size; i++) {
		decToBin(decArray[i], binArray[i],11);
	}
}

void cpyTab(int *dest, int* src, size_t size){
	for(unsigned int i=0; i<size; i++){
		dest[i] = src[i];
	}
}


int* HexToBinC(char c) 
{ 
	int* bin= (int*)malloc(sizeof(int)*4);
	memset(bin, 0, sizeof(bin));

  	int tabHex[16][4]= {
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
	{1,1,1,1}};


        switch (c) { 
	        case '0': 
	            cpyTab(bin,tabHex[0],4); 
	            break; 
	        case '1': 
	            cpyTab(bin,tabHex[1],4); 
	            break; 
	        case '2': 
	            cpyTab(bin,tabHex[2],4); 
	            break; 
	        case '3': 
	            cpyTab(bin,tabHex[3],4);  
	            break; 
	        case '4': 
	            cpyTab(bin,tabHex[4],4);  
	            break; 
	        case '5': 
	            cpyTab(bin,tabHex[5],4);  
	            break; 
	        case '6': 
	            cpyTab(bin,tabHex[6],4);  
	            break; 
	        case '7': 
	            cpyTab(bin,tabHex[7],4);  
	            break; 
	        case '8': 
	            cpyTab(bin,tabHex[8],4);  
	            break; 
	        case '9': 
	            cpyTab(bin,tabHex[9],4);  
	            break; 
	        case 'A': 
	        case 'a': 
	            cpyTab(bin,tabHex[10],4);  
	            break; 
	        case 'B': 
	        case 'b': 
	            cpyTab(bin,tabHex[11],4);  
	            break; 
	        case 'C': 
	        case 'c': 
	            cpyTab(bin,tabHex[12],4);  
	            break; 
	        case 'D': 
	        case 'd': 
	            cpyTab(bin,tabHex[13],4); 
	            break; 
	        case 'E': 
	        case 'e': 
	            cpyTab(bin,tabHex[14],4);  
	            break; 
	        case 'F': 
	        case 'f': 
	            cpyTab(bin,tabHex[15],4);  
	            break; 
	        default: 
	            printf("\nInvalid hexadecimal digit");
        }
   return bin;
}

int* HexToBin(char* hexdec) 
{ 
	int* bin= (int*)malloc(sizeof(int)*128);
	int* tmp= (int*)malloc(sizeof(int)*4);
	memset(bin, 0, sizeof(bin));

    long int i = 0;
    int  j=0;

  
    for(i = 0; i<strlen(hexdec); i++)
    {
	    tmp = HexToBinC(hexdec[i]);
	    cpyTab(&bin[j], tmp, 4);    
	    j=j+4;
    }

   return bin;
}


void split(int **dest, int* src ,size_t size, size_t sizeBits){
	unsigned int j=0;
	for(unsigned int i=0; i< size; i++){
		cpyTab(dest[i],&src[j], sizeBits);
		j +=sizeBits;
	}
	//displayBin(dest,12,11);
}

void unsplit(int* dest, int ** src, size_t size){
	unsigned int j = 0;

	for(unsigned int i=0; i<size; i++){
		cpyTab(&dest[j],src[i],11);
		j+=11;
	}
	display(dest,132);
}

void binToHex(int* bin, size_t nbChar){

	int tmp[4];

	for(unsigned int i=0; i< nbChar; i=i+4){
		cpyTab(tmp, &bin[i], 4);
		printf("%x", binToDec(tmp, 4));
	}
	printf("\n");
}
