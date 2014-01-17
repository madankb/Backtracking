/****************************************************************************************************************************************************************************************

What is Backtracking :-
                If the 8 queens has to be placed in 8*8 chess board,64C8 combinations are there to find the matching rule of queens.It is brute force method.It can be reduced by O(8*8)
                by backtracking.If we place one queen and second queen conflicts with that queen, then change the position of second queen. If all the positions of second queen conflict
                with first queen then backtrack the first queen for different posistion. By this method number of combinations would be reduced to O(8*8).

Logic :-
      Place one queen in a column and try the next queen in next column. Because placing the queen in same column conflicts the rule which is obivious.

Time complexity :-
                O(N*N) -> Chessboard size.
*****************************************************************************************************************************************************************************************/
#include<iostream>
#include<stdio.h>
#define N 8
#include<string.h>
using namespace std;
bool Is_Safe(int C[N+1][N+1],int r,int c)
{
	if (C[r][c] == 1)
		return false;
	
	for (int i=1;i<=N;i++)
	{
		if (C[r][i] == 1)
			return false;
	}
	
	for (int j=1;j<=N;j++)
	{
		if (C[j][c] == 1)
			return false;
	}
	
	//int i,j;
	for (int i=r,j=c;i>=1&&j>=1;i--,j--)//Wrong way to do int i=r,int j=c. It should be doe as int i=r,j=c
	{
		if (C[i][j] == 1)
			return false;
	}	

	for (int i=r,j=c;i<=N&&j>=1;i++,j--)//Since we are moving(increasing through the columns we can check the conflict with positions before columns not after columns.
	{
		if (C[i][j] == 1)
			return false;
	}
	
	return true;
}	
bool N_queen_Backtrack(int C[N+1][N+1],int col)
{
	if (col > N)
		return true;
	
	for (int i=1;i<=N;i++)
	{
		if (Is_Safe(C,i,col)==true)
		{
			C[i][col]=1;
			
			if(N_queen_Backtrack(C,col+1))
				return true;
			
			C[i][col]=0;//Backtrack, if that position conflicts with other queens. This is the most important step, you forget it.
		}
	}

	return false;
}	
int main()
{
	int C[N+1][N+1];
	memset(C,0,sizeof(C));
	
	if (N_queen_Backtrack(C,1))
		printf("Successfully all queens are placed \n");
	else
		printf("Conflicts exist between the queens \n");
	
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j++)
		{
			printf("%d ",C[i][j]);
		}
		cout<<endl;
	}	
}	
