#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <string>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void generateRandomData(std::vector<int>& arr, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    arr.resize(size);
    for (int& num : arr) {
        num = dis(gen);
    }
}

void measureSortingTime(void (*sortFunc)(std::vector<int>&), std::vector<int>& data, const std::string& sortName) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << std::fixed << std::setprecision(6) << sortName << " took " << duration.count() << " seconds.\n";
}

int main() {
    const int dataSize = 1000;
    std::vector<int> data;

    generateRandomData(data, dataSize);
    
    std::vector<int> dataCopy = data;
    measureSortingTime(bubbleSort, dataCopy, "Bubble Sort");

    dataCopy = data;
    measureSortingTime(selectionSort, dataCopy, "Selection Sort");

    dataCopy = data;
    measureSortingTime(insertionSort, dataCopy, "Insertion Sort");

    return 0;
}
