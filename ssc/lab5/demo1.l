%{
/* 
* this is sample demostrations recognition:
* a verb/not a verb.
*/
%}
%%

[\t ]+  /* ignore whitespace*/;

is |
am |
are |
were |
was {printf("%s: is a verb\n",yytext);}

[0-9]+ {printf("%s: is number\n",yytext );}

[a-zA-Z]+ {printf("%s: is not a verb\n", yytext);}


.|\n     {ECHO;/*normal default anyway*/}
%%

main()
{
    yylex();
    yywrap();
}

int yywrap(void)
{
    return 1;
}