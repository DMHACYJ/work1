#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int select_(int arr[],int x,int right,int left)
{
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (arr[mid] > x)
		{
			right=mid-1;
			mid = (left + right) / 2;
		}
		if (arr[mid] < x)
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int x=7;
	int left = 0;
	int ret = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	ret = select_(arr, x, right, left);
	printf("%d\n",ret);
	system("pause");
	return 0;
}