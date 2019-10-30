#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			//findWord(/*fonction qui converti binaire en entiers*/, /*cheminFichier*/,);
			break;
		case '2':
			viderBuffer();
			printf("enter entropy:\n");
			fgets(entropy, 32, stdin);
			//findWord(/*fonction qui converti hexa en entiers*/, /*cheminFichier*/);s
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
					//resultChar = findWord(/*fonction qui converti binaire en entiers*/, /*cheminFichier*/, result);
					break;
				case '2':
					viderBuffer();
					printf("enter entropy:\n");
					fgets(entropy, 32, stdin);
					//resultChar = findWord(/*fonction qui converti hexa en entiers*/, /*cheminFichier*/);s
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
}