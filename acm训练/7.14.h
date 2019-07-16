#include<stdio.h>
int main()
{
	int A,B,C,D,y1,y2,y3,y4,sum=0; 
	scanf("%d %d %d %d",&A,&B,&C,&D);
	for(y1=0;y1<=100;y1++)
	{
		for(y2=0;y2<=100;y2++)
		{
			for(y3=0;y3<=100;y3++)
			{
				for(y4=0;y4<=100;y4++)
				{
					if ((A * y1*y1 )+ (B * y2*y2) + (C * y3*y3) + (D * y4*y4) == 0)
					{
						sum++;
					}
				}
			}
		}
	}
	printf("%d",sum);
	
} 
