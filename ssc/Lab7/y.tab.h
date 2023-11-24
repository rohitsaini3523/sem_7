#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE { struct var_name {char name[100];struct node1* nd;} nam ; 
	struct gen_code{char tr[10];char fal[10];struct node1* nd;} gen;
	 } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
