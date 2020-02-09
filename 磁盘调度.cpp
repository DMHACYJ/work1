#include<iostream>
#include<time.h>
#include<algorithm>
#define MAXN 200
#define BEGIN 100//从100号磁道开始
#define MAXN_LEN 500//每个磁头之间最大距离
using namespace std;
int main(){
	int pcbNum[MAXN];//保存请求的进程的磁道号
	int n;
	cout << "请输入请求的进程数：";
	cin >> n;
	srand((unsigned int)time(NULL));//设置随机数种子
	for (int i = 0; i < n; i++){
		pcbNum[i] = 1 + rand() % MAXN;//设置磁道号，1-200
	}
	sort(pcbNum, pcbNum + n);
	int flag=0;
	for (int i = 0; i < n; i++){
		if (pcbNum[i] <= BEGIN&&pcbNum[i+1] >= BEGIN){
			flag = i+1;
		}
	}
	cout << "请求的次序->";
	int sumLen = 0;
	for (int i = flag; i < n; i++){
		int len = 1 + rand() % MAXN_LEN;//随机生成两个磁头之间的距离
		sumLen += len;
		cout << pcbNum[i] << " ";
	}
	for (int i = flag-1; i>=0; i--){
		int len = 1 + rand() % MAXN_LEN;//随机生成两个磁头之间的距离
		sumLen += len;
		cout << pcbNum[i] << " ";
	}
	cout << endl;
	cout << "平均寻道时间->" << sumLen / (n*1.0) << endl;
	system("pause");
	return 0;
}
