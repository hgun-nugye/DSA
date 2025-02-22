#include<iostream>
#include<string>
using namespace std;
int FirstPosNum(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		if(a[i]>0) 
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
	if(FirstPosNum(a,n)!=0) cout<<"\nSo duong dau tien la: "<<FirstPosNum(a,n)<<endl;
	else cout<<"\nKhong tim thay!"<<endl;
	
	return 0;
}