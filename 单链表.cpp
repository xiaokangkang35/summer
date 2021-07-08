#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node * next;
}SLinkNode;

//初始化线性表
void InitList(SLinkNode *&L)
{
	L=(SLinkNode *)malloc(sizeof(SLinkNode));//开辟空间
	L->next=NULL;
}
//销毁线性表
void DestroyList(SLinkNode *&L)
{
	SLinkNode * pre=L ,*p=pre->next;
	while(p!=NULL)
	{
		free(pre);//释放pre节点空间
		pre=p;
		p=p->next;
	}
	free(pre);//释放pre指向的尾结点空间
}
//单链表长度
int GetLength(SLinkNode * L)
{
	int i=0;
	SLinkNode *p=L->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;//当P为空时，i为数据节点个数
}
//求单链表中第i个元素
int GetElem(SLinkNode * L,int i,ElemType &e)
{
	int j=0;
	SLinkNode *p=L;
	if(i<=0)
		return 0;
	while(p!=NULL && j<i)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return 0;
	else
	{
		e=p->data;
		return 1;
	}
}
//按值查找
int Locate(SLinkNode * L,ElemType e)
{
	SLinkNode * p=L->next;
	int j=1;
	while(p!=NULL && p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
		return (0);
	else
		return (j);
}
//插入元素
int InsElem(SLinkNode *&L,ElemType x,int i)
{
	int j=0;
	SLinkNode *p=L,*s;
	if(i<=0)
		return 0;
	while(p!=NULL && j<i-1)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return 0;
	else
	{
		s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;
		s->next=p->next;
		p->next=s;
		return 1;
	}
}
//删除元素
int DelElem(SLinkNode *&L,int i)
{
	int j=0;
	SLinkNode *p=L,*q;
	if(i<=0)
		return 0;
	while(p!=NULL && j<i-1)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return 0;
	else
	{
		q=p->next;
		if(q==NULL)
			return 0;
		else
		{
			p->next=q->next;
			free(q);
			return 1;
		}
	}
}
//输出单链表
void DispList(SLinkNode *L)
{
	SLinkNode * p=L->next;
	while(p!=NULL)
	{
		printf("%2d",p->data);
		p=p->next;
	}
	printf("\n");
}

//头插法建表
void CreateListF(SLinkNode * &L)
{
	SLinkNode *s;
	int i;
	int n;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));
	L->next=NULL;
	printf("总数为:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s=(SLinkNode *)malloc(sizeof(SLinkNode));
		printf("第%d数字",i+1);
		scanf("%d",&s->data);
		s->next=L->next;
		L->next=s;
	}
}

//尾插法建立链表
void CreateListR(SLinkNode * &L)
{
	SLinkNode * s,* tc;
	int i;
	int n;
	L=(SLinkNode * )malloc(sizeof(SLinkNode));
	tc=L;
	printf("总数为:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s=(SLinkNode *)malloc(sizeof(SLinkNode));
		printf("第%d数字",i+1);
		scanf("%d",&s->data);
		tc->next=s;
		tc=s;
	}
	tc->next=NULL;
	printf("建立成功\n");
}

int main()
{
	int x;
	int i;
	int r;
	int e;
	SLinkNode * L;
	printf("开始建立单链表");
	CreateListR(L);//尾插法
	//CreateListF(L);//头插法
	printf("开始输出单链表\n");
	DispList(L);
	printf("请输入想插入的位置:");
	scanf("%d",&i);
	printf("请输入想插入的数字:");
	scanf("%d",&x);
	InsElem(L,x,i);
	DispList(L);
	printf("请输入想删除元素的位置");
	scanf("%d",&r);
	DelElem(L,r);
	DispList(L);
	printf("请输入想查找的值");
	scanf("%d",&e);
	printf("元素%d是第%d个元素\n",e,Locate(L,e));
	DestroyList(L);//销毁链表
	return 0;
}