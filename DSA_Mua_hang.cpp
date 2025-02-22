#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void MuaVe(int prices[],int n, int limit[], int m, int result[])
{
	sort(prices, prices+n);
	for(int i=0; i<m; i++) result[i]=0;
	for(int i=0; i<m; i++)
	{
		int j=0;
		while(j<n && prices[j]<=limit[i])
		{
			j++;
		} 
		if(j>0) 
		{
			result[i]=prices[j-1];
			for(int t=j-1; t<n;t++)
			{
				prices[t]=prices[t+1];
			}
			n--;
		}
		else result[i]=-1;
	}
}
int main()
{
	int prices[100],n, limit[100], m, result[100];
	cout<<"Nhap vao so luong mat hang: ";
	cin>>n;
	cout<<"Nhap vao cac gia tri mat hang: ";
	for(int i=0; i<n; i++)
	{
		cin>>prices[i];
	}
	cout<<"Nhap vao so luong nguoi mua: ";
	cin>>m;
	cout<<"Nhap vao cac gia tri toi da co the mua: ";
	for(int i=0; i<m; i++)
	{
		cin>>limit[i];
	}
	MuaVe(prices,n,limit,m,result);
	cout<<"\nCac gia tri toi da co the mua: ";
	for(int i=0; i<m; i++)
	{
		cout<<limit[i]<<"  ";
	}
	cout<<"\nGia moi nguoi co the mua duoc tu gia tri toi da theo thu tu la: "<<endl;
	for(int i=0; i<m; i++)
	{
		cout<<result[i]<<"  ";
	}
	
	return 0;
}