#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 10

typedef struct{
	char Nom[12] ;
	char Prenom[12] ;
	char CIN[12];
	float Montant;
}Bank;
//***________Declaration Fichier_______***//
FILE *f;
//***___________Fonction client_________***//
void clientn() 
{
	int i, n= 3, A;
	Bank clientn[Max];
//***________Fichier Cree_______***//
	f = fopen("Donnees_clients.txt","a");
	
	if (f==NULL){
		printf("le fichier n'existe pas \n");
	}
	else
	{ //***_______Boucle de creation de donnes pour 100 clients______***//
		n<=Max;
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
	    	fprintf(f ,"Nom: %s \t", clientn[i].Nom);
			fprintf(f ,"Prenom: %s \t", clientn[i].Prenom);
			fprintf(f ,"CIN: %s \t", clientn[i].CIN);
			fprintf(f ,"Montant: %f \t", clientn[i].Montant);
			}
	}
	
	fclose(f);
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
			fprintf(f ,"Nom: %s \t", client1.Nom);
			
			fprintf(f ,"Prenom: %s \t", client1.Prenom);
			
			fprintf(f ,"CIN: %s \t", client1.CIN);
			
			fprintf(f ,"Montant: %f \t", client1.Montant); }
	fclose(f);
}


//********_____________Menu_____________**********//
void menu()
{ int Menu_Bank_X;
	printf("\t \t \t ********Menu Bank X*********** \n");
	printf("\t \t \t --------1- Nouveau clients----- \n");
	printf("\t \t \t --------2- Ajouter plusieurs clients--- \n");
	printf("\t \t \t --------3- Affichage-------------\n");
	printf("\t \t \t --------4- Quitter--------------- \n");
	printf("Entrez votre choix: \t");
	scanf("%d",&Menu_Bank_X);
	switch (Menu_Bank_X)
		{
			case 1: 
				printf("Nouveau client \n");
				client1();
				break;
			case 2: 
				printf("Ajouter plusieurs clients \n");
				clientn();
				break;
			case 3: 
				printf("Affichage \n");
				affichage();
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

//***__________Affichage_________****//
void affichage();
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
        case 2: printf("Montant descendant \n");
                descendant();
                break;
        case 3: printf("Recherche par CIN");
				Recherche();
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
    
		for(i=0;i<Max;++i){
            for(j=i+1;j=Max;++j){
                if(clientn[i].Montant<clientn[j].Montant)
                tmp= clientn[i].Montant;
               clientn[i].Montant = clientn[j].Montant;
                clientn[j].Montant= tmp;
            }
        }
    printf("\n Les Montant des Comptes Decroissant");
        

    fclose(f);
}
//***______Fonction recherche_______***//

void Recherche {
	chercher();
	afficher();
	Lister();
}
int chercher(FILE *f,int compte){  //fonction Pour chercher un compte
            Bank clientn;
            int trouve=0, ret;
            rewind(f);
            while(!trouve){
                       ret=fread(&clientn,sizeof(Bank),1,f);
                       if(ret==0)break;
                       if(clientn.CIN==compte){
                                   fseek(f,-11*sizeof(Bank),SEEK_CUR);
                                   return 1;
                       							}
            					}
            return 0;
 
}
void afficher(FILE *f){   //fonction pour montrer le compte chervher
            Bank cli;
            char compte[Max],nom[Max];
            float M,ret;
            printf("Consultation par Cin\n");
            printf("Numero du compte:");
            scanf("%d",&compte);
            ret=chercher(f,compte);
            if(ret==0){
                       printf("Compte inexistant...\n");
            }
            else{
                       fread(&cli,sizeof(Bank),1,f);
                       printf("Nom:\t%s\nPrenom:\t%s\nMontant: %.2f\n",cli.Nom,cli.Prenom,cli.Montant);
				}
}
 
void lister(FILE *f){   //fontion pour lister tous les comptes deja ajouter
            Bank cli;
            rewind(f);
            printf("listage du contenu du fichier.\n");
            printf("Nom\t\tPrenom\t\tCIN\t\tMontant\n");
            while(fread(&cli,sizeof(Bank),1,f)==1){
                       printf("%s\t\t%s\t\t%s\t\t%.2f\n",cli.Nom,cli.Prenom,cli.CIN,cli.Montant);
            }
}

//***_______Operations________***//


//***_________fonction main_______***//
int main()
{
	menu();
	
	return 0;
}
