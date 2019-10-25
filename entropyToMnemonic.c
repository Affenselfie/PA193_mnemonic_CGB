//entropyToMnemonic


#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int bitToDec(int* bits, int size) {

	int ret = 0;

	for (int i = 0; i < size; i++) {
		ret = ret + bits[i] * (pow(2, (size - i)));
	}

	return ret;
}

int main() {

	int ret = 0;
	int bit[11] = { 0,1,1,0,0,1,0,1,1,0,1 };
	ret = bitToDec(bit, 11);
	return 0;
}