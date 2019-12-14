#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashFct.h"

#define sizeWordMax 50




void conv(char** tab, char* Conv){
	int j=0, cpt=0;
	for (int i=0; i< sizeof(tab); i++){
		j=0;
		while(tab[i][j] != '\n' && tab[i][j] != '\0'){
			Conv[cpt]=tab[i][j];
			j++;
			cpt++;
		}
	}
	Conv[cpt]='\0';
	//printf("\n%s", Conv);
}



int* StringToInt(char* CheminFichier, char** listWord, int* result){
	int j = 0, cpt;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));
	char** seedString = (char**)malloc(12 * sizeof(char*));
	for (int i = 0; i < 12; i++) {
		seedString[i] = (char*)malloc(sizeWordMax * sizeof(char));
	}

	char* seed = (char*)malloc(sizeof(char)*sizeWordMax*12);
	FILE* file = fopen(CheminFichier, "r");
	if(file!=NULL){
		printf("\nFile openning ok\n");

	}
	for (int i = 0; i < 12; i++) {
		if (file != NULL && Chaine != NULL)
		{
			fseek(file,0,SEEK_SET);
			cpt=0;
			char c;
			while (fscanf(file, "%c", &c) != EOF)
			{
				if (c == '\n' || c == EOF) {
					Chaine[j] = '\0';
					if (strcmp(Chaine, listWord[i]) == 0) {
						result[i] = cpt;
						strcpy(seedString[i],Chaine);
						printf("the word %s is the number : %d\n", Chaine, cpt);
					}
					else cpt++;
					j=0;
				}
				else {
					Chaine[j] = c;
					j++;
				}

			}
		}
	}
	fclose(file);
	conv(seedString,seed);
	Seed(seed, strlen(seed),"mnemonic", 8,1,64);
	free(Chaine);
	return result;
}


char** findWord(int* nb, char* cheminFichier, char** result) {
	int cpt, j = 0;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));


	FILE* file = NULL;
	file = fopen(cheminFichier, "r");
	if (file != NULL) {
		printf("File opening: OK\n");
	}
	 if (file != NULL && Chaine != NULL){
		for(int i = 0; i<12;i++)
		{
			fseek(file,0,SEEK_SET);
			char c;
			cpt = 0;
			while (fscanf(file, "%c", &c) != EOF && cpt <= nb[i])
			{
				if (c == '\n' || c == EOF) {
					Chaine[j] = '\0';
					j = 0;
					if (cpt == nb[i]) {
						strcpy(result[i], Chaine);
						printf("Word's number %d is : %s\n", cpt, result[i]);
					}
					cpt++;
				}
				else {
					Chaine[j] = c;
					j++;
				}
			}
		}
		}
	fclose(file);
	free(Chaine);
	return result;
}
