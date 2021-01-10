#include "Functions.h"

void DataEntry(Data* (&d), int& n) {

	cout << "Введите количество данных: " << endl;
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО:";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.firstname;
		cin >> d[i]._initial.patronymic;

		cout << "Введите дату:";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "Введите адрес:";
		cin >> d[i]._address.city;
		cin >> d[i]._address.home;

		cout << "________________________" << endl;
	}


}

void ReadingData(Data* (&d), int& n, string fileName) {

	ifstream reading(fileName);
	
	if (reading) {
		
			reading >> n;

			d = new Data[n];

			for (int i = 0; i < n; i++) {
		
				reading >> d[i]._initial.surname;
				reading >> d[i]._initial.firstname;
				reading >> d[i]._initial.patronymic;

				reading >> d[i]._date.day;
				reading >> d[i]._date.month;
				reading >> d[i]._date.year;

				reading >> d[i]._address.city;
				reading >> d[i]._address.home;
			}

			cout << "Данные считаны!" << endl;
		
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}

void Print(Data* d, int n) {
	
	for (int i = 0; i < n; i++) {
		cout << "Данные № " << i + 1 << " : " << endl;

		cout << "ФИО: " << d[i]._initial.surname <<" "<< d[i]._initial.firstname << " "<< d[i]._initial.patronymic <<endl;

		cout << "Дата: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;

		cout << "Адрес: " << d[i]._address.city << " " << d[i]._address.home << endl;

		cout << "________________________" << endl;
	}
}

void DataChange(Data* (&d), int n) {

	int _n;
	cout << "Выберите номер изменяемого элемента (от 1 до " << n << "):";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		
		cout << "Введите ФИО:";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.firstname;
		cin >> d[_n]._initial.patronymic;

		cout << "Введите дату:";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout << "Введите адрес:";
		cin >> d[_n]._address.city;
		cin >> d[_n]._address.home;

		system("cls");

		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;

}

void Copy(Data* (&d_n), Data* (&d_o), int n) {
	
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}

}

void Copy(Data& d_n, Data& d_o) {
	
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.firstname = d_o._initial.firstname;
	d_n._initial.patronymic = d_o._initial.patronymic;
	
	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;
	
	d_n._address.city = d_o._address.city;
	d_n._address.home = d_o._address.home;

}

void DeleteData(Data* (&d), int& n) {
	int _n;
	cout << "Выберите номер элемента (от 1 до " << n << "):";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {

		Data* buf = new Data[n];

		Copy(buf, d, n);

		--n;
		d = new Data[n];

		int q = 0;

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;
}

void AddData(Data* (&d), int& n) {

	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n);

	n++;

	d = new Data[n];

	Copy(d, buf, --n);

	cout << "Введите ФИО:";
	cin >> d[n]._initial.surname;
	cin >> d[n]._initial.firstname;
	cin >> d[n]._initial.patronymic;

	cout << "Введите дату:";
	cin >> d[n]._date.day;
	cin >> d[n]._date.month;
	cin >> d[n]._date.year;

	cout << "Введите адрес:";
	cin >> d[n]._address.city;
	cin >> d[n]._address.home;

	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[]buf;

}

void DataSorting(Data* d, int n) {
	Data buf;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname > d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "Данные отсортированны!" << endl;
}

void SaveData(Data* d, int n, string fileName) {

	ofstream record(fileName, ios::out);

	
	if (record) {

		record << n << endl;

		for (int i = 0; i < n; i++) {

			record << d[i]._initial.surname << endl;
			record << d[i]._initial.firstname << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << endl;
			record << d[i]._date.month << endl;
			record << d[i]._date.year << endl;

			record << d[i]._address.city << endl;

			if (i < n - 1) {
				record << d[i]._address.home << endl;
			}
			else {
				record << d[i]._address.home;
			}

			cout << "Данные сохранены в файле " << fileName << endl;
		}
	}
	else {
		cout << "Ошибка открытия буфера!" << endl;
	}

	record.close();

}