/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "while.y"

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "lex.yy.c"

char nL[3];

void yyerror(const char*);
int yylex();
int yywrap();
void insert_type();
void add(char);
int sym_search(char *);
int search(char *);
void addTo(char i,char *n);
void FOO();
void add_ptr();
void pop();
void insert_type_table();
char temptype(char *,char*);
void type_check(char *,char*);
void printtree(struct node1*);
void optimized();
struct node{ int val;} x;
struct dataType{
	char * id_name;
	char * data_type;
	char * type;
	int line_no;
	}symbolTable[100];
int ifd=0;/*Label*/
int eld=20;
char typeStack[10][100];
int typeStack_top = 0;
char type[10];
char count=0;
int nxt=1;/*printed next once*/
int c=0;/*Temp var count*/
int q;
extern int countn;
struct intermediate
{
	char op[2];
	char op1[5];
	char op2[5];
	char res[5];
}intermediate_code[20];
int code=0;
struct node1{ struct node1*left;struct node1*right;char* token;};
struct node1* mknode(struct node1 *left,struct node1 *right, char *token);

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 55 "while.y"
typedef union YYSTYPE { struct var_name {char name[100];struct node1* nd;} nam ; 
	struct gen_code{char tr[10];char fal[10];struct node1* nd;} gen;
	 } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 89 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IF 257
