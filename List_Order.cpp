#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MaxSize = 100;
typedef struct {
	ElemType data[MaxSize];
	int len;
}SqList;
void InitList(SqList& L);
void InsertList(SqList& L, ElemType e, int pos);
void DeleteList(SqList& L, ElemType& e, int pos);
void FindList(SqList L, int& e, int index);
void TraverseList(SqList L);
void CreateList(SqList& L, int a[], int n);
int main(void)
{
	SqList L;
	InitList(L);
	int n = 10; int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 100 };
	CreateList(L, a, n);
	cout << "��ʼ˳���";
	TraverseList(L);
	InsertList(L, 999, 2);
	cout << "˳����2��λ�ò���Ԫ��999��ִ�к��˳���Ϊ��";
	TraverseList(L);
	int e;
	DeleteList(L, e, 5);
	cout << "˳���ɾ����5��λ�õ�Ԫ�أ���Ϊ��" << e << "��ɾ��֮���˳���Ϊ��";
	TraverseList(L);
	int x;
	FindList(L, x, 6);
	cout << "���ҵ�6��Ԫ�أ�" << x << endl;
	return 0;
}
void InitList(SqList& L) {
	L.len = 0;
}
void InsertList(SqList& L, ElemType e, int pos) {
	if (pos < 0 || pos > L.len) {
		cout << "����λ���쳣��" << endl;
		exit(-1);
	}
	for (int i = L.len; i >= pos - 1; --i) 
		L.data[i] = L.data[i - 1];
	L.data[pos - 1] = e;
	L.len++;
}
void DeleteList(SqList& L, ElemType& e, int pos) {
	if (pos < 0 || pos > L.len) {
		cout << "����λ���쳣��" << endl;
		exit(-1);
	}
	e = L.data[pos - 1];
	for (int i = pos - 1; i < L.len - 1; ++i)
		L.data[i] = L.data[i + 1];
	L.len--;
}
void FindList(SqList L, int& e, int index) {
	e = L.data[index - 1];
}
void TraverseList(SqList L) {
	for (int i = 0; i < L.len; ++i)
		cout << L.data[i] << ' ';
	cout << endl;
}
void CreateList(SqList& L, int a[], int n) {
	for (int i = 0; i < n; ++i) {
		L.data[i] = a[i];
		L.len++;
	}

}