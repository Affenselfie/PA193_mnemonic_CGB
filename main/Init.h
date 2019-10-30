#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <openssl/sha.h>

void setRandDec(int* decTab, size_t size);
void setRandBin(int** binTab, size_t size);
int* Init(size_t size);
int ** InitTab(size_t sizeH, size_t sizeL);