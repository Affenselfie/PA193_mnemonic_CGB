#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define sizeWordMax 50

int* StringToInt(char* CheminFichier, char** listWord, int* result){
	int* j = (int*)malloc(sizeof(int));
	*j = 0;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));
	FILE* Fichier = fopen(CheminFichier, "r");
	int cpt = 0;
	for (int i = 0; i < 12; i++) {
		if (Fichier != NULL && Chaine != NULL)
		{
			char c;
			while (fscanf(Fichier, "%c", &c) != EOF)
			{
				if (c == '\n' || c == EOF) {
					Chaine[*j] = '\0';
					if (strcmp(Chaine, listWord[i]) == 0) {
						result[i] = cpt;
					}
					else cpt++;
				}
				else {
					Chaine[*j] = c;
					*j++;
				}

			}
		}
		else perror("\n\n MemoriserFicher ");
	}
	fclose(Fichier);
	free(j);
	free(Chaine);
	return result;
}


char** findWord(int* nb, char* cheminFichier, char** result) {
	int cpt, j = 0;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));

	FILE* file = NULL;
	file = fopen(cheminFichier, "r");
	if (file != NULL) {
		printf("ouverture du fichier OK\n");
	}
	 if (file != NULL && Chaine != NULL){
		for(int i = 0; i<12;i++)
		{
			fseek(file,0,SEEK_SET);
			printf("enter for\n");
			char c;
			while (fscanf(file, "%c", &c) != EOF)
			{
				if (c == '\n' || c == EOF) {
					Chaine[j] = '\0';
					j = 0;
					if (cpt == nb[i]) {
						strcpy(result[i], Chaine);
						printf("Le mot numero %d est : %s\n", cpt, result[i]);
						cpt=0;
						printf("%d",i);
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
	return result;
}
