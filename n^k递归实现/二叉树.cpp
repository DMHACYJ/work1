#include<stdio.h>
#include<malloc.h>
typedef struct BiTNode
{
	char data;
	struct BiTNode*lchlid,*rchlid;
}BiTNode,*BiTree;
BiTree CreateBiTree(BiTree T)//���� 
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')return NULL;
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data=ch;
		T->lchlid= CreateBiTree(T->lchlid);
		T->rchlid= CreateBiTree(T->rchlid);
	}
	return T;
}
void PutTree(BiTree T,int h)
{
	char bra[]={"-/\\<"};
	int i;
	if(T!=NULL)
	{
		PutTree(T->rchlid,h+1);
		for(i=0;i<h;i++)putchar('\t') ;
		printf("%c",T->data);
		putchar(bra[((NULL!=(T->lchlid))<<1)|(NULL!=(T->rchlid))]);
		putchar('\n') ;
		PutTree(T->lchlid,h+1);
	}
}
void PreOrderTraverse(BiTree T)//����ݹ���� 
{
	if(T)
	{
		printf("%c ",T->data);
		PreOrderTraverse(T->lchlid);
		PreOrderTraverse(T->rchlid);
	}
}
void InOrderTraverse(BiTree T)//����ݹ����
{
	if(T)
	{
		InOrderTraverse(T->lchlid);
		printf("%c ",T->data);
		InOrderTraverse(T->rchlid);
	}
}
void PostOrderTraverse(BiTree T)//����ݹ����
{
	if(T)
	{
		PostOrderTraverse(T->lchlid);
		PostOrderTraverse(T->rchlid);
		printf("%c ",T->data);
	}
}
void zhong_xu_fei_di_gui_Traverse(BiTree T)
{
 	BiTNode *stack[1000],*p=T;
    int top=0;
    while(p||top)
    {
        if(p)
        {
            stack[top++]=p;
            p=p->lchlid;
        }
        else
        {
            p=stack[--top];
            printf("%c ",p->data);
            p=p->rchlid;
        }
    }
}
int main()
{
	BiTree T;
	int h=0;
	T=CreateBiTree(T) ;
	PutTree(T,h);
	printf("����",&T);
	PreOrderTraverse(T);
	printf("\n");
	printf("����",&T);
	InOrderTraverse(T);
	printf("\n");
	printf("����",&T);
	PostOrderTraverse(T);
	printf("\n");
	printf("����",&T);
	zhong_xu_fei_di_gui_Traverse(T); 
}
	


 
