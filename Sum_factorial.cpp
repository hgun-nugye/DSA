#include<stdio.h>

float factorial(int n)
{
	if (n==0) return 1;
	else 
	{
		return n*(n-1);
	}
}
float Sn(int n)
{
	if (n==0) return 1;
	else return factorial(n)+Sn(n-1);
}
int main()
{
	int n;
	do
	{
		printf("Nhap vao n>0: ");
		scanf("%d", &n);
	} while (n<=0);
	printf("\nDay la ket qua vua tinh: %.2f", Sn(n));
	return 0;
}