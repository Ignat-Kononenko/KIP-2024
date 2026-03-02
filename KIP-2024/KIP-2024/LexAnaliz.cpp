#include "stdafx.h"
#include <stack>
#include "MFST.h"

#define max_word	1000
#define size_word	20

bool typeint(char word[]) {
	FST::FST typeint(word, 4,
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('n', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE()
	);
	return FST::execute(typeint);
}
bool typestr(char word[]) {
	FST::FST typestr(word, 4,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE()
	);
	return FST::execute(typestr);
}

bool typechar(char word[]) {
	FST::FST typestring(word, 5,
		FST::NODE(1, FST::RELATION('c', 1)),
		FST::NODE(1, FST::RELATION('h', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE(1, FST::RELATION('r', 4)),
		FST::NODE()
	);
	return FST::execute(typestring);
}
bool typebool(char word[]) {
	FST::FST typestring(word, 5,
		FST::NODE(1, FST::RELATION('b', 1)),
		FST::NODE(1, FST::RELATION('o', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE()
	);
	return FST::execute(typestring);
}
bool typefunction(char word[]) {
	FST::FST typefunction(word, 5,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE()
	);
	return FST::execute(typefunction);
}
bool strnew(char word[]) {
	FST::FST strdeclare(word, 4,
		FST::NODE(1, FST::RELATION('n', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('w', 3)),
		FST::NODE()
	);
	return FST::execute(strdeclare);
}
bool streturn(char word[]) {
	FST::FST streturn(word, 4,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE()
	);
	return FST::execute(streturn);
}
bool strmain(char word[]) {
	FST::FST strmain(word, 5,
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE()
	);
	return FST::execute(strmain);
}
bool strprint(char word[]) {
	FST::FST strprint(word, 6,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
	);
	return FST::execute(strprint);
}
bool expression(char word[]) {
	FST::FST expression(word, 2,
		FST::NODE(4,
			FST::RELATION('+', 1),
			FST::RELATION('-', 1),
			FST::RELATION('*', 1),
			FST::RELATION('/', 1)),

		FST::NODE()
	);
	return FST::execute(expression);
}
bool leftbrace(char word[]) {
	FST::FST leftbrace(word, 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE()
	);
	return FST::execute(leftbrace);
}
bool rightbrace(char word[]) {
	FST::FST rightbrace(word, 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE()
	);
	return FST::execute(rightbrace);
}
bool leftthesis(char word[]) {
	FST::FST leftthesis(word, 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE()
	);
	return FST::execute(leftthesis);
}
bool rightthesis(char word[]) {
	FST::FST rightthesis(word, 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE()
	);
	return FST::execute(rightthesis);
}
bool semicolon(char word[]) {
	FST::FST semicolon(word, 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE()
	);
	return FST::execute(semicolon);
}
bool comma(char word[]) {
	FST::FST comma(word, 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE()
	);
	return FST::execute(comma);
}
bool left(char word[]) {
	FST::FST left(word, 5,
		FST::NODE(1, FST::RELATION('l', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('f', 3)),
		FST::NODE(1, FST::RELATION('t', 4)),
		FST::NODE()
	);
	return FST::execute(left);
}
bool right(char word[]) {
	FST::FST right(word, 6,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('i', 2)),
		FST::NODE(1, FST::RELATION('g', 3)),
		FST::NODE(1, FST::RELATION('h', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
	);
	return FST::execute(right);
}
bool ravno(char word[]) {

	FST::FST ravno(word, 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE()
	);
	return FST::execute(ravno);
}

bool cycle(char word[]) {

	FST::FST cycle(word, 6,
		FST::NODE(1, FST::RELATION('c', 1)),
		FST::NODE(1, FST::RELATION('y', 2)),
		FST::NODE(1, FST::RELATION('c', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE(1, FST::RELATION('e', 5)),
		FST::NODE()
	);
	return FST::execute(cycle);
}

//bool literalint(char word[]) {
//	FST::FST literalint(word, 3,
//		FST::NODE(1,
//			FST::RELATION('-', 1),       // Отрицательные числа
//			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
//			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
//			FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2),
//			FST::RELATION('9', 2)
//		),
//		FST::NODE(10,
//			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
//			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
//			FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2),
//			FST::RELATION('9', 2)
//		),
//		FST::NODE()
//	);
//	return FST::execute(literalint);
//}



bool literalint(char word[]) {

	FST::FST literalint(word, 2,
		FST::NODE(20,
			FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
			FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
			FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
			FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
			FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1)),
		FST::NODE()
	);
	return FST::execute(literalint);
}

//bool literalNegativeInt(char word[]) {
//
//	FST::FST literalnegativeint(word, 3,
//		FST::NODE(1, FST::RELATION('~', 0)),
//		FST::NODE(20,
//			FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
//			FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
//			FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
//			FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
//			FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
//			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
//			FST::RELATION('8', 1), FST::RELATION('9', 1)),
//		FST::NODE()
//	);
//	return FST::execute(literalnegativeint);
//}
bool literalNegativeInt(char word[]) {
	FST::FST literalnegativeint(word, 3,
		FST::NODE(2,  // Начальное состояние
			FST::RELATION('~', 1)  // Обработка знака ~
		),
		FST::NODE(20,  // Состояние после знака ~
			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
			FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2),
			FST::RELATION('9', 2)
		),
		FST::NODE()  // Конечное состояние
	);
	return FST::execute(literalnegativeint);
}

//bool literalint(char word[]) {
//	FST::FST literalint(word, 3,
//		FST::NODE(1,
//			FST::RELATION('~', 1),       // Отрицательные числа
//			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
//			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
//			FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2),
//			FST::RELATION('9', 2)
//		),
//		FST::NODE(10,
//			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
//			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
//			FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2),
//			FST::RELATION('9', 2)
//		),
//		FST::NODE()
//	);
//	return FST::execute(literalint);
//}

//bool literaluint8(char word[]) {
//	FST::FST literaluint8(word, 4,
//		FST::NODE(1, FST::RELATION('8', 1)),
//		FST::NODE(1, FST::RELATION('x', 2)),
//		FST::NODE(20,
//			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
//			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
//			FST::RELATION('6', 2), FST::RELATION('7', 2),
//			FST::RELATION('0', 3), FST::RELATION('1', 3),
//			FST::RELATION('2', 3), FST::RELATION('3', 3), FST::RELATION('4', 3),
//			FST::RELATION('5', 3), FST::RELATION('6', 3), FST::RELATION('7', 3)),
//
//		FST::NODE()
//	);
//	return FST::execute(literaluint8);
//}

bool literalchar(char word[]) {
	FST::FST literalchar(word, 3,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(153,
			FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1),
			FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1),
			FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1),
			FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),
			FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),
			FST::RELATION('y', 1), FST::RELATION('z', 1),
			FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1),
			FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1),
			FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),
			FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1),
			FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),
			FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),
			FST::RELATION('Y', 1), FST::RELATION('Z', 1),
			FST::RELATION('а', 1), FST::RELATION('б', 1), FST::RELATION('в', 1), FST::RELATION('г', 1),
			FST::RELATION('д', 1), FST::RELATION('е', 1), FST::RELATION('ё', 1), FST::RELATION('ж', 1),
			FST::RELATION('з', 1), FST::RELATION('и', 1), FST::RELATION('й', 1), FST::RELATION('к', 1),
			FST::RELATION('л', 1), FST::RELATION('м', 1), FST::RELATION('н', 1), FST::RELATION('о', 1),
			FST::RELATION('п', 1), FST::RELATION('р', 1), FST::RELATION('с', 1), FST::RELATION('т', 1),
			FST::RELATION('у', 1), FST::RELATION('ф', 1), FST::RELATION('х', 1), FST::RELATION('ц', 1),
			FST::RELATION('ч', 1), FST::RELATION('ш', 1), FST::RELATION('щ', 1), FST::RELATION('ь', 1),
			FST::RELATION('ы', 1), FST::RELATION('ъ', 1), FST::RELATION('э', 1), FST::RELATION('ю', 1),
			FST::RELATION('я', 1),
			FST::RELATION('А', 1), FST::RELATION('Б', 1), FST::RELATION('В', 1), FST::RELATION('Г', 1),
			FST::RELATION('Д', 1), FST::RELATION('Е', 1), FST::RELATION('Ё', 1), FST::RELATION('Ж', 1),
			FST::RELATION('З', 1), FST::RELATION('И', 1), FST::RELATION('Й', 1), FST::RELATION('К', 1),
			FST::RELATION('Л', 1), FST::RELATION('М', 1), FST::RELATION('Н', 1), FST::RELATION('О', 1),
			FST::RELATION('П', 1), FST::RELATION('Р', 1), FST::RELATION('С', 1), FST::RELATION('Т', 1),
			FST::RELATION('У', 1), FST::RELATION('Ф', 1), FST::RELATION('Х', 1), FST::RELATION('Ц', 1),
			FST::RELATION('Ч', 1), FST::RELATION('Ш', 1), FST::RELATION('Щ', 1), FST::RELATION('Ь', 1),
			FST::RELATION('Ы', 1), FST::RELATION('Ъ', 1), FST::RELATION('Э', 1), FST::RELATION('Ю', 1),
			FST::RELATION('я', 1),
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),
			FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1),
			FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1),
			FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1),
			FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1),
			FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1),
			FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('&', 1),
			FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1),
			FST::RELATION('^', 1),
			FST::RELATION('\'', 2)),
		FST::NODE()
	);
	return FST::execute(literalchar);
}

