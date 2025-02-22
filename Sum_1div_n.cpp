#include<stdio.h>
#include<stdlib.h>
float Sn(float n)
{
	if (n==1) return 1;
	else 
	{
		return 1/n + Sn(n-1);
	}
}
int main()
{
	float n;
	do
	{
		printf("Nhap vao n>0: ");
		scanf("%f", &n);
	} while (n<=0);
	printf("\nDay la ket qua vua tinh: %.2f", Sn(n));
	return 0;
}