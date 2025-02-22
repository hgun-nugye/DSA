#include <stdio.h>

double SaveMoney(int n, float a, float b, float c, float x[]) 
//n la so nam gui tien
//a la % tinh lai
//b la so tien gui ban dau
//c la tien qua tang 10 nam
{
    x[0]=b;
		float result=0;    
    if (n==0) return x[0];
    else 
		for (int i = 1; i <=n; i++) 
		{
        x[i]=SaveMoney(i-1,a,b,c,x)*(1 + a/100);
      
        if (i%10==0) x[i]+=c;
        result = x[i];
    }
    return result;
}

int main() {
    int n;
    float a, b, c, x[100];

    do {
        printf("Nhap vao so nam: ");
        scanf("%d", &n);
    } while (n < 0);

    do {
        printf("Nhap vao gia tri lai suat (%%): ");
        scanf("%f", &a);
    } while (a <= 0);

    do {
        printf("Nhap vao so tien gui ban dau: ");
        scanf("%f", &b);
    } while (b <= 0);
    
    do {
        printf("Nhap vao so tien qua tang 10 nam: ");
        scanf("%f", &c);
    } while (c <= 0);

    float futureValue = SaveMoney(n, a, b,c, x);
    printf("\nDay la gia tri Tien tiet kiem can tim: %5.3f\n", futureValue);

    return 0;
}