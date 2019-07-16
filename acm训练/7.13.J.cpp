#include<stdio.h>
int main()
{
	int n,i,j,tmp;
	int a[20];
	int index;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[index])
			{
				index=j;
			}
		}
		if(index!=i)
		{
			tmp=a[index];
			a[index]=a[i];
			a[i]=tmp; 
		} 
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
