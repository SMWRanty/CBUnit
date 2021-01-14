#pragma once
#include <iostream>
#ifdef _WINDOWS
	#include <Windows.h>

	inline std::ostream& green(std::ostream& stream)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		return stream;
	}

	inline std::ostream& red(std::ostream& stream)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		return stream;
	}

	inline std::ostream& white(std::ostream& stream)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		return stream;
	}

	inline std::ostream& grey(std::ostream& stream)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return stream;
	}
#else

	inline std::ostream& green(std::ostream& stream)
	{
		stream << "\033[1;32m";
		return stream;
	}

	inline std::ostream& red(std::ostream& stream)
	{
		stream << "\033[1;31m";
		return stream;
	}

	inline std::ostream& white(std::ostream& stream)
	{
		stream << "\033[1;37m";
		return stream;
	}

	inline std::ostream& grey(std::ostream& stream)
	{
		stream << "\033[1;30m";
		return stream;
	}

	inline std::ostream& clear(std::ostream& stream)
	{
		stream << "\033[0m";
		return stream;
	}
#endif