bool literalstring(char word[]) {
	FST::FST literalstring(word, 3,
		FST::NODE(1, FST::RELATION('\"', 1)),
		FST::NODE(153,
			FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1),
			FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1),
			FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1),
			FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),
			FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),
			FST::RELATION('y', 1), FST::RELATION('z', 1),
			FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1),
			FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1),
			FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),
			FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1),
			FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),
			FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),
			FST::RELATION('Y', 1), FST::RELATION('Z', 1),
			FST::RELATION('а', 1), FST::RELATION('б', 1), FST::RELATION('в', 1), FST::RELATION('г', 1),
			FST::RELATION('д', 1), FST::RELATION('е', 1), FST::RELATION('ё', 1), FST::RELATION('ж', 1),
			FST::RELATION('з', 1), FST::RELATION('и', 1), FST::RELATION('й', 1), FST::RELATION('к', 1),
			FST::RELATION('л', 1), FST::RELATION('м', 1), FST::RELATION('н', 1), FST::RELATION('о', 1),
			FST::RELATION('п', 1), FST::RELATION('р', 1), FST::RELATION('с', 1), FST::RELATION('т', 1),
			FST::RELATION('у', 1), FST::RELATION('ф', 1), FST::RELATION('х', 1), FST::RELATION('ц', 1),
			FST::RELATION('ч', 1), FST::RELATION('ш', 1), FST::RELATION('щ', 1), FST::RELATION('ь', 1),
			FST::RELATION('ы', 1), FST::RELATION('ъ', 1), FST::RELATION('э', 1), FST::RELATION('ю', 1),
			FST::RELATION('я', 1),
			FST::RELATION('А', 1), FST::RELATION('Б', 1), FST::RELATION('В', 1), FST::RELATION('Г', 1),
			FST::RELATION('Д', 1), FST::RELATION('Е', 1), FST::RELATION('Ё', 1), FST::RELATION('Ж', 1),
			FST::RELATION('З', 1), FST::RELATION('И', 1), FST::RELATION('Й', 1), FST::RELATION('К', 1),
			FST::RELATION('Л', 1), FST::RELATION('М', 1), FST::RELATION('Н', 1), FST::RELATION('О', 1),
			FST::RELATION('П', 1), FST::RELATION('Р', 1), FST::RELATION('С', 1), FST::RELATION('Т', 1),
			FST::RELATION('У', 1), FST::RELATION('Ф', 1), FST::RELATION('Х', 1), FST::RELATION('Ц', 1),
			FST::RELATION('Ч', 1), FST::RELATION('Ш', 1), FST::RELATION('Щ', 1), FST::RELATION('Ь', 1),
			FST::RELATION('Ы', 1), FST::RELATION('Ъ', 1), FST::RELATION('Э', 1), FST::RELATION('Ю', 1),
			FST::RELATION('я', 1),
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),
			FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1),
			FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1),
			FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1),
			FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1),
			FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1),
			FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('&', 1),
			FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1),
			FST::RELATION('^', 1),
			FST::RELATION('\"', 2)),
		FST::NODE()
	);
	return FST::execute(literalstring);
}


