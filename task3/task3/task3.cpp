#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double* lastmonth(int n, int minPrice, int maxPrice) {
    double* prices = new double[n];
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < n; i++) {
        prices[i] = rand() % (maxPrice - minPrice + 1) + minPrice; // Генерация случайного числа в диапазоне [minPrice, maxPrice]
    }
    cout << "Цены в прошлом месяце: ";
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;
    return prices;
}

double* currentmonth(int n, int minPrice, int maxPrice) {
    double* prices = new double[n];
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < n; i++) {
        prices[i] = rand() % 200; // Генерация случайного числа в диапазоне [minPrice, maxPrice]
    }
    cout << "Цены в текущем месяце: ";
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;
    return prices;
}

int* numofproducts(int n, int minVal, int maxVal) {
    int* arr = new int[n];
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal; // Генерация случайного числа в диапазоне [minVal, maxVal]
    }
    cout << "Количество товаров: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return arr;
}

double inflation(double arr1[], double arr2[], int arr3[], int n) {
    double numerator = 0;
    for (int i = 0; i < n; i++) {
        numerator += arr1[i] * arr3[i];
    }
    double determinator = 0;
    for (int j = 0; j < n; j++) {
        determinator += arr2[j] * arr3[j];
    }

    int Infl = numerator / determinator;

    return Infl;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int n = 10, minPrice = 1, maxPrice = 100, minVal = 1, maxVal = 100;
    double* lastprices = lastmonth(n, minPrice, maxPrice);
    double* currentprices = currentmonth(n, minPrice, maxPrice);
    int* numofprod = numofproducts(n, minVal, maxVal);

    double Infl = inflation(currentprices, lastprices, numofprod, n);

    cout <<endl<< Infl << endl;

    delete[] lastprices;
    delete[] currentprices;
    delete[] numofprod;

    return 0;
}