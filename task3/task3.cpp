#include <iostream>
#include <string.h>

using namespace std;

char* myStrncpy(char* dest, const char* src, size_t num) {
    for (size_t i = 0; i < num; i++)
    {
        dest[i] = src[i];
    }

    return dest;
}

int main()
{
    const size_t num = 5;
    const char* src = "Источник";
    char dest[num+1];
    setlocale(LC_ALL, "Russian");

    printf("Стандартная функция strncpy: ");
    char* result = strncpy(dest, src, num);
    result[num] = '\0';
    cout << result << endl;

    printf("Собственная функция myStrncpy: ");
    char* myResult = myStrncpy(dest, src, num);
    myResult[num] = '\0';
    cout << myResult << endl;
}

