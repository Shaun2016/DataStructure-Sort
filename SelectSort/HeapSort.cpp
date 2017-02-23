#include<stdio.h>
/*
* 堆排序
* 2017-2-21
*/

void print(int *keys,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",*(keys+i));
    }
    printf("\n");
}

//调整为最小堆
void sift_minheap(int keys[],int n,int ibegin,int iend) {
    int parent = ibegin,child = 2*parent + 1;
    int value = keys[parent];
    while(child <= iend) {
        if(child<iend && keys[child]>keys[child+1])
            child++;
        if(value>keys[child]) {
            keys[parent] = keys[child];
            parent = child;
            child = 2*parent + 1;
        }
        else break;
    }
    keys[parent] = value;
    print(keys,n);
}

//交换函数
void iswap(int keys[],int n,int m) {
    int temp = keys[n];
    keys[n] = keys[m];
    keys[m] = temp;
}

//堆排序
/*
堆排序算法分析：
        将一个数据序列调整为堆的时间复杂度为O(logn),因此堆排序的时间复杂度为O(n*logn)
        空间复杂度为O(1)
        不稳定
        最小（大）堆得到的结果是降（升）序的
*/
void HeapSort(int keys[],int n) {
    for(int i=n/2-1;i>=0;i--) {
        sift_minheap(keys,n,i,n-1);
    }
    for(int i=n-1;i>0;i--) {
        iswap(keys,0,i);
        sift_minheap(keys,n,0,i-1);
    }
}

int main() {
    int arr[] = {6,3,2,5,9,8,7,4,0,1};
    HeapSort(arr,10);
    print(arr,10);
    return 0;
}
