#include<iostream>
using namespace std;
class BinInsert {
public:
    unsigned ror(unsigned val, int size) {
        unsigned res = val >> size;
        res |= val << (32 - size);
        return res;
    }
    int binInsert(int n, int m, int j, int i) {
        // write code here
        unsigned tmp = ror(n, j);
        tmp >>= 32 - j;
        n >>= i + j;
        n <<= i + j;
        m <<= j;
        return n + tmp + m;
    }
};
int main() {
	BinInsert b;
	cout << b.binInsert(15, 1, 1, 2);
	return 0;
}
