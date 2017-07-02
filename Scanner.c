#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"
#include "string.h"

/*
◦ Qué hace: Obtiene operadores y operandos.
◦ Qué usa:
	▪ Biblioteca Estándar
		• getcar
		• EOF
		• isdigit
		• ungetc
*/

#define MAXTOKEN 100

char lexeme[MAXTOKEN];

int GetNextToken(Token *t /*out*/) /* return next token */
{
	int c,i;
	TokenType type;
	TokenValue val;
	/*
	enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};
	*/

	while ((lexeme[0] = c = getchar()) == ' ' || c == '\t')
		;

	lexeme[1] = '\0';

		if (!isdigit(c) && c != '.'){
			switch (c) {
				case Addition :
					type = Addition;
					break;
				case Multiplication :
					type = Multiplication;
					break;
				case Substraction :
					type = Substraction;
					break;
				case Division :
					type = Division;
					break;
				case PopResult :
					type = PopResult;
					break;
				default :
					type = PopResult;
					//*t.val = c;		
		 	} /* not a number */
		}
		else
		{

			i = 0;
		
			if (isdigit(c)) /* collect integer part */
		 	while (isdigit(lexeme[++i] = c = getchar()))
		 	;
			
			if (c == '.') /* collect fraction part */
			while (isdigit(lexeme[++i] = c = getchar()))
		 	;

			lexeme[i] = '\0';

			if (c != EOF)
				ungetc(c,stdin);

			type = Number;
			val = atof(lexeme);
			 
		}
		

		t-> type ='+';
		//t->val = val;
		return 0;

}

int main (void){
	Token *t;

	GetNextToken(t);

	return 0;
}

/*
// reverse Polish calculator 
 main()
 {
 int type;
 double op2;
 char s[MAXOP];
 while ((type = getop(s)) != EOF) {
 switch (type) {
 case NUMBER:
 push(atof(s));
 break;
 case '+':
 push(pop() + pop());
 break;
 case '*':
 push(pop() * pop());
66
 break;
 case '-':
 op2 = pop();
 push(pop() - op2);
 break;
 case '/':
 op2 = pop();
 if (op2 != 0.0)
 push(pop() / op2);
 else
 printf("error: zero divisor\n");
 break;
 case '\n':
 printf("\t%.8g\n", pop());
 break;
 default:
 printf("error: unknown command %s\n", s);
 break;
 }
 }
 return 0;
 }
*/