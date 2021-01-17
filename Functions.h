#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Data {
	string brand;
	string model;
	string numberCar;
	int mileage;
	string color;
	int year;
};

void DataEntry(Data* (&d), int &n);
void ReadingData(Data* (&d), int& n, string fileName);
void Print(Data* d, int n);
void Copy(Data* (&d_n), Data* (&d_o), int n);
void Copy(Data& d_n, Data& d_o);
void AddData(Data* (&d), int& n);
void DataSorting(Data *d, int n);
void SaveData(Data* d, int n, string fileName);
void SearchData(Data* d, int n, string name);

