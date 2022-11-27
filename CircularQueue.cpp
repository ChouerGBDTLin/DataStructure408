#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MaxSize = 6;
typedef struct {
	ElemType a[MaxSize];
	int rear, front;
}SqQueue;
void InitQue(SqQueue& Q);	//初始化循环队列
bool IsEmpty(SqQueue Q);	//判断空
bool IsFull(SqQueue Q);		//判断满
bool EntryQue(SqQueue& Q, ElemType x);	//入队
bool PutOutQue(SqQueue& Q, ElemType& e);	//出队！
ElemType GetRear(SqQueue Q);	//获得队尾元素！
ElemType GetFront(SqQueue Q);	//获得队首元素！
int main(void)
{
	SqQueue Q;
	InitQue(Q);
	int a[6] = { 1, 2 ,3 ,4 ,5, 6 };
	int i = 0;
	while (EntryQue(Q, a[i++]));	//插入元素到队列中！
	cout << GetRear(Q) << endl << GetFront(Q) << endl; 
	PutOutQue(Q, i);
	cout << "出队元素：" << i << endl;
	cout << GetRear(Q) << endl << GetFront(Q) << endl;
	return 0;
}
void InitQue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
bool IsEmpty(SqQueue Q) {
	return Q.front == Q.rear;
}
bool IsFull(SqQueue Q) {
	return ((Q.rear + 1) % MaxSize) == Q.front;
}
bool EntryQue(SqQueue& Q, ElemType x) {
	if (IsFull(Q)) {
		cout << "循环队列满！" << endl;
		return false;
	}
	Q.a[(Q.rear++ % MaxSize)] = x;
	return true;
}
bool PutOutQue(SqQueue& Q, ElemType& e) {
	if (IsEmpty(Q)) {
		cout << "循环队列空！" << endl;
		return false;
	}
	e = Q.a[(Q.front++ % MaxSize)];
	return true;
}
ElemType GetRear(SqQueue Q) {
	return Q.a[Q.rear - 1];
}
ElemType GetFront(SqQueue Q) {
	return Q.a[Q.front];
}