#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stack>
using namespace std;
/*插入排序*/
//时间：O(N^2)
//空间：O(1)
//稳定性：稳定
void InsertSort(int* a, int n)
{
	assert(a);
	int i;
	for (i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

/*希尔排序*/
//时间:O(n^1.3 - n^2)
//空间：O(1)
//稳定性：不稳定
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*选择排序*/
//时间：O(N^2)
//空间：O(1)
//稳定性：稳定
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	//每次选一个最大的和最小的，放到相应的位置
	while (begin < end)
	{
		int i, max, min;
		max = min = begin;
		for (i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] >= a[min])//if (a[i] > a[min]) 修改条件后不稳定
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		--end;
	}
}

/*堆排序*/
//时间：O(n * log(n))
//空间：O(1)
//稳定性：
void ShiftDown(int* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//当前节点是否有孩子
	while (child < n)
	{
		//是否有右孩子，有则进行比较
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//孩子是否大于父亲，大则进行交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			//更新下一次调整的位置
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//以父亲为根的子树已经是一个大堆，结束调整
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	assert(a);
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		ShiftDown(a, n, i);
	}
	while (n > 1)
	{
		Swap(&a[0], &a[n - 1]);
		ShiftDown(a, n - 1, 0);
		n--;
	}
}

/*冒泡排序*/
//时间：O(n^2)
//空间：O(1)
//稳定性：稳定
void BubbleSort(int* a, int n)
{
	assert(a);
	for (int i = n; i > 0; i--)
	{
		int flag = 0;
		for (int j = 0; j < i - 1; j++)
		{
			//标记一次的冒泡过程是否发生元素交换
			flag = 1;
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
		if (flag == 0)//如果没有发生元素交换，提前结束
			break;
	}
}

//快速排序
//时间复杂度：N * logN
//空间复杂度：空间可以复用，最大的递归调用链 ---> logN
int getMid(int* a, int left, int right) {
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left]) {
		if (a[mid] < a[right]) return mid;
		else {
			if (a[left] > a[right]) return left;
			else return right;
		}
	}
	else {
		if (a[left] < a[right]) return left;
		else {
			if (a[mid] > a[right]) return mid;
			else return right;
		}
	}
}
int PartSort(int* a, int left, int right) {
	int mid = getMid(a, left, right);
	int start = left;
	Swap(&a[start], &a[mid]);
	int key = a[start];
	while (left < right) {
		while (left < right && a[right] >= key)  --right;
		while (left < right && a[right] <= key)  ++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[start], &a[left]);
	return left;
}
void QuickSort(int* a, int left, int right) {
	if (left >= right) return;
	else if (left - right + 1 < 5) {
		InsertSort(a + left, right - left + 1);
	} 
	else {
		int mid = PartSort(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
}

int PartSort2(int* a, int left, int right) {
	int key = a[left];
	while (left < right) {
		while (left < right && a[right] >= key)  --right;
		a[left] = a[right];
		while (left < right && a[right] <= key)  ++left;
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

int PartSort3(int* a, int left, int right) {
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	//最后一个小于key的位置
	int prev = left;
	//下一个小于key的位置
	int cur = left + 1;
	int key = a[left];
	//如果下一个小于key的位置于上一个小于key的位置不连续
	//说明中间有大于key的值，进行交换，大--->向后移动，小<---向前移动
	while (cur < right) {
		if (a[cur] < key && ++prev != cur) Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[left], &a[prev]);
	return left;
}

//非递归
void QuickSortNoR(int* a, int left, int right) {
	stack<int> st;
	if (left < right) {
		st.push(right);
		st.push(left);
	}
	while (st.empty() == 0) {
		int begin = st.top();
		st.pop();
		int end = st.top();
		st.pop();
		//划分当前区间
		int mid = PartSort3(a, begin, end);
		//划分左右子区间
		if (begin < mid - 1) {
			st.push(mid - 1);
			st.push(begin);
		}
		if (mid + 1 < end) {
			st.push(end);
			st.push(mid + 1);
		}
	}
}

/*合并牌序*/
//时间：O(N * logN)
//空间：O(N + logN) ~ O(N) 
//稳定性：稳定
void _MergeSort(int* a, int left, int right, int* tmp)
{
	assert(a);
	//区间只剩一个元素，无需分解和归并
	if (left >= right)
		return;
	//分解
	int mid = (right - left) / 2 + left;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//合并
	int begin1 = left, end1 = mid, begin2 = mid + 1, end2 = right;
	int tmpindex = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[tmpindex++] = a[begin1++];
		}
		else
		{
			tmp[tmpindex++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[tmpindex++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[tmpindex++] = a[begin2++];
	}
}
void MergeSort(int* a, int n)
{
	assert(a);
	int *tmp = (int*)malloc(n * sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

/*计数排序*/
//时间：O(max(N, 范围))
void CountSort(int* a, int n) {
	//范围：0~最大值 90 100
	//范围：最小值~最大值
	int min = a[0], max = a[0];
	int i;
	//获取数据范围
	for (i = 1; i < n; ++i) {
		if (a[i] < min) min = a[i];
		if (a[i] > max) max = a[i];
	}
	//
	int range = max - min - 1;
	int *CountArr = (int*)malloc(sizeof(int)*range);
	memset(CountArr, 0, sizeof(int)*range);
	//计数
	for (i = 0; i < n; ++i) {
		CountArr[a[i] - min]++;
	}
	int index = 0;
	for (i = 0; i < range; ++i) {
		while (CountArr[i]--) {
			a[index++] = i + min;
		}
	}
}

void ArrayPrint(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testSort()
{
	int a[] = { 10, 2, 3, 8, 9, 7, 6, 1, 5, 4 };
	ArrayPrint(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	ArrayPrint(a, sizeof(a) / sizeof(int));
}

int main()
{
	testSort();
	system("pause");
	return 0;
}