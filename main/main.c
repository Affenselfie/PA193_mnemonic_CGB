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
	int bit[11] = { 0,1,1,0,0,1,0,1,1,0,1 };
	ret = bitToDec(bit, 11);
	printf("%d", ret);
	return 0;
}