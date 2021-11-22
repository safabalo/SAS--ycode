#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//********_____________Menu_____________**********//
void menu()
{ int Menu_Bank_X;
	printf("*****Menu Bank X*********\n");
	printf("1- Nouveau clients \n");
	printf("2- Ajouter plusieurs clients \n");
	printf("3- Affichage \n");
	printf("4- Quitter \n") ;
	printf("Entrez votre choix: \t");
	scanf("%d",&Menu_Bank_X);
	switch (Menu_Bank_X)
		{
			case 1: printf("Nouveau client \n");
					break;
			case 2: printf("Ajouter plusieurs clients \n");
					break;
			case 3: printf("Affichage \n");
					break;
			case 4: printf("Quitter \n") ;
					break;
			default: printf("Eureur de saisie \n");
					break;		
		}
}
//***fonction main______***//
int main()
{
	menu();
	
	return 0;
}


