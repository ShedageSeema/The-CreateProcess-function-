#include <windows.h>
#include <stdio.h>   
#include <string.h>
#include<iostream>






int main(VOID)
{
	HANDLE hProcess;
	HANDLE hTreadl;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwProcessId = 0;


	//ALLOCATE MEMORY 
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	//create child process
	if (!CreateProcess(NULL, "C:\\WINDOWS\\system32\\mspaint.exe", //use command line
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{
		fprintf(stderr, "Create Process Faild");

	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");

	//Close handles 

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);


}