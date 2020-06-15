#pragma once
#include "word.h"
#include<stack>
#include<fstream>
#include<unordered_map>
using namespace std;
enum TokenID
{
	AND = 1,
	ARRAY,
	BEGIN,
	CASE,
	CONST,
	DIV,
	DO,
	DOWNTO,
	ELSE,
	END,
	_FILE,
	FOR,
	FUNC,
	GOTO,
	IF,
	IN,
	LABEL,
	MOD,
	NIL,
	NOT,
	OF,
	OR,
	PACKED,
	PROC,
	PROG,
	RECODE,
	REPEAT,
	SET,
	THEN,
	TO,
	TYPE,
	UNTIL,
	VAR,
	WHILE,
	WITH,
	ID,
	INT,
	REAL,
	STRING,
	PLUS,
	MINUS,
	MULTI,
	RDIV,
	EQ,
	LT,
	GT,
	LE,
	GE,
	NE,
	LR_BRAC,
	RR_BRAC,
	COMMA,
	P_MARK,
	F_STOP,
	RANGE,
	COLON,
	ASSIGN,
	SEMIC,
	CAP,
	EXP,
	LS_BRAC,
	RS_BRAC,
	Q_MARK
};
extern std::stack<char>stack_data;
extern char get_data;    //ͨ���ļ���ȡ���ַ�
extern int station;  //��ǰ״̬
extern fstream input_file; //�ļ�����
extern string word;
extern unordered_map<string, enum TokenID>unordered_map_data;