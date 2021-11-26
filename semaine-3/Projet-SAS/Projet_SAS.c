#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
void menu();
void affichage();
void rechercher();
void operetions();
void depot();
void retrait();
void descendant();

int indice;

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

	int i, n;
	printf("Saisie le nombre de client a ajouter :  ");
	scanf("%d",&n);
//***________Fichier Cree_______***//
	f = fopen("Donnees_clients.txt","a");
	
	if (f==NULL){
		printf("le fichier n'existe pas \n");
	}
	else
	{ 
	
		
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

//********_____________Menu_____________**********//
void menu()
{ int Menu_Bank_X;
	printf("\t \t \t ********Menu Bank X*********** \n");
	printf("\t \t \t --------1--Ajouter un ou plusieurs clients--- \n");
	printf("\t \t \t --------2--Operations-------------\n");
	printf("\t \t \t --------3--Affichage-------------\n");
	printf("\t \t \t --------4--Quitter--------------- \n");
	printf("Entrez votre choix: \t");
	scanf("%d",&Menu_Bank_X);
	system("cls");
	switch (Menu_Bank_X)
		{
			case 1: 
				printf("\t \t==============Ajouter un ou plusieurs clients============== \n");
				clientns(f);
				break;
			case 2: 
				printf("\t ===========Operations============= \n");
				operetions();
				break;
				
			case 3: 
				printf("\t =============Affichage============= \n");
				affichage(f);
				break;
				

			case 4: printf("A bientot") ;
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
    
    fscanf(f,"%s %s %s %f",&clientn[i].Nom,&clientn[i].Prenom,&clientn[i].CIN,&clientn[i].Montant);
		for(i=0;i<Max;i++){
            for(j=i+1;j=Max;j++){
                if(clientn[i].Montant>clientn[j].Montant)
                tmp= clientn[i].Montant;
               clientn[i].Montant = clientn[j].Montant;
                clientn[j].Montant= tmp;
            }
        }
    printf("\n Les Montant des Comptes Croissant");
    printf("%s %s %s %f",clientn[i].Nom,clientn[i].Prenom,clientn[i].CIN,clientn[i].Montant);
	
    fclose(f);
}
//***________Descendant___________***//
void descendant()
{
    Bank clientn[Max];
    int i,j,tmp;
    printf("Tri descendant des montants");
    FILE *f = fopen("Donnees_clients.txt","r");
    
	fscanf(f,"%s %s %s %f",&clientn[i].Nom,&clientn[i].Prenom,&clientn[i].CIN,&clientn[i].Montant);
		for(i=0;i<Max-1;i++){
            for(j=0;j<Max-i-1;j++){
                if(clientn[i].Montant>clientn[j+1].Montant)
                tmp= clientn[j].Montant;
               clientn[j].Montant = clientn[j+1].Montant;
                clientn[j+1].Montant= tmp;
            }
			 printf("\n Les Montant des Comptes Decroissant/n");
			 printf("%s %s %s %f",clientn[i].Nom,clientn[i].Prenom,clientn[i].CIN,clientn[i].Montant);
        }
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
	printf("0- Retour au Menu principale \t ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: printf("Montant ascendant \n");
                ascendant();
                break;
        case 2: printf("/n Montant descendant \n");
                descendant();
                break;
        case 3: printf(" \n Recherche par CIN \n");
				rechercher();
                break;
        case 0: printf("\n Retour au Menu principale \n "); 
				menu();
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
		indice = i;
		return;	
			 }
		}
		fclose(f);
}


//***_______Operations________***//
void operetions()
{	
	int z; 
	printf("\n \t \t______1- Depot:_________\n");
	printf("\n \t \t______2- Retrait:_______ \n");
	printf("\nTapez un autre nombre pour revenir au menu principale: \n");
	scanf("%d",&z);
	system("cls");
	switch (z)
	{
		case 1: printf("********Depot***********\n");
				depot();
				break;
		case 2: printf("********Retrait***********\n");
				retrait();
				printf("\n Revenir au menu principale:");
				menu();
				break;
		default:
				menu();
				break;
	}


}
//*****__________Depot__________****//
void depot()
{
	rechercher();
	float d , x;
	printf("\n Veuillez entrer le Montant a deposer: \n");
		do{
	printf("\Le montant doit etre positive \n");
	scanf("%f",&x);
	system("cls");
	menu();}
	
	FILE *f = fopen("Donnees_clients.txt","a");

	d= clientn[indice].Montant +x;
	fprintf(f,"%f",d);
	fscanf(f,"%s %s %s %f",&clientn[indice].Nom,&clientn[indice].Prenom,&clientn[indice].CIN,&d);
	printf("%s %s %s Nouveu Montant: %f",clientn[indice].Nom,clientn[indice].Prenom,clientn[indice].CIN,d);
	fclose(f);
	
}


//*****__________Retrait__________****//
void retrait()
{
	rechercher();
	float r , u;
	printf("\n Veuillez entrer le Montant a retrait: \n");
	do{
	printf("\Le montant doit etre positive \n");
	scanf("%f",&u);
	system("cls");
	menu();}
	while(u<0);
	FILE *f = fopen("Donnees_clients.txt","a");

	r= clientn[indice].Montant-u;
	
	fprintf(f,"%f",r);
	fscanf(f,"%s %s %s %f",&clientn[indice].Nom,&clientn[indice].Prenom,&clientn[indice].CIN,&r);
	printf("%s %s %s Nouveu Montant: %f",clientn[indice].Nom,clientn[indice].Prenom,clientn[indice].CIN,r);
	fclose(f);

	
}

//***_________fonction main_______***//
int main()
{
	menu();
	
	return 0;
}
