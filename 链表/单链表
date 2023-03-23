//设 ha=(a1，a2，…，an)和 hb=(b1，b2， …，bm) 是两个带头结点的循环单链表。设计一个算法将这两个表合并为带头结点的循环单链表 hc。
#include <iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;		//指向后继结点
} LinkNode;					//声明单链表结点类型

void CreateListF(LinkNode*& L, ElemType a[], int n)
//头插法建立单链表
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));  	//创建头结点
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//创建新结点s
		s->data = a[i];
		s->next = L->next;			//将结点s插在原开始结点之前,头结点之后
		L->next = s;
	}
}

void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));  	//创建头结点
	L->next = NULL;
}

void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);	//此时p为NULL,pre指向尾结点,释放它
}

void DispList(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	cout << endl;
}

LinkNode Merge(LinkNode*& L1, LinkNode*& L2) {
	LinkNode* pa = L1->next, *L3 = L1;
	LinkNode* pb = L2->next;
	while (pa->next!=L1)
	{
		pa = pa->next;
	}

	while (pb->next!=L2)
	{
		pb = pb->next;
	}

	pa->next = L2->next;
	pb->next = L3;
	free(L2);
	return *L3;
}

int main() {
	LinkNode* L1, * L2, *L3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	ElemType a1[5] = { 1,2,3,4,5 };
	ElemType a2[5] = { 6,7,8,9,10 };
	CreateListF(L1, a1, 5);
	CreateListF(L2, a2, 5);
	cout << "两个链表分别为：" << endl;
	DispList(L1);
	DispList(L2);
	cout << "将第二个链表合并到第一个链表后：" << endl;
	*L3 = Merge(L1, L2);
	DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 0;
}
