#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    int j = high - 1;

    while(i <= j) {
        while(i <= j && arr[i] < pivot) {
            i++;
        }

        while(j >= i && arr[j] > pivot) {
            j--;
        }

        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else {
            break;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pivotindex = partition(arr, low, high);

        quicksort(arr, low, pivotindex - 1);
        quicksort(arr, pivotindex + 1, high);
    }
}
