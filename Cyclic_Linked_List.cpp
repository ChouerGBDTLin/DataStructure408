#include <bits/stdc++.h>
/*循环链表！*/
using namespace std;
typedef int ElemType;
const int MaxSize = 100;
typedef struct Node {
	struct Node* next;
	ElemType val;
}Node, *LinkList;
void CreateList(LinkList &L);	//创建循环链表
void TraverseList(LinkList L);	//普通遍历
void TraverseList_More(LinkList L, int n);	//循环遍历n次
void InsertList(LinkList& L, int pos, int x);	//插入
void DeleteList(LinkList& L, int pos, int& e);	//删除
Node* LocationList(LinkList& L, int pos);	//返回第pos个链表的节点！
int main(void)
{
	LinkList L;
	CreateList(L);
	TraverseList(L);
	int n = 2; //循环两次
	TraverseList_More(L, n);
	InsertList(L, 3, 999);
	TraverseList_More(L, 3);
	int e;
	DeleteList(L, 5, e);
	cout << e << endl;
	TraverseList_More(L, 2);
	return 0;
}
void CreateList(LinkList& L) {
	L = (LinkList)malloc(sizeof(Node) * MaxSize);
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	L->next = L;
	Node *P = L;
	for (int i = 0; i < 10; ++i) {
		Node* t = (LinkList)malloc(sizeof(Node));
		t->val = a[i];
		P->next = t;
		t->next = L;
		P = t;
	}
	
}
void TraverseList(LinkList L) {
	Node* P = L->next;
	while (P != L) {
		cout << P->val << ' ';
		P = P->next;
	}
	cout << endl;
}
void TraverseList_More(LinkList L, int n) {
	Node* P = L->next;
	while (n--) {
		while (P != L) {
			cout << P->val << ' ';
			P = P->next;
		}
		P = P->next;
	}
	cout << endl;
}
void InsertList(LinkList& L, int pos, int x) {
	Node* t = LocationList(L, pos - 1);
	Node* p = (Node*)malloc(sizeof(Node));
	p->val = x;
	p->next = t->next;
	t->next = p;
}
void DeleteList(LinkList& L, int pos, int& e) {
	Node* p = LocationList(L, pos - 1);
	Node* t = p->next;
	e = t->val;
	p->next = t->next;
	free(t);
}
Node* LocationList(LinkList& L, int pos) {
	int i = 0;
	Node* P = L->next;
	while (true) {
		if (P == L) {
			cout << "插入序号不合规！" << endl;
			return NULL;
		}
		if (i++ != pos - 1)
			P = P->next;
		else
			break;
			
	}
	return P;
}