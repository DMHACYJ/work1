#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("--- ");
			}
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>");
	while (1)
	{
		printf("请输入要下棋的坐标 ：>");
		scanf("%d %d", &x, &y);
		if ((x >= 1) && (y >= 1) && (x <= 3) && (y <= 3))
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("坐标被占用，请重新输入\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
				count++;
		}
	}
	if (count == 9)
		return 1;
	else
		return 0;
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}
//int main()
//{
//	int arr[非零常量表达式]={0}
//	char arr1[] = { 'a','b','c','\0' };长度为3   0='\0'(可互换)   '0'=48
//			||注意字符串结束标志'\0'
//	char arr2[] = "abc";
//	int*p=arr;//p+i==&arr[i],*(p+i)==arr[i]
//}
//int main()
//{
//	int arr[3][4];//数组类型：int[3][4],左边为行，可以省略，右边为列，不可省略。在内存中连续存放
//	sizeof(arr)/sizeof(arr[0])//总大小除一行的大小=行数
//	sizeof(arr[0]) / sizeof(arr[0][0])//一行的大小除以一个的大小=列数
//	return 0;
//	int* p=&arr[0][0];......
//}
void menu()
{
	printf("=======================================\n");
	printf("=========      1. play      ===========\n");
	printf("=========      0. exit      ===========\n");
	printf("=======================================\n");
}
void game()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret!='C')
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else if (ret == 'Q')
		printf("平局\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("没有此选择，请重新输入");
			continue;
		}
	} while (1);
}