#include<iostream>
#include<string>
#include<fstream>
using namespace std;
 
class FileOperate {
public:
	FileOperate();
};
 
FileOperate::FileOperate() {
	ofstream outfile;
	outfile.open("myfile", ios::out);
 
	for (int i = 0; i < 100; i++) {
		if(i % 10 == 0)
			outfile << endl;
		outfile << i << " ";	//向文件写入数据
	}
	outfile << endl; 
	outfile.close();			//关闭文件
 
	outfile.open("myfile",ios::app);

	for (int i = 0; i < 100; i++) {
		if(i % 10 == 0)
			outfile << endl;
		outfile << i << " ";	//向文件写入数据
	}
	outfile << endl;
	outfile.close();
 
	ifstream infile;
	infile.open("myfile",ios::in);
	string temp;
	while(!infile.eof()) {
		getline(infile, temp);
		cout << temp << endl;
	}
	infile.close();
}

int main() {
	FileOperate file;
	system("pause");
	return 0;
}
