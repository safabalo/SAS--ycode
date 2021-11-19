#include<stdio.h>

int main()
{
	//**Challenge 1 les fonctions**//
	int a, b;
	printf("Entrez la valeur de A: ");
	scanf("%d",&a);
	printf("Entrez la valeur de B: ");
	scanf("%d",&b);
	echanger(a,b);

}
void echanger(int a,int b)
{
	int c=a;
	a=b;
	b=c;
	printf("La valeur de A est = %d \t",a);
	printf("La valeur de B est = %d",b);
}
