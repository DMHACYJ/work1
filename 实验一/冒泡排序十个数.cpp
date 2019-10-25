#include<iostream>
using namespace std;

int main() {
	int a[] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 10};
	for(int i = 10; i > 0; i--) {
		int flag = 1;
		for(int j = 0; j < i-1; j++) {
			if(a[j] > a[j + 1]) {
				flag = 0;
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		if(flag) break;
	}
	for(int i = 0; i < 10; i++) cout << a[i] << " ";
	return 0;
} 
