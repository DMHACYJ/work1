#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string a,b,c;
string add(string s1, string s2) 
{  
    if(s1.length() < s2.length()) 
	{
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    for(int i = s1.length() - 1, j = s2.length() - 1; i >= 0; i--, j--) 
	{
        s1[i] += j >= 0 ? s2[j] - '0' : 0;
        if(s1[i] - '0' >= 10) 
		{  
            s1[i] = (s1[i] - '0') % 10 + '0';
            if(i) s1[i - 1]++;  
            else s1 = '1' + s1;
        }
    }
    return s1;
}
string ans, rem;  
 
string sub(string s1, string s2)
{
    for (int i = s1.length() - 1, j = s2.length() - 1; j >= 0; i--, j--)
	{
        if (s1[i] >= s2[j])
		{	
            s1[i] = s1[i] - s2[j] + '0';
        }
        else
		{
            int k = i;
            s1[i] = s1[i] + 10 - s2[j] + '0';
            while (s1[k - 1] == '0')
			{
                s1[k - 1] = '9';
                k--;
            }
            s1[k - 1]--;
        }
    }
    while (s1[0] == '0')
	{
        if (s1.length() == 1)
            break;
        s1.erase(0, 1);
    }
    return s1;
}
 
string div(string a, string b)
{
    ans.clear();
    int lena = a.length(), lenb = b.length();
    for (int i = lenb; i < lena; i++){
        b += '0';
    }
    while (lena >= lenb){
        int cnt = 0;
        while (a.length() > b.length() || (a.length() == b.length() && a >= b)){
            a = sub(a, b);
            cnt++;
        }
        ans += (cnt + '0');
        lena--;
        b.erase(lena, 1);
    }
    rem = a;
    if (ans.length() == 0) ans += '0';
    else if (ans[0] == '0') ans.erase(0, 1);
    return ans;
}
int main()
{
	int q;
	string s;
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>c;
		s=add(add(a,b),c);
		string d="2";
		cout<<div(s,d)<<endl;
	}
	return 0;
} 
