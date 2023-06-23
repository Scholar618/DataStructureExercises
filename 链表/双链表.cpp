//在结点类型为DLinkNode的双链表中将p所指结点（非尾结点）与其后继结点交换的操作
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;

void InitList(DLinkNode*& L) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
}

void DestroyList(DLinkNode*& L) {
	DLinkNode* pre = L;
	DLinkNode* temp = L->next;
	while (temp != L) {
		pre = temp;
		temp = temp->next;
		free(pre);
	}
	free(L);
}

void CreatListF(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void ChangeNode(DLinkNode*& p)
{
	DLinkNode *q = p->next;
	if (q->next == NULL) {
		p->next = q->next;
		p->prior->next = q;
		q->prior = p->prior;
		p->prior = q;
		q->next = p;
	}
	else
	{
		p->next = q->next;
		p->prior->next = q;
		q->prior = p->prior;
		p->prior = q;
		q->next->prior = p;
		q->next = p;
	}
}

void DisplayNode(DLinkNode* L) {
	DLinkNode *p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int main() {
	DLinkNode* L;
	InitList(L);
	ElemType a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	CreatListF(L, a, 10);
	cout << "当前链表为：" << endl;
	DisplayNode(L);
	cout << endl;
	cout << "交换第三个和第四个节点为：" << endl;
	DLinkNode* p = L->next->next->next;
	ChangeNode(p);
	DisplayNode(L);

}
