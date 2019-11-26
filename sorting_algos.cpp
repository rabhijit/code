#include <bits/stdc++.h>
using namespace std;

#define SIZE 12

void bubble_sort(int*);
void selection_sort(int*);
void insertion_sort(int*);
void merge_sort(int*, int, int);
void merge(int*, int, int, int);
void quicksort(int*, int, int);
int partition(int*, int, int);
void counting_sort(int*);
void radix_sort(int*);

int main() {
    int arr[SIZE] = {234, 6, 346, 89, 73, 12, 6, 0, 1, 235, 2};
    int arr2[SIZE] = {3, 9, 7, 4, 6, 0, 2, 1, 8, 5, 0, 7};
    radix_sort(arr);
    //counting_sort(arr2);
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
        //cout << arr2[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[SIZE]) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < SIZE - 1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
    }
}

void selection_sort(int arr[SIZE]) {
    int index = 0;
    while (index < SIZE - 1) {
        bool found = false;
        int minimum = index;
        for (int i = index; i < SIZE; i++) {
            if (arr[i] < arr[minimum]) {
                minimum = i;
                found = true;
            }
        }
        if (found) {
            swap(arr[index], arr[minimum]);
        }
        index++;
    }
}

void insertion_sort(int arr[SIZE]) {
    int max_sorted = 1;
    while (max_sorted != SIZE) {
        for (int i = max_sorted; i > 0 && arr[i] < arr[i-1]; i--) {
            if (arr[i] < arr[i-1]) {
                swap(arr[i], arr[i-1]);
            }
        }
        max_sorted++;
    }
}

void merge_sort(int arr[SIZE], int low, int high) {
  int mid = (high + low) / 2;
  if (high > low) {
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

void merge(int arr[SIZE], int low, int mid, int high) {
  int temp_arr[high-low+1];
  int left_index = low;
  int right_index = mid + 1;
  int temp_index = 0;

  while (left_index <= mid && right_index <= high) {
    if (arr[left_index] < arr[right_index]) {
      temp_arr[temp_index] = arr[left_index];
      left_index++;
    }
    else {
      temp_arr[temp_index] = arr[right_index];
      right_index++;
    }
    temp_index++;
  }

  while (left_index <= mid) {
    temp_arr[temp_index] = arr[left_index];
    left_index++;
    temp_index++;
  }
  while (right_index <= high) {
    temp_arr[temp_index] = arr[right_index];
    right_index++;
    temp_index++;
  }
  for (int i = 0; i < (high - low + 1); i++) {
    arr[low + i] = temp_arr[i];
  }
}

void quicksort(int arr[SIZE], int low, int high) {
    if (low < high) {
        int median = partition(arr, low, high);
        quicksort(arr, low, median-1); // median element already sorted
        quicksort(arr, median+1, high);
    }
}

int partition(int arr[SIZE], int low, int high) {
    int pivot = low;
    int median = pivot;
    for (int i = median+1; i <= high; i++) {
        if (arr[i] < arr[pivot]) {
            median++;
            swap(arr[median], arr[i]);
        }
    }
    swap(arr[median], arr[pivot]);
    return median;
}

void counting_sort(int arr[SIZE]) {
    int frequencies[SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        frequencies[arr[i]]++;
    }
    int arr_counter = 0;
    int freq_counter = 0;
    while (arr_counter < SIZE) {
        for (int j = 0; j < frequencies[freq_counter]; j++) {
            arr[arr_counter] = freq_counter;
            arr_counter++;
        }
        freq_counter++;
    }
}

void radix_sort(int arr[SIZE]) {
    int maximum = arr[*max_element(arr, arr+SIZE)];
    for (int exponent = 1; maximum / exponent > 0; exponent *= 10) {
        for (int i = 0; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        int output[SIZE];
        int radix[10] = {0};
        for (int i = 0; i < SIZE; i++) {
            radix[(arr[i] / exponent) % 10]++;
        }
        for (int j = 1; j < 10; j++) {
            radix[j] += radix[j - 1]; // adjusting each element in radix to the first position of its
        }
        for (int k = SIZE - 1; k >= 0; k--) {
            output[radix[(arr[k] / exponent) % 10] - 1] = arr[k];
            radix[(arr[k] / exponent) % 10]--;
        }
        for (int l = 0; l < SIZE; l++) {
            arr[l] = output[l];
        }
    }
}
