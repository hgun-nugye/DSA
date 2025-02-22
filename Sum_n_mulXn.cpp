//Dequy DSA cau 10

#include<stdio.h>

int Factorial(int n);
int xn(int n);
int main()
{
	int n;
	do
	{
		printf("Nhap vao gia tri cua n: ");
		scanf("%d", &n);
	}while(n<=0);
	
	printf("\nDay la gia tri x_n can tim: %d", xn(n));
	
}
int Factorial(int n)
{
	if(n==0) return 1;
	return n*Factorial(n-1);
}
int xn(int n)
{
	int a;
	int result=0;
	if(n==0) return 1;
	else	
		for (int i=1; i<=n;i++)
		{
			result+=(n-i+1)*xn(i-1);
		}
	return result;
}