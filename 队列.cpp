#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 20
typedef struct
{
	int data[Max];
	int front,rear;
}queue;
//初始化队列
void initqueue(queue & q)
{
	q.front = q.rear = 0;
}
//判断队列是否为空
int queueempty(queue q)
{
	if(q.front == q.rear)//队空
		return 1;
	else
		return 0;
}
//进队函数
int enqueue(queue & q,int e)
{
	if((q.rear + 1) % Max == q.front)//队满
		return 0;
	q.rear = (q.rear + 1) % Max;
	q.data[q.rear] = e;
	return 1;
}
//出队函数
int dequeue(queue & q,int & x)
{
	if(q.rear == q.front)
		return 0;
	q.front = (q.front + 1) % Max;
	x = q.data[q.front];
	return 1;
}
//取对头元素函数
int gethead(queue q,int & y)
{
	if(q.rear == q.front)
		return 0;
	y = q.data[(q.front + 1) % Max];
	return 1;
}
//输出全部元素函数
int output(queue q)
{
	if(q.rear == q.front)
		return 0;
	int i = q.front + 1;
	while(i != q.rear)
	{
		printf("%d ",q.data[i]);
		i = (i + 1) % Max;
	}
	printf("\n");
	return 1;
}

int main()
{
	int i = 0;
	queue q;
	int e = 0;//入队元素
	int length = 0;
	int x = 0;//出队元素
	int y = 0;//队列第一个元素
	int t[20];//删除时用于储存不需被删除的
	int j = 0;
	int s = 0;
	int k = 0;//想要删除的元素位置
	initqueue(q);
	printf("输入元素，以-1结束\n");
	while(e != -1)
	{
		scanf("%d",&e);
		enqueue(q,e);
		length++;
	}
	printf("length=%d\n",length-1);
	gethead(q,y);
	printf("队列第一个元素是%d\n",y);
	printf("队列中的元素有：");
	output(q);
	printf("请输入你想删除的元素的位置:");
	scanf("%d",&k);
	if(k <= 0 || k > length-1)
		printf("你选择的位置超出范围\n");
	else
	{
		while(!queueempty(q))
		{
			dequeue(q,x);//出队列
			if(q.front != k)
				t[j++] = x;//将不被删除的元素保存起来
		}
		while(s != j)
		{
			enqueue(q,t[s++]);
		}
		printf("删除第%d个元素后剩余的元素为：",k);
		output(q);//全部输出
	}
	return 0;
}
