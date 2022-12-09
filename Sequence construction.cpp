#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct BTree {
	ElemType data;
	struct BTree* left;
	struct BTree* right;
}BTNode, *BiTree;
typedef struct Que {
	BTNode* p;
	struct Que* next;
}tag_t, *ptag_t;
void Init(BiTree& T);
void CreateLevelTree(BiTree& T);
void OrderTraverse(BiTree T);
int main(void)
{
	BiTree T;
	Init(T);
	CreateLevelTree(T); 
	OrderTraverse(T);
	return 0;
}
void Init(BiTree& T) {
	T = NULL;

}
void CreateLevelTree(BiTree& T) {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	BTNode* pnew;
	ptag_t phead = NULL;
	ptag_t ptail = NULL;
	ptag_t list_pnew = NULL;
	ptag_t pcur = NULL;
	for (int i = 0; i < 10; ++i) {
		pnew = (BiTree)calloc(1, sizeof(BTNode));
		pnew->data = a[i];
		list_pnew = (ptag_t)calloc(1, sizeof(tag_t));
		list_pnew->p = pnew;
		if (T == NULL) {
			T = pnew;
			phead = list_pnew;
			ptail = list_pnew;
			pcur = list_pnew;
			continue;
		}
		else {
			if (pcur->p->left == NULL) {
				pcur->p->left = pnew;
				ptail->next = list_pnew;
				ptail = list_pnew;
			}
			else if (pcur->p->right == NULL) {
				pcur->p->right = pnew;
				ptail->next = list_pnew;
				ptail = list_pnew;
				pcur = pcur->next;
			}
			
		}
	}
}
void OrderTraverse(BiTree T) {
	if (T != NULL) {
		OrderTraverse(T->left);
		cout << T->data << ' ';
		OrderTraverse(T->right);
	}
}