bool literalbool1(char word[]) {

	FST::FST literalbool(word, 5,
		FST::NODE(1, FST::RELATION('t', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('u', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(literalbool);
}
bool literalbool2(char word[]) {

	FST::FST literalbool(word, 6,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('l', 3)),
		FST::NODE(1, FST::RELATION('s', 4)),
		FST::NODE(1, FST::RELATION('e', 5)),
		FST::NODE()
	);
	return FST::execute(literalbool);
}

bool idenf(char word[]) {

	FST::FST idenf(word, 2,
		FST::NODE(54,
			FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
			FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
			FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
		FST::NODE()
	);
	return FST::execute(idenf);
}

bool Atom_fi(char word[]){
	FST::FST staticfi(word, 5,
		FST::NODE(1, FST::RELATION('A', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('m', 4)),
		FST::NODE()
	);
	return FST::execute(staticfi);
}

bool Leng_fi(char word[]) {
	FST::FST staticfi(word, 5,
		FST::NODE(1, FST::RELATION('L', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('g', 4)),
		FST::NODE()
	);
	return FST::execute(staticfi);
}


bool Data_fi(char word[]) {
	FST::FST staticfi(word, 5,
		FST::NODE(1, FST::RELATION('D', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(staticfi);
}
bool Time_fi(char word[]) {
	FST::FST staticfi(word, 5,
		FST::NODE(1, FST::RELATION('T', 1)),
		FST::NODE(1, FST::RELATION('i', 2)),
		FST::NODE(1, FST::RELATION('m', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(staticfi);
}

namespace LexAnal
{

	void Synchronization(LexAnal::Lex& lex) {
		bool* is_changed = new bool[lex.idtab.size] { 
			false 
		};
		for (int i = 0; i < lex.lextab.size; i++)
		{
			if (lex.lextab.table[i].idxTI != -1 && !is_changed[lex.lextab.table[i].idxTI])
			{
				lex.idtab.table[lex.lextab.table[i].idxTI].idxfirstLE = i;
				is_changed[lex.lextab.table[i].idxTI] = true;
			}
		}
		delete[] is_changed;
	}

	Lex LexAnaliz(Parm::PARM parm, In::IN in)
	{
		Lex lex;
		LT::LexTable lextab = LT::Create(LT_MAXSIZE - 1);
		IT::IdTable idtab = IT::Create(TI_MAXSIZE - 1);
		char** word = new char* [max_word];
		for (int i = 0; i < max_word; i++)
			word[i] = new char[size_word] {NULL};

		do
		{
			word = In::splitText(in.text, in.size);
		} while (word == NULL);

		stack<std::string> functions;
		int literalCounter = 1;
		int indexLex = 1;
		int position = 0;
		int is_cycle = 0;
		bool findDeclaration = false;
		bool findType = false;
		bool findFunc = false;
		bool findMain = false;
		bool findParm = false;
		bool findProc = false;
		int findFalse = 0;
		int idxFalse = 0;
		int mainCounter = 0;

		char* bufprefix = new char[10] { "" };
		char* L = new char[2] { "L" };
		char* bufL = new char[TI_STR_MAXSIZE];
		char* charclit = new char[10] { "" };
		char* nameLiteral = new char[10] { "" };
		int line = 1;

		IT::Entry entryIT = {};

		for (int i = 0; word[i] != NULL; i++)
		{
		/*	cerr << "ff: " << word[i] << endl;*/
			bool findSameID = false;
			position += strlen(word[i]);
			if (strnew(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_NEW, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findDeclaration = true;
			}
			else if (typeint(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_INT, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::INT;
			}
			else if (typebool(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BOOL, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::BOOL;
			}
			else if (typestr(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_STR, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::STR;
				strcpy(entryIT.value.vstr.str, "");
			}
			else if(typechar(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_CHAR, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::CHAR;
				strcpy(entryIT.value.vchar.ch, "");
			}
			else if (typefunction(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_FUNCTION, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findFunc = true;
			}
			else if (streturn(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RETURN, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (strprint(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_PRINT, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (strmain(word[i]))
			{
				strcpy(entryIT.id, word[i]);
				entryIT.idxfirstLE = indexLex;
				entryIT.idtype = IT::F;
				entryIT.iddatatype = IT::INT;
				IT::Add(idtab, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_MAIN, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
				functions.push(word[i]);
				findMain = true;
				mainCounter++;
			}
			else if (Atom_fi(word[i]) || Leng_fi(word[i])) {
				if (int idx = IT::IsId(idtab, word[i]) == TI_NULLIDX) {
					entryIT.idtype = IT::F;
					entryIT.iddatatype = IT::INT;
					entryIT.idxfirstLE = indexLex;
					entryIT.params.count = 1;
					entryIT.params.type[entryIT.params.count] = IT::STR;
					strcpy(entryIT.id, word[i]);
					IT::Add(idtab, entryIT);
					entryIT = {};
				}
				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
			}
			else if (Data_fi(word[i]) || Time_fi(word[i])) {
				if (int idx = IT::IsId(idtab, word[i]) == TI_NULLIDX) {
					entryIT.idtype = IT::F;
					entryIT.iddatatype = IT::STR;
					entryIT.idxfirstLE = indexLex;
					entryIT.params.count = 0;
					strcpy(entryIT.id, word[i]);
					IT::Add(idtab, entryIT);
					entryIT = {};
				}

				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
			}
			else if (cycle(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_CYCLE, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				is_cycle++;
			}
			else if (literalint(word[i]))
			{
				/*std::cerr << "Обнаружен int: " << word[i] << std::endl;*/
				int value = atoi((char*)word[i]);
				if (value > TI_INT_MAXSIZE || value < TI_INT_MINSIZE)
				{
					throw ERROR_THROW(313);
				}
				bool findSameID = false;
				for (int k = 0; k < idtab.size; k++) {
					if (idtab.table[k].value.vint == value &&
						idtab.table[k].idtype == IT::L &&
						idtab.table[k].iddatatype == IT::INT)
					{
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						findSameID = true;
						/*std::cerr << "Найден существующий идентификатор с значением: " << value << std::endl;*/
						break;
					}
				}

				if (findSameID)
					continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::INT;
				entryIT.value.vint = value;
				entryIT.idxfirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtab, entryIT);
				entryIT = {};

				/*std::cerr << "Добавление нового литерала с значением: " << value << std::endl;*/

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
				}

			else if (literalNegativeInt(word[i]))
			{
		/*		std::cerr << "Обнаружен neg int: " << word[i] << std::endl;*/
				

				if (word[i][0] == '~') { 
					word[i][0] = '-'; 
				}
				int value = atoi((char*)word[i]);
				if (value > TI_INT_MAXSIZE || value < TI_INT_MINSIZE)
				{
					throw ERROR_THROW(313);
				}
				for (int k = 0; k < idtab.size; k++) {
					if (idtab.table[k].value.vint == value &&
						idtab.table[k].idtype == IT::L &&
						idtab.table[k].iddatatype == IT::INT)
					{
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						findSameID = true;/*
						std::cerr << "Найден существующий идентификатор с значением: " << value << std::endl;*/
						break;
					}
				}

				if (findSameID)
					continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::INT;
				entryIT.value.vint = value;
				entryIT.idxfirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtab, entryIT);
				entryIT = {};

			/*	std::cerr << "Добавление нового литерала с значением: " << value << std::endl;*/

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
				}
			
			else if (literalbool1(word[i]) || literalbool2(word[i]))
			{
				bool value = true;
				if (literalbool2(word[i]))
				{
					value = false;
					findFalse++;
				}
				if (value == true)
				{
					for (int k = 0; k < idtab.size; k++) {
						if (idtab.table[k].value.vbool == value)
						{
							findSameID = true;
							LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
							LT::Add(lextab, entryLT);
							break;
						}
					}
				}
				if (findFalse == 1)
				{
					idxFalse = idtab.size;
				}
				if (findFalse != 1 && findFalse > 1) {

					findSameID = true;
					LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, idxFalse, line);
					LT::Add(lextab, entryLT);
					break;

				}
				if (findSameID) continue;

				entryIT.value.vbool = value;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::BOOL;
				entryIT.idxfirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtab, entryIT);
				entryIT = {};

				/*int k = 0;
				for (k = 0; k < idtab.size; k++)
				{
					if (idtab.table[k].value.vbool = word[i])
						break;
				}*/
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtab, nameLiteral), line);
				LT::Add(lextab, entryLT);
			}

			else if (literalchar(word[i]))
			{
				/*cerr << "word char- " << word[i] << endl;*/
				int length = strlen(word[i]);
				if (strlen(word[i]) == 2)
				{
					throw ERROR_THROW(321)
				}
				if (length - 2 > TI_CHAR_MAXSIZE)
				{
					throw ERROR_THROW(316);
				}
				for (int k = 0; k < length; k++) {
					word[i][k] = word[i][k + 1];
					/*cerr << "word - " << word[i][k] << endl;*/
				}

				word[i][length - 2] = 0;
				/*cerr << "word - " << word[i][length - 2] << endl;*/

				for (int k = 0; k < idtab.size; k++) {
					if (!(strcmp(idtab.table[k].value.vchar.ch, word[i])))
					{
						findSameID = true;
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						break;
					}
				}
				if (findSameID)
					continue;

				strcpy(entryIT.value.vchar.ch, word[i]);
				entryIT.value.vchar.lenghtOfChar = length - 2;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::CHAR;
				entryIT.idxfirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtab, entryIT);
				entryIT = {};

				int k = 0;
				for (k = 0; k < idtab.size; k++)
				{
					if (!(strcmp(idtab.table[k].value.vchar.ch, word[i])))
						break;
				}
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
				LT::Add(lextab, entryLT);
				}
			else if (literalstring(word[i]))
			{
				/*cerr << "word str- " << word[i] << endl;*/
				int length = strlen(word[i]);
				if (strlen(word[i]) == 2)
				{
					throw ERROR_THROW(321)
				}
				if (length - 2 > TI_STR_MAXSIZE)
				{
					throw ERROR_THROW(316);
				}
				for (int k = 0; k < length; k++) {
					word[i][k] = word[i][k + 1];
					/*cerr << "word - " << word[i][k] << endl;*/
				}
				
				word[i][length - 2] = 0;
				/*cerr << "word - " << word[i][length - 2] << endl;*/

				for (int k = 0; k < idtab.size; k++) {
					if (!(strcmp(idtab.table[k].value.vstr.str, word[i])))
					{
						findSameID = true;
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						break;
					}
				}
				if (findSameID) 
					continue;

				strcpy(entryIT.value.vstr.str, word[i]);
				entryIT.value.vstr.len = length - 2;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::STR;
				entryIT.idxfirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtab, entryIT);
				entryIT = {};

				int k = 0;
				for (k = 0; k < idtab.size; k++)
				{
					if (!(strcmp(idtab.table[k].value.vstr.str, word[i])))
						break;
				}
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
				LT::Add(lextab, entryLT);
			}
			else if (left(word[i]) || right(word[i]) || expression(word[i]))
			{
				if (left(word[i])) strcpy(word[i], "<<");
				if (right(word[i])) strcpy(word[i], ">>");
				strcpy(entryIT.id, word[i]);
				entryIT.idxfirstLE = indexLex;
				entryIT.idtype = IT::OP;
				if (IT::IsId(idtab, word[i]) == TI_NULLIDX)
					IT::Add(idtab, entryIT);
				entryIT = { };

				LT::Entry entryLT = WriteEntry(entryLT, LEX_OPERATOR, IT::IsId(idtab, word[i]), line);
				switch (word[i][0])
				{
				case '>':
					entryLT.priority = 2;
					entryLT.op = LT::operations::RIGHT;
					break;
				case '<':
					entryLT.priority = 2;
					entryLT.op = LT::operations::LEFT;
					break;
				case '+':
					entryLT.priority = 1;
					entryLT.op = LT::operations::OPLUS;
					break;
				case '-':
					entryLT.priority = 1;
					entryLT.op = LT::operations::OMINUS;
					break;
				case '*':
					entryLT.priority = 3;
					entryLT.op = LT::operations::OMUL;
					break;
				case '/':
					entryLT.priority = 3;
					entryLT.op = LT::operations::ODIV;
					break;

				}
				LT::Add(lextab, entryLT);

			}
			else if (idenf(word[i]))
			{
				if (strlen(word[i]) > ID_MAXSIZE)
				{
					throw ERROR_THROW(317);
				}
				if (findParm)
					entryIT.idtype = IT::P;
				else if (findFunc)
				{
					entryIT.idtype = IT::F;
					functions.push(word[i]);
				}
				else
				{
					entryIT.idtype = IT::V;
					int idx = IT::IsId(idtab, word[i]);
					if (idx != TI_NULLIDX) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, idx, line);
						LT::Add(lextab, entryLT);

						entryIT = { };
						continue;
					}
					if (idx == TI_NULLIDX && !findDeclaration && findType) throw ERROR_THROW(304);
					if (idx == TI_NULLIDX && findDeclaration && !findType) throw ERROR_THROW(306);


					if (entryIT.iddatatype == IT::INT)
						entryIT.value.vint = TI_INT_DEFAULT;
					/*else if (entryIT.iddatatype == IT::UINT)
						entryIT.value.vuint = TI_INT_DEFAULT;*/
					else if (entryIT.iddatatype == IT::BOOL)
					{
						entryIT.value.vbool = false;
					}
					else if (entryIT.iddatatype == IT::STR)
					{
						entryIT.value.vstr.len = 0;
						memset(entryIT.value.vstr.str, TI_STR_DEFAULT, sizeof(char));
					}
					else if (entryIT.iddatatype == IT::CHAR)
					{
						entryIT.value.vchar.lenghtOfChar = 0;
						memset(entryIT.value.vchar.ch, TI_CHAR_DEFAULT, sizeof(char));
					}
				}
				int idx = IT::IsId(idtab, word[i]);
				if (idx != TI_NULLIDX && findParm) 
					throw ERROR_THROW(308);
				entryIT.idxfirstLE = indexLex;
				if (entryIT.idtype != IT::F && !functions.empty())
				{
					strcpy(bufprefix, functions.top().c_str());
					bufprefix = strcat(bufprefix, "_");
					word[i] = strcat(bufprefix, word[i]);
				}
				strcpy(entryIT.id, word[i]);
				idx = IT::IsId(idtab, word[i]);

				if (idx != TI_NULLIDX && findDeclaration && findType) throw ERROR_THROW(308);
				if (findFunc && !findParm)
				{
					int c = i + 1;


					while (!leftbrace(word[c]))
					{
						if (typestr(word[c]) || typebool(word[c]) || /*typeuint(word[c]) ||*/ typeint(word[c]) || typechar(word[c]))
						{
							if (typeint(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::INT;

							}
							if (typestr(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::STR;

							}
							if (typebool(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::BOOL;

							}
							if (typechar(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::CHAR;

							}
							/*if (typeuint(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::INT;

							}*/
							entryIT.params.count++;
							if (entryIT.params.count > MAX_PARAMS)
							{
								throw ERROR_THROW(318)
							}
						}
						c++;
					}
				}
				if (idx != TI_NULLIDX && typefunction(word[i - 1])) throw ERROR_THROW(307);
				if (idx == TI_NULLIDX && !findFunc && !findParm)
				{
					if (i > 1)
					{
						if (!(typestr(word[i - 1]) || typebool(word[i - 1]) /*|| typeuint(word[i - 1])*/ || typeint(word[i-1]) || typechar(word[i-1])))
						{
							throw ERROR_THROW(305);
						}
					}
					else
						throw ERROR_THROW(305);
				}
				if (idx == TI_NULLIDX)
					IT::Add(idtab, entryIT);
				/*if (idx == TI_NULLIDX && !findDeclaration && !findType && !findFunc && !findParm)
					throw ERROR_THROW(305);*/
				if (!findFunc && functions.empty()) 
					throw ERROR_THROW(303);
				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
				entryIT = { };
			}
			else if (semicolon(word[i]))
			{
				/*if (findDeclaration && findFunc && findType)
					functions.pop();*/
				LT::Entry entryLT = WriteEntry(entryLT, LEX_SEMICOLON, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findDeclaration = findFunc = findType = findParm = false;
				entryIT = { };
			}
			else if (comma(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_COMMA, LT_TI_NULLIDX, line);

				LT::Add(lextab, entryLT);
			}
			else if (leftbrace(word[i]))
			{
				findType = findDeclaration = findFunc = findParm = false;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTBRACE, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (rightbrace(word[i]))
			{
				if (!functions.empty() && is_cycle == 0)
					functions.pop();
				else if (is_cycle != 0) is_cycle--;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BRACELET, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (leftthesis(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTHESIS, LT_TI_NULLIDX, line);

				LT::Add(lextab, entryLT);
				if (findFunc)
					findParm = true;
			}
			else if (rightthesis(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RIGHTHESIS, LT_TI_NULLIDX, line);

				findParm = false;
				LT::Add(lextab, entryLT);
			}
			else if (ravno(word[i]))
			{
				findDeclaration = findType = false;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_EQUALS, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (word[i][0] == DIV)
			{
				line++;
				position = 0;
				indexLex++;
			}
			else
				throw ERROR_THROW(205);
		}


		if (lextab.size > LT_MAXSIZE) 
			throw ERROR_THROW(201);
		if (idtab.size > TI_MAXSIZE) 
			throw ERROR_THROW(203);
		if (!findMain) 
			throw ERROR_THROW(302);
		if (mainCounter > 1) 
			throw ERROR_THROW(301);

		lex.lextab = lextab;
		lex.idtab = idtab;

		return lex;


	}
}