#include<iostream>
#include<cstring>
using namespace std;
const int maxn=57;//匹配字符串个数 
const int maxs=1000010;//文本（模式串）长度 
const int maxp=10000*maxn;//ac自动机长度
struct trie
{
	trie* next[26];
	trie* fail;
	int num;
	trie()
	{
		for(int i=0;i<26;i++)
		{
			next[i]=NULL;
		}
		fail=NULL;
		num=0;
	}
}; 
char nn[maxn];
char sn[maxs];
trie* pn[maxp];
void insert(trie* root,char* s)
{
	trie* p=root;
	for(int i=0;s[i]!='\0';i++)
	{
		int c=s[i]-'a';
		if(p->next[c]==NULL)
		{
			p->next[c]=new trie;
		}
		p=p->next[c];
	}
	p->num++;
}
void build_ac_automation(trie* root)
{
	int head=0;
	int tail=0;
	pn[tail++]=root;
	while(head!=tail)
	{
		trie* temp=pn[head++];
		for(int i=0;i<26;i++)
		{
			if(temp->next[i]!=NULL)
			{
				trie *p=temp->fail;
				while(p!=NULL)
				{
					if(p->next[i]!=NULL)
					{
						temp->next[i]->fail=p->next[i];
						break;
					}
					p=p->fail;
				}
				if(p==NULL)
				{
					temp->next[i]->fail=root;
				}
				pn[tail++]=temp->next[i];
			}
		}
	}
}
int query(trie* root,char *sn)
{
	int ans=0;
	trie* p=root;
	for(int i=0,len=strlen(sn);i<len;i++)
	{
		int c=sn[i]-'a';
		while(p->next[c]==NULL&&p!=root) p=p->fail;
		if(p->next[c]!=NULL) p=p->next[c];
		trie *temp=p;
		while(temp!=root&&temp->num!=-1)
		{
			ans+=temp->num;
			temp->num=-1;
			temp=temp->fail;
		}
	}
	return ans;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		trie* root=new trie;
		cin>>n;
		getchar();
		while(n--)
		{
			gets(nn);
			insert(root,nn);
		}
		build_ac_automation(root);
		gets(sn);
		cout<<query(root,sn)<<endl;
	}
	return 0;
} 
