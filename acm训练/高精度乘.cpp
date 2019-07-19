/*#include<stdio.h>
#include<string.h>

#define maxn 10000
char* strrev(char *str)
{
	char *p1,*p2;
	if(!str||!*str)
	{
		return str;
	}
	for(p1=str,p2=str+strlen(str)-1;p2>p1;++p1,--p2)
	{
		*p1^=*p2;
		*p2^=*p1;
		*p1^=*p2;
	}
	return str; 
}
int ans[maxn];
char anss[maxn];
char* solve(char* a,char* b)
{
	memset(ans,0,sizeof(ans));
	memset(anss,0,sizeof(anss));
	strrev(a);
	strrev(b);
	int lena=strlen(a);
	int lenb=strlen(b);
	for(int i=0;i<lenb ;i++)
	{
		for(int j=0;j<lena;j++)
		{
			ans[j+i]+=(b[i]-'0')*(a[j]-'0');
		}
	}
	int yu=0;
	int i;
	for(i=0; ;i++)
	{
		if(yu!=0||i<lena+lenb-1)
		{
			yu=yu+ans[i];
			ans[i]=yu%10;
			yu=yu/10;
		}
		else
		{
			break;
		}
	}
	int nu=0;
	while(i--)
	{
		anss[nu++]=ans[i]+'0';
	}
	strrev(anss);
	return anss;
}

char a[maxn],b[maxn];

int main()
{
	while(scanf("%s %s",a,b)) 
	{
		if(strcmp(a,"0")==0||strcmp(a,"0")==0)
		{
			
			printf("0\n");
		}
		else
		{
			printf("%s\n",solve(a,b));
		}
		
	}
}*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 500007;
string s1, s2;
int ans[maxn];
void mul(string a, string b){
    for(int i = b.length() - 1; i >= 0; i--){
        for(int j = a.length() - 1; j >= 0; j--){
            ans[b.length() - 1 - i + a.length() - 1 - j] += (b[i] - '0') * (a[j] - '0');
        }
    }
    for(int i = 0; i < a.length() + b.length() - 1; i++){
        if(ans[i] >= 10){
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    return;
}
 
int main()
{
    while(cin >> s1 >> s2){
        if(s1 == "0" || s2 == "0"){
            cout << "0" << endl;
            continue;
        } 
        memset(ans, 0, sizeof(ans));
        if(s1.length() < s2.length()){
            string tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        mul(s1, s2);
        int flag = 0;
        for(int i = s1.length() + s2.length() - 1; i >= 0; i--){
            if(ans[i] == 0 && flag == 0){
                continue;
            }
            else{
                flag = 1;
                cout << ans[i];
            }
        }
        cout << endl;
    }
    return 0;
}

