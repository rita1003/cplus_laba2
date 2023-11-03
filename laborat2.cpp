#include <iostream>
#include <fstream> // для чтения из файла
#include <string>
#include <vector>
#include <algorithm> // для сортировки вектора
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()

using namespace std;

int size_of_text_file(ifstream& base);
string* array_names(ifstream& base, int n);
int GetRandomNumber(int min, int max);
void var1(int size_of_vect, string* arr, int n);
void var2(int size_of_vect, string* arr, int n);
void var3(int size_of_vect);
void mean(vector <int>& vec_marks);
void median(vector <int>& vec_marks);
void mode(vector <int>& vec_marks, vector <string>& vec_names);
void range_based_for_loop(vector <int>& vec_marks, vector <string>& vec_names);
//void with_iterator(vector <int>& vec_marks, vector <string>& vec_names);
//void with_index_range(vector <int>& vec_marks, vector <string>& vec_names);


//функция для подсчета количества строк в текстовом файле
//понадобится нам в дальнейшем для создания динамического массива, который будет
//состоять из имён  


int size_of_text_file(ifstream& base) {

    char* str = new char[1024];
    int i = 0;

    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }

    base.clear(); //возвращаемся в начало файла
    base.seekg(0);

    delete str;

    return i;

}

//создание динамического массива строк (будут записаны имена из текстового файла)

string* array_names(ifstream& base, int n) {

    // Объявление переменной для хранения строки
    string line;

    // Объявление массива строк
    string* lines = new string[n];

    // Счетчик строк
    int count = 0;

    // Чтение строк из файла и сохранение их в массив
    while (getline(base, line, '\n')) {
        lines[count] = line;
        count++;
    }

    return lines;

}

//функция для рандомного значения

int GetRandomNumber(int min, int max)
{
    return min + rand() % (max - min);
}

//функции, реализующие выбранный пользователем вариант инициализации

void var1(int size_of_vect, string* arr, int n) { //демонстрационный анализ на дефолтных входных значениях

    vector <int> marks(size_of_vect);
    vector <string> names(size_of_vect);

    srand(time(0)); // Установить генератор случайных чисел

    for (int i = 0; i < size_of_vect; i++) { //заполнение векторов
        marks[i] = GetRandomNumber(0, 100);
        names[i] = arr[GetRandomNumber(0, n)];
    }

    range_based_for_loop(marks, names);
//    with_iterator(marks, names);
//    with_index_range(marks, names);
    mean(marks);
    median(marks);
    mode(marks, names);

}

void var2(int size_of_vect, string* arr, int n) { //анализ на случайных входных значениях

    vector <int> marks(size_of_vect);
    vector <string> names(size_of_vect);

    for (int i = 0; i < size_of_vect; i++) { //заполнение векторов
        marks[i] = GetRandomNumber(0, 100);
        names[i] = arr[GetRandomNumber(0, n)];
    }

    range_based_for_loop(marks, names);
//    with_iterator(marks, names);
//    with_index_range(marks, names);
    mean(marks);
    median(marks);
    mode(marks, names);

}

void var3(int size_of_vect) { //анализ на входных значениях от самого пользователя

    vector <int> marks(size_of_vect);
    vector <string> names(size_of_vect);

    string name;
    int mark;

    for (int i = 0; i < size_of_vect; i++) {

        cout << '\n' << "Write the name: " << endl;
        cin >> name;
        names[i] = name;

        cout << '\n' << "Write the mark: " << endl;
        cin >> mark;
        marks[i] = mark;

    }

    range_based_for_loop(marks, names);
//    with_iterator(marks, names);
//    with_index_range(marks, names);
    mean(marks);
    median(marks);
    mode(marks, names);
}

//функции подсчета

void mean(vector <int>& vec_marks) { //функция для подсчета среднего значения

    int sum = 0;

    for (int i = 0; i < size(vec_marks); i++) {
        sum += vec_marks[i];
    }

    cout << '\n' << "The mean is " << sum / size(vec_marks) << endl;
}

