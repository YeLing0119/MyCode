#include "AllSort.h"
#include <stdio.h>

void swap(int *left, int *right){
    int temp = *left;
    *left = *right;
    *right = temp;
}

void PrintArray(int *arr , int size){
    for(int i = 0; i < size; ++i){
        printf("%d  ", arr[i]);
    }

    printf("\n");
}

void BubbleSort(int *arr , int size){
    for(int i = 0; i < size - 1; ++i){
        int swap_flag = 0;
        for(int j = 0; j < size - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap_flag = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if(swap_flag == 0){
            return;
        }
    }
}

void InsterSort(int *arr , int size){
    for(int start = 1; start < size; ++start){
        int key = arr[start];
        int prev = start - 1;
        while( prev >= 0 && key < arr[prev]){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }
}

void ShellSort(int *arr , int size){
    int gap = size;
    while(gap > 1){
        gap = (gap / 3) + 1;
        for(int start = gap; start < size; ++start){
            int key = arr[start];
            int prev = start - gap;
            while( prev >= 0 && key < arr[prev]){
                arr[prev + gap] = arr[prev];
                prev -= gap;
            }
            arr[prev + gap] = key;
        }
    }
}