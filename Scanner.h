 /* scanner.h
  * Equipo 06
  * 02/07/2017
  */
#ifndef SCANNER_H_
#define SCANNER_H_

/*
Qué exporta:
	▪ GetNextToken
	▪ Token
	▪ TokenType
	▪ TokenValue
*/
enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};

typedef enum TokenType TokenType;
typedef double TokenValue;

typedef struct Token{
 TokenType type;
 TokenValue val;
 char errorLexema;
} Token;

int GetNextToken(Token *t);

#endif
