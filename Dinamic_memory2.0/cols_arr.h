#pragma once
#include <iostream>
using namespace std;

template<typename T> void push_cols_front(T**& arr, int rows, int& cols) {

	cols += 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols]{};
		for (int j = 0; j < cols; j++) {

			if (j == 0) {
				continue;
			}
			else
				buffer[i][j] = arr[i][j - 1];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void push_cols_back(T**& arr, int rows, int& cols)
{
	cols += 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols]{};
		for (int j = 0; j < cols; j++) {

			if (j == cols - 1) {
				continue;
			}
			else
				buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;

}
template<typename T> void insert_cols(T**& arr, int rows, int& cols, int index)
{
	cols += 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols]{};
		for (int j = 0; j < cols; j++) {

			if (j == index) {
				continue;
			}
			if (j < index) {

				buffer[i][j] = arr[i][j];
			}
			if (j > index) {

				buffer[i][j] = arr[i][j - 1];
			}

		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void Add_cols(T**& arr, int rows, int& cols)
{
	int choice, index;
	cout << "Выберите куда добавить колонку." << endl;
	cout << "1 - В начало"
		"\n2 - В конец"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		push_cols_front(arr, rows, cols);
		break;
	case 2:
		push_cols_back(arr, rows, cols);
		break;
	case 3:
		cout << "Введите куда встваить колонку: "; cin >> index;
		insert_cols(arr, rows, cols, index);
	}
}

template<typename T> void pop_cols_front(T**& arr, int rows, int& cols)
{
	cols -= 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols];

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;


}
template<typename T> void pop_cols_back(T**& arr, int rows, int& cols)
{
	cols -= 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols];

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;

}
template<typename T> void erase_cols(T**& arr, int rows, int& cols, int index)
{
	cols -= 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		buffer[i] = new T[cols];

		for (int j = 0; j < cols + 1; j++) {

			if (j == index) {
				continue;
			}
			if (j < index) {
				buffer[i][j] = arr[i][j];
			}
			if (j > index) {
				buffer[i][j - 1] = arr[i][j];
			}

		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void Delete_cols(T**& arr, int rows, int& cols)
{
	int choice, index;
	cout << "Выберите какую колонку удалить." << endl;
	cout << "1 - первую"
		"\n2 - последнюю"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_cols_front(arr, rows, cols);
		break;
	case 2:
		pop_cols_back(arr, rows, cols);
		break;
	case 3:
		cout << "какую колонку удалить: "; cin >> index;
		erase_cols(arr, rows, cols, index);
	}

}

template<typename T> void work_cols(T**& arr, int rows, int& cols) {

	cout << "1 - Добавление колонок" << endl;
	cout << "2 - Удаление колонок" << endl;
	int r; cin >> r;
	switch (r)
	{
	case 1:
		Add_cols(arr, rows, cols);
		break;
	case 2:
		Delete_cols(arr, rows, cols);
	}
}