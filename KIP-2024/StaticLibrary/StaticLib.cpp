#define _CRT_SECURE_NO_WARNINGS
#include "StaticLib.h"

extern "C"
{

	int _stdcall Atom(char* ptr)					// преобразование символьного литерала
	{
		int n = 0;
		while (*ptr >= '0' && *ptr <= '9')
		{
			n *= 10;
			n += *ptr++;
			n -= '0';
		}
		return n;
	}


	int _stdcall Leng(char* str)					// вычисление длины строки
	{
		if (str == nullptr)
			return 0;
		int len = 0;
		for (int i = 0; i < 256; i++)
			if (str[i] == '\0')
			{
				len = i; 
				break;
			}
		return len;
	}

	char* Date()
	{
		const time_t tm = time(nullptr);
		char buf[64];
		strftime(buf, std::size(buf), "%d.%m.%Y", localtime(&tm));
		return buf;
	}

	char* Time()
	{
		const time_t tm = time(nullptr);
		char buf[64];
		strftime(buf, std::size(buf), "%H:%M:%S", localtime(&tm));
		return buf;
	}

	void _stdcall OutputInt(int a) {
		std::cout << a << std::endl;
	}

	void _stdcall OutputStr(char* ptr) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr) {
			std::cout << '\n';
			return;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];

		std::cout << '\n';
	}
}
