#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n - 1; i++){
        if(s[i] <= s[i + 1] && s[i].size() <= s[i + 1].size()){
            flag1 = 1;
            flag2 = 0;
            flag3 = 0;
        }
        else if(s[i] <= s[i + 1]){
            flag1 = 0;
            flag2 = 1;
            flag3 = 0;
        }
        else if(s[i].size() <= s[i + 1].size()){
            flag1 = 0;
            flag2 = 0;
            flag3 = 1;
        }
		else {
        	flag1 = 0;
        	flag2 = 0;
        	flag3 = 0;
    	}
    }
    if(flag1) cout << "both" << endl;
    else if(flag2) cout << "lexicographically" << endl;
    else if(flag3) cout << "lengths" << endl;
    else cout << "none" << endl;
}
