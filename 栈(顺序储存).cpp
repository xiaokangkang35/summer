#include<stdio.h>

#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &st)
{
	st.top=-1;
}

void DestroyStack(SqStack st)
{ }
//进栈
int Push(SqStack &st,ElemType x)
{
	if(st.top==MaxSize-1)
		return 0;
	else
	{
		st.top++;
		st.data[st.top]=x;
		return 1;
	}
}

//出栈
int Pop(SqStack &st,ElemType &x)
{
	if(st.top == -1)
		return 0;
	else
	{
		x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st,ElemType &x)
{
	if(st.top == -1)
		return 0;
	else
	{
		x=st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)
{
	if(st.top==-1)
		return 1;
	else 
		return 0;
}

//回文判断
int Palindrome(char str[],int n)
{
	SqStack st;
	InitStack(st);
	int i;
	char ch;
	for(i=0;i<n;i++)
		Push(st,str[i]);
	i=0;
	while(!StackEmpty(st))
	{
		Pop(st,ch);
		if(ch!=str[i++])
		{
			DestroyStack(st);
			return 0;
		}
	}
	DestroyStack(st);
	return 1;
}

int main()
{
	SqStack st;
	ElemType e;
	int n;
	int i;
	char str[10];
	printf("初始化栈\n");
	InitStack(st);
	printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
	printf("1进栈\n");
	Push(st,1);
	printf("3进栈\n");
	Push(st,3);
	printf("2进栈\n");
	Push(st,2);
	printf("4进栈\n");
	Push(st,4);
	printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
	GetTop(st,e);
	printf("栈顶元素为:%d\n",e);
	printf("出栈次序:");
	while(!StackEmpty(st))
	{
		Pop(st,e);
		printf("%2d",e);
	}
	printf("\n");
	
	/*printf("开始回文判断");
	scanf("%d",&n);
	for(i=0;i<n;i++);
	{
		scanf("%c",&str[i]);
	}
	Palindrome(str[10],n);
	*/
	DestroyStack(st);
	return 0;
}

