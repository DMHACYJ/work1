#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct poly 
{
	float coef;
	int exp; 
	struct poly*pNext; 
}POLY;
POLY* BuyPOLY(int x,int y)//初始化 
{
	POLY* pNew;
	pNew=(POLY*)malloc(sizeof(POLY));
	assert(pNew);
	pNew->coef=x;
	pNew->exp=y;
	pNew->pNext=NULL;
	return pNew;
}
void myprint(POLY* phead)//输出
{
	POLY* cur=phead;
	printf("%.1fx^%d",cur->coef,cur->exp);
	while(cur!=NULL)
	{
		printf("%+.1fx^%d",cur->coef,cur->exp);
		cur=cur->pNext;
	}
	printf("\n");
} 
void POLYPushFront(POLY**pphead,int x,int y)//头插 
{
	if(*pphead==NULL)
	{
		*pphead=BuyPOLY(x,y);
	}
	else
	{
		POLY*pNew=BuyPOLY(x,y);
		pNew->pNext=*pphead;
		*pphead=pNew;
	}
}
void POLYArrange(POLY**pphead)//排序 
{
	POLY*cur=*pphead;
	POLY*teil=NULL;
	assert(*pphead);
	while(cur!=teil)
	{
		while(cur->pNext!=teil)
		{
			if(cur->exp>cur->pNext->exp)
			{
				int nexp=cur->exp;
				float ncoef=cur->coef;
				cur->exp=cur->pNext->exp;
				cur->coef=cur->pNext->coef;
				cur->pNext->exp=nexp;
				cur->pNext->coef=ncoef;
			}
			cur=cur->pNext;
		}
		teil=cur;
		cur=*pphead;
	}
	return;
}
POLY* POLYAdd(POLY *head1, POLY *head2)//相加 
{
	POLY *head, *tmp, *dele;
	if (head1->exp<head2->exp)
	{
		head = head1;
		head1 = head1->pNext;
	}
	else
	{
		head = head2;
		head2 = head2->pNext;
	}
	tmp = head;
	while (head1&&head2)
	{
		if (head1->exp<head2->exp)
		{
			tmp->pNext = head1;
			head1 = head1->pNext;
			tmp = tmp->pNext;
		}
		else if (head1->exp>head2->exp)
		{
			tmp->pNext = head2;
			head2 = head2->pNext;
			tmp = tmp->pNext;
		}
		else
		{
			float x = head1->coef + head2->coef;
			if (x == 0)
			{
				dele = head1;
				head1 = head1->pNext;
				free(dele);
				dele = head2;
				head2 = head2->pNext;
				free(dele);
			}
			else
			{
				head1->coef = x;
				tmp->pNext = head1;
				tmp = tmp->pNext;
				head1 = head1->pNext;
				dele = head2;
				head2 = head2->pNext;
				free(dele);
			}
		}
	}
	if (head1 != NULL) tmp->pNext = head1;
	if (head2 != NULL) tmp->pNext = head2;
	return head;
}
POLY* POLYPole(POLY *head1, POLY *head2)//相减 
{
	POLY *head, *tmp, *dele,*cur=head2;
	while (cur)
	{
		cur->coef = -(cur->coef);
		cur = cur->pNext;
	}
	if (head1->exp<head2->exp)
	{
		head = head1;
		head1 = head1->pNext;
	}
	else
	{
		head = head2;
		head2 = head2->pNext;
	}
	tmp = head;
	while (head1&&head2)
	{
		if (head1->exp<head2->exp)
		{
			tmp->pNext = head1;
			head1 = head1->pNext;
			tmp = tmp->pNext;
		}
		else if (head1->exp>head2->exp)
		{
			tmp->pNext = head2;
			head2 = head2->pNext;
			tmp = tmp->pNext;
		}
		else
		{
			float x = head1->coef+head2->coef;
			if (x == 0)
			{
				dele = head1;
				head1 = head1->pNext;
				free(dele);
				dele = head2;
				head2 = head2->pNext;
				free(dele);
			}
			else
			{
				head1->coef = x;
				tmp->pNext = head1;
				tmp = tmp->pNext;
				head1 = head1->pNext;
				dele = head2;
				head2 = head2->pNext;
				free(dele);
			}
		}
	}
	if (head1 != NULL) tmp->pNext = head1;
	if (head2 != NULL) tmp->pNext = head2;
	return head;
}
int main()
{
	
	POLY*head1=NULL;
	POLY*head2=NULL;
	POLY*head3=NULL;
	POLY*head4=NULL;
	POLY*result1=NULL;
	POLY*result2=NULL;
	POLYPushFront(&head1,1,0);
	POLYPushFront(&head1,2,1);
	POLYPushFront(&head1,3,2);
	POLYPushFront(&head1,4,3);
	printf("head1初始化：\n");
	myprint(head1);
	POLYPushFront(&head2,4,3);
	POLYPushFront(&head2,5,4);
	POLYPushFront(&head2,6,5);
	POLYPushFront(&head2,7,6);
	printf("head2初始化：\n");
	myprint(head2);
	POLYArrange(&head1);
	printf("head1排序：\n");
	myprint(head1);
	POLYArrange(&head2);
	printf("head2排序：\n");
	myprint(head2);
	printf("head1+head2=");
	result1=POLYAdd(head1,head2);
	myprint(result1);
	POLYPushFront(&head3,1,0);
	POLYPushFront(&head3,2,1);
	POLYPushFront(&head3,3,2);
	POLYPushFront(&head3,4,3);
	POLYPushFront(&head4,4,3);
	POLYPushFront(&head4,5,4);
	POLYPushFront(&head4,6,5);
	POLYPushFront(&head4,7,6);
	POLYArrange(&head3);
	POLYArrange(&head4);
	printf("head3-head4=");
	result2=POLYPole(head3,head4);
	myprint(result2);
}
