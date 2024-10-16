#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Function to perform Quicksort
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to get the maximum number from the array
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Function to perform Counting Sort (used in Radix Sort)
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform Radix Sort
void radixSort(std::vector<int>& arr) {
    int maxNum = getMax(arr);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    printArray(arr);

    // Quicksort
    std::vector<int> quicksortArr = arr;
    quicksort(quicksortArr, 0, quicksortArr.size() - 1);
    std::cout << "Sorted array using Quicksort: ";
    printArray(quicksortArr);

    // Radix Sort
    std::vector<int> radixSortArr = arr;
    radixSort(radixSortArr);
    std::cout << "Sorted array using Radix Sort: ";
    printArray(radixSortArr);

    return 0;
}
