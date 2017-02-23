#include<stdio.h>
/*
* 选择排序包括：直接选择和堆排序
* 直接选择排序
* 2017-2-21
*/

void print(int *keys,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",*(keys+i));
    }
    printf("\n");
}

void iswap(int arr[],int i,int imin) {
    int temp = arr[i];
    arr[i] = arr[imin];
    arr[imin] = temp;
}
/*
直接选择排序算法分析
        直接选择排序的比较次数与数据序列的初始排列无关，第i趟排序的比较次数是 n-i;
        移动次数与初始排序有关，排序序列移动 0 次，反序序列每趟都要交换，移动 3(n-1) 次
        时间复杂度为 O(n*n)
        空间复杂度为 O(1)
        不稳定
*/
void StraightSelectSort(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int imin = i;
        for(int j=i;j<n-1;j++)
            if(arr[j+1]<arr[imin])
                imin = j+1;
        if(imin != i)
            iswap(arr,i,imin);
            print(arr,n);
    }
}

int main() {
    int arr[] = {9,6,5,8,7,2,3,1,4,0};
    StraightSelectSort(arr,10);
    print(arr,10);
    return 0;
}
