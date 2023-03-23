//编写程序实现顺序表的各种基本运算。对给定字符数组a[]={'4','9','2','8','0','5','4','6','7','9'}，创建顺序表L，删除大于等于'1'小于等于'5'的元素。
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];		//存放顺序表元素
	int length;					//存放顺序表的长度
} SqList;						//顺序表的类型
void CreateList(SqList*& L, ElemType a[], int n)
//建立顺序表
{
	L = (SqList*)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}
//初始化线性表，构造一个空的线性表L，只需分配线性表的存储空间并将length域设置为0即可
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));	//分配存放线性表的空间
	L->length = 0;
}

//销毁线性表DestroyList,释放线性表L占用的内存空间
void DestroyList(SqList*& L)
{
	free(L);
}

//输出
void DispList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i] - '0');
	printf("\n");
}

//删除操作
bool ListDelete(SqList*& L, int i, ElemType& e)
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;						//将顺序表位序转化为elem下标
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)	//将data[i]之后的元素前移一个位置
		L->data[j] = L->data[j + 1];
	L->length--;				//顺序表长度减1
	return true;
}

int main() {
	SqList* L;
	InitList(L);
	ElemType e;
	InitList(L);
	char a[] = { '4','9','2','8','0','5','4','6','7','9' };
	CreateList(L, a, 10);
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] >= '1' && a[i] <= '5') {
			ListDelete(L, i + 1 - count, e);
			count++;
		}
	}
	DispList(L);
	DestroyList(L);
return 0;
}
