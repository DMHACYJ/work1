#include<iostream>
using namespace std;

int func(int a, int b) {
    int res = 1;
    for(int i = 2; i <= min(a, b); i++) {
         if(a % i == 0 && b % i == 0) {
             res = max(res, i);
         }
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << a * b / func(b, a) << endl;
}
