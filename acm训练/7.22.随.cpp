/*��Ŀ����
��ĳ��������Ա�����Ӵ�Ҫ�ж������Ƿ������ݣ�ȷʵ�����ף�����ĳ�����ݹ�ϵͼ��������������������Ƿ�������ݹ�ϵ��
�涨��x��y�����ݣ�y��z�����ݣ���ôx��zҲ�����ݡ����xy�����ݣ���ôx�����ݶ���y�����ݣ�y������Ҳ����x������
����
��һ�У���������nmp����n< =5000m< =5000p< =5000��
�ֱ��ʾ��n���ˣ�m�����ݹ�ϵ��ѯ��p�����ݹ�ϵ��
����m�У�ÿ��������
mi ��mj ����ʾ���������ݹ�ϵ
�������ݹ�ϵ��
������p�У�ÿ��������
 Pi �� Pj��ѯ�� Pi�� Pj�Ƿ�������ݹ�ϵ��
���
��P�У�ÿ��һ����Yes����No������ʾ��Pi ��ѯ�ʵĴ�Ϊ���С���û�С����ݹ�ϵ��*/
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 5000
int n,m,p;
int pre[maxn];
int Find(int root)
{
	int son=root,temp;
	while(root!=pre[root])
	{
		root=pre[root];
	} 
//	while(son!=root)
//	{
//		temp=pre[son];
//		pre[son]=root;
//		son=root;
//	}
	return root;
}
int main()
{
	int mi,mj;
	cin>>n>>m>>p;
	for(int i=1;i<n;i++)
	{
		pre[i]=i;
	}
	while(m--)
	{
		cin>>mi>>mj;
		mi=Find(mi);
		mj=Find(mj);
		if(mi!=mj)
		{
			pre[mi]=mj;
		}
	}
	while(p--)
	{
		int pi,pj;
		cin>>pi>>pj;
		if(Find(pi)==Find(pj))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		
		}
	}
} 
