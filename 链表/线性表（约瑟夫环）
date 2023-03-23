//试用用线性表的顺序存储结构实现约瑟夫(Josephu)问题。
//约瑟夫问题如下：设有n个人围坐圆桌周围。从某个位置上的人开始从1报数，数到m的人便出列，下一个人(第m+1个)又从1报数开始，数到m的人便是第2个出列的人，
//依次类推，直到最后一个人出列为止，这样就可以得到一个人员排列的新次序。例如，n=8,m=4,从第1个人数起，得到的新次序为48521376
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
}LN;
void CreatListR(LN*& L, int n)
{

	int j;
	LN* s;
	L = (LN*)malloc(sizeof(LN));
	L->next = L;
	L->data = 1;

	for (j = n; j > 1; j--)
	{
		s = (LN*)malloc(sizeof(LN));
		s->data = j;
		s->next = L->next;
		L->next = s;
	}
}
void NewList(LN*& L, int m, int n)
{
	int i;
	LN* a = L, * b, * c, * d;
	for (i = 0; i < n; i++)
	{
		int j = 1;
		while (j < m)
		{
			a = a->next;
			j++;
		}
		printf("%d ", a->data);
		d = a->next;
		a->data = a->next->data;
		a->next = a->next->next;
		free(d);

	}


}
void DispList1(LN* L, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}



int main()
{
	LN* L, * L1;
	int m, n;
	printf("请输入一个数n:");
	scanf("%d", &n);
	CreatListR(L, n);
	printf("请输入一个数m:");
	scanf("%d", &m);
	DispList1(L, n);
	NewList(L, m, n);
}
