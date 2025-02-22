#include<iostream>
#include<string>
using namespace std;
#define M 6
struct nut
{
	int key;
	nut *tiep;
};
typedef struct nut *Node;
void Init(Node B[])
{
	int i;
	for(int i=0; i<M; i++)
	{
		B[i]=NULL;
	}
}
int Search(Node B[], int x) 
{
	Node tam;
	tam=B[x%M];
	while(tam!=NULL)
	{
		if(tam->key==x) return 1;
		tam=tam->tiep;
	}
	return -1;
}
void Add(Node B[], int x)
{
	Node newNode, tam;
	tam=B[x%M];
	newNode=new (nut);
	newNode->key=x;
	newNode->tiep=NULL;
	if(!tam) tam=newNode;
	else
	{
		while(tam->tiep) tam=tam->tiep;
		tam->tiep=newNode;
	}
	B[x%M]=tam;
}
int main()
{
	Node B[M];
	Init(B);
	int a[100];
	int key=0;
	cout<<"Nhap vao cac phan tu cua mang (dung khi nhap -1):"<<endl;
	while(key!=-1)
	{
		cin>>key;
		Add(B,key);
	}
	int x;
	cout<<"Nhap vao gia tri can tim: ";
	cin>>x;
	if(Search(B,x)==1) cout<<"Tim thay "<<x<<" trong bang!"<<endl;
	else cout<<"Khong tim thay!"<<endl;

	return 0;
	
}