#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

typedef struct items
{
    char name[20];
    unsigned int weight;
    float profit;
};

float max(float a, float b)
{
    return ((a > b) ? a : b);
}

float knapsack(unsigned int n, struct items object[], unsigned int capacity)
{
    float** table = new float* [n + 1];

    for (unsigned int i = 0; i <= n; i++)
    {
        table[i] = new float[capacity + 1];
        for (unsigned int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0.0;
            else if (object[i - 1].weight <= j)
                table[i][j] = max((object[i - 1].profit + table[i - 1][j - object[i - 1].weight]), table[i - 1][j]);
            else
                table[i][j] = table[i - 1][j];
        }
    }


    int i = n;
    int j = capacity;

    cout << "\n Прведметы и их цена: \n\n";

    while (i > 0 && j > 0)
    {
        if (table[i][j] != table[i - 1][j])
        {
            cout << object[i - 1].name << " " << object[i - 1].profit << endl;
            j -= object[i - 1].weight;
        }
        i--;
    }

    cout << endl;
    system("pause");
    return table[n][capacity];
}

void main()
{
    setlocale(LC_ALL, "rus");
    unsigned int capacity;
    while (true)
        try
    {
        cout << "Введите объем рюкзака:";
        cin >> capacity;
        if (!cin || capacity < 1) throw exception("Неправильный ввод, повторите попытку!");
        else break;
    }
    catch (const exception e)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << e.what() << endl;
    }



    unsigned int n;
    while (true)
        try
    {
        cout << "Введите общее количество элементов:";
        cin >> n;
        if (!cin || n < 1) throw exception("Неправильный ввод, повторите попытку!");
        else break;
    }
    catch (const exception e)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << e.what() << endl;
    }


    items* item = new items[n];

    printf("Введите запрашиваемые данные:\n");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("==========Item No. %d ==========\n", i + 1);
        printf("Имя : ");
        cin >> item[i].name;
        while (true)
            try
        {
            cout << "Вес: ";
            cin >> item[i].weight;
            if (!cin || item[i].weight < 1) throw exception("Неправильный ввод, повторите попытку!");
            else break;
        }
        catch (const exception e)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << e.what() << endl;
        }
        while (true)
            try
        {
            cout << "Цена: ";
            cin >> item[i].profit;
            if (!cin || item[i].weight < 1) throw exception("Неправильный ввод, повторите попытку!");
            else break;
        }
        catch (const exception e)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << e.what() << endl;
        }

    }

    float max_profit = knapsack(n, item, capacity);

    printf("Максимальная прибыль - это %.2f.", max_profit);
}