#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node * next;
}SLinkNode;

//��ʼ�����Ա�
void InitList(SLinkNode *&L)
{
	L=(SLinkNode *)malloc(sizeof(SLinkNode));//���ٿռ�
	L->next=NULL;
}
//�������Ա�
void DestroyList(SLinkNode *&L)
{
	SLinkNode * pre=L ,*p=pre->next;
	while(p!=NULL)
	{
		free(pre);//�ͷ�pre�ڵ�ռ�
		pre=p;
		p=p->next;
	}
	free(pre);//�ͷ�preָ���β���ռ�
}
//��������
int GetLength(SLinkNode * L)
{
	int i=0;
	SLinkNode *p=L->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;//��PΪ��ʱ��iΪ���ݽڵ����
}
//�������е�i��Ԫ��
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
//��ֵ����
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
//����Ԫ��
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
//ɾ��Ԫ��
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
//���������
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

//ͷ�巨����
void CreateListF(SLinkNode * &L)
{
	SLinkNode *s;
	int i;
	int n;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));
	L->next=NULL;
	printf("����Ϊ:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s=(SLinkNode *)malloc(sizeof(SLinkNode));
		printf("��%d����",i+1);
		scanf("%d",&s->data);
		s->next=L->next;
		L->next=s;
	}
}

//β�巨��������
void CreateListR(SLinkNode * &L)
{
	SLinkNode * s,* tc;
	int i;
	int n;
	L=(SLinkNode * )malloc(sizeof(SLinkNode));
	tc=L;
	printf("����Ϊ:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s=(SLinkNode *)malloc(sizeof(SLinkNode));
		printf("��%d����",i+1);
		scanf("%d",&s->data);
		tc->next=s;
		tc=s;
	}
	tc->next=NULL;
	printf("�����ɹ�\n");
}

int main()
{
	int x;
	int i;
	int r;
	int e;
	SLinkNode * L;
	printf("��ʼ����������");
	CreateListR(L);//β�巨
	//CreateListF(L);//ͷ�巨
	printf("��ʼ���������\n");
	DispList(L);
	printf("������������λ��:");
	scanf("%d",&i);
	printf("����������������:");
	scanf("%d",&x);
	InsElem(L,x,i);
	DispList(L);
	printf("��������ɾ��Ԫ�ص�λ��");
	scanf("%d",&r);
	DelElem(L,r);
	DispList(L);
	printf("����������ҵ�ֵ");
	scanf("%d",&e);
	printf("Ԫ��%d�ǵ�%d��Ԫ��\n",e,Locate(L,e));
	DestroyList(L);//��������
	return 0;
}