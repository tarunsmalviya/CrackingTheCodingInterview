/*
	Implement a method to perform basic string compression using the counts
	of repeated characters. For example, the string aabcccccaaa would become
	a2blc5a3. If the "compressed" string would not become smaller than the original
	string, your method should return the original string.
*/

#include <iostream>
#include <string.h>
using namespace std;

void compress(char*, char*);

int main() {
	char str[100], buffer[100];
	memset(str, 0, 100 * sizeof(char));
	memset(buffer, 0, 100 * sizeof(char));
	
	cout<<"Enter a string(max 60 character): ";
	cin>>str;
	
	compress(str, buffer);
	cout<<endl<<buffer<<endl;
	
	return 0;
}

void compress(char* str, char* buffer)
{
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        char key = str[i];
        while (str[i] == key)
        {
            count++;
            i++;
        }
        
        i--;
        
        buffer[j] = key;
        buffer[j + 1] = (count + 48);
        j += 2;
        
        if (size < j)
        {
            memset(buffer, 0, 100 * sizeof(char));
            strcpy(buffer, str);
            return;
        }
    }
}