//Recursion DSA cau 8
#include<stdio.h>
#include<math.h>
int Xn(int n);
int main()
{
	int n;
	do
	{
		printf("Nhap vao gia tri cua n: ");
		scanf("%d", &n);
	}while(n<=0);
	
	printf("\nDay la gia tri X_n can tim: %d", Xn(n));
}
int Xn(int n)
{
	if (n==0) return 0;
	else if(n==1) return 1;
	else 
	{
		return pow((Xn(n-1)+Xn(n-2)),2)+pow((Xn(n-1)-Xn(n-2)),2);
	}
}