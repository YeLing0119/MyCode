#include "AllSort.h"
#include <stdio.h>

void swap(int *left, int *right){
    int temp = *left;
    *left = *right;
    *right = temp;
}

void PrintArray(int *arr, int size){
    for (int i = 0; i < size; ++i){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int *arr, int size){
    for (int i = 0; i < size - 1; ++i){
        int swap_flag = 0;
        for (int j = 0; j < size - i - 1; ++j){
            if (arr[j] > arr[j + 1]){
                swap_flag = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (swap_flag == 0){
            return;
        }
    }
}

void InsterSort(int *arr, int size){
    for (int start = 1; start < size; ++start){
        int key = arr[start];
        int prev = start - 1;
        while (prev >= 0 && key < arr[prev]){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }
}

void ShellSort(int *arr, int size){
    int gap = size;
    while (gap > 1){
        gap = (gap / 3) + 1;
        for (int start = gap; start < size; ++start){
            int key = arr[start];
            int prev = start - gap;
            while (prev >= 0 && key < arr[prev]){
                arr[prev + gap] = arr[prev];
                prev -= gap;
            }
            arr[prev + gap] = key;
        }
    }
}

void SelectSort(int *arr, int size){
    int start = 0;
    int end = size;
    while (start < end){
        int max = start;
        int min = start;
        for (int cur = start; cur < end; ++cur){
            if (arr[cur] > arr[max]){
                max = cur;
            }
            if (arr[cur] < arr[min]){
                min = cur;
            }
        }
        // 修正特殊情况　最大值在最小索引处，最小值在最大索引处
        swap(&arr[max], &arr[end - 1]);
        if(min == end - 1){
            min = max;
        }
        swap(&arr[start], &arr[min]);
        end--;
        start++;
    }
}


// 第一种方式：选择基准值，先从前到后找第一个大于基准值的，
// 然后从后往前找第一个小于基准值的，交换两个值，
// 当前后指针相遇时，交换相遇点和基准点的值
int DivWay1(int *arr, int left, int right){
    int start = left;
    int end =  right - 1;
    int key = arr[right - 1];

    while(start < end){
        while(start < end && arr[start] < key){
            start++;
        }

        while(start < end && arr[end] >= key){
            end--;
        }

        swap(&arr[start], &arr[end]);
    }

    swap(&arr[right-1], &arr[start]);

    return start;
}

// 取最后一个为基准值，保存基准值，然后基准值这里就形成了一个‘坑’
// end 指针刚开始放在最有一个数处，标记这个‘坑’
// start 指针　从前往后找第一个大于基准值的数，填入这个坑，start 处就又形成一个‘坑’
// end 指针从后往前找，找到第一个小于基准值的填入坑中，如此循环
// 当　start 指针与 end 指针相遇时，把key值填入最后的‘坑’中

int DivWay2(int *arr, int left, int right){
    int start = left;
    int end = right - 1;
    int key = arr[right - 1];

    while(start < end){
        while(start < end && arr[start] < key){
            start++;
        }
        swap(&arr[start], &arr[end]);

        while(start < end && arr[end] > key){
            end--;
        }
        swap(&arr[start], &arr[end]);
    }
    arr[start] = key;
    return start;
}

// 两个指针，start = left ; end = left - 1;
// 详细不详，待补充

int DivWay3(int *arr, int left, int right){
    int cur = left;
    int pre = left;
    int key = arr[right - 1];

    //while(start < size){
    //    while(){
    //        
    //    }
    //}
}

void QuickSort(int *arr, int left, int right){
    if(left < right){
        int divpos = DivWay2(arr, left, right);
        QuickSort(arr, left, divpos);
        QuickSort(arr, divpos + 1, right);
    }
}

void AdjustArray(int *arr, int root, int size){
    // 升序 ---> 大堆
    // 降序 ---> 小堆
    
    int parent = root;
    // 默认左孩子最大
    int child = parent * 2 + 1 ;

    while(child < size){
        //　如果右孩子存在且右孩子比左孩子大，标记右孩子
        if(child + 1 < size && arr[child + 1] > arr[child]){
            child += 1;
        }
        // 若最大的的孩子比父节点大，则交换
        if(arr[parent] < arr[child]){
            swap(&arr[parent], &arr[child]);
        }

        parent = child;
        child = parent * 2 + 1;
    }
}

void HeapSort(int *arr, int size){
    // 建堆
    int root = (size - 2) >> 1;
    for(; root >= 0; --root){
        AdjustArray(arr, root, size);
    }

    // 从堆中取除最大的，放入最后，堆　size --
    int count = size - 1;
    while(count > 0){
        swap(&arr[0], &arr[count]);
        AdjustArray(arr, 0, count);
        count--;
    }
}