#include<iostream>
using namespace std;

// process ，resorces
const int p = 4;
const int r = 3;

//比较函数，如果所有m[i] < n[i]，返回1，否则返回0
int compare(int m[r], int n[r]) {
	int flag = 0;
	for (int i = 0; i < r; i++) {
		if (m[i] < n[i]) {
			flag = 1;
			break;
		}
	}
	if (flag)	return 0;
	return 1;
}

//安全性算法
int check(int allocation[p][r], int need[p][r], int available[r]) {
	int flag = 0, flag1 = 0;
	int work[r];
	bool finish[p];
	for (int i = 0; i < p; i++) finish[i] = false;//
	for (int i = 0; i < r; i++) work[i] = available[i];//开始时，work = available
	cout << "Distribute list:" << endl;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			if (finish[i] == true)continue;
			else {
				if (compare(work, need[j])) {
					finish[j] = true;
					cout << i + 1 << '\t';
					flag = 1;
					for (int l = 0; l < r; l++) work[l] += allocation[j][l];
					break;
				}
			}
			if (flag) break;
		}
	}
	cout << endl;
	for (int i = 0; i < p; i++) {
		if (finish[i] == false) flag1 = 1;
	}
	if (!flag1) return 1;
	else return 0;
}

void bank(int allocation[p][r], int need[p][r], int available[r], int request[r], int n) {
	int t[r];
	n = n - 1;
	for (int i = 0; i < r; i++) t[i] = need[n][i];
	if (compare(available, request) && compare(t, request)) {
		for (int j = 0; j < r; j++) {
			allocation[n][j] += request[j];
			need[n][j] -= request[j];
			available[j] -= request[j];
		}
		if (check(allocation, need, available))
			cout << "Allowing " << n + 1 << " processes application resources!" << endl;
		else {
			cout << "Don't allow " << n + 1 << " processes application resources!"<< endl;

			cout << "Return" << endl;
			for (int j = 0; j < r; j++) {
				allocation[n][j] -= request[j];
				need[n][j] += request[j];
				available[j] += request[j];
			}
		}
	}
	else cout << "Request faild!" << endl;
}

int main() {        
	int max[p][r], allocation[p][r], need[p][r], available[r], request[r];
	
	cout << "Input max:" << endl;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++) cin >> max[i][j];
	cout << "Input allocation:" << endl;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++) cin >> allocation[i][j];
	cout << "Input need:" << endl;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++) cin >> need[i][j];
	cout << "Input available:" << endl;
	for (int j = 0; j < r; j++) cin >> available[j];

	if (check(allocation, need, available) == 1) cout << "Safe!"<<endl;
	else cout << "Unsafe!" << endl;

	cout << " Input request data:" << endl;
	for (int j = 0; j < r; j++) cin >> request[j];

	cout << "Input process requests:" << endl;
	int n;
	cin >> n;

	bank(allocation, need, available, request, n);
	getchar();
	return 0;
}