#pragma once
#define CHUNK_BYTE 64
#include<string>
typedef unsigned int uint32;

class MD5 {
public:
	/*
	F(x,y,z) = (x & y) | ((~x) & z) 
	G(x,y,z) = (x & z) | ( y & (~z)) 
	H(x,y,z) = x ^ y ^ z 
	I(x,y,z) = y ^ (x | (~z)) 
	*/
	//位运算的函数： F G H I
	uint32 F(uint32 b, uint32 c, uint32 d) {
		return (b & c) | ((~b) & d);
	}
	uint32 G(uint32 b, uint32 c, uint32 d) {
		return (b & d) | (c & (~d));
	}
	uint32 H(uint32 b, uint32 c, uint32 d) {
		return b ^ c ^ d;
	}
	uint32 I(uint32 b, uint32 c, uint32 d) {
		return c ^ (b | (~d));
	}
	//循环左移
	uint32 leftShift(uint32 number, int shiftNumber) {
		return (number << shiftNumber) | (number >> (32 - shiftNumber));
	}

	void init();

	//重置
	void reset();

	//一个chunk的MD5运算
	void calMD5(uint32* chunk);

	//进行填充，再进行MD5运算
	void calFinalMD5();

	MD5();

	std::string getStringMD5(const std::string& str);
	std::string getFileMD5(const char* filePath);
private:
	//循环移位的位数
	static int _leftShift[64];

	//k[i] : K[i] = floor(2^(32) * abs(sin(i + 1)))
	uint32 _k[64];
	//数据块：64byte
	char _chunk[CHUNK_BYTE];
	//填充相关的变量
	//最后一块数据的字节数
	uint32 _lastByte;
	//总字节数
	uint32 _totalByte;

	//MD5信息, A B C D
	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};

//不能在这里进行static 成员的初始化，多个cc,cpp文件会导致重定义
//int MD5 ::  _leftShift