#include <iostream>
#include "menu.h"
using namespace std;
#define tab "\t"

template<typename T> void New_arr(T**& arr, int rows, int cols);
template<typename T> void FillRand(T**& arr, int rows, int cols);
template<typename T> void Print(T**& arr, int rows, int cols);
template<typename T> void Delete_arr(T**& arr, int rows);

int main()
{
	setlocale(LC_ALL, "ru");
	int** arr_int = nullptr;
	double** arr_double = nullptr;
	char** arr_char = nullptr;
	cout << "Введите количество строк: "; int rows; cin >> rows;
	cout << "Введите количество столбцов: "; int cols; cin >> cols;

	cout << "Выберите с каким типом данных работать." << endl;
	cout << "1 - int"
		"\n2 - double"
		"\n3 - char" << endl;
	int type; cin >> type;
	switch (type)
	{
	case 1:
		New_arr(arr_int, rows, cols);
		FillRand(arr_int, rows, cols);
		Print(arr_int, rows, cols);
		Menu(arr_int, rows, cols);
		Print(arr_int, rows, cols);
		Delete_arr(arr_int, rows);
		break;
	case 2:
		New_arr(arr_double, rows, cols);
		FillRand(arr_double, rows, cols);
		Print(arr_double, rows, cols);
		Menu(arr_double, rows, cols);
		Print(arr_double, rows, cols);
		Delete_arr(arr_double, rows);
		break;
	case 3:
		New_arr(arr_char, rows, cols);
		FillRand(arr_char, rows, cols);
		Print(arr_char, rows, cols);
		Menu(arr_char, rows, cols);
		FillRand(arr_char, rows, cols);
		Print(arr_char, rows, cols);
		Delete_arr(arr_char, rows);
	}
	cout << "1 - Для повтора(0 выход)" << endl;
	int rep; cin >> rep;
	switch (rep)
	{
	case 1:
		system("cls");
		main();
		break;
	case 0:
		return 0;
	}
}

template<typename T> void New_arr(T**& new_arr, int rows, int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++) {

		arr[i] = new T[cols];
	}
	new_arr = arr;
}
template<typename T> void FillRand(T**& arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			if (sizeof(T) == 8) {
				arr[i][j] = rand() / 10E2;
			}
			else
				arr[i][j] = rand() % 255;
		}
	}
}
template<typename T> void Print(T**& arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T> void Delete_arr(T**& arr, int rows)
{
	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}

	delete[] arr;
}