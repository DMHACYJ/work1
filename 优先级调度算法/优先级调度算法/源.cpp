#define _CRT_SECURE_NO_WARNINGS 1
#include"primary.h"

void init() {
	char name;
	int pri, runtime;
	int i = 0;
	printf("%d pcbName primary runtime\n", ++i);
	while (cin >> name >> pri >> runtime) {
		if (i != 1) {
			PCB pcb(name, pri, runtime, 'R');
			printf("%d pcbName primary runtime\n", ++i);
			list.push_back(pcb);
		}
		else {
			PCB pcb(name, pri, runtime, 'R');
			list.push_back(pcb);
		}
	}
}

int max_pri_process() {
	int max = -inf;
	int key = 0;
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i].getState() == 'r') return -1;
		else if (max < list[i].getPri() && list[i].getState() == 'R') {
			max = list[i].getPri();
			key = i;
		}
	}
	if (list[key].getState() == 'E') return -1;
	else return key;
}

void show() {
	printf("\n pcbName  primary runtime state\n");
	for (size_t i = 0; i < list.size(); i++) {
		cout << i << " ";
		list[i].toString();
	}
}

void run() {
	int t = 0;
	for (size_t j = 0; j < list.size(); j++) t += list[j].getRuntime();
	printf("\n处理器之前的状态\n");
	show();
	getchar();
	int f = t, g = t;
	for (int j = 0; j < t; j++) {
		while (max_pri_process() != -1) list[max_pri_process()].setState('r');
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i].getState() == 'r') {
				if (list[i].getPri() >= 1) list[i].setPri(list[i].getPri() - 1);
				list[i].setRuntime(list[i].getRuntime() - 1);
			}
			if (list[i].getRuntime() == 0) list[i].setState('E');
			else list[i].setState('R');
			show();
			getchar();
		}
	}
}

int main() {
	init();
	run();
	getchar();
	return 0;
}







