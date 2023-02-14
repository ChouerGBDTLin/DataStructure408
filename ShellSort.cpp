#include <bits/stdc++.h>
using namespace std;
int* ShellSort(int* a, int n);

int main(void)
{
	int a[10] = { 5, 2, 9, 3, 5, 12, 6, 7, 11, 1 };
	int* b = ShellSort(a, 10);
	for (int i = 0; i < 10; ++i)
		cout << b[i] << ' ';
	
	return 0;
}
int* ShellSort(int* a, int n) {
	int d, i, j;
	int tmp;
	for (d = n / 2; d >= 1; d /= 2)
		for (i = d + 1; i < n; ++i)
			if (a[i] < a[i - d]) {
				tmp = a[i];
				for (j = i - d; j >= 0 && tmp < a[j]; j -= d)
					a[j + d] = a[j];
				a[j + d] = tmp;
			}
				
	return a;
}

//5, 2, 9, 3, 5, 12, 6, 7, 11, 1
//*  -        *   -            *