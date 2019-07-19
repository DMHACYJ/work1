/*#include<stdio.h>
#include<string.h>

#define maxn 100000
char* strrev(char* s)
{
    // h指向s的头部 
    char* h = s;
    char* t = s;
    char ch;
    // t指向s的尾部 
    while(*t++){};
    t--;    // 与t++抵消 
    t--;    // 回跳过结束符'\0' 
    // 当h和t未重合时，交换它们所指向的字符 
    while(h < t)
    {
        ch = *h;
        *h++ = *t;    // h向尾部移动 
        *t-- = ch;    // t向头部移动 
    }
    return(s);
}
char ans[maxn];

int judge(char* a,char* b)
{
	int lena=strlen(a);
	int lenb=strlen(b);
	
	if(lena>lenb)
	{
		return 1;
	}
	else if(lena<lenb)
	{
		return -1;
	}
	return strcmp(a,b);
}
char *solve(char* a,char* b)
{
	char aa[maxn];
	char bb[maxn];
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	memset(ans,0,sizeof(ans));
	if(judge(a,b)>0)
	{
		strcpy(aa,a);
		strcpy(bb,b);
		
	}
	else if(judge(a,b)<0)
	{
		strcpy(aa,b);
		strcpy(bb,a);
		
	}
	else
	{
		ans[0]='0';
		return ans;
	}
	int lena=strlen(aa);
	int lenb=strlen(bb);
	strrev(aa);
	strrev(bb);
	
	int i;
	for(i=0; ;i++)
	{
		if(i<lena&&i<lenb)
		{
			if(aa[i]>=bb[i])
			{
				ans[i]=aa[i]-bb[i]+'0';
			}
			else
			{
				ans[i]=aa[i]-bb[i]+10+'0';
				for(int j=i+1; ;j++)
				{
					if(aa[j]=='0')
					{
						aa[j]='9';
					}
					else
					{
						aa[j]--;
						break;
					}
				}
			}
		}
		else if(i<lena)
		{
			ans[i]=aa[i];
		}
		else if(i<lenb)
		{
      		ans[i]=bb[i];
  		}
		else break;
	}
	while(i--)
	{
		ans[i+1]='\0';
		if(ans[i]-'0'>0)
		{
			break;
		}
	}
	if(judge(a,b)<0) ans[i+1]='-';
	strrev(ans);
	return ans;
}
char a[maxn],b[maxn];
int main()
{
	
	while(~scanf("%s %s",a ,b))
	{
		printf("%s\n",solve(a,b));
	}
	return 0;
}*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int flag = 0;
string sub(string s1, string s2){
    for(int i = s1.length() - 1, j = s2.length() - 1; j >= 0; i--, j--){
        if(s1[i] >= s2[j]){
            s1[i] = s1[i] - s2[j] + '0';
        }
        else{
            int k = i;
            s1[i] = s1[i] + 10 - s2[j] + '0';
            while(s1[k - 1] == '0'){  //借位
                s1[k - 1] = '9';
                k--;
            }
            s1[k-1]--;
        }
    }
    while(s1[0] == '0'){  //去掉前导0
        if(s1.length() == 1) break;
        s1.erase(0, 1);
    }
    return s1;
}
 
int main()
{
    string a, b;
    while(cin >> a >> b){
        flag = 0;
        if(a.length() < b.length()) flag = 1;
        else if(a.length() == b.length() && a < b) flag = 1;
        if(flag) cout << "-" << sub(b, a) << endl;
        else cout << sub(a, b) << endl;
    }
    return 0;
}

