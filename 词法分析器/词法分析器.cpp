#include<iostream>
#include<fstream>
#include<stack>
#include<cctype>
#include<boost/program_options.hpp>
#include "word.h"
using namespace std;
using namespace boost::program_options;
char NextChar(void) {
	if (stack_data.empty())
		get_data = input_file.get();
	else {
		get_data = stack_data.top();
		stack_data.pop();
	}
	if (isspace(get_data) == 0 and get_data != EOF)
		word += get_data;
	return get_data;
}
void PrintWord(TokenID id, string value = "") {
	if (stack_data.empty() == false)
		if (isspace(stack_data.top()) != 0 or get_data == EOF)
			stack_data.pop();
		else
			word.erase(word.end() - 1);
	if (unordered_map_data.find(word) != unordered_map_data.end())
		id = unordered_map_data[word];
	if (value != "")
		cout << "< " << id << " , " << value << " >" << endl;
	else
		cout << "< " << id << " , " << word << " >" << endl;
	word.clear();
	input_file >> ws;
	station = 0;
	if(id==ID or id==INT or id==REAL)
		last_ls_ID_INT_REAL = true;
	else
		last_ls_ID_INT_REAL = false;
}
int main(int argc, char* argv[])
{
	try {
		options_description desc("允许的参数");
		desc.add_options()
			("help,h", "帮助信息")
			("I,i", value<string>(), "从文件读取")
			//("O,o", value<string>(), "输出到文件")
			;
		variables_map data;
		store(parse_command_line(argc, argv, desc), data);
		notify(data);
		if (data.count("help") or argc == 1) {  //显示帮助信息
			cout << desc << "\n";
			return 1;
		}

		//cout << data["I"].as<string>();
		if (data.count("I") == 0)
			cout << "未指定输入文件";
		else {
			input_file.open(data["I"].as<string>(), ios_base::in);
			if (input_file.is_open() == false) {
				cerr << "错误: 文件打开错误" << endl;
				return 1;
			}
		}
	}
	catch (exception& e) {
		cerr << "错误: " << e.what() << "\n";
		return 1;
	}
	catch (...) {
		cerr << "未知类型错误\n";
	}
	input_file >> ws;
	try
	{
		while (input_file.eof() == false or station != 0)
		{
			switch (station)
			{
			case 0:switch (NextChar())
			{
			case '+':
			case '-': station = 1; break;
			case '0':station = 2; break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':station = 6; break;
			case '*':station = 32; break;
			case ':':station = 35; break;
			case '<':station = 38; break;
			case '=':station = 42; break;
			case '>':station = 43; break;
			case '/':station = 46; break;
			case ',':station = 47; break;
			case ';':station = 48; break;
			case '(':station = 49; break;
			case ')':station = 50; break;
			default:
				station = 30;
			}break;

			case 1:
				if (last_ls_ID_INT_REAL == true)
					station = 8;
				else {
					NextChar();
					if (get_data == '0')
						station = 2;
					else if (get_data >= '1' and get_data <= '9')
						station = 6;
					else throw get_data;
				}
				break;

			case 2:switch (NextChar())
			{
			case 'x':
			case 'X':station = 3; break;
			case '0':station = 51; break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':station = 5; break;
			case '.':station = 25; break;
			default:
				station = 7;
			}break;
			case 3:NextChar();
				if((get_data >= '1' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 4;
				else if (get_data == '0')
					station = 52;
				else if (get_data == '.')
					station = 10;
				else throw get_data;
				break;
			case 4:
				NextChar();
				if ((get_data >= '0' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 9;
				else if (get_data == '.')
					station = 16;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case 5:
				NextChar();
				if (get_data >= '0' and get_data <= '7')
					station = 17;
				else if (get_data == '.')
					station = 23;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case 6:
				NextChar();
				if (get_data >= '0' and get_data <= '9')
					station = 24;
				else if (get_data == '.')
					station = 29;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case 7:
				stack_data.push(get_data);
				PrintWord(INT);
				break;
			case 8:
				if (word[0] == '+')
					PrintWord(PLUS, "+");
				else
					PrintWord(MINUS, "-");
				break;
			case 9:
				NextChar();
				if ((get_data >= '0' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 9;
				else if (get_data == '.')
					station = 10;
				else if (get_data == 'E')
					station = 11;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;

			case 10:
				NextChar();
				if ((get_data >= '0' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 10;
				else if (get_data == 'E')
					station = 11;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case 11:
				NextChar();
				if ((get_data >= '1' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 15;
				else if (get_data == '+' or get_data == '-')
					station = 12;
				else throw get_data;
				break;
			case 12:
				NextChar();
				if (get_data == '0')
					station = 13;
				else throw get_data;
				break;
			case 13:
				NextChar();
				if (get_data == 'x' or get_data == 'X')
					station = 14;
				else throw get_data;
				break;
			case 14:
				NextChar();
				if ((get_data >= '1' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 15;
				else throw get_data;
				break;
			case 15:
				NextChar();
				if ((get_data >= '0' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 15;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case 16:
				NextChar();
				if ((get_data >= '0' and get_data <= '9') or (get_data >= 'a' and get_data <= 'f'))
					station = 10;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case 17:
				NextChar();
				if (get_data >= '0' and get_data <= '7')
					station = 17;
				else if (get_data == '.')
					station = 18;
				else if (get_data == 'E')
					station = 19;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case 18:
				NextChar();
				if (get_data >= '0' and get_data <= '7')
					station = 18;
				else if (get_data == 'E')
					station = 19;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case 19:
				NextChar();
				if (get_data >= '1' and get_data <= '7')
					station = 22;
				else if (get_data == '+' or get_data == '-')
					station = 20;
				else throw get_data;
				break;
			case 20:
				NextChar();
				if (get_data == '0')
					station = 21;
				else throw get_data;
				break;
			case 21:
				NextChar();
				if (get_data >= '1' and get_data <= '7')
					station = 22;
				else throw get_data;
				break;
			case 22:
				NextChar();
				if (get_data >= '0' and get_data <= '7')
					station = 22;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case 23:
				NextChar();
				if (get_data >= '0' and get_data <= '7')
					station = 18;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case  24:
				NextChar();
				if (get_data >= '0' and get_data <= '9')
					station = 24;
				else if (get_data == '.')
					station = 25;
				else if (get_data == 'E')
					station = 26;
				else {
					stack_data.push(get_data);
					PrintWord(INT);
				}
				break;
			case  25:
				NextChar();
				if (get_data >= '0' and get_data <= '9')
					station = 25;
				else if (get_data == 'E')
					station = 26;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case 26:
				NextChar();
				if (get_data >= '1' and get_data <= '9')
					station = 28;
				else if (get_data == '+' or get_data == '-')
					station = 27;
				else throw get_data;
				break;
			case 27:
				if (get_data >= '1' and get_data <= '9')
					station = 29;
				else throw get_data;
				break;
			case  28:
				NextChar();
				if (get_data >= '0' and get_data <= '9')
					station = 28;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case  29:
				NextChar();
				if (get_data >= '0' and get_data <= '9')
					station = 25;
				else {
					stack_data.push(get_data);
					PrintWord(REAL);
				}
				break;
			case  30:
				NextChar();
				if ((get_data >= '0' and get_data <= '9') or (get_data >= 'a' and get_data <= 'z') or (get_data >= 'A' and get_data <= 'Z'))
					station = 30;
				else station = 31;
				break;
			case  31:
				stack_data.push(get_data);
				PrintWord(ID);
				break;
			case  32:
				NextChar();
				if (get_data == '*')
					station = 33;
				else station = 34;
				break;
			case 33:
				PrintWord(EXP, "**");
				break;
			case 34:
				stack_data.push(get_data);
				PrintWord(MULTI, "*");
				break;
			case 35:
				if (get_data == '=')
					station = 36;
				else station = 37;
				break;
			case 36:
				PrintWord(ASSIGN, ":=");
				break;
			case 37:
				stack_data.push(get_data);
				PrintWord(COLON, ":");
				break;
			case 38:
				if (get_data == '=')
					station = 39;
				else if (get_data == '>')
					station = 40;
				else station = 41;
				break;
			case 39:
				PrintWord(LE, "<=");
				break;
			case 40:
				PrintWord(NE, "<>");
				break;
			case 41:
				stack_data.push(get_data);
				PrintWord(LT, "<");
				break;
			case 42:
				PrintWord(EQ, "=");
				break;
			case 43:
				NextChar();
				if (get_data == '=')
					station = 44;
				else station = 45;
				break;
			case 44:
				PrintWord(GE, ">=");
				break;
			case 45:
				stack_data.push(get_data);
				PrintWord(GT, ">");
				break;
			case 46:
				PrintWord(RDIV, "/");
				break;
			case 47:
				PrintWord(COMMA, ",");
				break;
			case 48:
				PrintWord(SEMIC, ";");
				break;
			case 49:
				PrintWord(LR_BRAC, "(");
				break;
			case 50:
				PrintWord(RR_BRAC, ")");
				break;
			case 51:
				NextChar();
				if (get_data == '0' and get_data <= '9')
					station = 18;
				else throw get_data;
				break;
			case 52:
				NextChar();
				if (get_data == '.')
					station = 10;
				else throw get_data;
				break;
			}
		}
	}
	catch (char next_char)
	{
		cerr << "错误: 出现多余的" << next_char << endl;
		return 1;
	}
	return 0;
}