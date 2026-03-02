#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <ctime>

extern "C"
{

	int _stdcall Atom(char* str);

	int _stdcall Leng(char* str);

	char* Date();

	char* Time();

	void _stdcall OutputInt(int a);

	void _stdcall OutputStr(char* ptr);
}

