#pragma once
#include <iostream>
#include "rows_arr.h"
#include "cols_arr.h"
using namespace std;

template<typename T> void Menu(T**& arr, int& rows, int& cols) {

	cout << "1 - ������ �� ��������" << endl;
	cout << "2 - ������ � ���������" << endl;
	int choice; cin >> choice;
	switch (choice)
	{
	case 1:
		work_rows(arr, rows, cols);
		break;
	case 2:
		work_cols(arr, rows, cols);
	}
}