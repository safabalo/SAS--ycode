#include<stdio.h>

int main()
{
	//**Challenge 2 variables**//
	float C, F;
	printf("Veuillez entrer la temperature: ");
	scanf("%f",&C);
	F=(C*1.8)+32;
	printf("La temperature en Fahrenheit est F= %.2f", F);
	return 0;
}

