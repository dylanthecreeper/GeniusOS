#pragma once
#include "scanner.h"
#include "usefulFunctions.h"
//#include "tokenizer"
//#include "character.h"
#include <string>
#include <map>

typedef enum{
	kCat_OPERATOR,
	kCat_KEYWORD,
	kCat_VALUE,
	kCat_VALUEUNSET,
	kCat_IDENTIFIER,
	kCat_EOS, //End Of Statement
	kCat_COMMA,
	kCat_UNKNOWN,
	kCat_TYPE
}TokenCAT;

typedef enum 
{
	kToken_UNKNOWN, 
	kToken_IF, 
	kToken_THEN, 
	kToken_ELSE, 
	kToken_ELSEIF, 
	kToken_WHILE, 
	kToken_LOOP, 
	kToken_ENDLOOP, 
	kToken_PUSH, 
	kToken_RETURN, 
	kToken_QUIT,
	kToken_OPEN,
	kToken_CLOSE, 
	kToken_EQUALS, 
	kToken_LPAREN, 
	kToken_RPAREN, 
	kToken_LESSTHAN, 
	kToken_GREATERTHAN, 
	kToken_DIVIDE, 
	kToken_MULTIPLY, 
	kToken_PLUS, 
	kToken_MINUS, 
	kToken_BANG, 
	kToken_AND, 
	kToken_DOT, 
	kToken_SEMICOLON, 
	kToken_EQUALITY, 
	kToken_LESSEQUAL, 
	kToken_GREATEREQUAL, 
	kToken_NOTEQUAL, 
	kToken_INCREMENT, 
	kToken_EXP, //EXPONENT
	kToken_DECREMENT, 
	kToken_PLUSEQUALS, 
	kToken_MINUSEQUALS, 
	kToken_OR,
	kToken_ARROW, 
	kToken_QUOTE, 
	kToken_SPACE, 
	kToken_TAB, 
	kToken_NEWLINE, 
	kToken_STRING,
	kToken_BOOL, 
	kToken_IDENTIFIER, 
	kToken_WHITESPACE, 
	kToken_NUMBER, 
	kToken_COMMENT,
	kToken_EMPTY,
	kToken_COMMA,
	kToken_OUT,
	kToken_IN,
	kToken_OSTREAM,
	kToken_ISTREAM,
	kToken_EOF
	
} TokenID;

typedef struct{
	std::string cargo, sourceText, sourceName;
	int lineIndex, colIndex; 
	TokenID type;
	TokenCAT cat;
} Token;


class Lexer
{
public:
	Lexer();
	~Lexer();

	
	Token lexerhandler(std::string doInit = "NULL");
	std::string tokenWrapper(Token self, bool showLineNumbers, bool align);
	bool doabort = false;

private:
	void lexerInit(std::string srcTxtArg);
	TokenID isKeyword(std::string i_keyword);
	bool isWhitespaceChar(std::string i_char);
	bool isIdentifierStartChar(std::string i_char);
	bool isIdentifierChar(std::string i_char);
	void getCharPackage();
	bool isNumberStart(std::string num, std::string &finishedcargo, int &loops);
	bool is_number(const std::string& s);
	TokenID isTwoCharOperator(std::string op);
	TokenID isOneCharSymbol(std::string sy);
	void abort(Token x, std::string msg);
	TokenID isTypeStartChars(std::string x);
	Token lexerMain();
	TokenID typeLookAhead(TokenID y, int &o_look);
private:
	std::string c1, c2;
	UsefulFunc *myljust;
	std::string tempSourceText, tempSourceTextName;
	int tempLineIndex, tempcolIndex;
std::string srcTxtSv, fileMbrSv;
	int lnDex = 0, clDex = 0;
	Scanner *myscanner;

	std::map<std::string, TokenID>  mKeywordMap;
	std::map<std::string, TokenID> mOperatorMap;
		std::map<std::string, TokenID> mTypeMap;



};