#define ELSE 258
#define INT 259
#define FLOAT 260
#define CHAR 261
#define WHILE 262
#define VOID 263
#define INCLUDE 264
#define RETURN 265
#define LE 266
#define GE 267
#define LT 268
#define GT 269
#define EQ 270
#define NE 271
#define NUM 272
#define AND 273
#define OR 274
#define TR 275
#define FL 276
#define STRLT 277
#define ID 278
#define printff 279
#define scanff 280
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
   21,   22,   23,   24,   25,    0,   10,   10,   11,   11,
   11,   11,   26,   12,   12,   12,   13,   13,   27,   14,
   28,   14,   29,   30,   15,   15,   31,   15,   15,   32,
   16,   16,   16,   17,   17,   17,   17,   17,   33,   17,
   34,   17,   17,   35,   36,   37,   38,   19,   19,   19,
   19,   39,   19,   40,   19,   19,   41,   42,   43,   44,
   20,   20,   20,   20,   45,   20,   46,   20,   20,   47,
   48,   18,   18,    9,    2,    2,    2,    2,    1,   49,
    1,    1,    1,    1,    1,   50,    8,    8,   51,    7,
   52,    7,    7,   53,    6,   54,    6,    6,   55,    5,
    5,   56,    4,   57,    4,   58,    4,    3,    3,    3,
    3,    3,
};
static const YYINT yylen[] = {                            2,
    0,    0,    0,    0,    0,   15,    2,    1,    1,    1,
    1,    1,    0,    4,    3,    2,    1,    0,    0,    3,
    0,    3,    0,    0,    6,    4,    0,    4,    0,    0,
    4,    3,    0,    1,    1,    1,    3,    2,    0,    6,
    0,    9,    0,    0,    0,    0,    0,   12,    1,    3,
    2,    0,    6,    0,    9,    0,    0,    0,    0,    0,
   12,    1,    3,    2,    0,    6,    0,    9,    0,    0,
    0,    6,    0,    1,    3,    3,    2,    1,    3,    0,
    4,    1,    1,    1,    1,    0,    5,    5,    0,    4,
    0,    4,    1,    0,    4,    0,    4,    1,    0,    4,
    1,    0,    4,    0,    3,    0,    2,    1,    1,    1,
    1,    1,
};
static const YYINT yydefred[] = {                         0,
    8,    0,    0,    9,   10,   11,   12,    0,    0,    1,
    0,    2,    0,   19,   21,    0,    0,    0,    0,    0,
    0,    3,   13,   17,   16,    0,   20,   22,   15,    0,
    0,    0,    0,    0,    4,    0,    0,   24,    0,    0,
   26,    0,   28,   44,   57,    0,   39,   41,   36,    0,
    0,   34,   35,    0,    0,    0,   86,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   25,    0,    0,
    0,   74,    0,    0,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,   83,   82,    0,  102,   78,    0,
  101,    0,    0,    0,    0,  106,  104,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    6,   77,  107,
   80,    0,    0,    0,    0,   45,   99,   94,   96,  108,
  109,  110,  111,  112,   89,   91,    0,   58,   87,   88,
    0,    0,    0,    0,    0,    0,    0,   32,    0,  105,
    0,   75,   76,    0,    0,    0,    0,    0,    0,    0,
    0,   40,   53,   66,    0,    0,    0,   31,    0,  103,
   46,    0,   95,   97,   90,   92,   59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   55,   68,
   47,   60,    0,    0,   70,   48,   61,    0,   71,    0,
    0,   72,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  264,  282,  292,  259,  260,  261,  263,  292,  293,  278,
  303,   40,  304,  278,   42,  293,  294,  296,  309,  310,
  296,   41,   44,   59,  295,   91,  297,  296,  295,  305,
  308,  278,  311,  313,  123,  294,   93,  272,   93,  306,
  297,  312,  297,  257,  262,  278,  279,  280,  290,  293,
  299,  301,  302,   93,  317,  323,   61,   40,  315,  321,
  327,  316,  322,  328,  278,  299,  307,  297,   40,   40,
  332,  277,  291,   40,   40,   40,   40,   40,   40,  295,
  265,  298,  271,  272,  275,  276,  278,   40,  283,  284,
  286,  287,  288,  289,  284,  272,  278,  289,   41,  277,
  277,  277,  277,  277,  277,  272,  278,  125,  283,  340,
   61,  339,  338,  273,  274,   41,   94,   42,   47,  266,
  267,  268,  269,  270,   43,   45,  285,   41,   59,   59,
   41,   41,   41,   44,   44,   44,  314,   59,  331,  297,
  289,  283,  283,  318,  337,  335,  336,  333,  334,  289,
  324,   59,   59,   59,   38,   38,   38,   59,  289,   41,
  123,  287,  288,  288,  289,  289,  123,  278,  278,  278,
  319,  325,   41,   41,   41,  299,  299,   59,   59,   59,
  125,  125,  320,  326,  258,  300,  300,  329,  123,  330,
  299,  125,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   89,   90,  127,   91,   92,   93,   94,   49,   73,    8,
   50,   17,   25,   18,   27,   82,   66,  186,   52,   53,
   11,   13,   30,   40,   67,   31,   19,   20,   33,   42,
   34,  137,   59,   62,   55,  144,  171,  183,   60,   63,
   56,  151,  172,  184,   61,   64,  188,  190,  139,   71,
  148,  149,  146,  147,  145,  113,  112,  110,
};
static const YYINT yysindex[] = {                      -248,
    0,    0, -155,    0,    0,    0,    0, -248, -253,    0,
   48,    0,  -36,    0,    0,  -34,  -32,   31,    9,  -34,
   31,    0,    0,    0,    0, -180,    0,    0,    0,  -16,
  -36,   25, -162,   29,    0,   79,    9,    0,    9,   64,
    0,   36,    0,    0,    0,  -25,    0,    0,    0, -158,
   64,    0,    0,    9,   88,   90,    0, -146,   92,   93,
   94,   96,  120,  121,   31,   64, -103,    0,  -40,  -40,
  -39,    0,  125, -110, -104, -102,  -95,  -87,  -86,    0,
 -265,   69,  -35,    0,    0,    0,  137,    0,    0,  -23,
    0,  105,   55,   50,  -14,    0,    0,   32,  141,  160,
  161,  162,  163,  164,  165,    0,  151,    0,    0,    0,
    0,    9,  -39,  -35,  -35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -39,    0,    0,    0,
  153,  154,  155,  177,  178,  179,  159,    0,  -39,    0,
   76,    0,    0,   97,  -39,  -39,  -39,  -39,  -39,   35,
   98,    0,    0,    0,  -59,  -56,  -52,    0,   35,    0,
    0,  105,    0,    0,    0,    0,    0,  187,  188,  189,
   64,   64,  175,  204,  223, -108,  -83,    0,    0,    0,
    0,    0,   30,   30,    0,    0,    0,  166,    0,   64,
  -74,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0, -147,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   43,   12,    0,
   43,    0,    0,    0,    0,  -91,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  251,  -21,    0,  -21, -106,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -97,    0,    0,  -21,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -122,  -81,  173,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    7,    0,    0,  -12,    0,    0,    0,
    0,   17,   40,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -4,
    0,    0,    0,    0,    0,    0,    0,    0,    5,    0,
    0,   27,    0,    0,    0,    0,    0,    0,    0,    0,
  174,  174,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -115, -115,    0,    0,    0,    0,    0,  174,
    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  -49,  232,    0,    0,  158,  -20,  -24,    0,    0,  304,
    1,  274,  -10,   47,   57,    0,   21,  127,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 344
static const YYINT yytable[] = {                         88,
   88,   27,   18,    9,   88,   15,  106,   15,   22,   73,
   29,   23,  107,   16,   58,    1,  181,  116,   43,   29,
   29,   29,   29,   29,   10,   29,  128,    5,   84,  104,
  104,   16,  104,  109,  104,   57,   79,   29,   29,   29,
   29,  182,   29,   38,   29,   81,   98,   85,  106,  106,
  192,  106,   29,  106,   80,   29,   29,   98,   98,   98,
   51,   98,   21,   98,  142,  143,   28,  100,  100,  100,
   29,  100,   29,  100,  125,   98,  126,  125,  104,  126,
   93,  104,   93,   18,   93,  100,   18,   12,  141,   24,
  129,   29,  125,   41,  126,   43,  118,   32,   93,   26,
  106,  119,  150,    4,    5,    6,   35,    7,    1,   38,
   68,    7,    7,    7,  159,    7,  160,   37,  125,   65,
  126,   39,   23,  165,  166,  163,  164,   69,   54,   70,
   72,   74,   75,   76,   18,   77,   18,   18,   18,   18,
   18,   73,   18,   73,   73,   73,   73,   73,   44,   73,
    4,    5,    6,   45,    7,   18,   18,   18,   43,   78,
   79,   81,   73,   73,   73,   99,  100,    5,  140,   46,
   47,   48,  101,   44,  102,    4,    5,    6,   45,    7,
   23,  103,   44,   38,    4,    5,    6,   45,    7,  104,
  105,  176,  177,  108,   46,   47,   48,  111,  117,  130,
  131,  132,  133,   46,   47,   48,  134,  135,  136,  138,
  191,  152,  153,  154,  155,  156,  157,  158,  168,  161,
  167,  169,    4,    5,    6,  170,    7,  173,  174,  175,
   83,   84,   96,  178,   85,   86,   84,   87,   97,   85,
   86,   14,   87,   14,   29,   29,   29,   29,   29,  114,
  115,   29,   29,  104,  104,  104,  104,  104,  114,  115,
   84,   84,  179,   29,   29,   29,   29,   29,   79,   79,
   29,   29,  106,  106,  106,  106,  106,   81,   81,   85,
   85,  180,   98,   98,   98,   98,   98,  185,  189,   98,
   98,   14,  100,  100,  100,  100,  100,   33,   43,  100,
  100,   95,  162,    3,   36,   93,   93,   93,   93,   93,
  187,    0,   93,   93,    0,  120,  121,  122,  123,  124,
   44,    0,    4,    5,    6,   45,    7,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   46,   47,   48,
};
static const YYINT yycheck[] = {                         40,
   40,   93,  125,    3,   40,   42,  272,   42,   41,  125,
   21,   44,  278,   13,   40,  264,  125,   41,  125,   41,
   42,   43,   44,   45,  278,   47,   41,  125,   41,   42,
   43,   31,   45,   83,   47,   61,   41,   59,   41,   42,
   43,  125,   45,  125,   47,   41,   71,   41,   42,   43,
  125,   45,   41,   47,   65,   44,   59,   41,   42,   43,
   40,   45,   16,   47,  114,  115,   20,   41,   42,   43,
   59,   45,   94,   47,   43,   59,   45,   43,   91,   45,
   41,   94,   43,   41,   45,   59,   44,   40,  113,   59,
   59,   94,   43,   37,   45,   39,   42,  278,   59,   91,
   94,   47,  127,  259,  260,  261,  123,  263,  264,  272,
   54,  259,  260,  261,  139,  263,   41,   93,   43,  278,
   45,   93,   44,  148,  149,  146,  147,   40,   93,   40,
  277,   40,   40,   40,  257,   40,  259,  260,  261,  262,
  263,  257,  265,  259,  260,  261,  262,  263,  257,  265,
  259,  260,  261,  262,  263,  278,  279,  280,  265,   40,
   40,  265,  278,  279,  280,   41,  277,  265,  112,  278,
  279,  280,  277,  257,  277,  259,  260,  261,  262,  263,
  272,  277,  257,  265,  259,  260,  261,  262,  263,  277,
  277,  171,  172,  125,  278,  279,  280,   61,   94,   59,
   41,   41,   41,  278,  279,  280,   44,   44,   44,   59,
  190,   59,   59,   59,   38,   38,   38,   59,  278,  123,
  123,  278,  259,  260,  261,  278,  263,   41,   41,   41,
  271,  272,  272,   59,  275,  276,  272,  278,  278,  275,
  276,  278,  278,  278,  266,  267,  268,  269,  270,  273,
  274,  273,  274,  266,  267,  268,  269,  270,  273,  274,
  273,  274,   59,  266,  267,  268,  269,  270,  273,  274,
  273,  274,  266,  267,  268,  269,  270,  273,  274,  273,
  274,   59,  266,  267,  268,  269,  270,  258,  123,  273,
  274,   41,  266,  267,  268,  269,  270,  125,  125,  273,
  274,   70,  145,    0,   31,  266,  267,  268,  269,  270,
  184,   -1,  273,  274,   -1,  266,  267,  268,  269,  270,
  257,   -1,  259,  260,  261,  262,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 341
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,
"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"error","IF","ELSE","INT","FLOAT","CHAR","WHILE",
"VOID","INCLUDE","RETURN","LE","GE","LT","GT","EQ","NE","NUM","AND","OR","TR",
"FL","STRLT","ID","printff","scanff","$accept","P","B","C","relop","Q","T","F",
"E","assign","Arg","I","M","R","TER","N","G","U","S","EL","S1","S2","$$1","$$2",
"$$3","$$4","$$5","$$6","$$7","$$8","$$9","$$10","$$11","$$12","$$13","$$14",
"$$15","$$16","$$17","$$18","$$19","$$20","$$21","$$22","$$23","$$24","$$25",
"$$26","$$27","$$28","$$29","$$30","$$31","$$32","$$33","$$34","$$35","$$36",
"$$37","$$38","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : P",
"$$1 :",
"$$2 :",
"$$3 :",
"$$4 :",
"$$5 :",
"P : I M ID $$1 '(' $$2 R ')' $$3 '{' $$4 S $$5 U '}'",
"I : I I",
"I : INCLUDE",
"M : INT",
"M : FLOAT",
"M : CHAR",
"M : VOID",
"$$6 :",
"R : R ',' $$6 R",
"R : M N TER",
"R : N TER",
"TER : ';'",
"TER :",
"$$7 :",
"N : ID $$7 G",
"$$8 :",
"N : '*' $$8 N",
"$$9 :",
"$$10 :",
"G : '[' $$9 NUM $$10 ']' G",
"G : '[' ID ']' G",
"$$11 :",
"G : '[' $$11 ']' G",
"G :",
"$$12 :",
"U : RETURN NUM $$12 ';'",
"U : RETURN ID ';'",
"U :",
"S : S1",
"S : S2",
"S : assign",
"S : M ID TER",
"S : S S",
"$$13 :",
"S : printff $$13 '(' STRLT ')' ';'",
"$$14 :",
"S : scanff $$14 '(' STRLT ',' '&' ID ')' ';'",
"S :",
"$$15 :",
"$$16 :",
"$$17 :",
"$$18 :",
"S1 : IF $$15 '(' C ')' $$16 '{' $$17 S '}' $$18 EL",
"S1 : assign",
"S1 : M ID TER",
"S1 : S S",
"$$19 :",
"S1 : printff $$19 '(' STRLT ')' ';'",
"$$20 :",
"S1 : scanff $$20 '(' STRLT ',' '&' ID ')' ';'",
"S1 :",
"$$21 :",
"$$22 :",
"$$23 :",
"$$24 :",
"S2 : WHILE $$21 '(' C ')' $$22 '{' $$23 S '}' $$24 EL",
"S2 : assign",
"S2 : M ID TER",
"S2 : S S",
"$$25 :",
"S2 : printff $$25 '(' STRLT ')' ';'",
"$$26 :",
"S2 : scanff $$26 '(' STRLT ',' '&' ID ')' ';'",
"S2 :",
"$$27 :",
"$$28 :",
"EL : ELSE $$27 '{' $$28 S '}'",
"EL :",
"Arg : STRLT",
"C : C AND B",
"C : C OR B",
"C : NE B",
"C : B",
"B : E relop E",
"$$29 :",
"B : ID '=' $$29 E",
"B : FL",
"B : TR",
"B : ID",
"B : NUM",
"$$30 :",
"assign : ID '=' $$30 E ';'",
"assign : ID '(' Arg ')' ';'",
"$$31 :",
"E : E '+' $$31 E",
"$$32 :",
"E : E '-' $$32 E",
"E : F",
"$$33 :",
"F : F '*' $$33 F",
"$$34 :",
"F : F '/' $$34 F",
"F : T",
"$$35 :",
"T : T '^' $$35 T",
"T : Q",
"$$36 :",
"Q : '(' $$36 E ')'",
"$$37 :",
"Q : ID $$37 G",
"$$38 :",
"Q : NUM $$38",
"relop : LE",
"relop : GE",
"relop : LT",
"relop : GT",
"relop : EQ",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 282 "while.y"

int main()
{
	
	extern int yylineno;
	x.val=10;
	printf("\n\n#######################################################################################\n");
	printf("\t\t\tIntermediate code\n");
	printf("#######################################################################################\n");
	yyparse();
	
	printf("\nParsing is Successful\n");	
	printf("\n\n#######################################################################################\n");
	printf("\t\t\tSymbol table\n");
	printf("#######################################################################################\n");	
	printf("\nsymbol \t type  \t identify \t line number\n");
	printf("_______________________________________________________________________________________\n");
	int i=0;
	for(i=0;i<100;i++){
		if(symbolTable[i].id_name!=NULL)
		printf("%s\t%s\t%s\t%d\t\n",symbolTable[i].id_name,symbolTable[i].data_type,symbolTable[i].type,symbolTable[i].line_no);
		
	}
	for(i=0;i<count;i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
	return 0;
}
void yyerror(const char* s)
{
	printf("Not accepted\n");
	exit(0);
}
//insert the type into symboltable
void insert_type(){

	
	strcpy(type,yytext);
	//printf("hey");
	q=search(type);
	//printf("qval=%d",q);
	if(q==0){
		
		symbolTable[count].id_name=strdup(yytext);
		symbolTable[count].data_type=strdup("N/A");
		symbolTable[count].line_no = countn;
		symbolTable[count].type=strdup("KEYWORD\t");
		count++;
	}
	
	
}

struct node1* mknode(struct node1 *left, struct node1 *right, char *token)
{
	
  struct node1 *newnode = (struct node1 *)malloc(sizeof(struct node1));
  char *newstr = (char *)malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}
void pop()
{
	int i;
	//printf("count %d\n",count);
	int temp=count-1;
	for(i=temp;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,"{")!=0)
		{
			//printf("$$\n");
			count=count-1;;
		}
		else
		{
			count=count-1;
			break;
		}
	}	
	

}
//add declaration of data to symboltable
void addTo(char i,char *n)
{
	if(i=='i')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="int";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='f')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="float";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='c')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="char";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='{')
	{
			symbolTable[count].id_name=strdup("{");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}
	else if(i=='}')
	{
			symbolTable[count].id_name=strdup("}");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}


}
char temptype(char* one,char* two)
{
		int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if((strcmp(onetype,"float")==0) || (strcmp(twotype,"float")==0))
		return 'f';
	else
		return 'i';
}
void insert_type_table(){
	
		q=search(yytext);
	
		if(q==0){
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("IDENTIFIER");
			count++;
		}
	
	
}
void type_check(char* one, char* two)
{
	int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if(strcmp(onetype,twotype)>0){ printf("type error at lineno %d\n",yylineno);exit(0);}
}
//ADD the recent parsed string into symboltable
void add(char c)
{
	q=search(yytext);
	if(q==0){
		if(c=='H')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c=='t')
		{	
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Punctuation");
			count++;
		}
		else if(c=='o')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Operator");
			count++;
		}
		else if(c=='r')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Rel Op\t");
			count++;
		}
		else if(c=='k')
		{
						
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("KEYWORD\t");
			//printf("ADDDDDDDDD%s\n",symbolTable[count].id_name);
			count++;
		}
		else if(c=='n')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("int");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("NUMBER\t");
			count++;
		}
	else if(c=='f')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("FUNCTION\t");
			count++;
		}
	}
}
int  sym_search(char *type)
{
	int i;
	for(i=count -1 ;i>=0&&(strcmp(symbolTable[i].id_name,"{")!=0);i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	
	}
	return 0;
}
//Search in the Symbol table whether the parsed String is present in Symbol table already
int  search(char *type)
{
	int i;
	for(i=count -1 ;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	
	}
	return 0;
}
void add_ptr(){
	strcat(type,"*");
}
//print the abstract syntax tree
void printtree(struct node1* tree)
{
  int i;

  
 
  if (tree->left)
	{

		printtree(tree->left);
	}
 printf(" %s , ", tree->token);
  if (tree->right)
	{
   
		printtree(tree->right);
	}
 
}
void optimized()
{

int i;
int j;
int n,m;
int k;
char yay[10];
int len;
int rem;
for (i=0;i<code;i++)// Common Subexpression Elimination
    for(j=i+1;j<code;j++)
        if(strcmp(intermediate_code[i].op,intermediate_code[j].op)==0)
            {
            if(strcmp(intermediate_code[i].op1,intermediate_code[j].op1)==0)
                if(strcmp(intermediate_code[i].op2,intermediate_code[j].op2)==0 && strcmp(intermediate_code[i].op1,intermediate_code[i].res)!=0 && strcmp(intermediate_code[i].op2,intermediate_code[i].res)!=0 )
                    {
                        for(k=i+1;k<j;k++)
			if(strcmp(intermediate_code[j].op1,intermediate_code[k].res)==0 ||strcmp(intermediate_code[j].op2,intermediate_code[k].res)==0)
			break;
			if(k==j)
			{
                        strcpy(intermediate_code[j].op,"=");
                        strcpy(intermediate_code[j].op1,intermediate_code[i].res);
                        strcpy(intermediate_code[j].op2,"");
                        }
                    }
        
           if(strcmp(intermediate_code[i].op1,intermediate_code[j].op2)==0 && strcmp(intermediate_code[i].op2,intermediate_code[j].op1)==0    &&(strcmp(intermediate_code[i].op,"+")==0 || strcmp(intermediate_code[i].op,"*")==0))
                    {
                     for(k=i+1;k<j;k++)
			if(strcmp(intermediate_code[j].op1,intermediate_code[k].res)==0 ||strcmp(intermediate_code[j].op2,intermediate_code[k].res)==0)
			break;
			if(k==j)
			{
                        strcpy(intermediate_code[j].op,"=");
                        strcpy(intermediate_code[j].op1,intermediate_code[i].res);
                        strcpy(intermediate_code[j].op2,"");
			}
                    }
            }

//constant Folding
for(i=0;i<code;i++)
    {
        n=strlen(intermediate_code[i].op1);
        m=strlen(intermediate_code[i].op2);
        for(k=0;k<n;k++)
            if(isdigit(intermediate_code[i].op1[k])==0)
                break;
        for(j=0;j<m;j++)
            if(isdigit(intermediate_code[i].op1[j])==0)
                break;
            if(j==m && k==n)
            {
                j=atoi(intermediate_code[i].op1);
                k=atoi(intermediate_code[i].op2);
                if(strcmp(intermediate_code[i].op,"*")==0)
                {
                    m=j*k;
                }
                else if(strcmp(intermediate_code[i].op,"+")==0)
                {
                    m=j+k;
                }
                else if(strcmp(intermediate_code[i].op,"-")==0)
                {
                    m=j-k;
                }
                else if(strcmp(intermediate_code[i].op,"/")==0)
                {
                    m=j/k;
                }
               /* j = m;
                while (j != 0)
                {
                    len++;
                    j /= 10;
                }
                for (i = 0; i < len; i++)
                {
                    rem = j % 10;
                    j = j / 10;
                    yay[len - (i + 1)] = rem + '0';
                }
                yay[len] = '\0';*/
                strcpy(intermediate_code[i].op,"=");
		sprintf(intermediate_code[i].op1,"%d",m);
                //strcpy(intermediate_code[i].op1,yay);
                strcpy(intermediate_code[i].op2,"");
                
            }
    }
            

    printf("\n\n_______________________________________________________________________________________\n");
    printf("Optimized  code\n");
printf("_______________________________________________________________________________________\n");

for (i=0;i<code;i++)
    printf("%s\t%s\t%s\t%s\n",intermediate_code[i].op,intermediate_code[i].op1,intermediate_code[i].op2,intermediate_code[i].res);
}
#line 1088 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 71 "while.y"
	{insert_type_table();}
