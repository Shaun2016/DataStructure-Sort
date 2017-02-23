#include<stdio.h>
/*
* 交换排序
* 2017-2-19
*/

//交换函数
void iswap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print(int *keys,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",*(keys+i));
    }
    printf("\n");
}

//冒泡排序
/*
 算法分析 ：比较相邻两个元素大小，如果反序则交换
            如果一趟比较发现isChanged为false，说明没有交换数据，排序已完成
            最好情况：数据序列排序，只需扫描一次，比较 n 次，没有数据移动，时间复杂度为 O(n)
            最坏情况：反序排列，扫描 n-1 趟，比较次数和移动次数都是 O(n*n),时间复杂度为 O(n*n)
            冒泡排序需要一个辅助元素用于交换：空间复杂度为 O(1)
            稳定的
*/
void BubbleSort(int arr[],int n) {
    bool isChanged = true;
    for(int i=1;i<n && isChanged;i++) {
        isChanged = false;
        for(int j=0;j<n-i;j++) {
            if(arr[j]>arr[j+1]) {
                iswap(arr,i,j);
                isChanged = true;
            }
        }
        print(arr,n);
    }
}

int main() {
    int arr[] = {5,2,1,4,6,3,9,8,7,0};
    BubbleSort(arr,10);
    print(arr,10);
    return 0;
}
