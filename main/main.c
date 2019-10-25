/** PROJECT SECURE CODING BIP39

AUTHORS: DE BAILLIENCOURT Evann / HAMAILI Stéphane


**/

#include <stdlib.h>
#include <stdio.h>



int main(int argc, char** argv) {

	printf_s("============ PROJECT SECURE BIP39 ============\n");
	printf_s("Choose :\n");
	printf_s("(1)---> entropy to mnemonic/seed\n(2)---> mnemonic to entropy/seed\n(3)--->mnemonic/seed validation\n");

	int ret = 0;
	int ret2 = 0;
	int *dec=(int*)malloc(sizeof(int)*2);
	int bit[2][11] = { {0,1,1,0,0,1,0,1,1,0,1},
					   {0,0,0,0,0,1,1,1,0,0,0} };

	ret = bitToDec(bit[0], 11);
	ret2 = bitToDec(bit[1], 11);

	printf("ret = %d\tret2 = %d", ret, ret2);
	dec = bitArrayToDecArray(bit,2);
	display(dec);


	return 0;
}