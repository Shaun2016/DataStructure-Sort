#include<stdio.h>
/*
* 插入排序:
    1.直接插入排序
    2.折半插入排序
* 2017-2-16
*/

/*
直接插入排序算法分析：
    数据序列有 n 个元素，直接插入排序执行 n-1 趟：
    最好情况：{1,2,3,4,5,6}，每趟元素ai与ai-1比较一次，移动2次（arr[i]到temp再返回）
            比较次数为n-1，移动次数为2*(n-1)，时间复杂度为O(n)
    最坏情况：{6,5,4,3,2,1}，第i趟插入元素ai比较i次，移动i+2次。
            比较次数为C=1+2+...+n-1=n(n-1)/2≈n*n/2,移动次数(1+2)+(2+2)+...+(n-1+2)=(n-1)(n+4)/2≈n*n/2,时间复杂度为O(n*n)
    随机情况：时间复杂度O(n*n)
    temp占用了一个存储单元，空间复杂度为O(1)
    关键字相等的元素会遇到一起进行比较，算法不会改变他们的原有次序：稳定
    如果改成：for(j=i-1;j>=0&&temp<=arr[j];j--) 则变为不稳定的
*/
void StraightInsertionSort(int arr[],int length) {
    int icount = 0;
    for(int i=1;i<length;i++) {
        int temp = arr[i];
        int j;
        for(j=i-1;j>=0&&temp<arr[j];j--) {
            icount++;
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    printf("Straight Insertion Sort times: %d\n",icount);
}

int binarySearch(int key,int* arr,int ibegin,int iend);
/*

*/
void BinaryInsertionSort(int arr[],int length) {
    int icount = 0;
	for (int i = 1; i<length; i++) {
		int temp = arr[i];
		int j = binarySearch(temp, arr, 0, i);
		for (int k = i; k>j; k--) {
			icount++;
			arr[k] = arr[k - 1];
		}
		arr[j] = temp;
	}
	printf("Binary Insertion Sort times: %d\n", icount);
}

int main() {
    //直接插入排序
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    StraightInsertionSort(arr1,10);
    for(int i=0;i<10;i++) {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    //二分插入排序
    int arr2[] = {9,8,7,6,5,4,3,2,1,0};
    BinaryInsertionSort(arr2,10);
    for(int i=0;i<10;i++) {
        printf("%d ",arr2[i]);
    }
    printf("\n");

    return 0;
}

int binarySearch(int key,int* arr,int ibegin,int iend) {
    while(iend - ibegin > 1) {
        int mid = (ibegin + iend)/2;
        if(key < arr[mid])
            iend = mid - 1;
        else
            ibegin = mid + 1;
        }
    if(key > arr[iend])
        return iend+1;
    if(key < arr[ibegin])
        return ibegin;
    return iend;
}
