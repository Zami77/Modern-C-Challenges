#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j;
    int arrLeftLength = m - l + 1;
    int arrRightLength = r - m;

    int arrLeft[arrLeftLength], arrRight[arrRightLength];

    //Fill up left and right array
    for(int i = 0; i < arrLeftLength; i++)
        arrLeft[i] = arr[l + i];
    for(int j = 0; j < arrRightLength; j++)
        arrRight[j] = arr[m + 1 + j];

    int LIndex = 0,RIndex = 0,arrIndex = l;

    //Sort array until left or right array is depleted
    while(LIndex < arrLeftLength && RIndex < arrRightLength)
    {
        if(arrLeft[LIndex] <= arrRight[RIndex])
            arr[arrIndex++] = arrLeft[LIndex++];
        else
            arr[arrIndex++] = arrRight[RIndex++];
    }
    //Clean up left array
    while(LIndex < arrLeftLength)
    {
        arr[arrIndex++] = arrLeft[LIndex++];
    }
    //Clean up right array
    while(RIndex < arrRightLength)
    {
        arr[arrIndex++] = arrRight[RIndex++];
    }

}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partition(arr,low, high);

        //Split array
        quickSort(arr,low,partitionIndex -1);
        quickSort(arr,partitionIndex + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int lowIndex = low - 1;

    for(int curIndex = low; curIndex < high; curIndex++)
    {
        if(arr[curIndex] < pivot)
        {
            lowIndex++;
            swap(&arr[lowIndex], &arr[curIndex]);
        }
    }
    swap(&arr[lowIndex + 1],&arr[high]);
    return lowIndex + 1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        printf("Array[%d]: %d\n", i, arr[i]);
    }
}

int main(void)
{
    int nums[] = { 14,1,74,9,6,3,41 };
    int numsLength = sizeof(nums) / sizeof(nums[0]);
    printf("Unsorted Array\n");
    printArray(nums, numsLength);
    mergeSort(nums,0, numsLength-1);
    printf("Merge Sort\n");
    printArray(nums, numsLength);
    int quickNums[] = { 14,1,74,9,6,3,41 };
    printf("Unsorted Array\n");
    printArray(quickNums, numsLength);
    quickSort(quickNums,0,numsLength-1);
    printf("Quick Sort\n");
    printArray(quickNums, numsLength);
    return 0;
}
