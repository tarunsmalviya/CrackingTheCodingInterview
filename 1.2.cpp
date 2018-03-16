#include <iostream>
#include <string.h>
using namespace std;

void reverse(char*);

int main() {
	char str[20];
	memset(str, 0, 20 * sizeof(char));
	
	cout<<"Enter a string(max 19 character): ";
	cin>>str;
	
	reverse(str);

	cout<<"String after reversing: "<<str;
	
	return 0;
}

void reverse(char* str)
{
    int size = strlen(str);
    for (int i = 0, j = size - 1 ; i < size / 2 ; i++, j--) {
        str[i] = str[i] + str[j];
        str[j] = str[i] - str[j];
        str[i] = str[i] - str[j];
    }
}