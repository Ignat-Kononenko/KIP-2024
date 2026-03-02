#pragma once
#include "LT.h"
#define ID_MAXSIZE 10				//макс кол-во символов в идент.
#define TI_MAXSIZE 4096				//макс кол-во строк в ТИ
#define TI_INT_DEFAULT 0x00000000	//знач. по умолч для integer
#define TI_STR_DEFAULT 0x00			//знач. по умолч для string
#define TI_CHAR_DEFAULT 0x00	
#define TI_NULLIDX 0xffffffff		//нет элементов ТИ
#define TI_STR_MAXSIZE 255			//максимальный размер строки
#define TI_CHAR_MAXSIZE 1
#define TI_INT_MAXSIZE 255
#define TI_INT_MINSIZE -256
#define MAX_PARAMS 5

namespace IT	//ТАБЛИЦА ИДЕНТИФИКАТОРОВ
{
	enum IDDATATYPE { INT = 1, CHAR = 2, BOOL = 3, STR = 4};		///типы данных идентификаторов: integer, string
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, OP = 5 };	///типы идентификаторов: переменная, функция, параметр, литерал, оператор

	struct Entry	//строка ТИ
	{
		int idxfirstLE;			///индекс первой строки в таблице лексем
		char id[ID_MAXSIZE * 2 + 1];	///идентификатор(автоматически усекается до ID_MAXSIZE)
		IDDATATYPE iddatatype;	///тип данных
		IDTYPE idtype;			///тип идентификатора
		struct
		{
			int count;
			IDDATATYPE type[MAX_PARAMS];
		}params;
		struct		// 
		{
			int vint = 0;
			struct {
				int lenghtOfChar;
				char ch[TI_CHAR_MAXSIZE]{};
			}vchar;
			bool vbool;
			struct
			{
				int len;						// количество символов в string
				char str[TI_STR_MAXSIZE - 1]{};	// символы string
			}vstr;								// значение string
		}value;		// значение идентификатора							
	};

	struct IdTable	//экземпляр ТИ
	{
		int maxsize;	///емкость ТИ < TI_MAXSIZE
		int size;		///текущий размер ТИ < maxsize
		Entry* table;	///массив строк ТИ
	};

	IdTable Create(				//создать таблицу идентификаторов
		int size				///емкость таблицы идентификаторов < TI_MAXSIZE
	);

	void Add(				//добавить строку в таблицу идентификаторов
		IdTable& idtable,		/// экземпл¤р таблицы идентификаторов
		Entry entry				///строка таблицы идентификаторов
	);

	Entry GetEntry(IdTable& idtable, int n);	//возвр. ид. по номеру строки

	int IsId(					//возврат: номер строки(если есть), TI_NULLIDX(если нет)
		IdTable& idtable,		///экземпл¤р таблицы идентификаторов
		char id[ID_MAXSIZE]		///идентификатор
	);

	void Delete(IdTable& idtable);		//удалить таблицу идент. (освободить пам¤ть)

	void ShowTable(
		IdTable idt,
		std::ostream& stream_out
	);
};