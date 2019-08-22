#include<iostream>
#include<cstring>
using namespace std;
const int maxn=507;//模式字符串个数 
const int maxs=1000010;//文本（匹配串）长度 
const int maxp=10000*maxn;//ac自动机长度
struct trie
{
	trie* next[95];//0-31,127号字符不可见，95个可见字符 
	trie* fail;
	int num,cnt;
	trie()
	{
		for(int i=0;i<95;i++)
		{
			next[i]=NULL;
		}
		fail=NULL;
		num=0;
		cnt=0;
	}
}; 
char nn[maxn];
char sn[maxs];
trie* pn[maxp];
void insert(trie* root,char* s,int j)
{
	trie* p=root;
	for(int i=0;s[i]!='\0';i++)
	{
		int c=s[i]-33;
		if(p->next[c]==NULL)
		{
			p->next[c]=new trie;
		}
		p=p->next[c];
	}
	p->num++;
	p->cnt=j;
}
void build_ac_automation(trie* root)
{
	int head=0;
	int tail=0;
	pn[tail++]=root;
	while(head!=tail)
	{
		trie* temp=pn[head++];
		for(int i=0;i<95;i++)
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
int result[maxn];
int query(trie* root,char *sn)
{
	int flag=0;
	trie* p=root;
	for(int i=0,len=strlen(sn);i<len;i++)
	{
		int c=sn[i]-33;
		while(p->next[c]==NULL&&p!=root) p=p->fail;
		if(p->next[c]!=NULL) p=p->next[c];
		trie *temp=p;
		while(temp!=root&&temp->num!=-1)
		{
			if(temp->num>0)
			{
				result[temp->cnt]=1;
				flag=1; 
			}
			temp=temp->fail;
		}
	}
	return flag;
}
int main()
{
	int n,m;
	trie* root=new trie;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		gets(nn);
		insert(root,nn,i);
	}
	build_ac_automation(root);
	cin>>m;
	getchar();
	int cot=0;
	for(int i=1;i<=m;i++)
	{
		gets(sn);
		if(query(root,sn))
		{
			cout<<"web "<<i<<":";
			for(int j=1;j<501;j++)
			{
				if(result[j])
				cout<<" "<<j;
			}
			cout<<endl;
			cot++;
		}
	}
	cout<<"total: "<<cot;
	return 0;
} 
