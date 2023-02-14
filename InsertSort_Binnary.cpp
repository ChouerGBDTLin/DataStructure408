#include <bits/stdc++.h>
using namespace std;
int* InsertSort(int* a, int n);	//插入排序1——普通遍历
int* InsertSort_Binnary(int* a, int n); // 二叉查找进行遍历

int main(void)
{
	int a[10] = { 5, 2, 9, 3, 5, 12, 6, 7, 11, 1 };
	int* b = InsertSort(a, 10);
	for (int i = 0; i < 10; ++i)
		cout << b[i] << ' ';
	cout << endl;
	int aa[10] = { 5, 2, 9, 3, 5, 12, 6, 7, 11, 1 };
	int* c = InsertSort_Binnary(aa, 10);
	for (int i = 0; i < 10; ++i)
		cout << c[i] << ' ';
	return 0;
}
int* InsertSort(int* a, int n) {
	for (int i = 1; i < n; ++i) {
		int tmp = a[i];
		for (int j = i - 1; j >= 0; --j) {	//遍历判断需要比较的数字与左边的所有数字的大小
			if (a[j] < tmp) {	// 若a[j] 小于 需要比较的数字则进行交换(即将更小的数向右移动)
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	return a;
}
int* InsertSort_Binnary(int* a, int n) {
	for (int i = 1; i < n; ++i) {
		int tmp = a[i];
		int low = 0, high = i - 1, mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (a[mid] > tmp)
				low = mid + 1;
				
			else
				high = mid - 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			a[j + 1] = a[j];
		a[high + 1] = tmp;
	}

	return a;
}