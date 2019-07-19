/*#include<cstdio>
#include<cstring>
#define maxn 5000000
char ans[maxn];
char a[maxn],b[maxn];
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
const char* add(char *a,char *b) 
{
	memset(ans,0,sizeof(ans));
	int lena =strlen(a);
	int lenb =strlen(b);
	strrev(a);
	strrev(b);
	int yu=0;
	for(int i=0; ;i++)
	{
		if(i<lena&&i<lenb)
		{
			ans[i]=(yu+a[i]-'0'+b[i]-'0')%10+'0';
			yu=(a[i]-'0'+b[i]-'0'+yu)/10;
		}
		else if(i<lena)
		{
			ans[i]=(yu+a[i]-'0')%10+'0';
			yu=(yu+a[i]-'0')/10;
		}
		else if(i<lenb)
		{
			ans[i]=(yu+b[i]-'0')%10+'0';
			yu=(yu+b[i]-'0')/10;
		}
		else if(yu!=0)
		{
			ans[i]=yu%10+'0';
			yu=yu/10;
		}
		else break;
	}
	strrev(ans);
	return ans;
}

int main()
{
	
	while(~scanf("%s %s",a,b))
	{
		printf("%s\n",add(a,b));
	}
	return 0;
}*/
#include <cstdio>
#include <iostream>
using namespace std;
 
string add(string s1, string s2) {  //s1更长
    if(s1.length() < s2.length()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    for(int i = s1.length() - 1, j = s2.length() - 1; i >= 0; i--, j--) {
        s1[i] += j >= 0 ? s2[j] - '0' : 0;
        if(s1[i] - '0' >= 10) {  //进位
            s1[i] = (s1[i] - '0') % 10 + '0';
            if(i) s1[i - 1]++;  //是否需要补位
            else s1 = '1' + s1;
        }
    }
    return s1;
}
 
int main() {
    string a, b;
    while(cin >> a >> b){
        cout << add(a, b) << endl;
    }
    return 0;
}

