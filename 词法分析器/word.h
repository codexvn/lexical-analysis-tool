#pragma once
#include<stack>
enum TokenID
{
	AND=1,
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
	NIF,
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
std::stack<char>stack_data;
char get_data;    //通过文件获取的字符
int station = 0;  //当前状态
fstream input_file; //文件对象
string word;