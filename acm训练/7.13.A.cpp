#include<stdio.h>
int main()
{
	int n;
	int pos;
	scanf("%d",&n);
	pos=n%4;
	do
	{
		switch(pos)
		{
			case 0:
				printf("A"); 
				break;
			case 1:
				printf("A");
				break;
			case 2:
				printf("B");
				break;	
			case 3:
				printf("A");
				break;
		}
	}while(0);
}
