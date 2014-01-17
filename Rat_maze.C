#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 4
using namespace std;
bool Is_Safe(int M[N][N],int r,int c)
{
	if (M[r][c] == 0)
		return false;
	
	if (r < 0 || r > N-1 || c < 0 || c > N-1)
		return false;
	
	return true;
}	
bool Rat_Maze(int M[N][N],int R[N][N],int r,int c)
{
	if (r == N-1 && c == N-1)
	{
		R[N-1][N-1]=1;
		return true;
	}

	if (Is_Safe(M,r,c))
	{
		R[r][c]=1;
		
		if (Rat_Maze(M,R,r+1,c) || Rat_Maze(M,R,r,c+1))
			return true;
		
		R[r][c]=0;//Backtrack if that path is not valid
	}	
		
	return false;
}	
int main()
{
	int M[N][N]={{1,0,0,0},
	             {1,1,0,1},
		     {0,1,1,1},
		     {1,0,0,1}};
		     
	int R[N][N];
	memset(R,0,sizeof(R));
		     
	if(Rat_Maze(M,R,0,0)==true)	     
	{
		printf("Rat has successfully crossed the maze \n");
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d ",R[i][j]);
			}
			cout<<endl;
		}	
	}	
	else
	{
		printf("Rat could not reach the destination \n");
	}	
	
}		     
