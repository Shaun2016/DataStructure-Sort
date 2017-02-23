#include<stdio.h>
/*
* Title: 希尔排序
* 2017-2-19
*/
void print(int *keys,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",*(keys+i));
    }
    printf("\n");
}
//定义版
void shellSort(int arr[],int n) {
    for(int delta=(n>>1);delta>0;delta=(delta>>1)) {
        for(int i=0;i<delta;i++) {
            for(int j=i+delta;j<n;j+=delta) {
                if(arr[j] < arr[j-delta]) {
                    int temp = arr[j];
                    int k = j-delta;
                    while(k >= 0 && arr[k] > temp) {
                        arr[k+delta] = arr[k];
                        k -= delta;
                    }
                    arr[k + delta] = temp;
                }
            }
        }
        print(arr,n);
    }
}

//优化版
void shellSort2(int arr[],int n) {
    for(int delta=n/2;delta > 0;delta /= 2) {
        for(int j=delta;j<n;j++) {
            if(arr[j] < arr[j-delta]) {
                int temp = arr[j];
                int k = j - delta;
                while(k >= 0 && arr[k] > temp) {
                    arr[k+delta] = arr[k];
                    k -= delta;
                }
                arr[k + delta] = temp;
            }
        }
        print(arr,n);
    }
}

//优化版
void shellSort3(int arr[],int n) {
    for(int delta=n>>1;delta>0;delta = delta>>1) {
        for(int i=delta;i<n;i++) {
            for(int j=i-delta;j>=0&&arr[j]>arr[j+delta];j -= delta) {
                int temp = arr[j];
                arr[j] = arr[j+delta];
                arr[j+delta] = temp;
            }
        }
        print(arr,n);
    }
}

int main() {
    int arr[] = {5,2,1,4,6,3,9,8,7,0};
    shellSort3(arr,10);
    print(arr,10);
    return 0;
}
