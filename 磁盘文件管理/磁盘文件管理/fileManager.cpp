#include"fileManager.hpp"
#include"fileutil.hpp"

void FileManager::scannerDir(const std::string& path) {
	//清理容器
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

//只保留重复文件的结果
void FileManager::getCopyList() {
	_filestoMd5.clear();

	//不要用范围for：涉及删除操作
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end()) {
		if (_md5toFiles.count(it->first) > 1) {
			//equal_range 返回值: pair<beginIt, endIt>：[beginIt, endIt)--->迭代器遍历时连续
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second) {
				//只存放重复文件的映射关系
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//下一个不同的md5的起始位置
			it = pairIt.second;
		}
		else {
			_files.erase(it->second);
			it = _md5toFiles.erase(it);
		}
	}
}
//所有的删除，保证一个文件不存在副本
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
	//删除是需要保留一份，保留第一个文件
	auto pairIt = _md5toFiles.equal_range(md5);
	std::cout << md5 << "--->" << _md5toFiles.count(md5) << std::endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second) {
		_files.erase(curIt->second);
		_filestoMd5.erase(curIt->second);
		//文件从磁盘中删除
		deleteFile(curIt->second.c_str());
		++count;
		++curIt;
	}
	//更新 md5 ---> files
	curIt = pairIt.first;
	++curIt;
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout << "delete files : " << count << std::endl;
}

//每个重复的文件只保留一个
void FileManager::deleteAllCopy() {
	std::unordered_set<std::string> md5Set;
	//找出所有的MD5值
	for (const auto& p : _md5toFiles) {
		md5Set.insert(p.first);
	}

	for (const auto& md5 : md5Set) {
		deleteByMD5(md5);
	}
}
//模糊删除：删除所有模糊匹配“matchName”所有文件的副本
void FileManager::deleteByMatchName(const std::string& matchName) {
	std::unordered_set<std::string> allFiles;
	//遍历所有文件
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
		//md5值相同的显示在一起
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5：" << it->first << std::endl;
		while (curIt != pairIt.second) {
			std::cout << "\t第" << idx << "个文件";
			std::cout << curIt->second << std::endl;
			++curIt;
			++idx;
			count++;
		}
		it = pairIt.second;
	}
	std::cout << "文件总数：" << total << "\t" << count << std::endl;
}
void FileManager::showAllFile() {
	for (const auto& f : _files) {
		std::cout << f << std::endl;
	}
}
