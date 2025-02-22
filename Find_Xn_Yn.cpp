//De quy DSA cau 9
#include<stdio.h>
int X(int n);
int Y(int n);
int main()
{
	int n;
	do
	{
		printf("Nhap vao gia tri cua n: ");
		scanf("%d", &n);
	}while(n<=0);
	printf("Gia tri X_n va Y_n lan luot la: %d va %d", X(n), Y(n));
}
int X(int n)
{
	if(n==0) return 1;
	else 
	{
		return 2*X(n-1)+3*Y(n-1);
	}
}
int Y(int n)
{
	if(n==0) return 1;
	else 
	{
		return -2*Y(n-1)+3*X(n-1);
	}
}