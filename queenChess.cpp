#include <iostream>
using namespace std;
int arr[4][4];
int queenX[4]; 
int queenY[4];
int queen = 0;
bool found = false;

int queenMovesX[8] = {1,1,1,0,0,-1,-1,-1};
int queenMovesY[8] = {1,0,-1,1,-1,1,0,-1};

void print()
{
	for(int i=0;i<4;i++)
	{		
	for(int j=0;j<4;j++)
	cout<<arr[i][j]<<" ";
	cout<<endl;
	}
}

void cleanBoard()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	arr[i][j]=0;	
}

void fillBoard(int x,int y,bool fill)
{
	if(!fill) arr[x][y]=0;
	else arr[x][y]=5;
	int startX = x;
	int startY = y;
	for(int i=0;i<8;i++)
	{
		x = startX;
		y = startY;
		while(x+queenMovesX[i]<4 && x+queenMovesX[i]>=0 && y+queenMovesY[i]<4 && y+queenMovesY[i]>=0)
		{
			arr[x+queenMovesX[i]][y+queenMovesY[i]] = fill;
			x+=queenMovesX[i];
			y+=queenMovesY[i];
		}
	}
}

void go(int x,int y,int depth)
{	
	if(found) return;
	cout<<"DEPTH "<<depth<<endl;
	int lastQueenX;
	int lastQueenY;
	
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	{
		if(found) return;
		cout<<"I "<<i<<" J "<<j<<" value "<<arr[i][j]<<endl;
		if(arr[i][j]==0) 
		{
			queenX[queen] = i;
			queenY[queen] = j;
			queen++;
			lastQueenX = i;
			lastQueenY = j;
			cout<<"QueenX "<<queenX[queen-1]<<" QueenY "<<queenY[queen-1]<<endl;
			fillBoard(i,j,1);
			print();
			go(i,j,depth+1);
		}
	}
	if(queen==4)
	{
		cout<<"FOUND ANWSER!!!"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		print();
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		found = true;
		return;		
	}
	
	queen--;
	cleanBoard();
	for(int k=0;k<queen;k++)
	{
		fillBoard(queenX[k],queenY[k],1);
	}
//	cout<<"no more space left for queens"<<endl;
//	print();
//	fillBoard(lastQueenX,lastQueenY,0);
//	queen--;
//	cout<<"After Deletion"<<endl;
//	print();
//	cout<<"Printing All Queens"<<endl;
//	for(int k=0;k<queen;k++)
//	{
//	 cout<<queenX[k]<<queenY[k]<<endl;
//	 fillBoard(queenX[k],queenY[k],1);
//	}	
//	cout<<"End of Recursion"<<endl;
//	print();
}

main()
{
	go(0,0,0);
}

