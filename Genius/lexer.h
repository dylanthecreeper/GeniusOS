#pragma once
#include "tokenizer"
#include "character"
#include <string>
class Lexer
{
public:
	Lexer();
	~Lexer();

	void lexerInit(std::string srcTxt);
	Token lexerMain();
private:
	std::string c1, c2;
	Character k;

};