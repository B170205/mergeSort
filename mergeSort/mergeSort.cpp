// mergeSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"malloc.h"
void merge(int a[], int low, int mid, int high)//归并两个有序队列
{
	int *R;
	R = (int *)malloc((high - low + 1) * sizeof(int));
	int i=low, j=mid+1;//先申请空间，然后进行合并，分两段，low-mid，实区间。mid+1，high，实区间
	int k = 0;
	while (i <= mid&&j <=high)
	{
		if (a[i] <=a[j])
		{
			R[k] = a[i];
			k++;
			i++;
		}
		else
		{
			R[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
		R[k++] = a[i++];
	while (j <=high)
		R[k++] = a[j++];
	for (i = low, k = 0; i <= high; i++, k++)//将R数组中的内容赋值给a数组从low到high的位置,实区间，当时少一个=，调试很久
		a[i] = R[k];
}
void merge_pass(int a[], int length, int n)//根据length，划分出每次需要归并的序列
{
	int i;
	for (i = 0; i + 2 * length - 1< n; i += 2 * length)//如果归并的两个子序列都在数组里，那么可以划分左右两个序列
		merge(a, i, i + length - 1, i + 2 * length - 1);
	if ((i + length - 1) < n)//如果归并的右序列长度达不到length，那么右序列就是从i+length到n-1
		merge(a, i, i + length - 1, n - 1);

}

void merge_Sort(int a[], int n)
{
	int length;
	for (length = 1; length < n; length *= 2)//确定需要几轮排序，让序列的长度从1开始，每次翻倍，直到length大于n
		merge_pass(a, length, n);
}
void output(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}


int main()
{
	int a[10] = {1,-1,2,-2,9,3,-6,6,13,6 };
	merge_Sort(a, 10);
	output(a, 10);
	//system("PAUSE");
	return 0;
    
}

