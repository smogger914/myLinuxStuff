# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "lexer.h"
//# include "parser.h"

//vars
int lookahead;


//function defs
void error();

void translationunit();
void globaldeclaration();
void typespecifier();
void pointers();
void parameters();
void parameterlist();
void parameter();
void declarations();
void declaration();
void declaratorlist();
void declarator();
void statement();
void statements();
void expression();
void expressionlist();
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


//code
void error(){

}
void translationunit(){
	globaldeclaration();
	translationunit();
}
void globaldeclaration(){
	if(lookahead == CHAR || lookahead == INT){
		typespecifier();
		pointers();
		match(ID);
		match('(');
		parameters();
		match(')');
		match('{');
		declarations();
		statements();
		match('}');
	}
	else{
		declaration();
	}
	
}
void typespecifier() {
	if(lookahead == CHAR || lookahead == INT){
      match(lookahead);
	}
	else{
      error();
	}

}
void pointers() {
	if(lookahead == '*')
	{
      match('*');
      pointers();
	}

}
void parameters(){
	if(lookahead == VOID)	
	match(VOID);
	else
	parameterlist();
}
void parameterlist(){
	parameter();
	if(lookahead == ','){	
		match(',');
		parameterlist();
	}
}
void parameter(){	
	typespecifier();
	declaratorlist();
	match(ID);
	
}
void declarations(){
	
	if(lookahead == CHAR || lookahead == INT){
      declaration();
      declarations();
	}

}
void declaration(){
	typespecifier();
	declaratorlist();
	match(';');
}
void declaratorlist(){
		declaration();	   
		while(lookahead == ','){
	     match(',');
        declaration();
		}
}
void declarator(){
	pointers();
	match(ID);
	if(lookahead = '['){
		match('[');
		match(NUM);
		match(']');
	}
	
}
void statement(){
	if(lookahead == '{') {
		match('{');
		declarations();
		statements();
		match('}');
	} 
	else if (lookahead == RET) {
		match(RET);
		expression();
		match(';');
	}
	else if (lookahead == WHILE) {
		match(WHILE);
		match('(');
		expression();
		match(')');
		statement();
	} 
	else if (lookahead == IF) {
		match(IF);
		match('(');
		expression();
		match(')');
		statement();
			if (lookahead == ELSE) {
				match(ELSE);
				statement();
			}
	} else {
	   expression();
		match(';');
	}
}
void statements(){
	statement();
	statements();
}
void expression(){
	E();
}

void expressionlist(){
	expression();
   while(lookahead == ','){
	   match(',');
      expression();
   }
}
void E(void) {
	T();
	
	if (lookahead =='=') {
	    match('=');
	    E();
	    printf("asgn\n");
	 } else
	 	error();
}

void T(void) {
	F();
	
    while(1) {
       if (lookahead == OR) {
	    match(OR);
	    F();
	 } else
	 	error();
    }
}

void F(void) {
	H();
	
    while(1) {
	if (lookahead == AND) {
	    match(AND);
	    H();
	 } else
	 	error();
    }
}

void H(void) {
	I();
	
    while(1) {
	if (lookahead == EQ) {
	    match(EQ);
	    I();
	 } else if (lookahead == NEQ) {
	    match(NEQ);
	    I();
	 } else
	 	error();
    }
}

void I(void) {
	J();
	
    while(1) {
	if (lookahead == '<') {
	    match('<');
	    J();
	 } else if (lookahead == '>') {
	 	match('>');
	 	J();
	 } else if (lookahead == GTE) {
	 	match(GTE);
	 	J();
	 } else if (lookahead == LTE) {
	 	match(LTE);
	 	J();
	 } else
	 	error();
     }
}

void J(void) {
	K();
	
    while(1) {
	if (lookahead == '+') {
	    match('+');
	    K();
	 } else if (lookahead == '-') {
	    match('-');
	    K();
	 } else
	 	error();
    }
}

void K(void) {
	L();
	
    while(1) {
	if (lookahead == '*') {
	    match('*');
	    L();
	 } else if (lookahead == '/') {
	    match('/');
	    L();
	 }  else if (lookahead == '%') {
	    match('%');
	    L();
	 } else
	 	error();
    }
}

void L(void) {
 	M();
 
 while (1) {
      if (lookahead =='(') {
	    match('(');
	    M();
	    match(')');
	} else
	    error();
     }	

}

void M(void) {
	N();
	
    while (1) {
      if (lookahead =='!') {
	    match('!');
	    N();
	} else if (lookahead == '-') {
	    match('-');
	    N();
	} else if (lookahead == '&') {
	    match('&');
	    N();
	} else if (lookahead == '*') {
	    match('*');
	    N();
	} else if (lookahead == SZOF) {
	    match(SZOF);
	    N();
	} else
	    error();
     }	
	
}

void N(void) {
//test
	lookahead = lexan();
}

void match(int t) {
	if(lookahead == t)
		lookahead = lexan();
	else
		error();
}

int main(void){

	int lookahead = lexan();
	//int x = 0;
	//printf("hello");
	while(lookahead != FILEND){
	//while(x < 10){
		if(lookahead != -1){

		expression();
		}
	//	x++;
		
		lookahead = lexan();
	}
	free (lexbuf);
	return 0;
}
