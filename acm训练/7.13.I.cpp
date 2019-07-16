#include<stdio.h>
int main()
{
	int n,i,j,tmp;
	int a[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		tmp=a[i];
		for(j=i;j>0&&a[j-1]>tmp;j--)
		{
			a[j]=a[j-1];
		}
		a[j]=tmp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
