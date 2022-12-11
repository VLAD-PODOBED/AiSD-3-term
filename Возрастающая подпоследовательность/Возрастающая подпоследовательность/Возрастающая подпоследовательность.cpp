//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//void findLIS(vector<int> const& arr)
//{
//    int n = arr.size();
//
//    if (n == 0) {
//        return;
//    }
//
//    vector<vector<int>> LIS(n, vector<int>{});
//
//    LIS[0].push_back(arr[0]);
//
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
//            {
//                LIS[i] = LIS[j];
//            }
//        }
//        LIS[i].push_back(arr[i]);
//    }
//
//    cout << "" << LIS[LIS.size() - 1].size() << endl;
//
//    for (int i : LIS[LIS.size() - 1]) {
//        cout << i << " ";
//    }
//}
//
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    vector<int> arr;
//
//    cout << "Введите элементы последовательности, как напишите цепочку, то напишите exit(маленькими буквами): ";
//
//    string num;
//    while (true)
//    {
//        cin >> num;
//        if (num == "exit") {
//            break;
//        }
//        arr.push_back(stoi(num));
//    }
//
//    cout << "Исходная последовательность: ";
//
//    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    findLIS(arr);
//
//    cout << endl << endl;
//}





#include <iostream>
#include <vector>
using namespace std;

// Итерационная функция для поиска самой длинной возрастающей подпоследовательности
// данного массива
void findLIS(vector<int> const& arr)
{
    int n = arr.size();

    // базовый вариант
    if (n == 0) {
        return;
    }

    // LIS[i] хранит самую длинную возрастающую подпоследовательность подмассива
    // `arr[0…i]`, оканчивающийся на `arr[i]`
    vector<vector<int>> LIS(n, vector<int>{});

    // LIS[0] обозначает самую длинную возрастающую подпоследовательность, заканчивающуюся на `arr[0]`
    LIS[0].push_back(arr[0]);

    // начинаем со второго элемента массива
    for (int i = 1; i < n; i++)
    {
        // делаем для каждого элемента подмассива `arr[0…i-1]`
        for (int j = 0; j < i; j++)
        {
            // найти самую длинную возрастающую подпоследовательность, заканчивающуюся на `arr[j]`
            // где `arr[j]` меньше, чем текущий элемент `arr[i]`

            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size()) {
                LIS[i] = LIS[j];
            }
        }

        // включить `arr[i]` в `LIS[i]`
        LIS[i].push_back(arr[i]);
    }

    // раскомментируйте следующий код, чтобы вывести содержимое `LIS`
     for (int i = 0; i < n; i++)
    {
        cout << "LIS[" << i << "] — ";
        for (int j: LIS[i]) {
            cout << j << " ";
        }
        cout << "end";
    } 

    // `j` будет хранить индекс LIS
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (LIS[j].size() < LIS[i].size()) {
            j = i;
        }
    }

    // распечатать ЛИС
    for (int i : LIS[j]) {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = { 5, 10, 6, 12, 3, 24, 7, 8 };

    findLIS(arr);

    return 0;
}