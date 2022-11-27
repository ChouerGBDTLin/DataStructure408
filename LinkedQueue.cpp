#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MaxSize = 100;
typedef struct Node {
	struct Node* next;
	ElemType val;
}LinkNode;
typedef struct Queue {
	LinkNode *rear, *front;
}LinkQueue;
void InitQue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool EntryQue(LinkQueue& Q, int x);
bool OutQue(LinkQueue& Q, int &e);
ElemType Getrear(LinkQueue Q);
ElemType GetFront(LinkQueue Q);
int main(void)
{	
	LinkQueue Q;
	InitQue(Q);
	int a[5] = { 1, 2, 3, 4, 5 };
	int i = 0;
	for (; i < 5; ++i)
		EntryQue(Q, a[i]);
	cout << Getrear(Q) << endl << GetFront(Q) << endl;
	OutQue(Q, i);
	cout << i << endl;
	cout << Getrear(Q) << endl << GetFront(Q) << endl;
	return 0;
}
void InitQue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
bool IsEmpty(LinkQueue Q) {
	return Q.front == Q.rear;
}
bool EntryQue(LinkQueue& Q, int x) {
	LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
	t->val = x;
	t->next = NULL;
	Q.rear->next = t;
	Q.rear = t;
	return true;
}
bool OutQue(LinkQueue& Q, int &e) {
	LinkNode* t = Q.front;
	e = t->next->val;
	Q.front = t->next;
	free(t);
	return true;
}
ElemType Getrear(LinkQueue Q) {
	return Q.rear->val;
}
ElemType GetFront(LinkQueue Q) {
	return Q.front->next->val;
}