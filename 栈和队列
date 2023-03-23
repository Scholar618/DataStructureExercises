//编写一个程序，输入 n（由用户输入）个 10 以内的垕，每输入 i（0≤i≤9），就把它插入垫第 i 号队列中。
//最后把 10 个队中非空队列，按队列号从小垫垬的顺序串接成一条链，并输出该链的所有元素。
#include<iostream>
using namespace std;
#define MaxSize 10

typedef struct QNode
{
	int data;
	struct QNode* next;
};

void Insert(QNode* q1[], QNode* q2[], int x) {
	QNode* s;
	s = (QNode*)malloc(sizeof(QNode));
	s->data = x;
	s->next = NULL;
	if (q1[x] == NULL)
	{
		q1[x] = s;
		q2[x] = s;
	}
	else
	{
		q2[x]->next = s;
		q2[x] = s;
	}
}

void Creat(QNode* q1[], QNode* q2[])
{
	int n, x;
	cout << "请输入你想输入的个数n：";
	cin >> n;
	for (int i = 0; i < n; i++) {
		do{
			cout << "请输入第" << i + 1 << "个数：";
			cin >> x;
		} while (x < 0 || x > 9);
		Insert(q1, q2, x);
	}
}

void InitQueue(QNode* q) {
	q = (QNode*)malloc(sizeof(QNode));
	q->next = NULL;
}

void Link(QNode*q1[], QNode*q2[]) {
	QNode* front, * rear;
	front = (QNode*)malloc(sizeof(QNode));
	rear = (QNode*)malloc(sizeof(QNode));
	int first = 0;
	for (int i = 0; i < MaxSize; i++) {
		if (q1[i] != NULL && first == 1) { //非空队列
			front = q1[i];
			rear = q2[i];
			first = 0;
		}
		else{
			rear -> next = q1[i];
			rear = q2[i];
		}
	}
	rear->next = NULL;
	cout << "输出新链中所有元素：";
	while (front != NULL) {
		cout << front->data << " ";
		front = front->next;
	}
	cout << "\n";
}

int main() {
	QNode *q1[MaxSize], *q2[MaxSize];
	for (int i = 0; i < MaxSize; i++) {
		q1[i] = q2[i] = NULL;
	}
	Creat(q1, q2);
	Link(q1, q2);
}
