#include <bits/stdc++.h>
using namespace std;
typedef struct BinarySearchTree {
	struct BinarySearchTree* left, * right;
	int data;
}BST, * PBST;
void InsertBST(PBST& T, int val);
void CreateBST(PBST& T);
void OrderTraverse(PBST T);
BST* LocalBST_Left_Max(PBST T);
void DeleteBST(PBST &T, int x);
int main(void)
{
	PBST T;
	CreateBST(T);
	OrderTraverse(T);
	DeleteBST(T, 3);
	cout << endl;
	OrderTraverse(T);
	return 0;
}
void CreateBST(PBST& T) {
	T = NULL;
	int a[10] = { 5, 3, 6 ,9, 1, 2, 8, 4, 7, 0 };
	for (int i = 0; i < 10; ++i) {
		InsertBST(T, a[i]);
	}
}
void InsertBST(PBST& T, int val) {
	if (T == NULL) {
		T = (PBST)calloc(1, sizeof(BST));
		T->data = val;
		T->left = NULL;
		T->right = NULL;
		return;
	}
	PBST p = T, parent = p;
	while (p) {
		parent = p;
		if (val == p->data)
			return;
		if (val > p->data)
			p = p->right;
		else if (val < p->data)
			p = p->left;
	}
	PBST t = (PBST)calloc(1, sizeof(BST));
	t->data = val;
	if (parent->data > val)
		parent->left = t;
	else
		parent->right = t;
}
void OrderTraverse(PBST T) {
	if (T != NULL) {
		OrderTraverse(T->left);
		cout << T->data << ' ';
		OrderTraverse(T->right);
	}
}
BST* LocalBST_Left_Max(PBST T) {
	PBST p = T, parent = p;
	while (p) {
		parent = p;
		p = p->right;
	}
	return parent;
}
void DeleteBST(PBST &T, int x) {
	if (T == NULL)
		return;
	if (T->data > x)
		DeleteBST(T->left, x);
	else if (T->data < x)
		DeleteBST(T->right, x);
	else {
		if (T->left == NULL) {
			PBST t = T;
			T = T->right;
			free(t);
		}
		else if (T->right == NULL) {
			PBST t = T;
			T = T->left;
			free(t);
		}
		else {
			PBST t = T->left;
			while (t->right != NULL)
				t = t->right;
			T->data = t->data;
			DeleteBST(T->left, t->data);
		}
	}

}
