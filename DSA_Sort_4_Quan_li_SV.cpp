#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100

typedef struct 
{
    char id[20];
    char name[MAX_NAME_LENGTH];
    float avg;
} sv;
int compare(const void *a, const void *b) 
{
  sv *studentA = (sv *)a; //ep kieu con tro cau truc
  sv *studentB = (sv *)b;
  return (studentB->avg - studentA->avg) > 0 ? 1 : -1;
  //gia tri tra ve 1 thi ham qsort sap xep giam dan
}
void ReadFile(char *filename,sv *students, int *count) 
{
  FILE *file = fopen("D:\\C_C++\\DSA\\Sort\\dssv.txt", "r");
  if (file == NULL) 
	{
  	perror("Error opening file!");
    exit(EXIT_FAILURE);
  }
  while (fscanf(file, "%19[^,],%99[^,],%f\n",//doc toi da 19, 99 ki tu cho id, name (gap ',' thi ngung)
	 students[*count].id, students[*count].name, &students[*count].avg) == 3) 
	 //dieu kien==3 de dam bao 3 gia tri duoc doc thanh cong
	{
    (*count)++;
  }
	fclose(file);
}

void WriteFile(char *filename,sv *students, int *count) 
{
	FILE *file= fopen("D:\\C_C++\\DSA\\Sort\\dssv_xep.txt", "w");
  if (file == NULL) 
	{
  	perror("Error opening file!");
    exit(EXIT_FAILURE);
  }
  fprintf(file,"DSSV da xep:\n");
  for (int i = 0; i<*count; i++) 
	{
    fprintf(file,"%s %s %.2f\n",students[i].id, students[i].name, students[i].avg);
  }
  fclose(file);
}

int main() 
{
  sv students[MAX_STUDENTS];
  int count=0;
  ReadFile("D:\\C_C++\\PROGRAMING_TECHNIQUES\\TH2-FILE\\dssv.txt", students, &count);   
  qsort(students, count, sizeof(sv), compare);
  WriteFile("D:\\C_C++\\PROGRAMING_TECHNIQUES\\TH2-FILE\\dssv_xep.txt", students, &count);
  return 0;
}