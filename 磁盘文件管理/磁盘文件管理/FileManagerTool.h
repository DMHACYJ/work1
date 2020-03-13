#pragma once
#include<iostream>
#include "fileManager.hpp"

using std::cout;
using std::cin;
using std::endl;

class FileManagerTool {
public:
	void scanner() {
		cout << "������Ҫɨ����ļ��У�" << endl;
		std::string path;
		getline(cin, path);
		_fm.scannerDir(path);
	}

	void deletebyMd5() {
		cout << "������Ҫɾ���ļ���MD5ֵ: " << endl;
		std::string md5;
		cin >> md5;
		_fm.deleteByMD5(md5);
	}

	void deletebyName() {
		cout << "������Ҫɾ�����ļ�����" << endl;
		std::string filename;
		getline(cin, filename);
		_fm.deleteByName(filename);
	}

	void deleteAllCopy() {
		_fm.deleteAllCopy();
	}
	void deleteFussyMatchCopy() {
		cout << "������ƥ���ļ�����" << endl;
		std::string match;
		getline(cin, match);
		_fm.deleteByMatchName(match);
	}

	void showCopy() {
		_fm.showCopyList();
	}

	void showAllFile() {
		_fm.showAllFile();
	}
private:
	FileManager _fm;
};