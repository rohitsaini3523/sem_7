%{
#include <stdio.h>
#include <string.h>
int count;
%}

%option noyywrap

letter [a-zA-Z]
digit [0-9]
space [' ']
identifier ({letter}({letter}|{digit})*)
classname (class{space}({letter}|{digit})*)
quote \"
datatype (int|char|float|double|void)
keywords (void|class|throws|import|try|catch|finally|static|implements|extends|main)
booleanvalues (true|false)
loops (while|for)
conditionalStatements (if|else|switch)
string ({quote}({letter}|{digit})*{quote})
array ({identifier}(\[\d+\])*)
parenthesis ([{}();,])
comment "//".*

%%
{space} ;
[ \t\n] ; // Ignore whitespace
"import"[^\n]*";" { printf("Preprocessor Directive: %s\n", yytext); }
"public|private|protected" { printf("Access Specifier: %s\n", yytext); }
{digit}          { printf("Integer: %s\n",yytext);}
{keywords}       { printf("Keyword: %s\n", yytext); }
{datatype}       { printf("Datatype: %s\n", yytext); }
{booleanvalues}  { printf("Boolean Value: %s\n", yytext);}
{parenthesis}    { printf("Parenthesis: %s\n", yytext);}
{identifier}     { printf("Identifier: %s\n", yytext);}
{classname}      { printf("Classname: %s\n", yytext);}
{array}          { printf("Array: %s\n", yytext);}
{string}         { printf("String: %s\n", yytext);}
{quote}          { printf("Quote: %s\n", yytext);}
{comment}        { printf("Comment: %s\n", yytext);}
"&&|\|\||!|!=" { printf("Logical Operator: %s\n", yytext); }
"<|>|<=|>=|==" { printf("Relational Operator: %s\n", yytext); }
"\+\+|--" { printf("Unary Operator: %s\n", yytext); }
"[+\-/%\*]" { printf("Arithmetic Operator: %s\n", yytext); }
"=" { printf("Assignment Operator: %s\n", yytext); }
. { printf("Unknown Token: %s\n", yytext); }

%%

int main() {
    yyin = fopen("input.java", "r");
    yylex();
    fclose(yyin);
    return 0;
}
