//假设一个顺序表L中所有元素为整数，设计一个算法调整该顺序表，使其中所有小于零的元素放在所有大于等于零的元素的前面
#include <iostream>
using namespace std;

#define MaxSize 6

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
} Sqlist;

//建立顺序表
void CreatList(Sqlist*& L, ElemType a[], int n) {
	L = (Sqlist*)malloc(sizeof(Sqlist));
	for (int i = 0; i < n; i++) 
		L->data[i] = a[i];
	L->length = n;
}

//初始化
void InitList(Sqlist*& L) {
	L = (Sqlist*)malloc(sizeof(Sqlist));
	L->length = 0;
}

//销毁
void DestroyList(Sqlist*& L) {
	free(L);
}

void res(Sqlist*& L) {
	int i = 0, j = L->length - 1;
	while (i < j) {
		while (L -> data[i] < 0) i++;
		while (L -> data[j] > 0) j--;
		if(i < j)
			swap(L -> data[i], L -> data[j]);
	}
}

void Display(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

int main() {
	Sqlist* L;
	ElemType a[] = { 1,-5,3,4,-8,-5 };
	InitList(L);
	CreatList(L, a, 6);
	Display(L);
	res(L);
	Display(L);
	DestroyList(L);

}
