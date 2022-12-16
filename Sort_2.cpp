/*选择排序、堆排序☆、归并排序*/
#include <bits/stdc++.h>
using namespace std;
class Sort {
public:
	void SelectSort(int* a, int len);	// 选择排序
	void HeapSort(int* a, int len) { BuildMaxHeap(a, len); }//堆排序
	void MergeSort(int* a, int low, int high);	// 归并排序
	void Merge(int* a, int low, int mid, int high); //归并
	void BuildMaxHeap(int* a, int len);	//建立大根堆
	void AdjustDown(int* a, int k, int len);	//调整子堆为大根堆
	void Swap(int& a, int& b) { int t = a; a = b; b = t; }	//两数交换
	void Print(int* a, int len) { for (int i = 0; i < len; ++i) cout << a[i] << ' '; cout << endl; }//输出
	int* GetArr() {	return a;}
private:
	int a[10] = { 48, 69, 22, 45, 24, 45, 99, 20, 90, 1 };
};
int main(void)
{
	Sort s;
	int *a = s.GetArr();
	s.SelectSort(a, 10);
	s.Print(a, 10);
	int* b = s.GetArr();
	s.HeapSort(a, 10);
	s.Print(a, 10);
	s.MergeSort(a, 0, 9);
	s.Print(a, 10);
	return 0;
} 
void Sort::SelectSort(int* a, int len) {
	for (int i = 0; i < len - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j)
			if (a[j] < a[min])
				min = j;
		if (min != i) Swap(a[min], a[i]);
		
	}
}
void Sort::BuildMaxHeap(int* a, int len) {
	for (int i = len / 2 - 1; i >= 0; --i)
		AdjustDown(a, i, len);	// 调整为大根堆
	Swap(a[0], a[len - 1]);	//将根节点与最后一个元素替换
	for (int i = len - 1; i > 1; --i) {//从最后一个元素开始，将其与根节点替换
		AdjustDown(a, 0, i);	//调整剩余元素为大根堆！
		Swap(a[0], a[i - 1]);
	}
		
		
		
}
void Sort::AdjustDown(int* a, int k, int len) {	
	int dad = k;
	int son = 2 * dad + 1;
	while (son < len) {
		if (son + 1 < len && a[son] < a[son + 1]) son++;
		if (a[dad] < a[son]) {
			Swap(a[dad], a[son]);
			dad = son;
			son = dad * 2 + 1;
		}
		else
			break;
	}
}
void Sort::MergeSort(int* a, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}
void Sort::Merge(int* a, int low, int mid, int high) {
	int i, j, k;
	int b[10];
	for (i = 0; i < 10; ++i) b[i] = a[i];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
		a[k] = (b[i] <= b[j] ? b[i++] : b[j++]);
	while (i <= mid) a[k++] = b[i++];
	while (j <= high) a[k++] = b[j++];
}
