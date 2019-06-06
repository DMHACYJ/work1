#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max_row 9
#define max_col 9
//ʹ��������ά�����ʾ��ͼ��
//show_map��ʾÿ��λ���Ƿ񱻷�����
//  *��ʾδ��������1����ʾ��Χ�˸��������м������ס�
//mine_map��ʾÿ��λ���Ƿ��е��ס�
// ��0����ʾ���ǵ��ף���1����ʾ�ǵ��ס�
//��ʼ��
//  show_map��˵��ʼ����ȫΪ*��
//  mine_map�ȳ�ʼ��ΪȫΪ0��Ȼ���������ʮ��λ����Ϊ���ס�
//��ӡ��ͼ��show_map����
//���û�����һ�����ꡣ��������ĺϷ��ԡ�
//�ж���ǰλ������ǵ�����ʾ��Ϸ������
//������ǵ����ж���Ϸ�Ƿ�ʤ����ʤ�������Ƿ��������в��ǵ��׵ĸ��ӡ�
//������ǵ��׾���Ҫ����һ�����֣�������ֱ�ʾ��Χ�˸��������м������ס�
#define Mine_count 10
void init(char show_map[max_row][max_col], char mine_map[max_row][max_col]) {
	//show_mapȫ����ʼ��Ϊ*
	//for��vs2013�汾�����ϱ��ʽ1���Զ������
	//shift+alt+r
	//VA���
	for (int row = 0; row < max_row; ++row) {
		for (int col = 0; col < max_col; ++col) {
			show_map[row][col] = '*';
		}
	}
	//mine_map��ʼ��
	for (int row = 0; row < max_row; ++row) {
		for (int col = 0; col < max_col; ++col) {
			mine_map[row][col] = '*';
		}
	}
	//�������10��λ�õĵ���
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
		printf("������һ������(row,col):");
		
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= max_row || col < 0 || col >= max_col) {
			printf("����������������������\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("�ѷ���������");
		}
		if (show_map[row][col] == '1') {
			system("cls");
			printf("����");
			printmap(mine_map);
			break;
		}
		++blank_count;
		if (blank_count==max_col*max_row-Mine_count) {
			printf("�ɹ�");
			break;
		}
		updateshowmap(show_map, mine_map, row, col);
	}
	
}
int menu(){
	printf("========================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("========================\n");
	printf("����������ѡ��\n");
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