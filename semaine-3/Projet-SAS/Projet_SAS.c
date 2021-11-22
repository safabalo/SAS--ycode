#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

typedef struct{
	char Nom ;
	char Prenom ;
	char CIN ;
	float Montant;
}Bank;
//***________Declaration Fichier_______***//
FILE* f=NULL;
//***___________Fonction client_________***//
void clientn() 
{
	int i, n, A;
	Bank clientn[Max];
//***________Fichier Cree_______***//
	f = fopen("Donnees_clients.txt","w");
	
	if (f==NULL){
		printf("le fichier n'existe pas \n");
	}
	else
	{
//***_______Boucle de creation de donnes pour 100 clients______***//
		n<=Max;
		for(i=0;i<n;i++)
		{
			
			printf("Donnez les information du clients numero %d : \n", i+1);
			printf("Donner le Nom : ");
			scanf("%s",&clientn[i].Nom );
			printf("Donner le Prenom : ");
			scanf("%s",&clientn[i].Prenom );
			printf("Donner le CIN : ");
			scanf("%s",&clientn[i].CIN );
			printf("Donner le Montant: ");
			scanf("%f",&clientn[i].Montant );
		}
		
	}
	
	fclose(f);
}
//***________Fonction Nouveau Client______***//
void client1()
{
	Bank client1[Max];
	f = fopen("Donnees_clients.txt","w");
	if (f==NULL){
		printf("le fichier n'existe pas \n");
	}
	else
	{
		system ("cls");
		printf("Donnez les information de nouveau client : \n");
			printf("Donner le Nom : ");
			scanf("%s",&client1[12].Nom );
			printf("Donner le Prenom : ");
			scanf("%s",&client1[12].Prenom );
			printf("Donner le CIN : ");
			scanf("%s",&client1[12].CIN );
			printf("Donner le Montant: ");
			scanf("%f",&client1[12].Montant ); }
	fclose(f);
}
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


