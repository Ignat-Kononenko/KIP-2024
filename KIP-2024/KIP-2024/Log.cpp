#include "stdafx.h"

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG tempLog = Log::INITLOG;

		tempLog.stream = new std::ofstream;
		tempLog.stream->open(logfile);

		if (!tempLog.stream)
		{
			throw ERROR_THROW(112);	///Ошибка при создании файла протокола
		}

		return tempLog;
	};


	void WriteLine(LOG log, char* c, ...)
	{
		char** p = &c;

		while (*p != "")
		{
			(*log.stream) << *p;
			p += sizeof(**p);
		}
	};


	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t** p = &c;
		char buffer[50];

		while (*p != L"")
		{
			wcstombs(buffer, *p, sizeof(buffer));
			(*log.stream) << buffer;
			p += sizeof(**p) / 2;
		}
	};


	void WriteLog(LOG log)
	{
		char buffer[PARM_MAX_SIZE];

		time_t rawtime;
		struct tm* timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, PARM_MAX_SIZE, "Дата: %d.%m.%y %H:%M:%S", timeinfo);
		(*log.stream) << "\n---- Протокол ---- \n" << buffer << " ---- \n";
	};


	void WriteParm(LOG log, Parm::PARM parm)
	{
		char inInfo[PARM_MAX_SIZE];
		char outInfo[PARM_MAX_SIZE];
		char logInfo[PARM_MAX_SIZE];

		wcstombs(inInfo, parm.in, sizeof(inInfo));
		wcstombs(outInfo, parm.out, sizeof(outInfo));
		wcstombs(logInfo, parm.log, sizeof(logInfo));

		(*log.stream) << "---- Параметры ---- \n"
			<< " -in: " << inInfo << "\n"
			<< " -out: " << outInfo << "\n"
			<< " -log: " << logInfo << "\n";
	};


	void WriteIn(LOG log, In::IN in)
	{
		(*log.stream) << "----------------------------------Исходные данныe-------------------------------\n";
		for (int i = 0; i < in.size; i++)
		{
			if (in.text[i] == '|')
			{
				(*log.stream) << "\n";
				continue;
			}
			(*log.stream) << in.text[i];
		}
		(*log.stream) << "\nВсего символов: " << in.size << "\n";
		(*log.stream) << "Всего строк: " << in.lines << "\n";
		(*log.stream) << "Пропущено: " << in.ignor << "\n";
		(*log.stream) << "-------------------------------------------------------------------------------\n";
	};


	void WriteError(LOG log, Error::ERROR error)
	{
		if (error.id == 100)
		{
			std::cout << "ОШИБКА " << error.id << ": " << error.message << "\n";
		}
		else
		{
			(*log.stream) << "ОШИБКА " << error.id << ": " << error.message << " "
				<< "Строка " << error.inext.line << ", позиция: " << error.inext.col << std::endl;
		}
	};

	void WriteLexTableLog(LT::LexTable& lextable, std::ostream& out)
	{
		int i;
		out << "\n\t\tТаблица лексем" << std::endl;
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
		out << "   #" << " | " << "Лексема" << std::setfill(' ') << std::setw(20) << ' ' << std::left
			<< " | " << "Строка" << std::setw(21) << ' ' << std::left << " | " << "Индекс в ТИ" << std::endl;
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
		for (i = 0; i < lextable.size; i++)
		{
			char op = ' ';
			switch (lextable.table[i].op)
			{
			case LT::operations::OPLUS:
				op = '+';
				break;
			case LT::operations::OMINUS:
				op = '-';
				break;
			case LT::operations::LEFT:
				op = '<';
				break;
			case LT::operations::RIGHT:
				op = '>';
				break;
			case LT::operations::OMUL:
				op = '*';
				break;
			case LT::operations::ODIV:
				op = '/';
				break;
			}
			out << std::setfill('0') << std::setw(4) << std::right << i << " | " << std::setfill(' ')
				<< std::setw(24) << std::left << lextable.table[i].lexema << op << "   | " << std::setw(24) << std::left
				<< lextable.table[i].sn << "    | ";
			if (lextable.table[i].idxTI == LT_TI_NULLIDX)
				out << "-" << std::endl;
			else
				out << std::setw(23) << lextable.table[i].idxTI << std::endl;
		}
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
		out << "\tВсего лексем: " << i << std::endl;
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
	}



	void WritePolishLog(LT::LexTable& lextable, std::ostream& out)
	{
		int i;
		out << "\n\t\tПольская запись" << std::endl;
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
		out << "   #" << " | " << "Лексема(входная)" << std::setfill(' ') << std::setw(20) << ' ' << std::left
			<< " | " << "Строка" << std::setw(21) << ' ' << std::left << " | " << "Лексема(выходная)" << std::endl;
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
		for (i = 0; i < lextable.size; i++)
		{
			char op = ' ';
			switch (lextable.table[i].op)
			{
			case LT::operations::OPLUS:
				op = '+';
				break;
			case LT::operations::OMINUS:
				op = '-';
				break;
			case LT::operations::LEFT:
				op = '<';
				break;
			case LT::operations::RIGHT:
				op = '>';
				break;
			case LT::operations::OMUL:
				op = '*';
				break;
			case LT::operations::ODIV:
				op = '/';
				break;
			}
			out << std::setfill('0') << std::setw(4) << std::right << i << " | " << std::setfill(' ')
				<< std::setw(24) << std::left << lextable.table[i].lexema << op << "   | " << std::setw(24) << std::left
				<< lextable.table[i].sn << "    | ";
				out << std::setw(23) << lextable.table[i].lexema << std::endl;
		}
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
		out << "\tВсего лексем: " << i << std::endl;
		out << std::setfill('-') << std::setw(90) << '-' << std::endl;
	}

	void Close(LOG log)
	{
		log.stream->close();
	}
};