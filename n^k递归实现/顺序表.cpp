#include<stdio.h> 
#include<stdlib.h>
typedef int ElemType;
#define LIST_INIT_SIZE 100 
#define LIST_INCREMENT 10 
typedef struct{
    ElemType *elem;       
    int length;      
    int listsize;    
}SqList;
int InitList(SqList *L)//初始化 
{
	int i,length;
	printf("输入线性表的长度：\n");
	scanf("%d",&length);
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
    {
        return -1; 
    }
    printf("输入%d个元素，以空格隔开：\n",length);
    for(i=0;i<length;i++)
    {
    	scanf("%d",&L->elem[i]);
	}
    L->length = length; 
    L->listsize = LIST_INIT_SIZE; 
    return 0;
}
int LocateElem(SqList *L, ElemType x)//查找 
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (L->elem[i] == x)
        {            
			return i;
        }
    }
    return -1;
}
int toString(SqList *L)//输出 
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d ",L->elem[i]);
    }
    printf("\n");
}
int InserElement(SqList *L,int m,ElemType e)//插入 
{
    if(m<1||m>L->length+1)
        return -1;
    if(L->length >= L->listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LIST_INCREMENT)*sizeof(ElemType));
        if (!newbase) return -1;
        L->elem = newbase;
        L->listsize += LIST_INCREMENT;
    }
    int i;
    for(i=L->length+1;i>=m;i--)
    {
    	L->elem[i]=L->elem[i-1];
	}
	L->elem[m-1]=e;
	L->length++;
}
int ListDelete(SqList *L,ElemType e)//删除 
{
    int i;
    if((i=LocateElem(L,e))<0)return -1;
	for(;i<L->length;i++)
	{
		L->elem[i]=L->elem[i+1];
	}
    L->length--;
}
int ListArrange(SqList *L)//排序 
{
	int a=0,i,j;
	L->length--;
	for(i=0;i<L->length-1;i++)
	{
		for(j=0;j<L->length;j++)
		{
			if(L->elem[j]<L->elem[j+1])
			{
				a=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=a;
			}
			continue;
		}
	}
}
int main()
{
	int m,e,x,i;
	SqList L;
	InitList(&L);
	printf("输入要查找的元素：\n");
	scanf("%d",&x);
	LocateElem(&L,x);
	i=LocateElem(&L,x)+1;
	printf("要查找的元素在第%d个位置:\n",i);
	printf("输入要插入的元素及位置；\n");
	scanf("%d %d",&m,&e);
	InserElement(&L,e,m);
	toString(&L);
	printf("输入要删除的元素：\n");
	scanf("%d",&e);
	ListDelete(&L,e); 
	toString(&L);
	printf("排序:\n");
	ListArrange(&L);
	toString(&L);
}




