#include<iostream>
#include<cstring>
using namespace std;
int board[8][8];
int sum=0;
int put_queen(int row);
int print_queen(void );
int check(int row, int col)
{
	int i,j;
	for(i=0; i<row; i++)
		if(board[i][col]==1) return 0;
	for(i=row, j=col; i>=0&&j>=0; i--,j--)//左上
		if(board[i][j]==1) return 0;
	for(i=row, j=col; i>=0&&j<8; i--,j++)//右上
		if(board[i][j]==1) return 0;
	return 1;

}
int put_queen(int row)
{
	if(row == 8)
	{
		sum++;
		print_queen();
		return 0;
	}
	for(int i=0;i<8;i++)
	{
		if(check(row,i))
		{
			board[row][i] = 1;
			put_queen(row+1);
			board[row][i] = 0;
		}

	}

}
int print_queen()
{
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
	printf("--------\n");
	printf("--------\n");
	printf("--------\n");
	return 0;
}


int main(void)
{
	memset(board,0,sizeof(board));
	cout<<"hello 8 queen"<<endl;
	put_queen(0);
	printf("total solve %d\n",sum);
}
