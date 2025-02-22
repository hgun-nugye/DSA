#include<iostream>
#include<string>
using namespace std;
int FirstNegNum(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		if(a[i]<0) 
		{
			return a[i];
		}
	}
	return 0;
}

int main()
{
	int a[100];
	int n,x;
	cout<<"Nhap vao kich thuoc mang: ";
	cin>>n;
	cout<<"\nNhap vao cac phan tu cua mang: ";
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	if(FirstNegNum(a,n)!=0) cout<<"\nSo am dau tien la: "<<FirstNegNum(a,n)<<endl;
	else cout<<"\nKhong tim thay!"<<endl;
	
	return 0;
}