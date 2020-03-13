#include<math.h>
#include<string>
#include<fstream>
#include<iostream>
#include "md5.h"
using std::cout;
//��ʼ��static��Ա
int MD5::_leftShift[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16,
23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

MD5 :: MD5() {
	init();
}

void MD5::init() {
	//��ʼ��k[i]
	for (int i = 0; i < 64; ++i) {
		_k[i] = static_cast<uint32>(abs(sin(i + 1.0)) * pow(2.0, 32));
	}

	reset();
}

void MD5 :: reset() {
	//��ʼ��A, B, C, D
	_a = 0x67452301; 
	_b = 0xefcdab89; 
	_c = 0x98badcfe; 
	_d = 0x10325476;

	memset(_chunk, 0, CHUNK_BYTE);

	_lastByte = _totalByte = 0;
}

void MD5::calMD5(uint32* chunk) {
	uint32 a = _a;
	uint32 b = _b;
	uint32 c = _c;
	uint32 d = _d;
	for (int i = 0; i < 64; ++i) {
		//λ����
		// 0~15 : F
		int f, g;
		if (0 <= i && i <= 15) {
			f = F(b, c, d);
			g = i;
		}
		// 16~31 : G
		if (16 <= i && i <= 31) {
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		// 32~47 : H
		if (32 <= i && i <= 47) {
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		// 48~63 : I
		if (48 <= i && i <= 63) {
			f = I(b, c, d);
			g = (7 * i) % 16;
		}

		//���£��ӷ���ѭ������
		int tmp = d;
		d = c;
		c = b;
		b = b + leftShift((a + f + chunk[g] + _k[i]), _leftShift[i]);
		a = tmp;
	}
	//����A, B, C, D
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}

void MD5::calFinalMD5() {
	//���������Ϣ�� ��һ��bitλ��1�� ʣ����0
	//�κ�����¶���Ҫ�������1byte��������Ϣ
	//��ȡ��һ��������λ��
	char* p = _chunk + _lastByte;
	//�������1byte��������Ϣ��1000 0000
	*p = 0x80;//����-128;
	int remainByte = CHUNK_BYTE - _lastByte - 1;
	//���ʣ���ֽ�������8Byte -> 64bit��������䳤����Ϣ
	//�ȴ���һ�����ݣ���ȥ����һ���µ����ݿ飬ǰ448λ��0�����64λ�����Ϣ
	if (remainByte < 8) {
		//ʣ��λȫ����0������һ��
		memset(p, 0, remainByte);
		calMD5((uint32*)_chunk);
		//����һ���µ����ݿ�
		memset(_chunk, 0, CHUNK_BYTE);
	}
	else {
		//ʣ���λȫ����0
		memset(p, 0, remainByte);
	}
	//�����ݿ�����64λ���ԭʼ������Ϣ
	unsigned long long totalBits = _totalByte;
	totalBits *= 8;
	((unsigned long long*)_chunk) [7] = totalBits;
	calMD5((uint32*)_chunk);
}

std::string changeHex(uint32 n) {
	static std::string strMap = "0123456789abcdef";
	std::string ret;
	//��ȡÿһ���ֽ�����
	for (int i = 0; i < 4; ++i) {
		int curByte = (n >> (i * 8)) & 0xff;
		//����ת��16�����ַ�
		std::string curRet;
		//��16����λ  ģ16����λ �ֽ��ڲ�����
		curRet += strMap[curByte / 16];
		curRet += strMap[curByte % 16];
		//�ֽ�֮������
		ret += curRet;
	}
	return ret;
}

std::string MD5::getStringMD5(const std::string& str) {
	if (str.empty()) {
		return changeHex(_a).append(changeHex(_b)).append(changeHex(_c));
	}
	_totalByte = str.size();
	uint32 chunkNum = _totalByte / CHUNK_BYTE;
	const char* strPtr = str.c_str();
	for (int i = 0; i < chunkNum; ++i) {
		memcpy(_chunk, strPtr + i * CHUNK_BYTE, CHUNK_BYTE);
		calMD5((uint32*) _chunk);
	}
	//�������һ�����ݣ���Ҫ���
	_lastByte = _totalByte % CHUNK_BYTE;
	memcpy(_chunk, strPtr + chunkNum * CHUNK_BYTE, _lastByte);
	calFinalMD5();
	return changeHex(_a).append(changeHex(_b)).append(changeHex(_c));
}

std::string MD5::getFileMD5(const char* filePath) {
	std::ifstream fin(filePath);
	if (!fin.is_open()) {
		std::cout << filePath;
		perror("file open failed");
		return "";
	}
	while (!fin.eof()) {
		//ȫ����������tellg��ȡ�ļ���С���ռ任ʱ��
		/*
		fin.seekg(0, fin.end);
		uint32 length = fin.tellg();
		fin.seekg(0, fin.beg);
		char* totalData = new char[length];
		fin.read(totalData, length);
		*/
		//ÿ��ֻ��ȡһ�����ݣ�ʱ�任�ռ�
		fin.read(_chunk, CHUNK_BYTE);
		//�Ƿ��ȡ��64�ֽڵ�����
		if (CHUNK_BYTE != fin.gcount()) {
			//˵��Ϊ���һ������
			break;
		}
		_totalByte += CHUNK_BYTE;
		calMD5((uint32*)_chunk);
	}
	//gcount:���Ե��ö�Σ�ʼ�շ������һ�ζ�����ֽ���
	_lastByte = fin.gcount();
	_totalByte += _lastByte;
	calFinalMD5();
	return changeHex(_a).append(changeHex(_b)).append(changeHex(_c));
}















