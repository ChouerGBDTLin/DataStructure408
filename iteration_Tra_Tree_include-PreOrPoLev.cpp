#include <bits/stdc++.h>
using namespace std;
typedef struct BTNode {
	struct BTNode* left;
	struct BTNode* right;
	int data;
}BTNode, *BiTree;
typedef struct Tag {
	BTNode* p;
	struct Tag* next;
}tag, *ptag;
void CreateTree(BiTree &T); // 顺序建立树
void PrintPreTree(BiTree T); //先序遍历
void PrintOrderTree(BiTree T); //中序遍历
void PrintLevelTree(BiTree T); //层序遍历
void PrintPostTree(BiTree T); //后序遍历
void InitTree(BiTree& T) { T = NULL; }

int main(void)
{
	BiTree T;
	InitTree(T);
	CreateTree(T); 
	PrintPreTree(T);
	PrintOrderTree(T);
	PrintLevelTree(T);
	PrintPostTree(T);
	return 0;
}
void CreateTree(BiTree& T) {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ptag pcur = NULL;
	ptag phead = NULL;
	ptag prear = NULL;
	ptag listtag = NULL;
	BTNode* pnew;
	for (int i = 0; i < 10; ++i) {
		pnew = (BiTree)calloc(1, sizeof(BTNode));
		pnew->data = a[i];
		listtag = (ptag)calloc(1, sizeof(tag));
		listtag->p = pnew;
		if (T == NULL) {
			T = pnew;
			pcur = listtag;
			phead = listtag;
			prear = listtag;
			continue;
		}
		else {
			if (pcur->p->left == NULL) {
				pcur->p->left = pnew;
				prear->next = listtag;
				prear = listtag;
			}
			else if (pcur->p->right == NULL) {
				pcur->p->right = pnew; 
				prear->next = listtag;
				prear = listtag;
				pcur = pcur->next;
			}
		}
	}
}
void PrintPreTree(BiTree T) {
	stack<BTNode*> stk;
	BTNode* p = T; 
	cout << "先序遍历：";
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			cout << p->data << ' ';
			stk.push(p);
			p = p->left;
		}
		BTNode* t = stk.top();
		stk.pop(); 
		if (t->right != NULL)
			p = t->right;
		
	}
	cout << endl;
}
void PrintOrderTree(BiTree T) {
	stack<BTNode*> stk;
	BTNode* p = T;
	cout << "中序遍历：";
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			stk.push(p);
			p = p->left;
		}
		BTNode* t = stk.top();
		cout << t->data << ' ';
		stk.pop();
		if (t->right != NULL)
			p = t->right;

	}
	cout << endl;
}
void PrintLevelTree(BiTree T) {
	queue<BTNode*>que;
	BTNode* p = T;
	que.push(p);
	cout << "层序遍历：";
	while (!que.empty()) {
		BTNode* t = que.front();
		que.pop();
		cout << t->data << ' ';
		if (t->left != NULL)
			que.push(t->left);
		if (t->right != NULL)
			que.push(t->right);
		
	}
	cout << endl;
}
void PrintPostTree(BiTree T) {
	stack<BTNode* > stk;
	BTNode* p = T;
	cout << "后序遍历：";
	BTNode* prev = NULL;
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			stk.push(p);
			p = p->left;
		}
		p = stk.top();
		stk.pop();
		if (p->right == NULL || p->right == prev) {
			cout << p->data << ' ';
			prev = p;
			p = NULL;
		}
		else {
			stk.push(p);
			p = p->right;
			
		}
	}
	cout << endl;
}