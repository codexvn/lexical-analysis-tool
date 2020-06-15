#include "word.h"
#include<stack>
#include<fstream>
#include<unordered_map>
using namespace std;

stack<char>stack_data;
char get_data;    //ͨ���ļ���ȡ���ַ�
int station = 0;  //��ǰ״̬
fstream input_file; //�ļ�����
string word;
unordered_map<string, enum TokenID>unordered_map_data = {
	{"and",AND},
	{"array",ARRAY},
	{"begin",BEGIN},
	{"case",CASE},
	{"const",CONST},
	{"div",DIV},
	{"do",DO},
	{"downto",DOWNTO},
	{"else",ELSE},
	{"end",END},
	{"file",_FILE},
	{"for",FOR},
	{"function",FUNC},
	{"goto",GOTO},
	{"if",IF},
	{"in",IN},
	{"label",LABEL},
	{"mod",MOD},
	{"nil",NIL},
	{"not",NOT},
	{"of",OF},
	{"or",OR},
	{"packed",PACKED},
	{"procedure",PROC},
	{"program",PROG},
	{"record",RECODE},
	{"repeat",REPEAT},
	{"set",SET},
	{"then",THEN},
	{"to",TO},
	{"type",TYPE},
	{"until",UNTIL},
	{"var",VAR},
	{"while",WHILE},
	{"with",WITH},
};