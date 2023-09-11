#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };
    int N = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, N);
    cout << "Insertion Sorted array: \n";
    printArray(arr, N);

    return 0;
}