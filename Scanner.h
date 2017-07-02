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

struct Token{
 TokenType type;
 TokenValue val;
};

typedef struct Token Token; 

//cambie bool por int
int GetNextToken(Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido.

#endif