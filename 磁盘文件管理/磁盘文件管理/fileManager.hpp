#pragma once 
#include "md5.h"
#include<string>
#include<unordered_set>
#include<unordered_map>
class FileManager {
public:
	void scannerDir(const std::string& path);
	void getCopyList();
	void getMd5toFiles();
	//���е�ɾ������֤һ���ļ������ڸ���
	void deleteByName(const std::string& name);
	void deleteByMD5(const std::string& md5);
	void deleteAllCopy();
	//ģ��ɾ����ɾ������ģ��ƥ�䡰matchName�������ļ��ĸ���
	void deleteByMatchName(const std::string& Match);
	void showCopyList();
	void showAllFile();
	void showMD5Map();
private:
	//vector, list, map, set
	std::unordered_set<std::string> _files;
	// md5 ---> file
	std::unordered_multimap<std::string, std::string> _md5toFiles;
	// file ---> md5
	std::unordered_map<std::string, std::string> _filestoMd5;
	MD5 _md5;
};