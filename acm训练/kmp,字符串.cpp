


#include <iostream>

#include <cmath>

#include <algorithm>

#include <cstdio>

#include <stdlib.h>

#include <string>

#include <cstring>

#include <map>

#include <set>

#include <queue>

#include <stack>

#define INF 0x3f3f3f3f

#define ms(x,y) memset(x,y,sizeof(x))

using namespace std;

typedef long long ll;

const double pi = acos(-1.0);

const int mod = 1e9 + 7;

const int maxn = 1e5 + 10;

int nextval[100010];

char s[1000100],p[1000010];

//p为模式串

void getnext(char p[], int nextval[]) //朴素kmp，nextval[i]即为1~i-1的最长前后缀长度

{

int len=strlen(p);

int i=0,j=-1;

nextval[0]=-1;

while(i<len)

{

if(j==-1||p[i]==p[j])

{

nextval[++i]=++j;

}

else

j=nextval[j];

}

}

//在s中找p出现的次数

int KMP(char s[], char p[], int nextval[])

{

getnext(p,nextval);

int ans=0;

int i=0; //s下标

int j=0; //p下标

int s_len=strlen(s);

int p_len=strlen(p);

while(i<s_len&&j<p_len)

{

if(j==-1||s[i]==p[j])

{

i++;

j++;

}

else

j=nextval[j];

if(j==p_len)

{

j=nextval[j]; //注意这个优化比较重要

ans++;

}

}

return ans;

}

int main()

{

//freopen("in.txt","r",stdin);

//freopen("out.txt","w",stdout);

int n;

scanf("%d",&n);

while(n--)

{

ms(p,0);

ms(s,0);

scanf(" %s %s",p,s);

printf("%d\n",KMP(s,p,nextval));

}

return 0;
}
