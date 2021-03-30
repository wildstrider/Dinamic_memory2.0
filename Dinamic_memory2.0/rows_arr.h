#pragma once
#include <iostream>
using namespace std;

template<typename T> void push_rows_front(T**& arr, int& rows, int cols)
{
	rows += 1;
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++) {

		if (i == 0) {

			buffer[i] = new T[cols]{};
		}
		else
			buffer[i] = arr[i - 1];

	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void push_rows_back(T**& arr, int& rows, int cols)
{
	rows += 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		if (i == rows - 1) {
			buffer[i] = new T[cols]{};
		}
		else
			buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void insert_rows(T**& arr, int& rows, int cols, int index)
{
	rows += 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows; i++) {

		if (i < index) {

			buffer[i] = arr[i];
		}
		if (i == index) {
			buffer[i] = new T[cols]{};
		}
		if (i > index)
			buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void Add_rows(T**& arr, int& rows, int cols)
{
	int choice, index;
	cout << "Выберите куда добавить строку." << endl;
	cout << "1 - В начало"
		"\n2 - В конец"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		push_rows_front(arr, rows, cols);
		break;
	case 2:
		push_rows_back(arr, rows, cols);
		break;
	case 3:
		cout << "Введите куда встваить строку: "; cin >> index;
		insert_rows(arr, rows, cols, index);
	}
}

template<typename T> void pop_rows_front(T**& arr, int& rows)
{
	rows -= 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows + 1; i++) {

		if (i == 0) {
			delete[] arr[i];
		}
		else
			buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void pop_rows_back(T**& arr, int& rows)
{
	rows -= 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows + 1; i++) {

		if (i == rows) {
			delete[] arr[i];
		}
		else
			buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void erase_rows(T**& arr, int& rows)
{
	int index;
	cout << "Введите какую строку удалить: "; cin >> index;
	rows -= 1;
	T** buffer = new T * [rows];
	for (int i = 0; i < rows + 1; i++) {

		if (i < index) {
			buffer[i] = arr[i];
		}
		if (i == index) {
			delete[] arr[i];
		}
		if (i > index) {
			buffer[i - 1] = arr[i];
		}
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void Delete_rows(T**& arr, int& rows)
{
	int choice;
	cout << "Выберите какую строку удалить." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_rows_front(arr, rows);
		break;
	case 2:
		pop_rows_back(arr, rows);
		break;
	case 3:
		erase_rows(arr, rows);
	}
}

template<typename T> void work_rows(T**& arr, int& rows, int cols) {

	cout << "1 - Добавление строк" << endl;
	cout << "2 - Удаление строк" << endl;
	int r; cin >> r;
	switch (r)
	{
	case 1:
		Add_rows(arr, rows, cols);
		break;
	case 2:
		Delete_rows(arr, rows);
	}
}