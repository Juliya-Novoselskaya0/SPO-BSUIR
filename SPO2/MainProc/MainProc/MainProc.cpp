﻿// MainProc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
struct book
{
	char Name[30];
	int year;
	int number_of_pages;
}hook;
HANDLE myFile;
DWORD n;
int main()
{

	setlocale(LC_ALL, "russian");
	int number;
	LPCTSTR filename = L"D:\\УНИВЕР\\2 КУРС\\СЕМ 4\\СПО\\LR\\SPO2\\library.dat";
	myFile = CreateFile(
		filename, // Имя файла
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (myFile == INVALID_HANDLE_VALUE)
		cout << "Error"; // Файла не существует
	else
		cout << " File is opened\n"; // Файл открыт
	while (ReadFile(myFile, &hook, sizeof(hook), &n, NULL) && n != 0)
	{
		cout << hook.Name << " " << hook.number_of_pages << " " << hook.year << endl;
	};
	cout << "Bведите номер структуры, которую хотите изменить" << endl;
	int k;
	cin >> k;



	//SetFilePointer(myFile, 0, 0, FILE_BEGIN);
	CloseHandle(myFile);

	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));

	wchar_t daughter[200], t[5];
	wcscpy(daughter, L"D:\\УНИВЕР\\2 КУРС\\СЕМ 4\\СПО\\LR\\SPO2\\Daughter.exe ");
	swprintf_s(t, L"%d", k);
	wcscat(daughter, t);
	wcout << wstring(daughter) << endl;


	//wchar_t name2[] = L"Dproc.exe"; не работает
	if (!CreateProcess(NULL, daughter, NULL, NULL, FALSE, 0,
		NULL, NULL, &StartupInfo, &ProcInfo)) return 0;

	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);

	//CloseHandle(myFile);
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
