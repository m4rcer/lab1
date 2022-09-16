#include <iostream>
#include <math.h>

using namespace std;

void initializeArray(int* arr, size_t N) {
	for (size_t i = 0; i < N; i++)
	{
		arr[i] = pow(i, 2) - 1;

		if (i % 2 == 1)
			arr[i] *= -1;
	}
}

void fill2dArrayFromArray(int* arr, int** arr2d,
    const size_t N, const size_t M, const size_t K) {

    int index = 0;
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < K; j++)
        {
            arr2d[i][j] = arr[index];
            index++;
        }
    }
}

void printArray(int* arr, size_t N) {
    for (size_t i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2dArray(int** arr, size_t M, size_t K) {
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < K; j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout << endl;
    }
}

int* bubbleSortDescending(int* arr, size_t N) {
    int temp;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}

int main()
{
    const size_t N = 18;
    const size_t M = 6;
    const size_t K = 3;
    int* arr = new int[N];
    int** arr2d = new int*[M];
    for (std::size_t i = 0; i < M; ++i)	
    {
        arr2d[i] = new int[K];
    }
    setlocale(LC_ALL, "Russian");


    initializeArray(arr, N);


    cout << "Инициализированный массив:" << endl;
    printArray(arr, N);

    cout << "Отсортированный массив:" << endl;
    int* sortedArr = bubbleSortDescending(arr, N);
    printArray(sortedArr, N);

    cout << "Двухмерный массив:" << endl;
    fill2dArrayFromArray(sortedArr, arr2d, N, M, K);
    print2dArray(arr2d, M, K);
}

