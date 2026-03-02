#include "Generation.h"

using namespace std;

namespace Gen {
	Generator::Generator(LT::LexTable plexT, IT::IdTable pidT, const char* pout)
	{
		lexT = plexT;
		idT = pidT;
		out = ofstream(pout);

		Head();
		Const();
		Data();
		Code();
	}

	void Generator::Head() {
		out << ".586\n";
		out << ".model flat, stdcall\n";
		out << "includelib libucrt.lib\n";
		out << "includelib kernel32.lib\n";
		out << "includelib ../Debug/StaticLibrary.lib\n";
		out << "ExitProcess PROTO :DWORD\n\n";
		out << "Atom PROTO : DWORD\n";
		out << "Leng PROTO : DWORD\n";
		out << "OutputInt PROTO : DWORD\n";
		out << "OutputStr PROTO : DWORD\n";
		out << "EXTRN Date: proc\n";
		out << "EXTRN Time: proc\n";


		out << "\n.stack 4096\n\n";
	}

	void Generator::Const() {
		out << ".CONST\n";
		out << "\toverflownum BYTE \"Выход за пределы значения\", 0\n";
		out << "\tnegativeValue BYTE \"Отрицательное число\", 0\n";
		out << "\tzerodel BYTE \"Деление на ноль\", 0\n";
		/*out << "\tzeroInCycle BYTE \"Ноль в цикле\", 0\n ";*/
		for (int i = 0; i < idT.size; i++)
		{
			if (idT.table[i].idtype == IT::L)
			{
				out << "\t" << idT.table[i].id;
				if (idT.table[i].iddatatype == IT::INT)
					out << " DWORD " << idT.table[i].value.vint;
				if (idT.table[i].iddatatype == IT::STR)
					out << " BYTE \"" << idT.table[i].value.vstr.str << "\", 0";
				if (idT.table[i].iddatatype == IT::CHAR)
					out << " BYTE \"" << idT.table[i].value.vchar.ch << "\", 0";
	
				if (idT.table[i].iddatatype == IT::BOOL)
					out << " DWORD " << idT.table[i].value.vbool;
				out << "\n";
			}
		}
	}

