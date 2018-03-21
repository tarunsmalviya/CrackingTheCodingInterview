/*
	Assume you have a method isSubstring which checks if one word is a substring
	of another. Given two strings, s1 and s2, write code to check If s2 is a rotation of s1
	using only onecalltoisSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").
*/

#include <iostream>
#include <string.h>
using namespace std;

bool isSubstring(char*, char*);

int main() {
	char str1[50], str2[50], temp[100];
	memset(str1, 0, 50 * sizeof(char));
	memset(str2, 0, 50 * sizeof(char));
	memset(temp, 0, 100 * sizeof(char));
	
	cout<<"Enter a string(max 49 character) S1: ";
	cin>>str1;

	cout<<"Enter another string(max 49 character) S2: ";
	cin>>str2;
	
	if (strlen(str1) != strlen(str2))
	{
	    cout<<"S2 is not rotation of S1.";
	    return 0;
	}
	
	strcat(temp, str1);
	strcat(temp, str2);
	
	if (isSubstring(temp, str2))
	    cout<<"S2 is rotation of S1.";
	else
	    cout<<"S2 is not rotation of S1.";
	
	return 0;
}

bool isSubstring(char* s1, char* s2)
{
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    
    if (size1 < size2)
        return false;
    
    bool flag = false;
    
    int end = size1 - size2;
    for (int i = 0; i <= end; i++) 
    {
        bool compare = true;
        for (int j = 0; j < size2; j++) 
        {
            if (s1[i + j] != s2[j])
            {
                compare = false;
                break;
            }
        }

        if (compare)
        {
            flag = true;
            break;
        }
    }
    
    return flag;
}