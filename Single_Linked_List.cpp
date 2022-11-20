#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
	struct LNode* next;
	int data;
}LNode, *LinkList;
LinkList List_Head(LinkList& L, int n);
LinkList List_Bot(LinkList &L, int n);
void ListInsert(LinkList& L, int i, int x);
void ListDelete(LinkList& L, int i, int &e);
void PrintList(LinkList L);
int main(void)
{
	int n = 10;
	LinkList L1 = List_Head(L1, n);
	cout << "头插法创建链表：";
	PrintList(L1);
	cout << "尾插法创建链表：";
	LinkList L2 = List_Bot(L2, n);
	PrintList(L2);

	int i = 5;
	int x = 999;
	cout << "在第" << i << "个位置插入" << x << "，插入后的链表为：";
	ListInsert(L2, i, x);
	PrintList(L2);

	i = 4;
	int e = 1;
	ListDelete(L2, i, e);
	cout << "删除第" << i << "个位置的元素：" << e << "，删除后的链表为：";
	PrintList(L2);
	return 0;
}
LinkList List_Head(LinkList &L, int n) { 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < n; ++i) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = 4 * i;
		s->next = L->next;
		L->next = s;

	}
	return L;
}
LinkList List_Bot(LinkList& L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s, * r = L;
	for (int i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = 2 * i;
		s->next = r->next;
		r->next = s;
		
		r = s;
	}
	return L;
}
void ListInsert(LinkList& L, int i, int x) {
	LNode* P = L->next;
	for (int j = 1; j < i - 1; ++j) 
		P = P->next;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	s->next = P->next;
	P->next = s;
	
	
}
void ListDelete(LinkList& L, int i, int& e) {
	if (i < 0 || !L) return;
	LNode* P = L->next;
	int j = 1;
	while (j++ != i - 1 && P)
		P = P->next;
	if (!P) return;
	LNode* t = P->next;
	e = t->data;
	P->next = t->next;
	free(t);
	
	
}
void PrintList(LinkList L) {
	LNode* P = L->next;
	while (P) {
		cout << P->data << " ";
		P = P->next;
	}
		
	cout << endl;
}