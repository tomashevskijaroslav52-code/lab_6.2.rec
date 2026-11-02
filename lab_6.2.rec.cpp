#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна функція формування масиву за допомогою генератора випадкових чисел
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивна функція виведення елементів масиву в рядок
void Print(const int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивна функція пошуку максимального елемента масиву
int FindMax(const int* a, const int size, int i, int max_val)
{
    if (a[i] > max_val)
    {
        max_val = a[i];
    }
    if (i < size - 1)
    {
        return FindMax(a, size, i + 1, max_val);
    }
    else
    {
        return max_val;
    }
}

// Рекурсивна функція пошуку мінімального елемента масиву
int FindMin(const int* a, const int size, int i, int min_val)
{
    if (a[i] < min_val)
    {
        min_val = a[i];
    }
    if (i < size - 1)
    {
        return FindMin(a, size, i + 1, min_val);
    }
    else
    {
        return min_val;
    }
}

// Функція обчислення суми максимального та мінімального елементів
int SumMaxAndMin(const int* a, const int size)
{
    int max_val = FindMax(a, size, 1, a[0]);
    int min_val = FindMin(a, size, 1, a[0]);
    return max_val + min_val;
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int n = 10; // Кількість елементів масиву
    int a[n];
    int Low = -25;
    int High = 25;

    // Рекурсивне формування та виведення масиву
    Create(a, n, Low, High, 0);
    cout << "Array:" << endl;
    Print(a, n, 0);
    cout << endl;

    // Знаходження максимального, мінімального та їх суми
    int max_val = FindMax(a, n, 1, a[0]);
    int min_val = FindMin(a, n, 1, a[0]);
    int resultSum = SumMaxAndMin(a, n);

    // Виведення результатів
    cout << "Max element = " << max_val << endl;
    cout << "Min element = " << min_val << endl;
    cout << "Sum (Max + Min) = " << resultSum << endl;

    return 0;
}