#line 1761 "y.tab.c"
break;
case 2:
#line 71 "while.y"
	{add('t');}
#line 1766 "y.tab.c"
break;
case 3:
#line 71 "while.y"
	{add('t');}
#line 1771 "y.tab.c"
break;
case 4:
#line 71 "while.y"
	{add('t');}
#line 1776 "y.tab.c"
break;
case 5:
#line 71 "while.y"
	{ printf("Label next:\n");}
#line 1781 "y.tab.c"
break;
case 6:
#line 71 "while.y"
	{yyval.nam.nd = mknode(NULL,yystack.l_mark[-3].nam.nd,"start");printf("\n\n-----------------------------------------------------------------------------------\n");printf("\n\t\t\tSyntax Tree in Inorder traversal\n-----------------------------------------------------------------------------------\n");
printtree(yyval.nam.nd);
printf("\n\n");
add('t');
optimized();}
#line 1790 "y.tab.c"
break;
case 8:
#line 76 "while.y"
	{add('H');}
#line 1795 "y.tab.c"
break;
case 9:
#line 77 "while.y"
	{insert_type();}
#line 1800 "y.tab.c"
break;
case 10:
#line 77 "while.y"
	{insert_type();}
#line 1805 "y.tab.c"
break;
case 11:
#line 77 "while.y"
	{insert_type();}
