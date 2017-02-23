#include<stdio.h>
/*
* 二路归并排序
* 2017-2-23
*/
void print(int *keys,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",*(keys+i));
    }
    printf("\n");
}

void imerge(int arr[],int len,int temp[],int begin1,int begin2,int n) {
    int i=begin1,j=begin2,k=begin1;
    while(i<begin1+n && j<begin2+n && j<len)
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while(i<begin1+n && i<len)
        temp[k++] = arr[i++];
    while(j<begin2+n && j<len)
        temp[k++] = arr[j++];
}

void mergePass(int arr[],int len,int temp[],int n) {
    for(int i=0;i<len;i+=2*n)
        imerge(arr,len,temp,i,i+n,n);
    print(temp,len);
}

void mergeSort(int arr[],int len) {
    int *temp = new int[len];
    int n = 1;
    while(n<len) {
        mergePass(arr,len,temp,n);
        n *= 2;
        if(n<len) {
            mergePass(temp,len,arr,n);
            n *= 2;
        }
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    mergeSort(arr,10);
    print(arr,10);
    return 0;
}
