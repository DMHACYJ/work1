#include<stdio.h>
#include<math.h>
int flag=1;
int row[20];
void queen(int now)
{
	if(now==9&&flag)
	{
		for(int i=0;i<9;i++)
		{
			if(i==0)
			{
				printf("%d",row[0]+1);
			}
			else
			{
				printf(" %d",row[i]+1);
			}
			
		}
		
		flag=0;
		return;
	}
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<now;j++)
		{
			if(i==row[j]||abs(now-j)==abs(i-row[j]))
			break;
		}
		if(j==now)
		{
			row[now]=i;
			queen(now+1);
		}
	}
}
int main()
{
	queen(0);
	return 0; 
}
