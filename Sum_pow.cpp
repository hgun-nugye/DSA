#include<stdio.h>
#include<math.h>

float Sn(int n)
{
	if (n==1) return 1;
	else 
	{
		return pow(-1,n+1)*n+Sn(n-1);
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
	printf("\nDay la ket qua vua tinh: %.2f", Sn(n));
	return 0;
}