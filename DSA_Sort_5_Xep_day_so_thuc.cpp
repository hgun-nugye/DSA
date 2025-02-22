#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Swap(float &a, float &b) {
    float t = a;
    a = b;
    b = t;
}
void SelectionSortDuongTang(float a[], int n) 
{
    for (int i = 0; i < n; i++) 
		{
    	int min = i;
      for (int j = i + 1; j < n; j++) 
			{
      if (a[i]>0 && a[j]>0 && a[j] < a[min]) min = j;
			}  
			Swap(a[i], a[min]);      
    }
}
void SelectionSortAmGiam(float a[], int n) 
{
    for (int i = 0; i < n; i++) 
		{
    		int max = i;
        for (int j = i + 1; j < n; j++) 
				{
       	 if (a[i]<0 && a[j]<0 && a[j] > a[max]) max = j;                        
        }
        Swap(a[i], a[max]);
			}        
}
int main() 
{
    float a[100];
    int n;
    FILE *fi,*fo;
    fi=fopen("D:\\C_C++\\DSA\\Sort\\xep_so.txt","r");
    if(fi==NULL)
    {
    	fprintf(stderr, "Khong the mo file\n");
   		fclose(fi);
   		return 1;
		}
		else
		{
			fscanf(fi,"%d\n",&n);
 			for(int i=0; i<n; i++)
			{
				fscanf(fi,"%f",&a[i]);			
			}
		}
		fclose(fi);
			SelectionSortDuongTang(a,n);
			SelectionSortAmGiam(a,n);			
		
		fo=fopen("D:\\C_C++\\DSA\\Sort\\da_xep_so.txt","w");
    if(fo==NULL)
    {
    	fprintf(stderr, "Khong the mo file\n");
   		fclose(fo);
   		return 1;
		}
		fprintf(fo, "%d\n",n);
 		for(int i=0; i<n; i++)
		{
			fprintf(fo,"%2.1f  ",a[i]);			
		}
		cout<<"Ket qua da duoc ghi vao file da_xep_so.txt.";
		fclose(fo);		
		return 0;
}
		