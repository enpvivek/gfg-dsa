#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void maxHeapify(int arr[], int i, int n)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, largest, n);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}