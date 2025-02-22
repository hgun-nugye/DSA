#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
const int MAX_WORDS = 100; 

int main() 
{ 
  ifstream inputFile("D:\\C_C++\\DSA\\Sort\\Tiengthu_LuuTrongLu.txt");
  if (!inputFile) 
	{
    cerr << "Khong the mo file!" << endl;
    return 1;
  }
  string line;
  string words[MAX_WORDS];
  int wordCount = 0;
  while (getline(inputFile, line)) 
	{
    stringstream ss(line);
    string word;
    while (ss >> word) 
		{
      if (wordCount < MAX_WORDS) 
			{
        words[wordCount++] = word; //Luu tu trong mang words
      }
			else 
			{
        cerr << "Vuot qua so luong ki tu toi da!" <<endl;
        break;
      }
    }
  }
	inputFile.close();

  //Sap xep lai thu tu cac tu trong mang 
    sort(words, words + wordCount);

  //Viet cac tu vua xep vao file
   ofstream outputFile("D:\\C_C++\\DSA\\Sort\\Tiengthu_LuuTrongLu_xep.txt");
  if (!outputFile) 
	{
    cerr << "Khong the mo file dang viet!" <<endl;
  	return 1;
  }
  for (int i = 0; i < wordCount; i++) 
	{
    outputFile << words[i] <<endl;
  }

  outputFile.close();
	cout << "Tu da sap xep duoc viet trong file Tiengthu_LuuTrongLu_xep.txt." <<endl;
	return 0;
}