%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ID NUM IF THEN ELSE WHILE FOR DO LE GE EQ NE OR AND 
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%left '!'

%%

S      : ST { printf("Input accepted.\n"); exit(0); };
ST     : IF '(' E2 ')' THEN ST1 ';'
        | IF '(' E2 ')' THEN ST1 ';' ELSE ST1 ';'
        | WHILE '(' E2 ')' ST1 ';'
        | DO ST WHILE '(' E2 ')' ';'
        | FOR '(' E2 ';' E2 ';' E2 ')' ST ';'
        ;
ST1    : ST
        | E
        ;
E      : ID '=' E
        | E '+' E
        | E '-' E
        | E '*' E
        | E '/' E
        | E '<' E
        | E '>' E
        | E LE E
        | E GE E
        | E EQ E
        | E NE E
        | E OR E
        | E AND E
        | ID
        | NUM
        ;
E2     : E'<'E
        | E'>'E
        | E LE E
        | E GE E
        | E EQ E
        | E NE E
        | E OR E
        | E AND E
        | ID
        | NUM
        ;

%%

main()
{
  printf("Enter the exp: ");
  yyparse();
}

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}