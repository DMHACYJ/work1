#define
#include<>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col); 
void ComputerMove(char board[ROW][COL], int row, int col);
char CheckWin(char board[ROW][COL], int row, int col);
//���Ӯ-��*��
//����Ӯ
//ƽ Q
//���� C