#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct BTNodeTree {
	struct BTNodeTree* left, * right;
	ElemType data;
}BTNode, *BiTree;
void ReBiTreePreOrder(BiTree &T, int *pre, int *order, int presize, int ordersize);
void ReBiTreePostOrder(BiTree& T, int* post, int* order, int postsize, int ordersize); 
void PrintOrderTree(BiTree T);
int main(void)
{
	BiTree T = NULL;
	int pre[10] = { 1, 2, 4, 8, 9, 5, 10, 3, 6, 7 };
	int order[10] = {8, 4, 9, 2, 10, 5, 1, 6, 3, 7};
	int post[10] = { 8, 9, 4, 10, 5, 2, 6, 7, 3, 1 };
	int level[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "前中序复原二叉树，中序输出：";
	ReBiTreePreOrder(T, pre, order, 10, 10);
	PrintOrderTree(T);
	cout << endl << "后中序复原二叉树，中序输出：";
	ReBiTreePostOrder(T, post, order, 10, 10);
	PrintOrderTree(T); 
	
	return 0;
}
void ReBiTreePreOrder(BiTree& T, int* pre, int* order, int presize, int ordersize) {
	if (presize == 0 || ordersize == 0) {
		T = NULL;
		return;
	}
	T = (BiTree)malloc(sizeof(BTNode));
	int i;
	for (i = 0; i < ordersize; ++i)
		if (order[i] == pre[0])
			break;
	T->data = order[i];
	ReBiTreePreOrder(T->left, pre + 1, order, i, i);
	ReBiTreePreOrder(T->right, pre + i + 1, order + i + 1, presize - i - 1, presize - i - 1);
}
void ReBiTreePostOrder(BiTree& T, int* post, int* order, int postsize, int ordersize) {
	if (ordersize == 0 || postsize == 0) {
		T = NULL;
		return;
	}
	T = (BiTree)malloc(sizeof(BTNode));
	int i = 0;
	for (; i < ordersize; i++)
		if (order[i] == post[postsize - 1])
			break;
	T->data = order[i];
	ReBiTreePostOrder(T->left, post, order, i, i);
	ReBiTreePostOrder(T->right, post + i , order + i + 1, postsize - i - 1, ordersize - i - 1);
} 
void PrintOrderTree(BiTree T) {
	stack<BTNode*>stk;
	BTNode* p = T;
	while (p || !stk.empty()) {
		if (p) {
			stk.push(p);
			p = p->left;
		}
		else {
			p = stk.top();
			cout << p->data << ' '; 
			stk.pop();
			p = p->right;
		}
	}
}