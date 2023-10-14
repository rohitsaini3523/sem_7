%{
/* 
* this is sample demostrations recognition:
* a verb/not a verb.
*/
%}
digit [0-9]+
letter [a-zA-Z]+
%%

[\t ]+  /* ignore whitespace*/;

{digit}+ {printf("%s: is number\n",yytext);}

{letter}+ {printf("%s: is identifier\n", yytext);}


.|\n     {ECHO;/*normal default anyway*/}
%%

main()
{
    printf("enter the string: ");
    yylex();
    yywrap();
}

int yywrap(void)
{
    return 1;
}