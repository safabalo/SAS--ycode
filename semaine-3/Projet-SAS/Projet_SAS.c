#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
void menu();
void affichage();
void rechercher();

typedef struct{
	char Nom[12] ;
	char Prenom[12] ;
	char CIN[12];
	float Montant;
}Bank;
Bank clientn[Max];
//***________Declaration Fichier_______***//
FILE *f;
//***___________Fonction client_________***//
void clientns() 
{

	int i, n= 3;
//***________Fichier Cree_______***//
	f = fopen("Donnees_clients.txt","a");
	
	if (f==NULL){
		printf("le fichier n'existe pas \n");
	}
	else
	{ //***_______Boucle de creation de donnes pour 3 clients______***//
	
		
		for(i=0;i<n;i++)
		{
			
			printf("Donnez les information du clients numero %d : \n", i+1);
			printf("Donner le Nom : ");
			scanf("%s",clientn[i].Nom );
		
			printf("Donner le Prenom : ");
			scanf("%s",clientn[i].Prenom );
		
			printf("Donner le CIN : ");
			scanf("%s",clientn[i].CIN );
		
			printf("Donner le Montant: ");
			scanf("%f",&clientn[i].Montant );
		
		}
		for(i=0;i<n;i++)
		{
	    	fprintf(f , "%s \t", clientn[i].Nom);
			fprintf(f ,"%s \t", clientn[i].Prenom);
			fprintf(f ,"%s \t", clientn[i].CIN);
			fprintf(f ," %.2f \t", clientn[i].Montant);
			fprintf(f,"\n");
			
		}
		
	}
	
	fclose(f);
	system("cls");
	menu();
}
//***________Fonction Nouveau Client______***//
void client1()
{
	Bank client1;
	f = fopen("Donnees_clients.txt","a");
	if (f==NULL){
		printf("le fichier n'existe pas \n");
	}
	else
	{ 	system ("cls");
		printf("Donnez les information de nouveau client : \n");
			
			printf("Donner le Nom : ");
			scanf("%s",client1.Nom );
			printf("Donner le Prenom : ");
			scanf("%s",client1.Prenom );
			printf("Donner le CIN : ");
			scanf("%s",client1.CIN );
			printf("Donner le Montant: ");
			scanf("%f",&client1.Montant );
			fprintf(f ,"%s \t", client1.Nom);
			
			fprintf(f ,"%s \t", client1.Prenom);
			
			fprintf(f ,"%s \t", client1.CIN);
			
			fprintf(f ,"%.2f \t", client1.Montant); 
			fprintf(f,"\n"); }
		
	fclose(f);
	system("cls");
	menu();
}


//********_____________Menu_____________**********//
void menu()
{ int Menu_Bank_X;
	printf("\t \t \t ********Menu Bank X*********** \n");
	printf("\t \t \t --------1--Nouveau clients----- \n");
	printf("\t \t \t --------2--Ajouter plusieurs clients--- \n");
	printf("\t \t \t --------3--Affichage-------------\n");
	printf("\t \t \t --------4--Operations-------------\n");
	printf("\t \t \t --------5--Quitter--------------- \n");
	printf("Entrez votre choix: \t");
	scanf("%d",&Menu_Bank_X);
	switch (Menu_Bank_X)
		{
			case 1: 
				printf("Nouveau client \n");
				client1(f);
				break;
			case 2: 
				printf("Ajouter plusieurs clients \n");
				clientns(f);
				break;
			case 3: 
				printf("Affichage \n");
				affichage(f);
				break;
			case 4: 
				printf("Operations \n");
				break;
			case 5: 
				printf("Quitter \n") ;
				break;
			default: 
				printf("Eureur de saisie \n");
				break;		
		}
}
//***___________Ascendant__________***//
void ascendant()
{
     Bank clientn[Max];
    int i,j,tmp;
    printf("Tri ascendant des montants");
    f = fopen("Donnees_clients.txt","r");
    
		for(i=0;i<Max;i++){
            for(j=i+1;j=Max;j++){
                if(clientn[i].Montant>clientn[j].Montant)
                tmp= clientn[i].Montant;
               clientn[i].Montant = clientn[j].Montant;
                clientn[j].Montant= tmp;
            }
        }
    printf("\n Les Montant des Comptes Croissant");
        
	
    fclose(f);
}
//***________Descendant___________***//
void descendant()
{
    Bank clientn[Max];
    int i,j,tmp;
    printf("Tri descendant des montants");
    f = fopen("Donnees_clients.txt","r");
    
		for(i=0;i<Max-1;i++){
            for(j=0;j<Max-i-1;j++){
                if(clientn[i].Montant>clientn[j+1].Montant)
                tmp= clientn[j].Montant;
               clientn[j].Montant = clientn[j+1].Montant;
                clientn[j+1].Montant= tmp;
            }
        }
    printf("\n Les Montant des Comptes Decroissant");
	// fgets("Nom, Prenom, CIN, Montant %s,%s,%s,%.2f");
	fclose(f);
}

//***__________Affichage_________****//
void affichage()
{
    printf("Veuillez effectuer un choix \n");
    int c ;
    printf("1- Les montant des comptes ascendant \t");
    printf("2- Les montant des comptes descendant \t");
	printf("3- Recherche par CIN \t");
    scanf("%d",&c);
    switch(c)
    {
        case 1: printf("Montant ascendant \n");
                ascendant();
                break;
        case 2: printf("/n Montant descendant \n");
                descendant();
                break;
        case 3: printf(" /n Recherche par CIN /n");
				rechercher();
                break;
    }
    
}

//***______Fonction recherche_______***//
void rechercher()
{

	int i;
    char B[20];

	FILE *f = fopen("Donnees_clients.txt","r");
	
	if (f==NULL)
		printf("le fichier n'existe pas \n");
	else
	{ 
		printf("Entrez le CIN: \n");
		scanf("%s",&B);
	}
		
		
		for(i=0;i<Max;i++)
		{ 
			
			fscanf(f,"%s\t%s\t%s\t%f",&clientn[i].Nom,&clientn[i].Prenom,&clientn[i].CIN,&clientn[i].Montant);
			if(strcmp(clientn[i].CIN,B)==0)
			{ 	
			
		printf("%s \t %s \t %s \t %f",clientn[i].Nom,clientn[i].Prenom,clientn[i].CIN,clientn[i].Montant);
		fclose(f);
		return;	
			 }
		}
		fclose(f);
}


//***_______Operations________***//


//***_________fonction main_______***//
int main()
{
	menu();
	
	return 0;
}
