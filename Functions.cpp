#include "Functions.h"

void DataInitialization() {
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;

	_buf.close();
}

void DataEntry() {
	string _surname;
	int _phoneNum;
	string _city;
	int n;

	cout << "Введите количество данных: " << endl;
	cin >> n;

	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Введите фамилию:";
			cin >> _surname;
			record << _surname << endl;

			cout << "Введите телефон:";
			cin >> _phoneNum;
			record << _phoneNum << endl;

			cout << "Введите город:";
			cin >> _city;
			record << _city << endl;
			cout << "________________________" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}

	record.close();
}

void DataReading(string fileName) {
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;
				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}

			cout << "Данные считаны!" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
	record.close();
}

void Print() {
	ifstream reading("Buffer.txt");

	if (reading) {

		string _surname;
		int _phoneNum;
		string _city;
		int n;

		reading >> n;
		cout << "Количество данных: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "Данные об № " << i + 1 << endl;

			reading >> _surname;
			cout << "Фамилия :" << _surname << endl;

			reading >> _phoneNum;
			cout << "Телефон :" << _phoneNum << endl;

			reading >> _city;
			cout << "Город :" << _city << endl;

			cout << "________________________" << endl;
		}

	}
	else {
		cout << "Ошибка чтения файла!" << endl;
	}

	reading.close();
}

bool DataCleaning() {
	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "Ошибка открытия буферного файла!" << endl;

	_buf.clear();

	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;

}

void DataChange() {

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			reading >> n;
			
			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "):";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else {
						cout << "Введите фамилию:";
						cin >> _surname;

						cout << "Введите телефон:";
						cin >> _phoneNum;

						cout << "Введите город:";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;

						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}

				}

				cout << "Данные изменены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;


		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	reading.close();
	record.close();

	remove("Buffer_.txt");

}

void Copy() {
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;
				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}

			cout << "Данные считаны!" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
	record.close();
}

int AmountOfData() {
	ifstream _buf("Buffer.txt");

	int n;

	if (_buf) {
		_buf >> n;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	_buf.close();

	return n;
}

void DeleteData() {
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			reading >> n;
			int b = n - 1;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "):";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else {

						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}

				}

				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;


		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	reading.close();
	record.close();

	remove("Buffer_.txt");
}

void AddData() {

	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;

	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
		record_ << n << endl;
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	if (record) {
		record << endl;

		cout << "Введите фамилию:";
		cin >> _surname;

		cout << "Введите телефон:";
		cin >> _phoneNum;

		cout << "Введите город:";
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	record_.close();

}

void SaveData(string fileName) {

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;
				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}

			cout << "Данные сохранены в файле " << fileName << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
	record.close();

}