#line 1810 "y.tab.c"
break;
case 12:
#line 77 "while.y"
	{insert_type();}
#line 1815 "y.tab.c"
break;
case 13:
#line 78 "while.y"
	{add('t');}
#line 1820 "y.tab.c"
break;
case 17:
#line 80 "while.y"
	{add('t');}
#line 1825 "y.tab.c"
break;
case 19:
#line 81 "while.y"
	{insert_type_table();}
#line 1830 "y.tab.c"
break;
case 21:
#line 81 "while.y"
	{add_ptr();}
#line 1835 "y.tab.c"
break;
case 23:
#line 82 "while.y"
	{add('t');}
#line 1840 "y.tab.c"
break;
case 24:
#line 82 "while.y"
	{add('n');}
#line 1845 "y.tab.c"
break;
case 27:
#line 82 "while.y"
	{add('t');}
#line 1850 "y.tab.c"
break;
case 30:
#line 84 "while.y"
	{add('n');}
#line 1855 "y.tab.c"
break;
case 31:
#line 84 "while.y"
	{add('t');printf("Return\t%s\n",yystack.l_mark[-2].nam.name);}
#line 1860 "y.tab.c"
break;
case 32:
#line 84 "while.y"
	{add('t');printf("Return\t%s\n",yystack.l_mark[-1].nam.name);}
