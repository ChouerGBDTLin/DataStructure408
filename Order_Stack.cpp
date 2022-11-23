#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
const int MaxSize = 100;
typedef struct Stack {
	ElemType a[MaxSize];
	int top;
}Stack;
void CreateStack(Stack* &S);	//创建栈
void Push(Stack*& S, int e);	//压栈
void Pop(Stack*& S, int &e);	//出栈
ElemType GetTop(Stack* S);	//获取栈顶元素
void ClearStack(Stack* S);	//清空栈
int main(void)
{
	Stack* S = (Stack*)malloc(sizeof(Stack));
	CreateStack(S);
	cout << "栈顶：" << GetTop(S) << endl;
	int e;
	Pop(S, e);
	cout << "出栈元素：" << e << endl;
	cout << "出栈后的栈顶元素：" << GetTop(S) << endl;
	ClearStack(S);
	cout << "清空栈：" << endl;
	GetTop(S); 
	return 0;
}
void CreateStack(Stack*& S) {
	int a[10] = { 1, 2, 3,4 ,5 ,6 ,7, 8, 9, 10 };
	S->top = -1;
	for (int i = 0; i < 10; ++i)
		Push(S, a[i]);
}
void Push(Stack*& S, int e) {
	S->a[++S->top] = e;
}
void Pop(Stack*& S, int& e) {
	if(S->top == -1){
		cout << "栈空！" << endl;
		exit(-1);
	}
	e = S->a[S->top--];
	
}
ElemType GetTop(Stack* S) {
	if (S->top == -1) {
		cout << "栈空！" << endl;
		exit(-1);
	}
	return S->a[S->top];
}
void ClearStack(Stack* S) {
	while (S->top--)
		S->a[S->top] = 0;
	
}