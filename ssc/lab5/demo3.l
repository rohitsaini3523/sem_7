%{
/* demo of number of word and char and length */
int nchar, nword, nline;
%}
%%

\n { nline++; nchar++;} 
[^ \t\n]+ { nword++; nchar += yyleng; }
. { nchar++; }
%%

int main(void)
{
    printf("Enter the String: ");
    yylex();
    yywrap();
    printf("%d\t%d\t%d\n",nchar,nword,nline);
    return 0;
}

int yywrap(void)
{
    return 1;
}