%{
#include <stdio.h>
#include <string.h>
int count;

%}
digit [0-9]+
letter [a-zA-Z]
space [' ']
identifier ({letter}({letter}|{digit})*)
classname (class{space}({letter}|{digit})*)
quote \"
datatype (int|char|float|void)
keywords (void|class|throws|import|try|catch|finally|static|implements|extends|main)
booleanvalues (true|false)
loops (while|for)
conditionalStatements (if|else|switch)
string ({quote}({letter}|{digit})+{quote})
array ({identifier}(\[))

parenthesis ()

accessspecifier (public|private|protected)
%%
{keywords} printf("\n %s is a keyword\n",yytext);
{accessspecifier} printf("\n %s is access specifier\n",yytext);
{booleanvalues} printf("\n %s is boolean value\n",yytext);
{classname} printf("\n %s is a classname\n",yytext);
{array} printf("\n %s is a array\n",yytext);
{string} printf("\n %s is a string \n",yytext);
{quote} printf("\n %s is a quote\n",yytext);
{conditionalStatements} printf("\n %s is a conditional Statement\n",yytext);
{loops} printf("\n %s is a loop \n",yytext);

%%

int main()
{
    int i;
    yyin = fopen("code.java","r");
    yylex();
    yywrap();
}

int yywrap(void)
{
    return 1;
}
