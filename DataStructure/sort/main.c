#include "AllSort.h"
#include <stdio.h>

int main(){
    
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Before Sort : ");
    PrintArray(arr, sizeof(arr)/sizeof(arr[0]));


    //BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));

    //InsterSort(arr, sizeof(arr)/sizeof(arr[0]));

    //ShellSort(arr, sizeof(arr)/sizeof(arr[0]));

    //SelectSort(arr, sizeof(arr)/sizeof(arr[0]));

    //QuickSort(arr, 0, sizeof(arr)/sizeof(arr[0]));

    //HeapSort(arr, sizeof(arr)/sizeof(arr[0]));

    printf("After  Sort : ");
    PrintArray(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}