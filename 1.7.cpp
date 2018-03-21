/*
	Write an algorithm such that if an element in an MxN matrix is 0,
	its entire row and column are set to 0.
*/

#include <iostream>
#include <string.h>
using namespace std;

#define ROW 4
#define COL 3

int MAT[ROW][COL];

void input();
void display();
void process();

int main() {
	
	input();
	display();
	process();
	display();
	
	return 0;
}

void input()
{
	cout<<"Enter value of matrix elements (row wise): ";
	for (int i = 0; i < ROW; i++) 
	{
	    for (int j = 0; j < COL; j++) 
	    {
	        cin>>MAT[i][j];
	    }
	}
}

void display()
{
    cout<<endl<<"Matrix:- "<<endl;
    
	for (int i = 0; i < ROW; i++)
	{
	    for (int j = 0; j < COL; j++)
	    {
	            cout<<MAT[i][j]<<"  ";
	    }
	    cout<<endl;
	}
}

void process()
{
    short row[ROW];
    for (int i = 0; i < ROW; i++) {
        row[i] = 0;
    }
    
    short col[COL];
    for (int i = 0; i < COL; i++) {
        col[i] = 0;
    }
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (MAT[i][j] == 0)
                row[i] = col[j] = 1;
        }
    }
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (row[i] == 1 || col[j] == 1)
                MAT[i][j] = 0;
        }
    }
}