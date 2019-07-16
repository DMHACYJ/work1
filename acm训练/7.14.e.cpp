#include<stdio.h>
int main()
{
	int stack[10],a[10],b[10];
	char *s[10];
	int i,temp,j=0;
	int top = 0;
	int n;
	int sum = 0;
	while (~scanf("%d", &n)) 
	{
		for(i=0;i<n;++i)
		{
			scanf("%d", &a[i]);
		}
		for(i=0;i<n;++i)
		{
			scanf("%d", &b[i]);
		}
		for(i=0;(i<2*n&&j<(n-1))||((top==n-1)&&(j!=0));++i)
		{
			if (!top) 
			{
				stack[++top] = a[i];
				*s[i]="In";
			}
			else 
			{
				if (b[j] == stack[top]) 
				{
					top--;
					j++;
					*s[i]="Out";
				}
				else
				{
					stack[++top] = a[i];
					*s[i]="In";
				}
			}
		}
		printf("%d\n", sum);
		top=0;
		sum=0;
	}
}
