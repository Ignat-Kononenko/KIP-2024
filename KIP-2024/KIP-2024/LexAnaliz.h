#pragma once
#include "stdafx.h"
#include "In.h"
#include "Parm.h"
#include "IT.h"
#include "LT.h"

#define max_word	5000
#define size_word	280

namespace LexAnal
{
	struct Lex
	{
		LT::LexTable lextab;					// таблица лексем
		IT::IdTable idtab;						// таблица идентификаторов
	};

	void Synchronization(LexAnal::Lex& lex);	// синхронизируем таблицу лексем и таблицу идентификаторов
	Lex LexAnaliz(Parm::PARM parm, In::IN in);	// выполняем анализ исходного текста

}