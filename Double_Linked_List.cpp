#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MaxSize = 100;
typedef struct Node {
	struct Node* next, * previous;
	ElemType val;
}Node, *LinkList;
void CreateList(LinkList& L);
void TraverseListOrder(LinkList L);
void TraverseListReverse(LinkList L);
void InsertList(LinkList& L, int pos, int e);
void DeleteList(LinkList& L, int pos, int& e);
Node* GetBottom(LinkList& L);
Node* GetNode(LinkList L, int pos);
int main(void)
{
	LinkList L;
	CreateList(L);
	TraverseListOrder(L);
	TraverseListReverse(L); 
	InsertList(L, 2, 999);
	TraverseListOrder(L);
	TraverseListReverse(L);
	int e;
	DeleteList(L, 5, e);
	cout << e << endl;
	TraverseListOrder(L);
	TraverseListReverse(L);
	return 0;
}
void CreateList(LinkList& L) {
	L = (LinkList)malloc(sizeof(Node) * MaxSize);
	L->next = NULL;
	L->previous = NULL;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Node* p = L;
	for (int i = 0; i < 10; ++i) {
		Node* t = (Node*)malloc(sizeof(Node));
		t->val = a[i];
		p->next = t;
		t->previous = p;
		t->next = NULL;
		p = t;
	}
	
}
void TraverseListOrder(LinkList L) {
	Node* P = L->next;
	while (P != NULL) {
		cout << P->val << ' ';
		P = P->next;
	}
	cout << endl;
}
void TraverseListReverse(LinkList L) {
	Node* P = GetBottom(L); 
	while (P->previous != NULL) {
		cout << P->val << ' ';
		P = P->previous;
	}
	cout << endl;
}
void InsertList(LinkList& L, int pos, int e) {
	if (pos < 0 || pos > MaxSize) {
		cout << "无效索引！" << endl;
		exit(-1);
	}
	Node* p = GetNode(L, pos);
	Node* t = p->previous;
	Node* n = (Node*)malloc(sizeof(Node));
	n->val = e;
	n->next = p;
	p->previous = n;
	t->next = n;
	n->previous = t;
}
void DeleteList(LinkList& L, int pos, int& e) {
	Node* p = GetNode(L, pos);
	e = p->val;
	Node* t = p->next;
	p->next->previous = p->previous;
	p->previous->next = p->next;
	free(p);
}
Node* GetBottom(LinkList& L) {
	Node* P = L;
	while (P->next != NULL)
		P = P->next;
	return P;
}
Node* GetNode(LinkList L, int pos) {
	Node* p = L;
	while (pos--)
		p = p->next;
	return p;
}