#line 1865 "y.tab.c"
break;
case 36:
#line 88 "while.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
#line 1870 "y.tab.c"
break;
case 37:
#line 89 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,"definition"); int i=sym_search(yystack.l_mark[-1].nam.name);if(i!=-1)
	{if(strcmp(yystack.l_mark[-2].nam.name,"int")==0){addTo('i',yystack.l_mark[-1].nam.name);}
	else if(strcmp(yystack.l_mark[-2].nam.name,"float")==0)addTo('f',yystack.l_mark[-1].nam.name);
	else addTo('c',yystack.l_mark[-1].nam.name);}
	else{printf("Variable already defined, error at line no: %d\n",yylineno);exit(0);}}
#line 1879 "y.tab.c"
break;
case 38:
#line 94 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-1].nam.nd,yystack.l_mark[0].nam.nd,"statement");strcpy(yyval.nam.name,"STATEMENT");}
#line 1884 "y.tab.c"
break;
case 39:
#line 95 "while.y"
	{add('f');}
#line 1889 "y.tab.c"
break;
case 40:
#line 95 "while.y"
	{yyval.nam.nd = mknode(NULL,NULL,"printf");}
#line 1894 "y.tab.c"
break;
case 41:
#line 96 "while.y"
	{add('f');}
#line 1899 "y.tab.c"
break;
case 42:
#line 96 "while.y"
	{yyval.nam.nd = mknode(NULL,NULL,"scanf");}
