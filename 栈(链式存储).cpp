#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node * next;
}LinkStack;

void InitStack(LinkStack * &ls)
{
	ls=NULL;
}

void DestroyStack(LinkStack *&ls)
{
	LinkStack * pre=ls,*p;
	if(pre==NULL)
		return ;
	p=pre->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}

int Push(LinkStack * &ls,ElemType x)
{
	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	p->data=x;
	p->next=ls;
	ls=p;
	return 1;
}

int Pop(LinkStack *&ls,ElemType &x)
{
	LinkStack *p;
	if(ls==NULL)
		return 0;
	else
	{
		p=ls;
		x=p->data;
		ls=p->next;
		free(p);
		return 1;
	}
}

int GetTop(LinkStack * ls,ElemType &x)
{
	if(ls==NULL)
		return 0;
	else
	{
		x=ls->data;
		return 1;
	}
}

int StackEmpty(LinkStack * ls)
{
	if(ls==NULL)
		return 1;
	else 
		return 0;
}

int main()
{
	ElemType e;
	LinkStack *st;
	InitStack(st);
	printf("Õ»%s\n",(StackEmpty(st)==1?"¿Õ":"²»¿Õ"));
	Push(st,'a');
	Push(st,'b');
	Push(st,'c');
	Push(st,'d');
	printf("Õ»%s\n",(StackEmpty(st)==1?"¿Õ":"²»¿Õ"));
	GetTop(st,e);
	printf("Õ»¶¥ÔªËØÎª: %c\n",e);
	printf("³öÕ»Ë³Ðò:");
	while(!StackEmpty(st))
	{
		Pop(st,e);
		printf("%2c",e);
	}
	printf("\n");
	DestroyStack(st);
	return 0;
}
