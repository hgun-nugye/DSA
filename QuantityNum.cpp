#include<stdio.h>

int Dem(int n)
{
	if (n==0) return 0;
	else 
	{
		return 1+Dem(n/10);
	}
}
int main()
{
	int n;
	do
	{
		printf("Nhap vao n>0: ");
		scanf("%d", &n);
	} while (n<=0);
	printf("\nSo chu so cua so vua nhap la: %d", Dem(n));
	return 0;
}