#line 1904 "y.tab.c"
break;
case 43:
#line 97 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,"EPSILON");}
#line 1909 "y.tab.c"
break;
case 44:
#line 101 "while.y"
	{add('k');}
#line 1914 "y.tab.c"
break;
case 45:
#line 101 "while.y"
	{printf("\n Label\t%s:\n",yystack.l_mark[-1].gen.tr);}
#line 1919 "y.tab.c"
break;
case 46:
#line 101 "while.y"
	{addTo('{',"Punctuations");}
#line 1924 "y.tab.c"
break;
case 47:
#line 101 "while.y"
	{addTo('}',"Punctuations");
	pop();
	printf("goto next\n");
	printf("\nLabel\t%s:\n",yystack.l_mark[-6].gen.fal);}
#line 1932 "y.tab.c"
break;
case 48:
#line 104 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-8].gen.nd,yystack.l_mark[-3].nam.nd,"IF");
	strcpy(yyval.nam.name,"IF");}
#line 1938 "y.tab.c"
break;
case 49:
#line 106 "while.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
#line 1943 "y.tab.c"
break;
case 50:
#line 107 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,"definition"); int i=sym_search(yystack.l_mark[-1].nam.name);if(i!=-1)
	{if(strcmp(yystack.l_mark[-2].nam.name,"int")==0){addTo('i',yystack.l_mark[-1].nam.name);}
	else if(strcmp(yystack.l_mark[-2].nam.name,"float")==0)addTo('f',yystack.l_mark[-1].nam.name);
	else addTo('c',yystack.l_mark[-1].nam.name);}
	else{printf("Variable already defined, error at line no: %d\n",yylineno);exit(0);}}
#line 1952 "y.tab.c"
break;
case 51:
#line 112 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-1].nam.nd,yystack.l_mark[0].nam.nd,"statement");strcpy(yyval.nam.name,"STATEMENT");}
#line 1957 "y.tab.c"
break;
case 52:
#line 113 "while.y"
	{add('f');}
#line 1962 "y.tab.c"
break;
case 53:
#line 113 "while.y"
	{yyval.nam.nd = mknode(NULL,NULL,"printf");}
#line 1967 "y.tab.c"
break;
case 54:
#line 114 "while.y"
	{add('f');}
#line 1972 "y.tab.c"
break;
case 55:
#line 114 "while.y"
	{yyval.nam.nd = mknode(NULL,NULL,"scanf");}
#line 1977 "y.tab.c"
break;
case 56:
#line 115 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,"EPSILON");}
#line 1982 "y.tab.c"
break;
case 57:
#line 118 "while.y"
	{add('k'); sprintf(nL,"L%d",ifd);ifd++;printf("\n Label \t %s : \n",nL);}
#line 1987 "y.tab.c"
break;
case 58:
#line 118 "while.y"
	{printf("\n Label\t%s:\n",yystack.l_mark[-1].gen.tr);}
#line 1992 "y.tab.c"
break;
case 59:
#line 118 "while.y"
	{addTo('{',"Punctuations");}
#line 1997 "y.tab.c"
break;
case 60:
#line 118 "while.y"
	{addTo('}',"Punctuations");
	pop();
	printf("goto %s\n",nL);
	printf("\nLabel\t%s:\n",yystack.l_mark[-6].gen.fal);}
#line 2005 "y.tab.c"
break;
case 61:
#line 121 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-8].gen.nd,yystack.l_mark[-3].nam.nd,"WHILE");
	strcpy(yyval.nam.name,"WHILE");}
