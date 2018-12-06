#include "AllSort.h"
#include <stdio.h>

int main(){
    
    int arr[] = {2, 5, 4, 8, 9, 6, 1, 7, 3, 0};

    printf("Before Sort : ");
    PrintArray(arr, sizeof(arr)/sizeof(arr[0]));


    //BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));

    //InsterSort(arr, sizeof(arr)/sizeof(arr[0]));

    ShellSort(arr, sizeof(arr)/sizeof(arr[0]));

    printf("After  Sort : ");
    PrintArray(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}