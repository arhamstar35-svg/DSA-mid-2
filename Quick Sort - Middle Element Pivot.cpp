#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int pivot = arr[mid];

    int i = low;
    int j = high;

    while(i <= j) {
        while(arr[i] < pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }

    return i;
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pivotindex = partition(arr, low, high);

        quicksort(arr, low, pivotindex - 1);
        quicksort(arr, pivotindex, high);
    }
}
