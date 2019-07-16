#include<stdio.h>
int main()
{
	int stack[100000];
	int i,temp;
	int top = 0;int n;
	int sum = 0;
	while (~scanf("%d", &n)) 
	{
		for(i=0;i<n;++i)
		{
			scanf("%d", &temp);
			if (!top) 
			{
				stack[++top] = temp;
			}
			else 
			{
				if (temp == stack[top]) 
				{
					top--;
					sum++;
				}
				else
				{
					stack[++top] = temp;
				}
			}
		}
		printf("%d\n", sum);
		top=0;
		sum=0;
	}
}
