#include<stdio.h>

int main()
{
	//**Challenge 1 les boucles**//
	int b, i;
	printf("Veuillez entrer un nombre: ");
	scanf("%d",&b);
	for (i=1;i<=10;i++)
	{
		printf("%d*%d = %d \n",b ,i ,b*i );
	}
	
	return 0;
}
