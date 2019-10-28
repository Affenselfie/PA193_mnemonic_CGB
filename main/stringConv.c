#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define sizeWordMax 50

int* StringToInt(char* CheminFichier, char** listWord){
	int j = 0, check=0;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));
	int* result = (int*)malloc(12 * sizeof(int));
	FILE* Fichier = fopen(CheminFichier, "r");
	int cpt = 0, compteur = 0;
	for (int i = 0; i < 12; i++) {
		if (Fichier != NULL && Chaine != NULL)
		{
			char c;
			while (fscanf(Fichier, "%c", &c) != EOF)
			{
				if (c == '\n' || c == EOF) {
					Chaine[j] = '\0';
					if (strcmp(Chaine, listWord[i]) == 0) {
						result[i] = cpt;
					}
					else cpt++;
				}
				else {
					Chaine[j] = c;
					j++;
				}
			}
		}
		else perror("\n\n MemoriserFicher ");
	}
	fclose(Fichier);
	return result;
}


char** findWord(int* nb, char* cheminFichier) {
	int cpt, j = 0;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));
	char** result[12][sizeWordMax];
	FILE* file = NULL;
	file = fopen(cheminFichier, "r");
	if (file != NULL) {
		printf("ouverture du fichier OK\n");
	}
	for (int i = 0; i < 12; i++) {
		if (file != NULL && Chaine != NULL)
		{
			char c;
			while (fscanf(file, "%c", &c) != EOF)
			{
				if (c == '\n' || c == EOF) {
					Chaine[j] = '\0';
					printf("Le mot numero %d est : %s\n", cpt, Chaine);
					j = 0;
					cpt++;
					if (cpt == nb[i]) {
						result[i]=Chaine;
					}
				}
				else {
					Chaine[j] = c;
					j++;
				}
			}
		}
	}
	fclose(file);
	return result;
}