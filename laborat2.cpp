#include <iostream>
#include <fstream> // ��� ������ �� �����
#include <string>
#include <vector>
#include <algorithm> // ��� ���������� �������
#include <stdlib.h> // ����� ��� ������ ������� rand(), srand()
#include <time.h> // ����� ��� ������ ������� time()

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


//������� ��� �������� ���������� ����� � ��������� �����
//����������� ��� � ���������� ��� �������� ������������� �������, ������� �����
//�������� �� ���  


int size_of_text_file(ifstream& base) {

    char* str = new char[1024];
    int i = 0;

    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }

    base.clear(); //������������ � ������ �����
    base.seekg(0);

    delete str;

    return i;

}

//�������� ������������� ������� ����� (����� �������� ����� �� ���������� �����)

string* array_names(ifstream& base, int n) {

    // ���������� ���������� ��� �������� ������
    string line;

    // ���������� ������� �����
    string* lines = new string[n];

    // ������� �����
    int count = 0;

    // ������ ����� �� ����� � ���������� �� � ������
    while (getline(base, line, '\n')) {
        lines[count] = line;
        count++;
    }

    return lines;

}

//������� ��� ���������� ��������

int GetRandomNumber(int min, int max)
{
    return min + rand() % (max - min);
}

//�������, ����������� ��������� ������������� ������� �������������

void var1(int size_of_vect, string* arr, int n) { //���������������� ������ �� ��������� ������� ���������

    vector <int> marks(size_of_vect);
    vector <string> names(size_of_vect);

    srand(time(0)); // ���������� ��������� ��������� �����

    for (int i = 0; i < size_of_vect; i++) { //���������� ��������
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

void var2(int size_of_vect, string* arr, int n) { //������ �� ��������� ������� ���������

    vector <int> marks(size_of_vect);
    vector <string> names(size_of_vect);

    for (int i = 0; i < size_of_vect; i++) { //���������� ��������
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

void var3(int size_of_vect) { //������ �� ������� ��������� �� ������ ������������

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

//������� ��������

void mean(vector <int>& vec_marks) { //������� ��� �������� �������� ��������

    int sum = 0;

    for (int i = 0; i < size(vec_marks); i++) {
        sum += vec_marks[i];
    }

    cout << '\n' << "The mean is " << sum / size(vec_marks) << endl;
}

void median(vector <int>& vec_marks) { //������� ��� �������� �������

    size_t size = vec_marks.size();
    sort(vec_marks.begin(), vec_marks.end());
    if (size % 2 == 0)
        cout << "The median is " << (vec_marks[size / 2 - 1] + vec_marks[size / 2]) / 2 << endl;
    else
        cout << "The median is " << vec_marks[size / 2] << endl;

}

void mode(vector <int>& vec_marks, vector <string>& vec_names) { //������� ��� �������� ����

    size_t size = vec_marks.size();

    int MAX = 0;

    int arr[100] = { 0 }; //�.�. ������ �� 0 �� 100, �������� ������, �������� ������ �������� 100, ����������� ������

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

//������� ������

void range_based_for_loop(vector <int>& vec_marks, vector <string>& vec_names) { //����� � ������� ����� range-based for-loop

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
void with_iterator(vector <int>& vec_marks, vector <string>& vec_names) { //����� � ������� ���������

    auto iter_for_marks{ vec_marks.begin() };  // �������� ��������

    cout << '\n' << "The table for vector of marks: " << endl;

    while (iter_for_marks != vec_marks.end())    // ���� �� ������ �� �����
    {
        cout << *iter_for_marks << endl;// �������� �������� ����� ��������
        ++iter_for_marks;             // ������������ ������ �� ���� �������
    }

    auto iter_for_names{ vec_names.begin() };

    cout << '\n' << "The table for vector of names: " << endl;

    while (iter_for_names != vec_names.end())    // ���� �� ������ �� �����
    {
        cout << *iter_for_names << endl;// �������� �������� ����� ��������
        ++iter_for_names;             // ������������ ������ �� ���� �������
    }

}
*/


/*
void with_index_range(vector <int>& vec_marks, vector <string>& vec_names) { //����� � ������� ����������� �����

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

// �������� �������

int main() {

    int user_search;

    ifstream base("names.txt"); //��� ������ ����� � �������
    if (!base) return 1; //���� ������ �������� �����, �� ��������� ���������

    int size_arr = size_of_text_file(base); //���������� ����� � �����

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