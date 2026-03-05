#include <iostream>
using namespace std;

const int MAX = 50;

/* -------------------------------------------------
   Введення матриці
------------------------------------------------- */
void inputMatrix(int a[MAX][MAX], int &m, int &n)
{
    cout << "Введіть M (рядки): ";
    cin >> m;

    cout << "Введіть N (стовпці): ";
    cin >> n;

    cout << "Введіть елементи матриці:\n";

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

/* -------------------------------------------------
   Виведення матриці
------------------------------------------------- */
void printMatrix(int a[MAX][MAX], int m, int n)
{
    cout << "\nМатриця:\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

/* -------------------------------------------------
   Matrix23
   У кожному рядку знайти мінімальний елемент
------------------------------------------------- */
void matrix23(int a[MAX][MAX], int m, int n)
{
    cout << "\nМінімальні елементи рядків:\n";

    for (int i = 0; i < m; i++)
    {
        int min = a[i][0];

        for (int j = 1; j < n; j++)
            if (a[i][j] < min)
                min = a[i][j];

        cout << "Рядок " << i + 1 << ": " << min << endl;
    }
}

/* -------------------------------------------------
   Matrix54
   Поміняти місцями N-й стовпець і перший стовпець,
   що містить тільки від’ємні елементи
------------------------------------------------- */
void matrix54(int a[MAX][MAX], int m, int n)
{
    int negColumn = -1;

    // шукаємо перший стовпець тільки з від'ємними числами
    for (int j = 0; j < n; j++)
    {
        bool onlyNegative = true;

        for (int i = 0; i < m; i++)
        {
            if (a[i][j] >= 0)
            {
                onlyNegative = false;
                break;
            }
        }

        if (onlyNegative)
        {
            negColumn = j;
            break;
        }
    }

    if (negColumn == -1)
    {
        cout << "\nСтовпця тільки з від’ємними елементами немає.\n";
        return;
    }

    // міняємо місцями знайдений стовпець і останній
    for (int i = 0; i < m; i++)
    {
        int temp = a[i][negColumn];
        a[i][negColumn] = a[i][n - 1];
        a[i][n - 1] = temp;
    }

    cout << "\nСтовпці поміняно місцями.\n";
}

/* -------------------------------------------------
   Головна функція
------------------------------------------------- */
int main()
{
    int a[MAX][MAX];
    int m, n;
    int choice;

    inputMatrix(a, m, n);

    do
    {
        cout << "\n----- МЕНЮ -----\n";
        cout << "1 - Matrix23\n";
        cout << "2 - Matrix54\n";
        cout << "3 - Показати матрицю\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                matrix23(a, m, n);
                break;

            case 2:
                matrix54(a, m, n);
                printMatrix(a, m, n);
                break;

            case 3:
                printMatrix(a, m, n);
                break;
        }

    } while (choice != 0);

    return 0;
}
