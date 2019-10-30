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

void entropyChoice (){
    char ch;
    char entropy[130];
    char *choiceEntropy=(char*)malloc(sizeof(char));

    while(ch!='q'){
    
    printf("choose 1 or 2 :\n1) binary\nor\n2) hexa\n");
    fgets(choiceEntropy, 2, stdin);
    ch = *choiceEntropy;
    switch(ch){
    case '1':
        viderBuffer();
        printf("enter entropy:\n");
        fgets(entropy,128,stdin);
        break;
    case '2':
        viderBuffer();
        printf("enter entropy:\n");
        fgets(entropy,32,stdin);
        break;
    default:
        printf("Choose 1 or 2 please\n");
        break;
    }
    }
}

int main(void){
    char *choice=(char*)malloc(sizeof(char)*3);
    char ch;
    char mnemonic[500];
    char seed[257];

    printf("What do you want to enter ? (Choose 1, 2 or 3)\n1) Entropy\n2) Mnemonic\n3) Mnemonic + seed\n");
    while (ch != 'q'){
    fgets(choice, 2, stdin);
    ch = *choice;

    switch(ch){
    case '1':
        viderBuffer();
        printf("type of entropy :\n");
        entropyChoice();
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
        fgets(seed,257 ,stdin);
        break;
    case 'q':
        return 0;
        break;
    default:
        printf("It is not 1, 2, 3 or q to quit !\n");
    }
    
    }
}
