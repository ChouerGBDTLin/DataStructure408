#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MaxSize = 100;
typedef struct Node {
	struct Node* next;
	int val;
}Node, *LinkList;
typedef struct Stack {
	Node* Top;
	Node* Bottom;
}Stack;d
void CreateStack(Stack*& S);	//创建一个新的链式栈
void Push(Stack*& S, int x);	//压栈操作
void Pop(Stack*& S, int &e);	//出栈操作
ElemType GetTop(Stack* S);	//获取栈顶元素
ElemType GetBottom(Stack* S);	//获取栈底元素
Node* GetPreTop(Stack* S);	//获取栈顶元素的前一个元素
void ClearStack(Stack*& S);	//清空栈！
int main(void)
{
	Stack* S;
	CreateStack(S);
	cout << "栈顶：" << GetTop(S) << endl;
	cout << "栈底：" << GetBottom(S) << endl;
	int e = 99;
	cout << "入栈：" << e << endl;
	Push(S, e);
	cout << "入栈后的栈顶：" << GetTop(S) << endl;  


	Pop(S, e); 
	Pop(S, e);
	cout << "出栈两次后的元素：" << e << endl;
	cout << "出栈两次后的栈顶元素：" << GetTop(S) << endl;
	cout << endl << "清空栈：";
	ClearStack(S);
	GetTop(S);
	return 0;
}
void CreateStack(Stack*& S){
	S = (Stack*)malloc(sizeof(Stack));
	Node* node = (Node*)malloc(sizeof(Node));
	S->Top = node;
	S->Bottom = node;
	node->next = NULL;	
	int a[10] = { 1, 2, 3, 4, 5, 6, 7 ,8 ,9 ,10 };
	for (int i = 0; i < 10; ++i) 
		Push(S, a[i]);
	
}
void Push(Stack*& S, int x) {
	Node* t = (Node*)malloc(sizeof(Node)); 
	t->val = x;
	S->Top->next = t;
	S->Top = t;
}
void Pop(Stack*& S, int &e) {
	e = S->Top->val;
	Node* PreT = GetPreTop(S);
	Node* t = S->Top;
	S->Top = PreT;
	free(t);
}
ElemType GetTop(Stack* S) {
	if (S->Top == S->Bottom) {
		cout << "栈空！" << endl;
		return NULL;
	}
	return S->Top->val;
}
ElemType GetBottom(Stack* S) {
	if (S->Bottom == S->Top) {
		cout << "栈空！" << endl;
		return NULL;
	}
	return S->Bottom->next->val;
}
Node* GetPreTop(Stack* S) {
	Node* t = S->Bottom;
	while (t->next != S->Top)
		t = t->next;
	return t;
}
void ClearStack(Stack*& S) { 
	int e;
	while (S->Bottom != S->Top) {
		Pop(S, e);
	}
}