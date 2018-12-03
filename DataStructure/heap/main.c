#include <stdio.h>
#include "heap.h"

int main(){
    //test();

    HDataType Arr[] = {7, 3, 0, 6, 9, 5, 8, 4, 2, 1};
    HeapSort(Arr, sizeof(Arr)/sizeof(Arr[0]));
    for(int i = 0 ; i < 10 ; i++){
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}