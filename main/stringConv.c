#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define sizeWordMax 50




int compare(char* tab, char* word) {
	int i = 0, cpt = 0;
	printf("debut processus\n");


	if (strcmp(word, tab) == 0) {
		printf("strcmp OK\n");
		return 1;
	}
	else {
		printf("strcmp not ok\n");
		return 0;
	}
}



int* LongueurFichier(char* CheminFichier)
{
	FILE* Fichier = fopen(CheminFichier, "r");
	int* Longueur = (int*)malloc(sizeof(int));
	Longueur = 0;
	char c;

	if (Fichier != NULL)
	{
		while (fscanf(Fichier, "%c", &c) != EOF)
		{
			*Longueur++;
		}
	}

	fclose(Fichier);
	return Longueur;
}

int StringToInt(char* CheminFichier, char* Chaine, int check, char* word)
{
	int j = 0;
	FILE* Fichier = fopen(CheminFichier, "r");
	int cpt = 0, compteur = 0;
	if (Fichier != NULL && Chaine != NULL)
	{
		char c;
		while (fscanf(Fichier, "%c", &c) != EOF)
		{
			if (c == '\n' || c == EOF) {
				Chaine[j] = '\0';
				printf("debut compare numero %d : %s\n", cpt, Chaine);
				check = compare(Chaine, word);
				if (check == 1) {
					compteur = cpt;
				}
				printf("check : %d\n", check);
				j = 0;
				cpt++;
			}
			else {
				Chaine[j] = c;
				j++;
			}
			printf("%c\n", c);
		}
		Chaine[j] = '\0';
		printf("debut compare numero %d : %s\n", cpt, Chaine);
		check = compare(Chaine, word);
		if (check == 1) {
			compteur = cpt;
		}
		printf("check : %d\n", check);
	}

	else perror("\n\n MemoriserFicher ");

	fclose(Fichier);
	return compteur;
}


char* findWord(int nb) {
	int cpt, j = 0;
	char* Chaine = (char*)malloc(sizeWordMax * sizeof(char));
	FILE* file = NULL;
	file = fopen("C:/Users/Stéphane/Documents/wordlist.txt", "r");
	if (file != NULL) {
		printf("ouverture du fichier OK\n");
	}
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
				if (cpt == nb) {
					return Chaine;
				}
			}
			else {
				Chaine[j] = c;
				j++;
			}
		}
	}
	return -1;
}

void menuFindWorld() {
	int nombre;
	printf("Combien de valeur ?\n");
	scanf("%d", nombre);
	int* tab = (int*)malloc(nombre * sizeof(int));
	printf("\nveuillez choisir les valeurs :\n");
	for (int i = 0; i < nombre; i++) {
		scanf("%d", tab[i]);
	}
	char** result[nombre][sizeWordMax];
	for (int i = 0; i < nombre; i++) {
		*result[i] = findWord(tab[i]);
		printf("%s", result[i]);
	}
}

void menuStringToInt(int nb, int longueur, char** argv) {
	int* tab = (int*)malloc(nb * sizeof(int));
	int check = (int)malloc(sizeof(int));
	int compteur = (int)malloc(sizeof(int));
	compteur = NULL;
	char* chaine = (char*)malloc(longueur * sizeof(char));
	for (int k = 0; k < nb; k++) {
		tab[k] = StringToInt("C:/Users/Stéphane/Documents/wordlist.txt", chaine, check, argv[k]);
		if (tab[k] != NULL) {
			printf("%d", tab[k]);
		}
		else {
			printf("Le mot ne fait pas parti de la liste");
		}
	}
}

int main(int argc, char** argv) {
	//initialisation variable
	int a = NULL, j = 0;
	int* longueur = (int*)malloc(sizeof(int));
	int choice = 0;
	*longueur = LongueurFichier("C:/Users/Stéphane/Documents/wordlist.txt");
	printf("%d\n", longueur);

	switch (choice) {
	case (1):
		menuFindWorld();
		break;
	case(2):
		menuStringToInt(argc, longueur, argv);
		break;
	}

	return 0;
}
