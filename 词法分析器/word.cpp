#include "word.h"
#include<stack>
#include<fstream>
#include<unordered_map>
using namespace std;

stack<char>stack_data;
char get_data;    //通过文件获取的字符
int station = 0;  //当前状态
fstream input_file; //文件对象
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