#line 2011 "y.tab.c"
break;
case 62:
#line 123 "while.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
#line 2016 "y.tab.c"
break;
case 63:
#line 124 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,"definition"); int i=sym_search(yystack.l_mark[-1].nam.name);if(i!=-1)
	{if(strcmp(yystack.l_mark[-2].nam.name,"int")==0){addTo('i',yystack.l_mark[-1].nam.name);}
	else if(strcmp(yystack.l_mark[-2].nam.name,"float")==0)addTo('f',yystack.l_mark[-1].nam.name);
	else addTo('c',yystack.l_mark[-1].nam.name);}
	else{printf("Variable already defined, error at line no: %d\n",yylineno);exit(0);}}
#line 2025 "y.tab.c"
break;
case 64:
#line 129 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-1].nam.nd,yystack.l_mark[0].nam.nd,"statement");strcpy(yyval.nam.name,"STATEMENT");}
#line 2030 "y.tab.c"
break;
case 65:
#line 130 "while.y"
	{add('f');}
#line 2035 "y.tab.c"
break;
case 66:
#line 130 "while.y"
	{yyval.nam.nd = mknode(NULL,NULL,"printf");}
#line 2040 "y.tab.c"
break;
case 67:
#line 131 "while.y"
	{add('f');}
#line 2045 "y.tab.c"
break;
case 68:
#line 131 "while.y"
	{yyval.nam.nd = mknode(NULL,NULL,"scanf");}
#line 2050 "y.tab.c"
break;
case 69:
#line 132 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,"EPSILON");}
#line 2055 "y.tab.c"
break;
case 70:
#line 134 "while.y"
	{add('k');}
#line 2060 "y.tab.c"
break;
case 71:
#line 134 "while.y"
	{addTo('{',"Punctuations");}
#line 2065 "y.tab.c"
break;
case 72:
#line 134 "while.y"
	{yyval.nam=yystack.l_mark[-1].nam;addTo('}',"Punctuations");
	pop();
	printf("goto next\n");
	printf("\n");}
#line 2073 "y.tab.c"
break;
case 73:
#line 137 "while.y"
	{printf("goto next\n");
	printf("\n");}
#line 2079 "y.tab.c"
break;
case 78:
#line 142 "while.y"
	{yyval.gen.nd=yystack.l_mark[0].gen.nd;}
#line 2084 "y.tab.c"
break;
case 79:
#line 145 "while.y"
	{yyval.gen.nd=mknode(yystack.l_mark[-2].nam.nd,yystack.l_mark[0].nam.nd,yystack.l_mark[-1].nam.name);
   	int i=search(yystack.l_mark[-2].nam.name);
   	int j=search(yystack.l_mark[0].nam.name);
   	if(i!=0&&j!=0){
   	printf("if %s %s %s goto L%d else goto L%d\n",yystack.l_mark[-2].nam.name,yystack.l_mark[-1].nam.name,yystack.l_mark[0].nam.name,ifd,eld);
   sprintf(yyval.gen.tr,"L%d",ifd);
   sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}   
   else{printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
#line 2096 "y.tab.c"
break;
case 80:
#line 153 "while.y"
	{add('o');}
#line 2101 "y.tab.c"
break;
case 81:
#line 153 "while.y"
	{int i=search(yystack.l_mark[-3].nam.name);
 	int j=search(yystack.l_mark[0].nam.name);
 	if(i!=0&&j!=0)
 	{
 	printf("if %s!=0 goto L%d else goto L%d\n",yystack.l_mark[-3].nam.name,ifd,eld);
 	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;} 
	else{printf(" Variable not declared at line no: %d\n", yylineno);
	exit(0);}}
#line 2114 "y.tab.c"
break;
case 82:
#line 162 "while.y"
	{printf("if False  goto L%d\n",eld);
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}
#line 2121 "y.tab.c"
break;
case 83:
#line 165 "while.y"
	{printf("if True  goto L%d\n",ifd);
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}
#line 2128 "y.tab.c"
break;
case 84:
#line 168 "while.y"
	{int i=search(yystack.l_mark[0].nam.name);
	if(i!=0)
	{
	printf("if %s!=0  goto L%d else goto L%d\n",yystack.l_mark[0].nam.name,ifd,eld);
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}    
	else {printf(" Variable not declared at line no: %d\n", yylineno);
	exit(0);} }
#line 2140 "y.tab.c"
break;
case 85:
#line 176 "while.y"
	{add('n');
	printf("if %s!=0  goto L%d else goto L%d\n",yystack.l_mark[0].nam.name,ifd,eld);
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}
#line 2148 "y.tab.c"
break;
case 86:
#line 181 "while.y"
	{add('o');}
#line 2153 "y.tab.c"
break;
case 87:
#line 181 "while.y"
	{yystack.l_mark[-4].nam.nd = mknode(NULL,NULL,yystack.l_mark[-4].nam.name);
	  yyval.nam.nd=mknode(yystack.l_mark[-4].nam.nd,yystack.l_mark[-1].nam.nd,"=");
	  strcpy(yyval.nam.name,"=");add('t');
	  int i=search(yystack.l_mark[-4].nam.name);
	  int j=search(yystack.l_mark[-1].nam.name);
	  if(i!=0&&j!=0) 
	  {
	  type_check(yystack.l_mark[-4].nam.name,yystack.l_mark[-1].nam.name);
	  printf("= \t %s\t %s \n",yystack.l_mark[-1].nam.name,yystack.l_mark[-4].nam.name);
		strcpy(intermediate_code[code].op,"=");
		strcpy(intermediate_code[code].res,yystack.l_mark[-4].nam.name);
		strcpy(intermediate_code[code].op1,yystack.l_mark[-1].nam.name);
		code++;
		} 
	  else {printf("Variable not declared at line no: %d\n", yylineno);
	  exit(0);}}
#line 2173 "y.tab.c"
break;
case 88:
#line 196 "while.y"
	{add('t');}
#line 2178 "y.tab.c"
break;
case 89:
#line 198 "while.y"
	{add('o');}
#line 2183 "y.tab.c"
break;
case 90:
#line 198 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"+");strcpy(yyval.nam.name,"+");
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"t%d",c);c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","+",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);strcpy(intermediate_code[code].op,"+");
		strcpy(intermediate_code[code].res,yyval.nam.name);
		strcpy(intermediate_code[code].op1,yystack.l_mark[-3].nam.name);
		strcpy(intermediate_code[code].op2,yystack.l_mark[0].nam.name);
		code++;}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
