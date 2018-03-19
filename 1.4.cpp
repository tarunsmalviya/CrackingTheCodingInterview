/*
	Write a method to replace all spaces in a string with '%20'. You may assume that the
	string has sufficient space at the end of the string to hold the additional characters,
	and that you are given the "true" length of the string. (Note: if implementing in Java,
	please use a character array so that you can perform this operation in place.)
*/

#include <iostream>
#include <string.h>
using namespace std;

void replace(char*, char, char*);

int main() {
	char str[100];
	memset(str, 0, 100 * sizeof(char));
	
	cout<<"Enter a string(max 60 character): ";
	cin.getline(str, 60);
	
	replace(str, ' ', "%20");
	cout<<endl<<str<<endl;
	
	return 0;
}

void replace(char* str, char replace, char* replaceWith)
{
    int size = strlen(str);
    int newSize = size;
    int add = strlen(replaceWith) - 1;
    
    for (int i = 0; i < size; i++)
        if (str[i] == replace)
            newSize += add;
        
    str[newSize] = 0;
    newSize--;
    
    for (int i = size - 1; i >=0 ; i--) 
    {
        if (str[i] == replace)
        {
            int j = add;
            while(j >= 0)
            {
                str[newSize] = replaceWith[j];
                newSize--;
                j--;
            }
        }
        else
        {
            str[newSize] = str[i];
            newSize--;
        }
    }
}