#include"fileManager.hpp"
#include"fileutil.hpp"

void FileManager::scannerDir(const std::string& path) {
	//��������
	_files.clear();

	searchDir(path, _files);
	getMd5toFiles();
	//getCopyList();
}

void FileManager::getMd5toFiles() {
	_md5toFiles.clear();

	for (const auto& f : _files) {
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}

//ֻ�����ظ��ļ��Ľ��
void FileManager::getCopyList() {
	_filestoMd5.clear();

	//��Ҫ�÷�Χfor���漰ɾ������
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end()) {
		if (_md5toFiles.count(it->first) > 1) {
			//equal_range ����ֵ: pair<beginIt, endIt>��[beginIt, endIt)--->����������ʱ����
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second) {
				//ֻ����ظ��ļ���ӳ���ϵ
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//��һ����ͬ��md5����ʼλ��
			it = pairIt.second;
		}
		else {
			_files.erase(it->second);
			it = _md5toFiles.erase(it);
		}
	}
}
//���е�ɾ������֤һ���ļ������ڸ���
void FileManager::deleteByName(const std::string& name) {
	if (_filestoMd5.count(name) == 0) {
		std::cout << name << "not exist!" << std::endl;
		return;
	}
	std::string curMD5 = _filestoMd5[name];
	std::cout << name << "--->" << _md5toFiles.count(curMD5) << std::endl;
	auto pairIt = _md5toFiles.equal_range(curMD5);
	auto curIt = pairIt.first;
	int count = 0;
	while (curIt != pairIt.second) {
		if (curIt->second != name) {
			_files.erase(curIt->second);
			_filestoMd5.erase(curIt->second);
			deleteFile(curIt->second.c_str());
			++count;
		}
		++curIt;
	}
	curIt = pairIt.first;
	while (curIt != pairIt.second) {
		if (curIt->second != name) {
			//key --- > name
			_md5toFiles.erase(curIt);
			pairIt = _md5toFiles.equal_range(curMD5);
			curIt = pairIt.first;
		}
		++curIt;
	}
	std::cout << "delete files : " << count << std::endl;
}
void FileManager::deleteByMD5(const std::string& md5) {
	//md5 ---> files
	if (_md5toFiles.count(md5) == 0) {
		std::cout << md5 << "not exit!" << std::endl;
		return;
	}
	//ɾ������Ҫ����һ�ݣ�������һ���ļ�
	auto pairIt = _md5toFiles.equal_range(md5);
	std::cout << md5 << "--->" << _md5toFiles.count(md5) << std::endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second) {
		_files.erase(curIt->second);
		_filestoMd5.erase(curIt->second);
		//�ļ��Ӵ�����ɾ��
		deleteFile(curIt->second.c_str());
		++count;
		++curIt;
	}
	//���� md5 ---> files
	curIt = pairIt.first;
	++curIt;
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout << "delete files : " << count << std::endl;
}

//ÿ���ظ����ļ�ֻ����һ��
void FileManager::deleteAllCopy() {
	std::unordered_set<std::string> md5Set;
	//�ҳ����е�MD5ֵ
	for (const auto& p : _md5toFiles) {
		md5Set.insert(p.first);
	}

	for (const auto& md5 : md5Set) {
		deleteByMD5(md5);
	}
}
//ģ��ɾ����ɾ������ģ��ƥ�䡰matchName�������ļ��ĸ���
void FileManager::deleteByMatchName(const std::string& matchName) {
	std::unordered_set<std::string> allFiles;
	//���������ļ�
	for (const auto&f : _files) {
		if (f.find(matchName) != std::string::npos)
			allFiles.insert(f);
	}
	for (const auto& f : allFiles) {
		if (_filestoMd5.count(f) != 0)
			deleteByName(f);
	}
}
void FileManager::showCopyList() {
	auto it = _md5toFiles.begin();
	int total = _md5toFiles.size();
	int count = 0;
	while (it != _md5toFiles.end()) {
		//md5ֵ��ͬ����ʾ��һ��
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5��" << it->first << std::endl;
		while (curIt != pairIt.second) {
			std::cout << "\t��" << idx << "���ļ�";
			std::cout << curIt->second << std::endl;
			++curIt;
			++idx;
			count++;
		}
		it = pairIt.second;
	}
	std::cout << "�ļ�������" << total << "\t" << count << std::endl;
}
void FileManager::showAllFile() {
	for (const auto& f : _files) {
		std::cout << f << std::endl;
	}
}
