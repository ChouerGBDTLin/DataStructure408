#include <bits/stdc++.h>
using namespace std; 
void Swap(int &a, int &b) { int t = a; a = b; b = t; }
void BubbleSort(int* a, int n);
void QuickSort(int* a, int low, int high);
int Partition(int* a, int low, int high);
void InsertSort(int* a, int n);
void Printa(int* a) { for (int i = 0; i < 10; ++i) cout << a[i] << ' '; cout << endl; }
int main(void)
{
	int a[10] = { 9, 5, 2, 19, 3, 90, 4, 66, 2, 11};
	BubbleSort(a, 10);
	int b[10] = { 9, 5, 2, 19, 3, 90, 4, 66, 2, 11 };
	QuickSort(b, 0, 9);
	Printa(b);
	int c[10] = { 9, 5, 2, 19, 3, 90, 4, 66, 2, 11 };
	InsertSort(c, 10);
	Printa(c);
	return 0;
}
void BubbleSort(int* a, int n) {	// 冒泡排序
	int i, j; 
	for (i = 0; i < n; ++i) 
		for (j = n - 1; j > i; --j)
			if (a[j] < a[j - 1]) 
				Swap(a[j - 1], a[j]);  

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}
void QuickSort(int* a, int low, int high) {
	if (low < high) {
		int t = Partition(a, low, high);
		QuickSort(a, low, t - 1);
		QuickSort(a, t + 1, high);
	}
}
int Partition(int* a, int low, int high) { 
	int t = a[low];
	while (low < high) {
		
		while (t <= a[high] && low < high) high--;
		a[low] = a[high];
		while (t >= a[low] && low < high) low++;
		a[high] = a[low];
	}
	a[low] = t;
	return low;
}
void InsertSort(int* a, int n) {
	int j;
	for (int i = 1; i < n; ++i) {
		int insertVal = a[i];
		for (j = i - 1; j >= 0 && a[j] >= insertVal; --j)
			a[j + 1] = a[j];
		a[j + 1] = insertVal;
	}
	
}