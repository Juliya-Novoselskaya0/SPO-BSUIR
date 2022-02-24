// SPO3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Написать программу, запускающую три дочерних потока. Каждый поток 
//увеличивает(начиная с 0) значение счетчика с разной скоростью(использовать функцию sleep).При нажатии на клавишу ‘q’ 
//закрыть все потоки и завершить выполнение программы
//Вариант 11 11.Остановить поток, счетчик которого последним достигнет значения 


#include <iostream>
#include <windows.h> 
using namespace std;

int valueOfThread_1 = 0, valueOfThread_2 = 0, valueOfThread_3 = 0, smallestThread, smallestThread_num;
HANDLE hTh1, hTh2, hTh3;

DWORD WINAPI thread_1() {
	while (true) {
		valueOfThread_1++;
		Sleep(100);
	}
	return 0;
}

DWORD WINAPI thread_2() {
	while (true) {
		valueOfThread_2++;
		Sleep(70);
	}
	return 0;
}

DWORD WINAPI thread_3() {
	while (true) {
		valueOfThread_3++;
		Sleep(120);
	}
	return 0;
}


void searchForTheLastTHERAD_slow()
{
	smallestThread = valueOfThread_1;
	smallestThread_num = 1;
	if (valueOfThread_2 < smallestThread)
	{
		smallestThread = valueOfThread_2;
		smallestThread_num = 2;
	}
	if (valueOfThread_3 < smallestThread)
	{
		smallestThread = valueOfThread_3;
		smallestThread_num = 3;
	}

	if (smallestThread >= 120)
	{
		switch (smallestThread_num)
		{
			case 1:
			{
				TerminateThread(hTh1, 0);
				cout << "Thread 1 was stopped" << endl;
			}
			case 2:
			{
				TerminateThread(hTh2, 0);
				cout << "Thread 2 was stopped" << endl;
			}
			case 3:
			{
				TerminateThread(hTh3, 0);
				cout << "Thread 3 was stopped" << endl;
			}
		}
	}
}

int main()
{
	int threads_count = 3, close1 = 0, close2 = 0, close3 = 0;
	DWORD IDThread1, IDThread2, IDThread3;

	//создание потоков
	if ((hTh1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_1, NULL, 0, &IDThread1)) == NULL) {
		int error = GetLastError();
		cerr << "There is an error while hTh1 thread creating: " << error << endl;
		return error;
	}

	if ((hTh2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_2, NULL, 0, &IDThread2)) == NULL) {
		int error = GetLastError();
		cerr << "There is an error while hTh2 thread creating: " << error << endl;
		return error;
	}

	if ((hTh3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_3, NULL, 0, &IDThread3)) == NULL) {
		int error = GetLastError();
		cerr << "There is an error while hTh3 thread creating: " << error << endl;
		return error;
	}

		char input_symbol;
	do {
		searchForTheLastTHERAD_slow(); //ищем последний поток, который достигнет значения 120 и останавливаем его

		cout << "'q' Close all threads" << endl;
		cout << "'w' Show current values" << endl;
		cin >> input_symbol;
		cin.clear();
		system("cls");
		switch (input_symbol)
		{
		case 'w':
			//вывод текущих значений счетчиков потоков
			cout << "Thread 1 value = " << valueOfThread_1 << endl;
			cout << "Thread 2 value = " << valueOfThread_2 << endl;
			cout << "Thread 3 value = " << valueOfThread_3 << endl;
			break;
		default:
			break;
		}
	} while (input_symbol != 'q');

	//закрываем потоки
	if (close1 != 1) CloseHandle(hTh1);
	if (close2 != 1) CloseHandle(hTh2);
	if (close3 != 1) CloseHandle(hTh3);

	return 0;
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