#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100
typedef char ElemType;

typedef struct tnode
{
	ElemType data;
	struct tnode *lchild,*rchild;
}BTNode;

typedef struct stack
{
	BTNode *elements[M];
	int top;
}
seqstack;
//����һ�����������͵�ַ��ջ�����������ʱ��׷�ٵ����ĵ�ַ

seqstack s;

void setnull()
{
	s.top=0;
}
void push(BTNode *temp)
{
	s.elements[s.top++]=temp;
}
BTNode *pop()
{
	return s.elements[--s.top];
}
int empty()
{
	return s.top== 0;
}


//������������
void CreateBTree(BTNode * &bt,char *str)
{
	BTNode * St[30],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;
	ch=str[j];
	while(ch!='\0')
	{
		switch(ch)
		{
		case'(':top++;St[top]=p;k=1;break;
		case')':top--;break;
		case',':k=2;break;
		default:p=(BTNode * )malloc(sizeof(BTNode));
			p->data=ch;
			p->lchild=p->rchild=NULL;
			if(bt==NULL)
				bt=p;
			else
			{
				switch(k)
				{
				case 1:St[top]->lchild=p;break;
				case 2:St[top]->rchild=p;break;
				}
			}
		}
		j++;
		ch=str[j];
	}
}

//����������������ݹ飩
void PreOrder(BTNode * bt)
{
	if(bt!=NULL)
	{
		printf("%c",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

//����������������ݹ飩
void InOrder(BTNode * bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf("%c",bt->data);
		InOrder(bt->rchild);
	}
}

//����������������ݹ飩
void PostOrder(BTNode * bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c",bt->data);
	}
}

//��α���
void LevelOrder(BTNode * bt)
{
	BTNode * p;
	BTNode * qu[30];
	int front,rear;
	front=rear=0;
	rear++;qu[rear]=bt;
	while(front!=rear)
	{
		front=(front+1)%30;
		p=qu[front];
		printf("%c",p->data);
		if(p->lchild!=NULL)
		{
			rear=(rear+1)%30;
			qu[rear]=p->lchild;
		}
		if(p->rchild!=NULL)
		{
			rear=(rear+1)%30;
			qu[rear]=p->rchild;
		}
	}
}

void inorder(BTNode *bt)//��������ķǵݹ��㷨
{
	BTNode *temp = bt;
	while(temp != NULL||s.top != 0)
	{
		while(temp != NULL)//�Ȱ�������ջ������������ջ����
		{
			push(temp);
			temp = temp->lchild;
		}
		if(s.top != 0)//������ջ������ȡջ�������ջ��Ԫ�أ������Һ���
		{
			temp = pop();
			printf("%c",temp->data);
			temp = temp->rchild;
		}
	}
	printf("\n");
}

//����֧�ڵ����
int onenodesl(BTNode * bt)
{
	int m,n;
	if(bt!=NULL)
	{
		m=onenodesl(bt->lchild);
		n=onenodesl(bt->rchild);
		if((bt->lchild==NULL&&bt->rchild!=NULL)||(bt->lchild!=NULL&&bt->rchild==NULL))
			return (1+m+n);
		else
			return (m+n);
	}
	else return 0;
}
//Ҷ�ӽڵ�
int LeafCount(BTNode * bt)
{
	int num1,num2;
	if(bt==NULL)
		return 0;
	else if(bt->lchild==NULL&&bt->rchild==NULL)
		return 1;
	else
	{
		num1=LeafCount(bt->lchild);
		num2=LeafCount(bt->rchild);
		return(num1+num2);
	}
}



int main()
{
	BTNode * bt;
	/*char c;
	scanf("%c",&c);
	printf("%c",c);*/
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");
	//printf("������bt:\n");
	printf("����������У�");
	PreOrder(bt);printf("\n");
	printf("����������У�");
	InOrder(bt);printf("\n");
	printf("����������У�");
	PostOrder(bt);printf("\n");
	printf("��α������У�");
	LevelOrder(bt);printf("\n");
	printf("�������:");
	inorder(bt);printf("\n");
	/*printf("����֧��");
	onenodesl(bt);printf("\n");
	printf("Ҷ�ӽڵ㣺");
	LeafCount(bt);printf("\n");
	*/
	return 0;
}




