/*
 * File:	lexer.h
 *
 * Description:	This file contains the public function and variable
 *		declarations for the lexical analyzer for Simple C.
 */

# ifndef LEXER_H
# define LEXER_H

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

extern char *lexbuf;
extern int lexan(void);
extern void report(char *format, char *string);

# endif /* LEXER_H */
