#include<iostream>
#include<time.h>
#include<algorithm>
#define MAXN 200
#define BEGIN 100//��100�Ŵŵ���ʼ
#define MAXN_LEN 500//ÿ����ͷ֮��������
using namespace std;
int main(){
	int pcbNum[MAXN];//��������Ľ��̵Ĵŵ���
	int n;
	cout << "����������Ľ�������";
	cin >> n;
	srand((unsigned int)time(NULL));//�������������
	for (int i = 0; i < n; i++){
		pcbNum[i] = 1 + rand() % MAXN;//���ôŵ��ţ�1-200
	}
	sort(pcbNum, pcbNum + n);
	int flag=0;
	for (int i = 0; i < n; i++){
		if (pcbNum[i] <= BEGIN&&pcbNum[i+1] >= BEGIN){
			flag = i+1;
		}
	}
	cout << "����Ĵ���->";
	int sumLen = 0;
	for (int i = flag; i < n; i++){
		int len = 1 + rand() % MAXN_LEN;//�������������ͷ֮��ľ���
		sumLen += len;
		cout << pcbNum[i] << " ";
	}
	for (int i = flag-1; i>=0; i--){
		int len = 1 + rand() % MAXN_LEN;//�������������ͷ֮��ľ���
		sumLen += len;
		cout << pcbNum[i] << " ";
	}
	cout << endl;
	cout << "ƽ��Ѱ��ʱ��->" << sumLen / (n*1.0) << endl;
	system("pause");
	return 0;
}
