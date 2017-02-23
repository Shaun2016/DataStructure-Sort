#include<stdio.h>
/*
* 快速排序
* 2017-2-20
*/

/*
快速排序算法分析：
    最好情况：每趟排序将序列分成长度相近的两个子序列，时间复杂度为O(n*logn)
    最坏情况：每趟将序列分成长度差异很大的两个子序列，时间复杂度为O(n*n)
    不稳定
*/

void print(int *keys,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",*(keys+i));
    }
    printf("\n");
}

void QuickSort(int arr[],int n,int ibegin,int iend) {
    if(ibegin<0 || iend<0 || ibegin>=n || iend>=n || ibegin>=iend)
        return;
    int i=ibegin,j=iend;
    int vot = arr[i];
    while(i!=j) {
        while(i<j&&vot<=arr[j])
            j--;
        if(i<j)
            arr[i++] = arr[j];
        while(i<j && arr[i]<=vot)
            i++;
        if(i<j)
            arr[j--] = arr[i];
    }
    arr[i] = vot;
    print(arr,n);
    QuickSort(arr,n,ibegin,j-1);
    QuickSort(arr,n,i+1,iend);
}

int main() {
    int arr1[] = {9,6,5,8,7,2,3,1,4,0};
    QuickSort(arr1,10,0,9);
    print(arr1,10);
    return 0;
}
