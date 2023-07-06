#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100; // Максимальный размер массива

// Функция для считывания чисел из файла в массив
int readNumbersFromFile(const string& fileName, int numbers[]) {
    fstream inputFile(fileName);
    if (!inputFile) {
        cout << "Ошибка открытия файла" << endl;
        return 0;
    }

    int count = 0;
    int num;

    while (inputFile >> num && count < MAX_SIZE) {
        numbers[count++] = num;
    }

    inputFile.close();
    return count;
}

// Функция для сортировки массива по возрастанию
void sortArray(int numbers[], int size) {
    sort(numbers, numbers + size);
}

// Функция для поиска арифметической прогрессии в массиве
bool findArithmeticProgression(const int numbers[], int size) {
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (2 * numbers[j] == numbers[i] + numbers[k]) {
                    cout << "Найдена арифметическая прогрессия: " << numbers[i] << ", " << numbers[j] << ", " << numbers[k] << endl;
                    return true;
                }
            }
        }
    }

    cout << "Арифметическая прогрессия не найдена" << endl;
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numbers[MAX_SIZE];
    int size = readNumbersFromFile("./../array.txt", numbers);

    if (size == 0) {
        return 1;
    }

    sortArray(numbers, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    findArithmeticProgression(numbers, size);

    return 0;
}
