/*��Ŀ����
�������һ�Ŵ�a�зɵ�c�еĻ�Ʊ�����ҵ��ǣ�û��ֱ�ɺ��ࡣ���кܶ��a�е�b�У���b�е�c�еĺ��ࡣ

��a�е�b����n�����࣬������ʱ��a1��a2��a3 ����an��ɣ�����taʱ��󵽴�b�С�

��b�е�c����n�����࣬������ʱ��b1��b2��b3����bm��ɣ�����tbʱ��󵽴�c�С�

ת����ʱ����Ժ��Բ��ƣ��������Ե��ҽ���bj��ai+taʱ�����Դ�a�е�b�е�i�η��кʹ�b�е�c�е�j�η��С�

��������ȡ��k�κ��ࡣ�����ȡ���˺��࣬���Ͳ���ʹ������

�����Ҫ��������ؽ���c�У�������������������ؽ���c�С�

��������ŵ�ȡ����k�κ��࣬�����쵽��c������ʱ�䡣

��������ȡ��k������ٵĺ��࣬����ʹ����޷�����c�У������- 1��

����
��һ�а���5������  n m ta tb k ��n��mС�ڵ���2e5��

�ڶ��а���n����ͬ����  a1  a2  a3 ���� an  ����֤�������ұ�֤��int��Χ�ڣ�

�ڶ��а���m����ͬ���� b1  b2  b3 ���� bn  ����֤�������ұ�֤��int��Χ�ڣ�


���
��������ȡ��k������ٵĺ��࣬����ʹ����޷�����c�У������- 1��

��������ŵ�ȡ����k�κ��࣬�����쵽��c������ʱ�䡣*/
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 200000
int a[maxn];
int b[maxn];

int lower(int l,int r,int n){
  while(l<=r){

    int mid=(l+r)/2;
    if(n>b[mid]) l=mid+1;
    else r=mid-1;
  }
  return l;
}
int main()
{
	int n,m,ta,tb,k;
	cin>>n>>m>>ta>>tb>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]+=ta;
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	if(k>=min(n,m))
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int ans=0;	
	for(int i=0;i<=k;i++)
	{
		int p=lower(0,m-1,a[i]);
		p+=k-i;
		if(p>=m)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		ans=max(ans,b[p]+tb);
	}
	cout<<ans<<endl;
	return 0;
} 


