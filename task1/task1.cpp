#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

void fillEvenIndices(int arr[], size_t N) {
    int degree = 1;
    for (size_t i = 0; i < N; i += 2)
    {
        arr[i] = pow(2, degree);
        degree++;
    }
}

void fillOddIndices(int arr[], size_t N) {
    int degree = 1;
    for (size_t i = 1; i < N; i += 2)
    {
        arr[i] = pow(3, degree);
        degree++;
    }
}

int* processArray(int arr[], size_t N) {
    fillEvenIndices(arr, N);
    fillOddIndices(arr, N);
    return arr;
}

void initializeArray(int arr[], size_t N) {
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = 1;
    }
}

bool isNumberContainsDigit(int number, int digit) {
    do {
        if (number % 10 == digit) {
            return true;
        }
    } while (number /= 10);
    return false;
}

int countOfNumbersContainingDigit(int arr[], size_t N) {
    int count = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (isNumberContainsDigit(arr[i], 1))
            count++;
    }

    return count;
}

int* bubbleSort(int arr[], size_t N) {
    int temp;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}

void printArray(int arr[], size_t N) {
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    const size_t N = 16;
    int arr[N];
    setlocale(LC_ALL, "Russian");

    initializeArray(arr, N);

    int* resultArray = processArray(arr, N);
    printf("Заполненный массив:\n");
    printArray(resultArray, N);


    int* sortedArray = bubbleSort(resultArray, N);
    printf("Отсортированный массив:\n");
    printArray(sortedArray, N);

    int cnt = countOfNumbersContainingDigit(sortedArray, N);
    printf("cnt = %d", cnt);
}

