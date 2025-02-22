#include<iostream>
#include<string>
using namespace std;
int LinearSearch(int a[], int n, int x)
{
	for(int i=0; i<n; i++)
	{
		if(a[i]==x) return i;
	}
	return -1;
}
int BinarySearch(int a[], int left, int right, int x)
{
	if(left>right) return -1;
	else 
	{
		int mid=(left+right)/2;
		if(x==a[mid]) return mid;
		else if(x>a[mid]) BinarySearch(a,mid+1,right,x);
		else BinarySearch(a,left,mid-1,x);
	}	
}

int main()
{
	int a[100];
	int n,x;
	cout<<"Nhap vao kich thuoc mang: ";
	cin>>n;
	cout<<"\nLinearSearch:";
	cout<<"\nNhap vao cac phan tu cua mang: ";
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	cout<<"\nNhap vao phan tu can tim: ";
	cin>>x;
	if(LinearSearch(a,n,x)!=-1) cout<<"\nSo "<<x<<" o vi tri thu "<<LinearSearch(a,n,x)<<endl;
	else cout<<"\nKhong tim thay!"<<endl;
	
	cout<<"\nBinarySearch:";
	cout<<"\nNhap vao cac phan tu cua mang theo thu tu tang dan: ";
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	cout<<"\nNhap vao phan tu can tim: ";
	cin>>x;
	if(BinarySearch(a,0,n-1,x)!=-1) cout<<"\nSo "<<x<<" o vi tri thu "<<BinarySearch(a,0,n-1,x)<<endl;
	else cout<<"\nKhong tim thay!"<<endl;
	return 0;
}