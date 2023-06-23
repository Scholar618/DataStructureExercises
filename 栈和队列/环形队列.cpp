//编写一个算法,将一个环形队列(容量为n,元素下标从1到n)的元素倒置。例如,图3-27(a)中为倒置前的队列(n=10),图3-27(b)中为倒置后的队列。
#include<iostream>
using namespace std;
typedef char ElemType;
#define Max 10

typedef struct
{
	ElemType data[Max];
	int front,rear;
}SqQueue;

typedef struct
{
	ElemType data[Max];
	int top;
}SqStack;

//初始化
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

//销毁
void DestroyQueue(SqQueue* q)
{
	free(q);
}

void DestroyStack(SqStack* s)
{
	free(s);
}

//插入
bool enQueue(SqQueue*& q, ElemType e)
{	
	if ((q->rear + 1) % Max == q->front)
		return false;
	q->rear = (q->rear + 1) % Max;
	q->data[q->rear] = e;
	return true;
}

bool Push(SqStack*& s, ElemType e)
{
	if (s->top == Max - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//出
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % Max;
	e = q->data[q->front];
	return true;
}

bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

//判断是否为空
bool QueueEmpty(SqQueue* q)
{
	return(q->front == q->rear);
}

bool StackEmpty(SqStack* s)
{
	return(s->top == -1);
}

void Reverse(SqQueue*& q)
{
	ElemType e;
	SqStack* s;
	InitStack(s);
	while (!QueueEmpty(q)) //队列不为空
	{
		deQueue(q, e);
		Push(s, e);
	}
	InitQueue(q);
	while (!StackEmpty(s)) //栈不为空
	{
		Pop(s, e);
		enQueue(q, e);
	}
	DestroyStack(s);
}

void DisPlay(SqQueue* q) {
	ElemType e;
	for (int i = 1; i <= q->rear; i++)
	{
		cout << q->data[i] << " ";
	}
	cout << endl;
}

int main() {
	ElemType e;
	SqQueue* q;
	InitQueue(q);
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	enQueue(q, 'd');
	enQueue(q, 'e');
	enQueue(q, 'f');
	cout << "初始为：" << endl;
	DisPlay(q);
	Reverse(q);
	cout << "翻转后：" << endl;
	DisPlay(q);
	DestroyQueue(q);

}