void median(vector <int>& vec_marks) { //функция для подсчета медианы

    size_t size = vec_marks.size();
    sort(vec_marks.begin(), vec_marks.end());
    if (size % 2 == 0)
        cout << "The median is " << (vec_marks[size / 2 - 1] + vec_marks[size / 2]) / 2 << endl;
    else
        cout << "The median is " << vec_marks[size / 2] << endl;

}

void mode(vector <int>& vec_marks, vector <string>& vec_names) { //функция для подсчета моды

    size_t size = vec_marks.size();

    int MAX = 0;

    int arr[100] = { 0 }; //т.к. оценки от 0 до 100, создадим массив, создадим массив размером 100, заполненный нулями

    for (int i = 0; i < size; i++) {
        arr[vec_marks[i] - 1] += 1;
    }

    for (int k = 0; k < 100; k++) {
        if (MAX < arr[k]) {
            MAX = arr[k];
        }
    }

    if (MAX == 1) {
        cout << "The mode is missing" << endl;
    }
    else {
        for (int j = 0; j < 100; j++) {
            if (arr[j] == MAX) {
                cout << "The mode is " << j + 1 << endl;
                cout << '\n' << "The list of people who has got that mode:" << endl;
                for (int q = 0; q < size; q++) {
                    if (vec_marks[q] == j+1) {
                        cout << vec_names[q] << endl;
                    }
                }
            }
        }
    }

}

//функции вывода

void range_based_for_loop(vector <int>& vec_marks, vector <string>& vec_names) { //вывод с помощью цикла range-based for-loop

    cout << '\n' << "The table for vector of names: " << endl;

    for (string x : vec_names) {
        cout << x << endl;
    }

    cout << '\n' << "The table for vector of marks: " << endl;

    for (int k : vec_marks) {
        cout << k << endl;
    }
}


/*
void with_iterator(vector <int>& vec_marks, vector <string>& vec_names) { //вывод с помощью итератора

    auto iter_for_marks{ vec_marks.begin() };  // получаем итератор

    cout << '\n' << "The table for vector of marks: " << endl;

    while (iter_for_marks != vec_marks.end())    // пока не дойдем до конца
    {
        cout << *iter_for_marks << endl;// получаем элементы через итератор
        ++iter_for_marks;             // перемещаемся вперед на один элемент
    }

    auto iter_for_names{ vec_names.begin() };

    cout << '\n' << "The table for vector of names: " << endl;

    while (iter_for_names != vec_names.end())    // пока не дойдем до конца
    {
        cout << *iter_for_names << endl;// получаем элементы через итератор
        ++iter_for_names;             // перемещаемся вперед на один элемент
    }

}
*/


/*
void with_index_range(vector <int>& vec_marks, vector <string>& vec_names) { //вывод с помощью индексового цикла

    cout << '\n' << "The table for vector of marks: " << endl;

    for (int i = 0; i < size(vec_marks); i++) {
        cout << vec_marks[i] << endl;
    }

    cout << '\n' << "The table for vector of names: " << endl;

    for (int k = 0; k < size(vec_names); k++) {
        cout << vec_names[k] << endl;
    }

}
*/

// основная функция

int main() {

    int user_search;

    ifstream base("names.txt"); //для чтения файла с именами
    if (!base) return 1; //Если ошибка открытия файла, то завершаем программу

    int size_arr = size_of_text_file(base); //количество строк в файле

    string* array_of_names;

    array_of_names = array_names(base, size_arr);

    cout << "Which variation of initialization you want to choose?" << '\n' << endl;
    cout << "1. Demo analysis with default input values" << endl;
    cout << "2. Analysis with random input values" << endl;
    cout << "3. Analysis with input values by user" << '\n' << endl;

    cin >> user_search;

    int size_of_vect;

    if (user_search == 1) {

        size_of_vect = 10;
        var1(size_of_vect, array_of_names, size_arr);

    }
    else if (user_search == 2) {

        cout << '\n' << "Write size of table: " << '\n' << endl;
        cin >> size_of_vect;
        var2(size_of_vect, array_of_names, size_arr);

    }
    else if (user_search == 3) {

        cout << '\n' << "Write size of table: " << '\n' << endl;
        cin >> size_of_vect;
        var3(size_of_vect);

    }
    else {

        cout << "Error" << endl;
    };

    delete[] array_of_names;

    return 0;
}