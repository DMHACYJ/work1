#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

const int inf = 0x3f3f3f3f;

class PCB {
public:
	PCB() {}
	PCB(char name, int runtime, int pri, int state) {
		_name = name;
		_runtime = runtime;
		_pri = pri;
		state = 'R';
//		_num++;
	}
	char getName() {
		return _name;
	}
//	int getNum() {
//		return _num;
//	}
	int getPri() {
		return _pri;
	}
	char getState() {
		return _state;
	}
	int getRuntime() {
		return _runtime;
	}

	void setPri(int pri) {
		_pri = pri;
	}
	void setState(char state) {
		_state = state;
	}
	void setRuntime(int runtime) {
		_runtime = runtime;
	}

	void toString() {
		cout << _name << " " << _pri << " " << _runtime << " " << _state << endl;
	}
private:
	char _name;
	int _runtime;
	int _pri;
	char _state;
//	static int _num;
};

//int PCB :: _num = 0;

vector<PCB> list;

void init();//进程初始化
int max_pri_process();//确定最大优先级进程子程序
void show();//显示子程序
void run();//运行子程序