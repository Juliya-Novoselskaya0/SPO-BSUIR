// MainProc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

struct train
{
	char destination[30];
	char departure_time[30];
	int number;
	int number_of_available_seats;
}current_train;
train b1;
DWORD n;
HANDLE myFile;

void fileOpening()
{
	LPCTSTR filename = L"list_of_trains.dat";
	myFile = CreateFile(
		filename, // Имя файла
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (myFile == INVALID_HANDLE_VALUE)
		cout << "Error (File does not exist)\n"; // Файла не существует
	else
		cout << " File is opened\n"; // Файл открыт
}

int main(char** s)
{

	int number;
	fileOpening();
	int countOfStru=0;
	while (ReadFile(myFile, &current_train, sizeof(current_train), &n, NULL) && n != 0)
	{	
			cout << current_train.number << " " << current_train.destination << " " << current_train.departure_time <<
				" " << current_train.number_of_available_seats << endl;
			countOfStru++;
	}

	cout << "Enter number of structure" << endl;
	int k;
	cin >> k;
	if(k<0 || k>countOfStru)
	cout << "Error (There is no such structure)\n";

	CloseHandle(myFile);

	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	
	wchar_t AppNameDaug[] = L"Daughter.exe 3";

	if (!CreateProcess(NULL, AppNameDaug, NULL, NULL, FALSE, 0,
		NULL, NULL, &StartupInfo, &ProcInfo)) return 0;

	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);

	fileOpening();
	cout << "After file changes\n\n";
	while (ReadFile(myFile, &current_train, sizeof(current_train), &n, NULL) && n != 0)
	{
		cout << current_train.number << " " << current_train.destination << " " << current_train.departure_time <<
			" " << current_train.number_of_available_seats << endl;
		countOfStru++;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


//#include <iostream> 
//#include <windows.h> 
//using namespace std;
//int main(int n, char** s)
//{
//	int i = 0;
//	if (n > 0) i = atoi(s[1]);
//	for (;; Sleep(100)) cout << i++ << " ";
//	return 0;
//}