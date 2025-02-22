#include <iostream>
#include <string>
#define M 9
using namespace std;

struct Node {
    int key;
    Node *next;
};
void Init(Node *B[]) 
{
  for (int i = 0; i < M; i++) 
	{
    B[i] = nullptr; 
  }
}
int Search(Node *B[], int x) 
{
  int i = x % M;
  Node *p = B[i];
  while (p != nullptr) 
	{
    if (p->key == x) return 1;
    p = p->next;
  }
  return -1;
}
void Add(Node *B[], int x) 
{
	int i = x % M;
  Node *p = B[i];

  // If the list is empty at this index, create a new node
  if (p == nullptr) 
	{
    B[i] = new Node;
    B[i]->key = x;
    B[i]->next = nullptr;
    return;
  }
  else 
  {
  	// Find the last node in the list
  while (p->next != nullptr) p = p->next;
 
	// Create a new node and append it to the end of the list
    p->next = new Node;
    p->next->key = x;
    p->next->next = nullptr;  	
	}  
}

int main() 
{
  Node *B[M];
  Init(B);
	int key;
  cout << "Nhap vao cac phan tu cua mang (dung khi nhap -1):" << endl;
  while (true) 
	{
    cin >> key;
  	if (key == -1) break;
    Add(B, key);
  }
	int x;
  cout << "Nhap vao gia tri can tim: ";
  cin >> x;

  if (Search(B, x) == 1) cout << "Tim thay " << x << " trong bang!" << endl;
  else cout << "Khong tim thay!" << endl;
   
  return 0;
}