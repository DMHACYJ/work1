#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datatype;
typedef struct SListNode
{
	datatype data; 
	struct SListNode *next;
}list;
list* BuySListNode(int x)//初始化 
{
	list* newnode;
	newnode=(list*)malloc(sizeof(list));
	assert(newnode);
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
int GetListLength(list*phead)//求链表的长度
{
	list*p=phead;
	int count=0;
	while(p)
	{
		p=p->next;
		count++;
	} 
	return count;
}
void myprint(list* phead)//输出
{
	list* cur=phead;
	while(cur!=NULL)
	{
		printf("%d\t",cur->data);
		cur=cur->next;
	}
	printf("\n");
} 
void SListPushFront(list**pphead,int x)//头插 
{
	if(*pphead==NULL)
	{
		*pphead=BuySListNode(x);
	}
	else
	{
		list*newnode=BuySListNode(x);
		newnode->next=*pphead;
		*pphead=newnode;
	}
}
void SListInsert(list **pphead,int pos,int x)//插入
{
	if(pos>GetListLength(*pphead)+1)
		return assert(NULL);
	if(pos==1)
	{
		SListPushFront(pphead,x);
	}
	else
	{
		list*cur=*pphead;
		list*newnode=BuySListNode(x);
		pos--;
		while(--pos)
		{
			cur=cur->next;
		}
		newnode->next=cur->next;
		cur->next=newnode;
	}
} 
void SListDelete(list**pphead,int pos)//删除
{
	if(pos>GetListLength(*pphead))
		return assert(NULL);
	if(pos==1)
	{
		list*cur=*pphead;
		*pphead=cur->next;
		free(cur);
	}
	else
	{
		list*cur=*pphead;
		list*next;
		pos--;
		while(--pos)
		{
			cur=cur->next;
		}
		next=cur->next;
		cur->next=next->next;
		free(next);
	}
} 
void SListArrange(list**pphead)//排序 
{
	list*cur=*pphead;
	list*teil=NULL;
	assert(*pphead);
	while(cur!=teil)
	{
		while(cur->next!=teil)
		{
			if(cur->data>cur->next->data)
			{
				datatype next=cur->data;
				cur->data=cur->next->data;
				cur->next->data=next;
			}
			cur=cur->next;
		}
		teil=cur;
		cur=*pphead;
	}
	return;
}
list*merge(list*head1,list*head2)//合并 
{
	list*p1=head1;
	list*p2=head2;
	list*head,* cur;
	if(p1->data<p2->data)
	{
		cur=p1;
		p1=p1->next;
	}
	else
	{
		cur=p2;
		p2=p2->next;
	}
	head=cur;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data<=p2->data)
		{
			cur->next=p1;
			p1=p1->next;
		}
		else
		{
			cur->next=p2;
			p2=p2->next;
		}
		cur=cur->next;
	}
	if(p1!=NULL)
		cur->next=p1;
	if(p2!=NULL)
		cur->next=p2;
	return head;
}
int main()
{
	list*head1=NULL;
	list*head2=NULL;
	list*result=NULL;
	SListPushFront(&head1,0);
	SListPushFront(&head1,1);
	SListPushFront(&head1,2);
	SListPushFront(&head1,3);
	printf("head1初始化：\n");
	myprint(head1);
	SListPushFront(&head2,3);
	SListPushFront(&head2,4);
	SListPushFront(&head2,5);
	SListPushFront(&head2,6);
	printf("head2初始化：\n");
	myprint(head2);
	SListInsert(&head1,2,4);
	printf("head1插入：\n");
	myprint(head1);
	SListDelete(&head1,2);
	printf("head1删除：\n");
	myprint(head1);
	SListArrange(&head1);
	printf("head1排序：\n");
	myprint(head1);
	SListArrange(&head2);
	printf("head2排序：\n");
	myprint(head2);
	SListArrange(&head1);
	SListArrange(&head2);
	printf("合并：\n");
	result=merge(head1,head2);
	myprint(result);
}
