#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include "conio.h" 

using namespace std;

struct train
{
    char destination[30];
    char departure_time[30];
    int number;
    int number_of_available_seats;
}current_train,entered_train;
train b1;
DWORD n;
HANDLE myFile;


int main(int v, char** s)
{
    //Вывод полученной информации
    std::cout << "There are " << v << " arguments:\n";  
    // Перебираем каждый аргумент и выводим его порядковый номер и значение
    for (int count = 0; count < v; ++count)
        std::cout << count << " " <<s[count] << '\n';

    //открытие файла
    LPCTSTR filename = L"list_of_trains.dat";
    myFile = CreateFile(
        filename, // Имя файла
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (myFile == INVALID_HANDLE_VALUE)
        cout << "Error (File does not exist)\n"; // Файл не создан
    else
        cout << " File is opened \n"; // Файл создан

    //новые данные структуры 
    cout << "Please, enter number of train" << endl;
    cin >> entered_train.number;
    cout << "Please, enter destination" << endl;
    cin >> entered_train.destination;
    cout << "Please, enter departure time" << endl;
    cin >> entered_train.departure_time;
    cout << "Please, enter number of available seats" << endl;
    cin >> entered_train.number_of_available_seats;
    SetFilePointer(myFile, 0, NULL, FILE_BEGIN);
    int c = 0;
    int a = atoi(s[1]);
    while (ReadFile(myFile, &current_train, sizeof(current_train), &n, NULL) && n != 0)
    {
        c++;
        if (c==a)
        {
            cout << "Writeln new structure...\n";
            WriteFile(myFile, &entered_train, sizeof(entered_train), &n, NULL);
        }
    }
	return 0;
}