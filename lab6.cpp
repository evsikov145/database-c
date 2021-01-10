#include "Functions.h"

using namespace std;

int _stateMenu;
void Menu()
{
    cout << "Выберите действие:" << endl
        << "(0) Выход из программы" << endl
        << "(1) Ввод данных" << endl
        << "(2) Вывод данных" << endl
        << "(3) Изменение данных" << endl
        << "(4) Удаление данных" << endl
        << "(5) Добавление данных" << endl
        << "(6) Сортировка данных" << endl
        << "(6) Сохранение данных" << endl
        << "Ваш выбор: ";
    cin >> _stateMenu;
}

void main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();

    int _actions,
        amountOfData = 0;
    string fileName;

    Data* d = new Data[amountOfData];

    while (_stateMenu != 0) {
        switch (_stateMenu)
        {
        case 1:
            system("cls");

            cout << "Ввод вручную (1) или из файла (2)?" << endl;
            cin >> _actions;
            system("cls");

            if (_actions == 1) {
                DataEntry(d, amountOfData);
            }    
            else
            {
                cout << "Введите название файла: " << endl;
                cin >> fileName;
                ReadingData(d, amountOfData, fileName);
            }
                
            system("pause");
            system("cls");
            Menu();
            break;
        case 2:
            system("cls");

            if (amountOfData != 0) {
                Print(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            
            system("pause");
            system("cls");
            Menu();
            break;
        case 3: 
            system("cls");

            if (amountOfData != 0) {
                DataChange(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();
            break;
        case 4: 
            system("cls");

            if (amountOfData != 0) {
                DeleteData(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            
            system("pause");
            system("cls");
            Menu();
            break;
        case 5: 
            system("cls");

            if (amountOfData != 0) {
                AddData(d, amountOfData);
                amountOfData++;
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();
            break;  
        case 6:
            system("cls");

            if (amountOfData != 0) {
                DataSorting(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            system("cls");

            cout << "Введите название файла: ";
            cin >> fileName;
            system("cls");

            if (amountOfData != 0) {
                SaveData(d, amountOfData, fileName);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();
            break;
        default:
            cout << "Неправильно выбран пункт меню!" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
    }
}

