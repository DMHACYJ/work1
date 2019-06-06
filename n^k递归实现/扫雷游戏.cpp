#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max_row 9
#define max_col 9
//使用两个二维数组表示地图。
//show_map表示每个位置是否被翻开。
//  *表示未翻开，‘1’表示周围八个格子中有几个地雷。
//mine_map表示每个位置是否有地雷。
// ‘0’表示不是地雷，‘1’表示是地雷。
//初始化
//  show_map来说初始化成全为*。
//  mine_map先初始化为全为0，然后随机生成十个位置作为地雷。
//打印地图（show_map）。
//让用户输入一组坐标。需检查坐标的合法性。
//判定当前位置如果是地雷提示游戏结束。
//如果不是地雷判定游戏是否胜利（胜利条件是翻开了所有不是地雷的格子。
//如果不是地雷就需要更新一个数字，这个数字表示周围八个格子中有几个地雷。
#define Mine_count 10
void init(char show_map[max_row][max_col], char mine_map[max_row][max_col]) {
	//show_map全部初始化为*
	//for在vs2013版本及以上表达式1可以定义变量
	//shift+alt+r
	//VA软件
	for (int row = 0; row < max_row; ++row) {
		for (int col = 0; col < max_col; ++col) {
			show_map[row][col] = '*';
		}
	}
	//mine_map初始化
	for (int row = 0; row < max_row; ++row) {
		for (int col = 0; col < max_col; ++col) {
			mine_map[row][col] = '*';
		}
	}
	//随机生成10个位置的地雷
	int mine_count = Mine_count;
	while (mine_count > 0) {
		int row = rand() % max_row;
		int col = rand() % max_col;
		if (mine_map[row][col] == '1')
			continue;
		mine_map[row][col] = '1';
		--mine_count;
	}
}
void printmap(char map[max_row][max_col]) {
	printf("  |");
	for (int col = 0; col < max_col; ++col) {
		printf("%d |", col);
	}
	printf("\n");
	printf("-----------------------------------\n");
	for (int row = 0; row < max_row; ++row) {
		printf("%d |", row);
		for (int col = 0; col < max_row; ++col) {
			printf("%c |", map[row][col]);
		}
		printf("\n");
	}
	printf("\n");
	//for (int row = 0; row < max_row; ++row) {
	//	printf("  ");
	//	for (int col = 0; col < max_row; ++col) {
	//		printf("%c|", map[row][col]);
	//	}
	//	printf("\n");
	//}
}
void updateshowmap(char show_map[max_row][max_col],char mine_map[max_row][max_col],int row,int col) {
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && mine_map[row - 1][col - 1] == '1') {
		++count;
	}
	if (row - 1 >= 0 && mine_map[row - 1][col] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col + 1 < max_col && mine_map[row - 1][col + 1] == '1') {
		++count;
	}
	if (col - 1 >= 0 && mine_map[row ][col - 1] == '1') {
		++count;
	}
	if (col + 1 < max_col && mine_map[row ][col + 1] == '1') {
		++count;
	}
	if (row + 1 < max_row && col - 1 >= 0 && mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col - 1 >= 0 && mine_map[row + 1][col ] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col - 1 >= 0 && mine_map[row + 1][col + 1] == '1') {
		++count;
	}
	show_map[row][col] = count + '0';
}
void game(){
	char show_map[max_row][max_col];
	char mine_map[max_row][max_col];
	init(show_map, mine_map);
	int blank_count = 0;
	int row = 0;
	int col = 0;
	while (1) {
		printmap(show_map);
		printf("请输入一组坐标(row,col):");
		
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= max_row || col < 0 || col >= max_col) {
			printf("您的输入有误，请重新输入\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("已翻开，重输");
		}
		if (show_map[row][col] == '1') {
			system("cls");
			printf("结束");
			printmap(mine_map);
			break;
		}
		++blank_count;
		if (blank_count==max_col*max_row-Mine_count) {
			printf("成功");
			break;
		}
		updateshowmap(show_map, mine_map, row, col);
	}
	
}
int menu(){
	printf("========================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("========================\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d\n", &choice);
	return choice;
}
int main(){
	srand((unsigned int)time(0));
	while (1) {
		int choice = menu();
		if (choice == 1) {
			game();
		}
	}
	system("pause");
	return 0;
}