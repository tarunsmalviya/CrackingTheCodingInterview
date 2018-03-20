/*
	Given an image represented by an NxN matrix, where each pixel in the image is 4
	bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <string.h>
using namespace std;

#define DIMENSION 4

int MAT[DIMENSION][DIMENSION];

void input();
void display(int);
void rotate();

int main() {
	
	input();
	display(0);
	rotate();
	display(1);
	
	return 0;
}

void input()
{
	cout<<"Enter value of matrix elements (row wise): ";
	for (int i = 0; i < DIMENSION; i++) 
	{
	    for (int j = 0; j < DIMENSION; j++) 
	    {
	        cin>>MAT[i][j];
	    }
	}
}

void display(int which)
{
    if (which == 0)
        cout<<endl<<"Matrix:- "<<endl;
    else
        cout<<endl<<"Rotated Matrix:- "<<endl;
	for (int i = 0; i < DIMENSION; i++)
	{
	    for (int j = 0; j < DIMENSION; j++)
	    {
	            cout<<MAT[i][j]<<"  ";
	    }
	    cout<<endl;
	}
}

void rotate()
{
    for (int layer = 0; layer < DIMENSION / 2; layer++)
	{
	    int first = layer;
	    int last = DIMENSION - 1 - layer;
	    for (int i = first; i < last; i++)
	    {   
	        int offset = i - first;
	        int top = MAT[first][i];
	        
	        // left -> top
	        MAT[first][i] = MAT[last - offset][first];
	        
	        // bottom -> left
	        MAT[last - offset][first] = MAT[last][last - offset];
	        
	        // right -> bottom
	        MAT[last][last - offset] = MAT[i][last];
	        
	        // top - > right
	        MAT[i][last] = top;
	    }
	}
}