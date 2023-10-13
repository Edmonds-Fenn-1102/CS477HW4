//
// Fenn Edmonds
// HW5
// 10/12/23
//

#include <iostream>
#include <stdio.h> 
using namespace std; 
  
void printArray(int A[], int n);

void merge(int array[], int const left, int const mid, int const right)
{
    auto const A1 = mid - left + 1;
    auto const A2 = right - mid;

    int leftArray[A1], rightArray[A2];

    for (auto i = 0; i < A1; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; j < A2; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    auto iA1 = 0, iA2 = 0;

    int iMA = left;

    while (iA1 < A1 && iA2 < A2)
    {
        if (leftArray[iA1] >= rightArray[iA2])
        {
            array[iMA] = leftArray[iA1];
            iA1++;
        }
        else
        {
            array[iMA] = rightArray[iA2];
            iA2++;
        }
        iMA++;
    }

    while (iA1 < A1)
    {
        array[iMA] = leftArray[iA1];
        iA1++;
        iMA++;
    }

    while (iA2 < A2)
    {
        array[iMA] = rightArray[iA2];
        iA2++;
        iMA++;
    }
}

void mergeSort(int array[], int const start, int const end)
{
    if (start >= end)
    {
        return;
    }

    auto mid = start + (end - start) / 2;
    printArray(array, end);
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, mid, end);
}

void printArray(int array[], int n)
{
    for (auto i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8 };
    auto n = sizeof(arr) / sizeof(arr[0]);

    cout << "Orginal: " << endl;
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted: " << endl;
    printArray(arr, n);
    return 0;
}
