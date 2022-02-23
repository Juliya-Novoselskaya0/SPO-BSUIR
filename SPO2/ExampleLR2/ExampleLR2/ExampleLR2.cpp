#include <iostream> 
#include <windows.h> 
#include <conio.h> 
using namespace std;
int main()
{
	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	wchar_t AppName[] = L"MainProc.exe";
	if (!CreateProcess(NULL, AppName, NULL, NULL, FALSE, 0,
		NULL, NULL, &StartupInfo, &ProcInfo)) return 0;

	//cout << "Click 'q' to stop" << endl;
	//char ch = NULL;
	//while (ch != 'q') ch = _getch();
	//TerminateProcess(ProcInfo.hProcess, 1);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);
	return 0;
}