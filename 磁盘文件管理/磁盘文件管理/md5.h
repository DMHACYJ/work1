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
	//λ����ĺ����� F G H I
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
	//ѭ������
	uint32 leftShift(uint32 number, int shiftNumber) {
		return (number << shiftNumber) | (number >> (32 - shiftNumber));
	}

	void init();

	//����
	void reset();

	//һ��chunk��MD5����
	void calMD5(uint32* chunk);

	//������䣬�ٽ���MD5����
	void calFinalMD5();

	MD5();

	std::string getStringMD5(const std::string& str);
	std::string getFileMD5(const char* filePath);
private:
	//ѭ����λ��λ��
	static int _leftShift[64];

	//k[i] : K[i] = floor(2^(32) * abs(sin(i + 1)))
	uint32 _k[64];
	//���ݿ飺64byte
	char _chunk[CHUNK_BYTE];
	//�����صı���
	//���һ�����ݵ��ֽ���
	uint32 _lastByte;
	//���ֽ���
	uint32 _totalByte;

	//MD5��Ϣ, A B C D
	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};

//�������������static ��Ա�ĳ�ʼ�������cc,cpp�ļ��ᵼ���ض���
//int MD5 ::  _leftShift