#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>

void display(int* aff, size_t size);
void displayBin(int** aff, size_t sizeh, size_t sizel);
int binToDec(int* bits, size_t size);
void binArrayToDecArray(int** binArray, size_t size, size_t sizeBin, int* decArray);
int* decToBin(int nbr, int* nbrBin);
void decArrayToBinArray(int * decArray, size_t size, int ** binArray);
void cpyTab(int *dest, int* src, size_t size);
int* HexToBinC(char c);
int* HexToBin(char* hexdec);
void split(int **dest, int* src, int* cs,size_t size);
void unsplit(int* dest, int ** src, size_t size);
void binToHex(int* bin, size_t nbChar);