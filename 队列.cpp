#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 20
typedef struct
{
	int data[Max];
	int front,rear;
}queue;
//��ʼ������
void initqueue(queue & q)
{
	q.front = q.rear = 0;
}
//�ж϶����Ƿ�Ϊ��
int queueempty(queue q)
{
	if(q.front == q.rear)//�ӿ�
		return 1;
	else
		return 0;
}
//���Ӻ���
int enqueue(queue & q,int e)
{
	if((q.rear + 1) % Max == q.front)//����
		return 0;
	q.rear = (q.rear + 1) % Max;
	q.data[q.rear] = e;
	return 1;
}
//���Ӻ���
int dequeue(queue & q,int & x)
{
	if(q.rear == q.front)
		return 0;
	q.front = (q.front + 1) % Max;
	x = q.data[q.front];
	return 1;
}
//ȡ��ͷԪ�غ���
int gethead(queue q,int & y)
{
	if(q.rear == q.front)
		return 0;
	y = q.data[(q.front + 1) % Max];
	return 1;
}
//���ȫ��Ԫ�غ���
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
	int e = 0;//���Ԫ��
	int length = 0;
	int x = 0;//����Ԫ��
	int y = 0;//���е�һ��Ԫ��
	int t[20];//ɾ��ʱ���ڴ��治�豻ɾ����
	int j = 0;
	int s = 0;
	int k = 0;//��Ҫɾ����Ԫ��λ��
	initqueue(q);
	printf("����Ԫ�أ���-1����\n");
	while(e != -1)
	{
		scanf("%d",&e);
		enqueue(q,e);
		length++;
	}
	printf("length=%d\n",length-1);
	gethead(q,y);
	printf("���е�һ��Ԫ����%d\n",y);
	printf("�����е�Ԫ���У�");
	output(q);
	printf("����������ɾ����Ԫ�ص�λ��:");
	scanf("%d",&k);
	if(k <= 0 || k > length-1)
		printf("��ѡ���λ�ó�����Χ\n");
	else
	{
		while(!queueempty(q))
		{
			dequeue(q,x);//������
			if(q.front != k)
				t[j++] = x;//������ɾ����Ԫ�ر�������
		}
		while(s != j)
		{
			enqueue(q,t[s++]);
		}
		printf("ɾ����%d��Ԫ�غ�ʣ���Ԫ��Ϊ��",k);
		output(q);//ȫ�����
	}
	return 0;
}
