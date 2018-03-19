#include <iostream>
#include <string.h>
using namespace std;

void sort(char*);
int compare(char*, char*);

int main() {
	char str1[20], str2[20];
	memset(str1, 0, 20 * sizeof(char));
	memset(str2, 0, 20 * sizeof(char));
	
	cout<<"Enter a string(max 19 character): ";
	cin>>str1;

	cout<<"Enter another string(max 19 character): ";
	cin>>str2;
	
	if (strlen(str1) != strlen(str2))
	{
	    cout<<"Both strings are not permutation of each other.";
	    return 0;
	}
	
	sort(str1);
	sort(str2);
	
	if (compare(str1, str2))
	    cout<<endl<<"Both strings are permutation of each other.";
    else
        cout<<endl<<"Both strings are not permutation of each other.";
	
	return 0;
}

void sort(char* str)
{
    int size = strlen(str);
    for (int j = 1; j < size; j++)
    {
        char key = str[j];
        int i = j - 1;
        while (i >= 0 && key < str[i])
        {
            str[i + 1] = str[i];
            str[i] = key;
            i--;
        }
    }
    
    cout<<endl;
    for (int j = 0; j < size; j++)
        cout<<str[j]<<" ";
}

int compare(char* str1, char* str2)
{
    int flag = 1;
    int count = strlen(str1);
    for (int i = 0; i < count; i++) {
        if (str1[i] != str2[i])
        {
            flag = 0;
            break;
        }
    }
    
    return flag;
}