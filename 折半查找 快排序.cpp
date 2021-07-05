#include<stdio.h>

typedef int KeyType;
typedef int ElemType;

typedef struct
{
	KeyType key;
	ElemType data;
}SqType;

int BinSeatch(SqType R[],int n,KeyType k)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(R[mid].key==k)
			return (mid+1);
		else if(R[mid].key>k)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}
void QuickSort(SqType R[],int s,int t)
{
	int i=s,j=t;
	SqType tmp;
	if(s<t)
	{
		tmp=R[s];
		while(i!=j)
		{
			while(j>i && R[j].key>=tmp.key)
				j--;
			R[i]=R[j];
			while(i<j && R[i].key<=tmp.key)
				i++;
			R[j]=R[i];
		}
		R[i]=tmp;
		QuickSort(R,s,i-1);
		QuickSort(R,i+1,t);
	}
}

int main()
{
	SqType R[100];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	int m;
	printf("排序前:");
	for(i=0;i<n;i++)
	{
		printf("%3d",A[i]);
		
	}
	printf("\n");
	for(i=0;i<n;i++)
		R[i].key=A[i];
	QuickSort(R,0,n-1);
	printf("排序后:");
	for(i = 0;i < n;i++)
		printf("%3d",R[i].key);
		printf("\n");
	printf("请输入你要查找的数：");
	scanf("%d",&m);
	printf("%d\n",BinSeatch(R,n,m));
	return 0;
}
