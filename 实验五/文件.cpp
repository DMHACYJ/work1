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
		outfile << i << " ";	//���ļ�д������
	}
	outfile << endl; 
	outfile.close();			//�ر��ļ�
 
	outfile.open("myfile",ios::app);

	for (int i = 0; i < 100; i++) {
		if(i % 10 == 0)
			outfile << endl;
		outfile << i << " ";	//���ļ�д������
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