#line 2198 "y.tab.c"
break;
case 91:
#line 211 "while.y"
	{add('o');}
#line 2203 "y.tab.c"
break;
case 92:
#line 211 "while.y"
	{ yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"-");
	strcpy(yyval.nam.name,"-");
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"t%d",c);c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","-",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name); strcpy(intermediate_code[code].op,"-");
		strcpy(intermediate_code[code].res,yyval.nam.name);
		strcpy(intermediate_code[code].op1,yystack.l_mark[-3].nam.name);
		strcpy(intermediate_code[code].op2,yystack.l_mark[0].nam.name);
		code++;} 
	else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
#line 2219 "y.tab.c"
break;
case 93:
#line 223 "while.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
#line 2224 "y.tab.c"
break;
case 94:
#line 225 "while.y"
	{add('o');}
#line 2229 "y.tab.c"
break;
case 95:
#line 225 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"*");
	 strcpy(yyval.nam.name,"*");
	 int i=search(yystack.l_mark[-3].nam.name);
	 int j=search(yystack.l_mark[0].nam.name);
	 sprintf(yyval.nam.name,"t%d",c);c++;
	 addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	 if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","*",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);strcpy(intermediate_code[code].op,"*");
		strcpy(intermediate_code[code].res,yyval.nam.name);
		strcpy(intermediate_code[code].op1,yystack.l_mark[-3].nam.name);
		strcpy(intermediate_code[code].op2,yystack.l_mark[0].nam.name);
		code++;}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
#line 2245 "y.tab.c"
break;
case 96:
#line 238 "while.y"
	{add('o');}
#line 2250 "y.tab.c"
break;
case 97:
#line 238 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"/");strcpy(yyval.nam.name,"/"); 
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"%d",c);
	strcat(yyval.nam.name,"t");c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) 
	{
	printf("%s\t%s\t%s\t%s\n","/",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);strcpy(intermediate_code[code].op,"/");
		strcpy(intermediate_code[code].res,yyval.nam.name);
		strcpy(intermediate_code[code].op1,yystack.l_mark[-3].nam.name);
		strcpy(intermediate_code[code].op2,yystack.l_mark[0].nam.name);
		code++;
	}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);
	 exit(0);}}
#line 2270 "y.tab.c"
break;
case 98:
#line 255 "while.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
#line 2275 "y.tab.c"
break;
case 99:
#line 257 "while.y"
	{add('o');}
#line 2280 "y.tab.c"
break;
case 100:
#line 257 "while.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"^");
	strcpy(yyval.nam.name,"^");
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"%d",c);
	strcat(yyval.nam.name,"t");c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) {
	printf("%s\t%s\t%s\t%s\n","^",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);strcpy(intermediate_code[code].op,"^");
		strcpy(intermediate_code[code].res,yyval.nam.name);
		strcpy(intermediate_code[code].op1,yystack.l_mark[-3].nam.name);
		strcpy(intermediate_code[code].op2,yystack.l_mark[0].nam.name);
		code++;} 
	else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
#line 2298 "y.tab.c"
break;
case 101:
#line 272 "while.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
#line 2303 "y.tab.c"
break;
case 102:
#line 274 "while.y"
	{add('t');}
#line 2308 "y.tab.c"
break;
case 103:
#line 274 "while.y"
	{add('t'); yyval.nam=yystack.l_mark[-1].nam;}
#line 2313 "y.tab.c"
break;
case 104:
#line 274 "while.y"
	{insert_type_table();}
#line 2318 "y.tab.c"
break;
case 105:
#line 274 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,yystack.l_mark[-2].nam.name);strcpy(yyval.nam.name,yystack.l_mark[-2].nam.name);}
#line 2323 "y.tab.c"
break;
case 106:
#line 274 "while.y"
	{add('n');}
#line 2328 "y.tab.c"
break;
case 107:
#line 274 "while.y"
	{yyval.nam.nd=mknode(NULL,NULL,yystack.l_mark[-1].nam.name);
	strcpy(yyval.nam.name,yystack.l_mark[-1].nam.name);}
#line 2334 "y.tab.c"
break;
case 108:
#line 278 "while.y"
	{add('r');}
#line 2339 "y.tab.c"
break;
case 109:
#line 278 "while.y"
	{add('r');}
#line 2344 "y.tab.c"
break;
case 110:
#line 278 "while.y"
	{add('r');}
#line 2349 "y.tab.c"
break;
case 111:
#line 278 "while.y"
	{add('r');}
#line 2354 "y.tab.c"
break;
case 112:
#line 278 "while.y"
	{add('r');}
#line 2359 "y.tab.c"
break;
#line 2361 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
