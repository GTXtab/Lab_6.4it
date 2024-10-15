#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void genArray(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Type element [" << i << "]: ";
        cin >> arr[i];
    }
}

template <typename T>
void Print(const T* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(8) << arr[i];
    }
    cout << endl;
}

template <typename T>
T productElement(const T* arr, int size) {
    T product = 1.0;
    bool foundPositive = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            product *= arr[i];
            foundPositive = true;
        }
    }
    return foundPositive ? product : 0;
}

template <typename T>
T sumToMinElement(const T* arr, int size) {
    T sum = 0;
    T minValue = arr[0];
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }

    for (int i = 0; i < minIndex; i++) {
        sum += arr[i];
    }

    return sum;
}

template <typename T>
void sortArray(T* arr, int size) {
    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Type size of array: ";
    cin >> n;

    double* arr = new double[n];

    genArray(arr, n);
    cout << "FirstArray:" << endl;
    Print(arr, n);

    double product = productElement(arr, n);
    cout << "ProductElements: " << product << endl;

    double sum = sumToMinElement(arr, n);
    cout << "SumToMin: " << sum << endl;

    sortArray(arr, n);
    cout << "SortedArray:" << endl;
    Print(arr, n);

    delete[] arr;

    return 0;
}
