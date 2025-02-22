#include<stdio.h>

int UCLN(int x, int y)
{
	if (y==0) return x;
	return UCLN(y, x%y); 
}
int BCNN(int x, int y)
{
	return x*y/UCLN(x,y);
}
int main()
{
	int x,y;
	do
	{
		printf("Nhap vao gia tri cua x va y: ");
		scanf("%d%d", &x,&y);
	}
	while (x<=0||y<=0);
	printf("Uoc chung lon nhat cua %d va %d la: %d",x,y, UCLN(x,y));
	printf("\nBoi chung nho nhat cua %d va %d la: %d",x,y, BCNN(x,y));
	return 0;
}