	void Generator::Data() {
		out << "\n.data\n";
		out << "\tcount DWORD 0\n";
		for (int i = 0; i < lexT.size; i++) {
			if (lexT.table[i].lexema == LEX_NEW) {
				if (idT.table[lexT.table[i + 2].idxTI].idtype == IT::V) {
					out << "\t" << idT.table[lexT.table[i + 2].idxTI].id;
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::INT)
						out << " DWORD 0\n";
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::STR)
						out << " DWORD ?\n";
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::CHAR)
						out << " DWORD ?\n";
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::BOOL)
						out << " DWORD 0\n";
				}
			}
		}
	}

	void Generator::Code() {
		stack<char*> myStack;
		int resultPosition;
		bool flagFunc = false, flagReturn = false, flagBody = false, flagCallFunc = false, flagCycle = false;
		int numOfReturn = 0, numOfCycles = 100, countParm = 0;
		int cycleCounter = 0;
		char* cycle = new char[6] {
			"CYCLE" 
		};
		char* bufCycle = new char[TI_STR_MAXSIZE];
		char* in = new char[10] {
			"" 
		};
		string nameOfFunction = string();
		
		

		out << "\n.code\n\n";
		for (int i = 0; i < lexT.size; i++) {
			switch (lexT.table[i].lexema) {
			case LEX_FUNCTION:
				nameOfFunction = idT.table[lexT.table[i + 1].idxTI].id;
				while (lexT.table[i].lexema != LEX_RIGHTHESIS) {
					if (lexT.table[i].lexema == LEX_ID && idT.table[lexT.table[i].idxTI].idtype == IT::F) {
						out << (char*)idT.table[lexT.table[i].idxTI].id << " PROC ";
					}

					if (lexT.table[i].lexema == LEX_ID && idT.table[lexT.table[i].idxTI].idtype == IT::P) {
						out << idT.table[lexT.table[i].idxTI].id << " : ";
						out << "DWORD";
					}

					if (lexT.table[i].lexema == LEX_COMMA)
						out << ", ";

					i++;
				}
				flagFunc = true;
				out << "\n";
				break;

			case LEX_MAIN:
				flagBody = true;
				out << "main PROC\n";
				break;
			case LEX_EQUALS:
				resultPosition = i - 1;
				while (lexT.table[i].lexema != LEX_SEMICOLON) {
					switch (lexT.table[i].lexema) {
					case LEX_ID:
					case LEX_LITERAL:
						if (idT.table[lexT.table[i].idxTI].idtype == IT::F)
							flagCallFunc = true;
						if (idT.table[lexT.table[i].idxTI].iddatatype == IT::INT) {
							out << "\tpush " << idT.table[lexT.table[i].idxTI].id << "\n";
							myStack.push(idT.table[lexT.table[i].idxTI].id);
							break;
						}
						if (idT.table[lexT.table[i].idxTI].iddatatype == IT::BOOL) {
							out << "\tpush " << idT.table[lexT.table[i].idxTI].id << "\n";
							myStack.push(idT.table[lexT.table[i].idxTI].id);
							break;
						}
						if (idT.table[lexT.table[i].idxTI].iddatatype == IT::STR || idT.table[lexT.table[i].idxTI].iddatatype == IT::CHAR) {
							char* s;
							if (idT.table[lexT.table[i].idxTI].idtype == IT::L) {
								out << "\tpush offset " << idT.table[lexT.table[i].idxTI].id << "\n";
								s = new char[8] { "offset " };
							}
							else {
								out << "\tpush " << idT.table[lexT.table[i].idxTI].id << "\n";
								s = new char[1] { "" };
							}

							int firstLenght = strlen((char*)s);
							int secondLenght = strlen((char*)idT.table[lexT.table[i].idxTI].id);
							char* result = (char*)malloc(firstLenght + secondLenght + 1);
							memcpy(result, s, firstLenght);
							memcpy(result + firstLenght, (char*)idT.table[lexT.table[i].idxTI].id, secondLenght + 1);
							myStack.push(result);
							break;
						}

					case LEX_OPERATOR:
						switch (lexT.table[i].op) {
						case LT::OMUL:
							out << "\tpop eax\n";
							out << "\tpop ebx\n";
							out << "\tmul ebx\n";
							out << "\tpush eax\n";
							break;
						case LT::OPLUS:
							out << "\tpop eax\n";
							out << "\tpop ebx\n";
							out << "\tadd eax, ebx\n";
							out << "\tpush eax\n";
							break;
						case LT::OMINUS:
							out << "\tpop ebx\n";
							out << "\tpop eax\n";
							out << "\tsub eax, ebx\n";
							out << "\tpush eax\n";
							break;
						case LT::ODIV:
							out << "\tpop ebx\n";
							out << "\tpop eax\n";
							out << "\cmp ebx, 0\n";
							out << "je DELZERO\n";
							out << "\tcdq\n";
							out << "\tidiv ebx\n";
							out << "\tpush eax\n";
							break;
						case LT::LEFT:
							_itoa_s(cycleCounter++, in, sizeof(char) * 10, 10);
							strcpy(bufCycle, cycle);
							bufCycle = strcat(bufCycle, in);
							out << "\tpop ecx\n";
							out << bufCycle << ":\n";
							out << "\tpop eax\n";
							out << "\tshl eax, 1\n";
							out << "\tcmp eax, 255\n";
							out << "jg OVERFLOW\n";
							out << "\tcmp eax, 0\n";
							out << "jl NEGNUM\n";
							out << "\tpush eax\n";
							out << "\tloop " ;
							out << bufCycle << "\n";
							break;
						case LT::RIGHT:
							_itoa_s(cycleCounter++, in, sizeof(char) * 10, 10);
							strcpy(bufCycle, cycle);
							bufCycle = strcat(bufCycle, in);
							out << "\tpop ecx\n";
							out << bufCycle << ":\n";
							out << "\tpop eax\n";
							out << "\tshr eax, 1\n";
							out << "\tcmp eax, 255\n";
							out << "jg OVERFLOW\n";
							out << "\tcmp eax, 0\n";
							out << "jl NEGNUM\n";
							out << "\tpush eax\n";
							out << "\tloop ";
							out << bufCycle << "\n";
							break;

						}
						break;

					case '@':
						countParm = (char)lexT.table[i + 1].lexema - '0';

						for (int j = 1; j <= countParm; j++)
							out << "\tpop edx\n";

						for (int j = 1; j <= countParm; j++) {
							out << "\tpush " << myStack.top() << "\n";
							myStack.pop();
						}
						out << "\tcall " << idT.table[lexT.table[i].idxTI].id ;
						out << "\n\tpush eax\n";
						flagCallFunc = false;
						break;
					}

					i++;
				}

				out << "\tpop " << idT.table[lexT.table[resultPosition].idxTI].id << "\n";
				break;

			case LEX_RETURN:
				out << "\tpush ";
				if (idT.table[lexT.table[i + 1].idxTI].idtype == IT::L)
				{
					if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::INT)
					{
						out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
					}
					else if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::BOOL)
					{
						out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
					}
					else if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::STR || idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::CHAR)
					{
						out << "offset ";
						out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
					}
				}
				else
					out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
				if (flagFunc) {
					out << "\tjmp local" << numOfReturn << "\n";
					flagReturn = true;
				}
				break;
			case LEX_BRACELET:
				if (flagBody && !flagFunc && !flagCycle) {
					out << "OutAsm:\n";
					out << "\tpush 0\n";
					out << "\tcall ExitProcess\n";
					out << "OVERFLOW:\n";
					out << "\tpush offset overflownum\n";
					out << "\tcall OutputStr\n";
					out << "\tpush 0\n";
					out << "\tcall ExitProcess\n";
					out << "NEGNUM:\n";
					out << "\tpush offset negativeValue\n";
					out << "\tcall OutputStr\n";
					out << "\tpush 0\n";
					out << "\tcall ExitProcess\n";
					out << "DELZERO:\n";
					out << "\tpush offset zerodel\n";
					out << "\tcall OutputStr\n";
					out << "\tpush 0\n";
					out << "\tcall ExitProcess\n";
					out << "main ENDP\n";
					out << "end main";
				}
				if (flagFunc && !flagCycle) {
					if (flagReturn) {
						out << "local";
						out << numOfReturn++ << ":\n";
						out << "\tpop eax\n";
						out << "\tret\n";
						out << "OVERFLOW:\n";
						out << "\tpush offset overflownum\n";
						out << "\tcall OutputStr\n";
						out << "\tpush 0\n";
						out << "\tcall ExitProcess\n";
						out << "NEGNUM:\n";
						out << "\tpush offset negativeValue\n";
						out << "\tcall OutputStr\n";
						out << "DELZERO:\n";
						out << "\tpush offset zerodel\n";
						out << "\tcall OutputStr\n";
						out << "\tpush 0\n";
						out << "\tcall ExitProcess\n";
						flagReturn = false;
					}
					out << nameOfFunction << " ENDP\n\n";
					flagFunc = false;
				}
				if (flagCycle) {
					out << "\tdec count\n";
					out << "\tmov ecx, count\n";
					out << "loop CYCLE" ;
					out << numOfCycles++ << endl;

					flagCycle = false;
				}
				break;
			case LEX_CYCLE:

				flagCycle = true;
				out << "\tpush " << idT.table[lexT.table[i + 2].idxTI].id << endl;
				out << "\tpop count\n";
				out << "\tadd count, 1\n";
				out << "\tmov ecx, count\n";
				out << "CYCLE" << numOfCycles << ":\n";
				i = i + 3;

				break;


			case LEX_PRINT:
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::INT) {
					out << "\tpush " << idT.table[lexT.table[i + 1].idxTI].id ;
					out << "\n\tcall OutputInt\n";
				}				
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::BOOL) {
					out << "\tpush " << idT.table[lexT.table[i + 1].idxTI].id ;
					out << "\n\tcall OutputInt\n";
				}	
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::STR) {
					if (idT.table[lexT.table[i + 1].idxTI].idtype == IT::L)
						out << "\tpush offset ";
					else
						out << "\tpush ";
					out << idT.table[lexT.table[i + 1].idxTI].id ;
					out << "\n\tcall OutputStr\n";
				}
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::CHAR) {
					if (idT.table[lexT.table[i + 1].idxTI].idtype == IT::L)
						out << "\tpush offset ";
					else
						out << "\tpush ";
					out << idT.table[lexT.table[i + 1].idxTI].id ;
					out << "\n\tcall OutputStr\n";
				}
				break;

			}
		}
	}
}