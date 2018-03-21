/*
	Implement an algorithm to determine if a string has all unique characters.
	What if you cannot use additional data structures?
*/

#include <iostream>
#include <string.h>
using namespace std;

#define ROW 4
#define COL 3

int MAT[ROW][COL];

bool containAllUniqueChar(char*);

int main() {
	
	char str[100];
	memset(str, 0, 100 * sizeof(char));
	
	cout<<"Enter a string(max 99 character): ";
	cin.getline(str, 99);

	if (containAllUniqueChar(str))
	    cout<<endl<<"String contain all unique characters.";
    else
        cout<<endl<<"String does not contain all unique characters.";
	
	return 0;
}

bool containAllUniqueChar(char* str)
{
	bool flag = true;
	
	int size = strlen(str);
	if (size > 256) {
		flag = false;
	} else {
		unsigned char character[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, };
		for (int i = 0; i < size; i++) {
			int value = str[i];
			int index = value / 8;
			int bit = value % 8;
			
			if ((character[index] & (1 << bit)) > 0) {
				flag = false;
				break;
			} else
				character[index] = (character[index] | (1 << bit));
		}
	}
	
	return flag;
}