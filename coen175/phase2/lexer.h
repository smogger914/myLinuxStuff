/*
 * File:	lexer.h
 *
 * Description:	This file contains the public function and variable
 *		declarations for the lexical analyzer for Simple C.
 */

# ifndef LEXER_H
# define LEXER_H

extern char *lexbuf;
extern int lexan(void);
extern void report(char *format, char *string);

# endif /* LEXER_H */