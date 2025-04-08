#pragma once
#include <ctime> // for time keeping
#include <deque>
#include <cctype> // for isdigit
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../Colors.hpp"

// utils fn
bool isnum(const char *str);
void printVector(std::vector<int>& arr);

// template fn deque and vector compatible
template <typename T>
void merge(T &arr, int left, int mid, int right) {

    int i = left, j = mid + 1, k = 0;
    T finalArr(right - left + 1); // Reserve space if possible (for vector)

    while ( i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            finalArr[k] = arr[i];
            i += 1;
        } else {
            finalArr[k] = arr[j];
            j += 1;
        }
        k += 1;
    }
    while (i <= mid) {
        finalArr[k] = arr[i];
        i += 1;
        k += 1;
    }
    while (j <= right) {
        finalArr[k] = arr[j];
        j += 1;
        k += 1;
    }
    std::copy(finalArr.begin(), finalArr.end(), arr.begin() + left);
}

// inplace algo to sort arr base on comparisons btw each int pos bef key int
template <typename T>
void insertionSort(T &arr, int left, int right) {

    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void mergeInsertionSort(T &arr, int left, int right) {

    int const S = 5; // Threshold for insertionSort
    
    if (right - left + 1 <= S) {
        insertionSort(arr, left, right);
        return ;
    }

    int mid = left + ((right - left) / 2); // Reajusting middle element index to split subarr in half
    mergeInsertionSort(arr, left, mid); // create Left subarray to new middle.
    mergeInsertionSort(arr, mid + 1, right); // create Right subarray from new middle.

    // Once base case reached: send tmp subArrays vectors to merger and sorting
    merge(arr, left, mid, right);
}

