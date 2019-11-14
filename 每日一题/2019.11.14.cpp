#include<iostream>
using namespace std;

int func(int n, int m){
    if(n == 1 || m == 1) {
        return n + m;
    }
    else return func(n - 1, m) + func(n, m - 1);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << func(n, m) << endl;
}
