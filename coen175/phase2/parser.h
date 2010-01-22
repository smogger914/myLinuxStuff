/*
 * File:	parser.h
 *
 *
 */

# ifndef PARSER_H
# define PARSER_H

#define ID 256
#define NUM 257
#define OR 258
#define AND 259
#define NEQ 260
#define EQ 261
#define GTE 262
#define LTE 263
#define IF 264
#define ELSE 265
#define CHAR 266
#define INT 267
#define SZOF 268
#define KEY 268 
#define STRING 270
#define DONE 271
#define WHILE 272
#define VOID 273
#define RET 274
#define FILEND 275

//vars
int lookahead;


//function defs
void error(void);

void translationunit(void);
void globaldeclaration(void);
void typespecifier(void);
void pointers(void);
void parameters(void);
void parameterlist(void);
void parameter(void);
void declarations(void);
void declaration(void);
void declaratorlist(void);
void declarator(void);
void statement(void);
void statements(void);
void expression(void);
void expressionlist(void);
void match(int t);

void E(void);
void T(void);
void F(void);
void H(void);
void I(void);
void J(void);
void K(void);
void L(void);
void M(void);
void N(void);
void P(void);

# endif /* PARSER.H */
