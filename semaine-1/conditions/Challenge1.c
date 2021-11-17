#include<stdio.h>

int main()
{
	//**Challenge 1 les conditions**//
	
	printf("Affichage temperature");
	float C,F ;
	
	printf("Veuillez entrer la valeur de la Temperature");
	scanf("%f",&F);
	C= (F-32)/1.8;
	printf("la temerature en degree C est: %.2f \n", C);
	
	if (C>=30)
	{
		printf("Chaud");
	}
	else if (C<=10)
{
	printf("Tres froid");

}

else
{
	printf("Froid");
}
	
	return 0;
}
