#include<iostream>
#include<string>
using namespace std;
void swap(int &a, int &b)
{
	int t=a; 
	a=b; b=t;
}
void DoiVT(int a[], int n)
{
	int min=0,max=0;
	for(int i=0; i<n; i++)
	{
		if(a[i]<a[min]) min=i;
	}
	for(int i=0; i<n; i++)
	{
		if(a[i]>a[max]) max=i;
	}
	swap(a[max],a[min]);
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
	DoiVT(a,n);
	cout<<"\nMang sau khi doi vi tri phan tu nho nhat dau tien va lon nhat cuoi cung: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<"  ";
	}
	
	return 0;
}