#include <stdio.h>

int main()
{
	//**Challenge 1 variable**//
	
	char p[8], n[8], g[8];
	long a, t;
	
	printf("Veuillez entrer votre prenom: ");
	scanf("%s",&p);
	
	printf("Veuillez entrer votre nom: ");
	scanf("%s",&n);
	
	printf("Veuillez entrer votre age: ");
	scanf("%d",&a);
	
	printf("Veuillez entrer votre genre: ");
	scanf("%s",&g);
	
	printf("Veuillez entrer votre numero: ");
	scanf("%d",&t);
	
	printf("%s %s %d ans %s %d",p , n, a, g, t);
	
	return 0;
}
