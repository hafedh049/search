#include <stdio.h>
#include <math.h>

// Linear Search (Recursive)
int linearSearchRecursive(int arr[], int start, int end, int key)
{
    if (start > end)
        return -1;

    if (arr[start] == key)
        return start;

    return linearSearchRecursive(arr, start + 1, end, key);
}

// Linear Search (Iterative)
int linearSearchIterative(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search (Recursive)
int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearchRecursive(arr, low, mid - 1, key);

        return binarySearchRecursive(arr, mid + 1, high, key);
    }

    return -1;
}

// Binary Search (Iterative)
int binarySearchIterative(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int jump(int arr[], int key, int step, int prev, int size) {
    if (arr[min(step, size) - 1] < key)
        return jump(arr, key, (int)(step + sqrt(size)), step, size);

    for (int i = prev; i < min(step, size); i++)
        if (arr[i] == key)
            return i;

    return -1;
}

int jumpSearchRecursive(int arr[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;

    return jump(arr, key, step, prev, size);
}

// Jump Search (Iterative)
int jumpSearch(int arr[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[min(step, size) - 1] < key) {
        prev = step;
        step += sqrt(size);

        if (prev >= size)
            return -1;
    }

    for (int i = prev; i < min(step, size); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Ternary Search (Recursive)
int ternarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = mid1 + (right - left) / 3;

        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (arr[mid1] > key)
            return ternarySearchRecursive(arr, left, mid1 - 1, key);

        if (arr[mid2] < key)
            return ternarySearchRecursive(arr, mid2 + 1, right, key);

        return ternarySearchRecursive(arr, mid1 + 1, mid2 - 1, key);
    }

    return -1;
}

// Ternary Search (Iterative)
int ternarySearchIterative(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = mid1 + (right - left) / 3;

        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (arr[mid1] > key)
            right = mid1 - 1;
        else if (arr[mid2] < key)
            left = mid2 + 1;
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

int fibonacciSearch(int arr[], int key, int left, int right, int fibMMinus2, int fibMMinus1, int fibM, int size) {
    if (left < right) {
        int mid = left + fibMMinus2;

        if (mid >= size)
            mid = size - 1;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            return fibonacciSearch(arr, key, mid + 1, right, fibMMinus1, fibMMinus2 - fibMMinus1, fibM - fibMMinus1, size);

        return fibonacciSearch(arr, key, left, mid, fibMMinus2, fibMMinus1 - fibMMinus2, fibM - fibMMinus1, size);
    }

    return -1;
}

int fibonacciSearchRecursive(int arr[], int size, int key) {
    int fibMMinus2 = 0;
    int fibMMinus1 = 1;
    int fibM = fibMMinus1 + fibMMinus2;

    while (fibM < size) {
        fibMMinus2 = fibMMinus1;
        fibMMinus1 = fibM;
        fibM = fibMMinus1 + fibMMinus2;
    }

    return fibonacciSearch(arr, key, 0, size, fibMMinus2, fibMMinus1, fibM, size);
}

// Fibonacci Search (Iterative)
int fibonacciSearchIterative(int arr[], int size, int key) {
    int fibM2 = 0; // (m-2)'th Fibonacci number
    int fibM1 = 1; // (m-1)'th Fibonacci number
    int fib = fibM1 + fibM2; // m'th Fibonacci number

    while (fib < size) {
        fibM2 = fibM1;
        fibM1 = fib;
        fib = fibM1 + fibM2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fibM2, size - 1);

        if (arr[i] < key) {
            fib = fibM1;
            fibM1 = fibM2;
            fibM2 = fib - fibM1;
            offset = i;
        } else if (arr[i] > key) {
            fib = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fib - fibM1;
        } else
            return i;
    }

    if (fibM1 && arr[offset + 1] == key)
        return offset + 1;

    return -1;
}

// Linear Probing (for Hash Tables with Open Addressing) - Linear Search
int linearProbingSearch(int hashTable[], int size, int key) {
    int hash = key % size;
    int index = hash;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % size;

        // If we have traversed the entire array
        if (index == hash)
            break;
    }

    return -1;
}

int exponentialSearch(int arr[], int size, int key) {
    if (arr[0] == key)
        return 0;

    int i = 1;
    while (i < size && arr[i] <= key)
        i *= 2;

    return binarySearchRecursive(arr, i / 2, min(i, size - 1), key);
}

// Interpolation Search
int interpolationSearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}