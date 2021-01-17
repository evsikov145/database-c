#include "Functions.h"

void DataEntry(Data* (&d), int& n) {

	cout << "Введите количество данных: " << endl;
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите Марку машины:";
		cin >> d[i].brand;

		cout << "Введите Модель машины:";
		cin >> d[i].model;

		cout << "Введите ГосНомер машины:";
		cin >> d[i].numberCar;

		cout << "Введите Пробег машины:";
		cin >> d[i].mileage;

		cout << "Введите Цвет машины:";
		cin >> d[i].color;

		cout << "Введите Год выпуска машины:";
		cin >> d[i].year;

		cout << "________________________" << endl;
	}


}

void ReadingData(Data* (&d), int& n, string fileName) {

	ifstream reading(fileName);
	
	if (reading) {
		
			reading >> n;

			d = new Data[n];

			for (int i = 0; i < n; i++) {
		
				reading >> d[i].brand;
				reading >> d[i].model;
				reading >> d[i].numberCar;
				reading >> d[i].mileage;
				reading >> d[i].color;
				reading >> d[i].year;
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

		cout << "Марка: " << d[i].brand <<endl;
		cout << "Модель: " << d[i].model << endl;
		cout << "ГосНомер: " << d[i].numberCar << endl;
		cout << "Пробег: " << d[i].mileage << endl;
		cout << "Цвет: " << d[i].color << endl;
		cout << "Год: " << d[i].year << endl;

		cout << "________________________" << endl;
	}
}

void Copy(Data* (&d_n), Data* (&d_o), int n) {
	
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}

}

void Copy(Data& d_n, Data& d_o) {

	d_n.brand = d_o.brand;
	d_n.model = d_o.model;
	d_n.numberCar = d_o.numberCar;
	d_n.mileage = d_o.mileage;
	d_n.color = d_o.color;
	d_n.year = d_o.year;

}

void AddData(Data* (&d), int& n) {

	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n);

	n++;

	d = new Data[n];

	Copy(d, buf, --n);

	cout << "Введите Марку машины:";
	cin >> d[n].brand;

	cout << "Введите Модель машины:";
	cin >> d[n].model;

	cout << "Введите ГосНомер машины:";
	cin >> d[n].numberCar;

	cout << "Введите Пробег машины:";
	cin >> d[n].mileage;

	cout << "Введите Цвет машины:";
	cin >> d[n].color;

	cout << "Введите Год выпуска машины:";
	cin >> d[n].year;


	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[]buf;

}

void DataSorting(Data* d, int n) {
	Data buf;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].mileage > d[j].mileage) {
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

			record << d[i].brand << endl;
			record << d[i].model << endl;
			record << d[i].numberCar << endl;
			record << d[i].mileage << endl;
			record << d[i].color << endl;

			if (i < n - 1) {
				record << d[i].year << endl;
			}
			else {
				record << d[i].year;
			}

			cout << "Данные сохранены в файле " << fileName << endl;
		}
	}
	else {
		cout << "Ошибка открытия буфера!" << endl;
	}

	record.close();

}

void SearchData(Data* d, int n, string name) {

	bool flag = false;

	for (int i = 0; i < n; i++) {
		if (d[i].numberCar == name) {
			flag = true;
			cout << "Марка: " << d[i].brand << endl;
			cout << "Модель: " << d[i].model << endl;
			cout << "ГосНомер: " << d[i].numberCar << endl;
			cout << "Пробег: " << d[i].mileage << endl;
			cout << "Цвет: " << d[i].color << endl;
			cout << "Год: " << d[i].year << endl;
			break;
		}
	}
	if (flag == false) {
		cout << "Данные по ГосНомеру не найдены" << endl;
	}
}