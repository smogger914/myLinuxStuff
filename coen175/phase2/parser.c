# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "lexer.h"
# include "parser.h"

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


//code
void error(void){
	//report();	
	//printf("error\n");
}
/*void translationunit(void){
	globaldeclaration();
	translationunit();
}*/
void globaldeclaration(void){
	
		typespecifier();
		pointers();
		match(ID);
			if(lookahead == '('){
				match('(');
				parameters();
				match(')');
				match('{');
				declarations();
				statements();
				match('}');
			}
	
	
	else{
		if(lookahead == '['){
			match('[');
			match(NUM);
			match(']');
			
		}
		if(lookahead == ','){
			declaratorlist();
			
		}
		match(';');

	}
	
}
void typespecifier(void) {
	if(lookahead == CHAR || lookahead == INT){
      match(lookahead);
	}
	else{
      error();
	}

}
void pointers(void) {
	if(lookahead == '*')
	{
      match('*');
      pointers();
	}

}
void parameters(void){
	if(lookahead == VOID)	
	match(VOID);
	else
	parameterlist();
}
void parameterlist(void){
	parameter();
	if(lookahead == ','){	
		match(',');
		parameterlist();
	}
}
void parameter(void){	
	typespecifier();
	declaratorlist();
	match(ID);
	
}
void declarations(void){
	
	if(lookahead == CHAR || lookahead == INT){
      declaration();
      declarations();
	}

}
void declaration(void){
	typespecifier();
	declaratorlist();
	match(';');
}
void declaratorlist(void){
		declarator();	   
		while(lookahead == ','){
	     match(',');
        declarator();
		}
}
void declarator(void){
	pointers();
	match(ID);
	if(lookahead == '['){
		match('[');
		match(NUM);
		match(']');
	}
	
}
void statement(void){
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
void statements(void){
	while(lookahead != '}')
		statement();
}
void expression(void){
	E();
}

void expressionlist(void){
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
	 } 
	 	
}

void T(void) {
	F();

    while(1) {
   	if (lookahead == OR) {
	    match(OR);
	    F();
		 printf("or\n");
	 } 
		else
	 		break;
    }
}

void F(void) {
	H();
	
    while(1) {
	if (lookahead == AND) {
	    match(AND);
		 H();
		 printf("and\n");
   	} else
	 	break;
    }
}

void H(void) {
	I();
	
   while(1) {
		if (lookahead == EQ) {
	    match(EQ);
		 
	    I();
		 printf("eql\n");
	 } else if (lookahead == NEQ) {
	    match(NEQ);
		 
	    I();
		 printf("neq\n");
	 } else
	 	break;
    }
}

void I(void) {
	J();
	
   while(1) {
		if (lookahead == '<') {
   	   match('<');
			J();		 
			printf("ltn\n");
	    
		 } else if (lookahead == '>') {
		 	match('>');
			J();	 	
			printf("gtn\n");
	 	
		 } else if (lookahead == GTE) {
		 	match(GTE);
		   J();
		   printf("geq\n");
	 
		 } else if (lookahead == LTE) {
		 	match(LTE);
			J();		
			printf("leq\n");
	 	
		 } else{
	      	//error();
				break;
			}
     }
}

void J(void) {
	K();
	
   while(1) {
	if (lookahead == '+') {
	    match('+');
		 K();
		 printf("add\n");
		     
	 } else if (lookahead == '-') {
	    match('-');
		 
	    K();
		 printf("sub\n");
	 } else
	 
		break;
    }
}

void K(void) {
	L();
	
    while(1) {
	if (lookahead == '*') {
	    match('*');
		 L(); 
		 printf("mul\n");
		    
	 } else if (lookahead == '/') {
	    match('/');
		 L();
		 printf("div\n");
	    
	 }  else if (lookahead == '%') {
	    match('%');
		 L();
		 printf("rem\n");
	    
	 } else
	 	break;
    }
}

void L(void) {

	if(lookahead == '('){
		match('(');

		if(lookahead == INT || lookahead == CHAR){
			match(lookahead);
			pointers();
			match(')');
			L();
			printf("cast\n");
		}
		else{
			expression();
			match(')');
		}
		
		
	}
	
	else{
		M();
	}
	


}

void M(void) {
	
	
 
      if (lookahead =='!') {
	    match('!');
		 M();
	    printf("not\n");
		 
	    
	} else if (lookahead == '-') {
	    match('-');
		 M();
		 printf("neg\n");
		 
	    
	} else if (lookahead == '&') {
	    match('&');
		 M();
		 printf("addr\n");
	    
	} else if (lookahead == '*') {
	    match('*');
		 M();
		 printf("dref\n");
	    
	} else if (lookahead == SZOF) {
	    match(SZOF);
		 match('(');
		 typespecifier();
		 pointers();
		 match(')');
		 printf("szof\n");
	  }
	else {
		N();
	} 

	
}

void N(void) {
	P();
	
	while(lookahead == '['){
		match('[');
		expression();
		match(']');
		printf("indx\n");
	}
	
	
}
void P(void){
	
	if(lookahead == ID){
		//
		char *temp;
		temp = strdup(lexbuf);
		
		match(ID);
			if(lookahead == '('){
				match('(');
				
					if (lookahead == ')'){
						match(')');
					}
					else{
						expressionlist();
						match(')');
					}
					printf("call %s\n", temp);
			}
			else{
				printf("push %s\n", temp);
			}
	}
	else if(lookahead == NUM){
		printf("push %s\n", lexbuf);
		
		match(NUM);
//		printf("push %s\n", lexbuf);
	}
	else if(lookahead == STRING){

		printf("push %s\n", lexbuf);
		match(STRING);
		
	}
	else if(lookahead == '('){
		match('(');
		expression();
		match(')');
	}
	
}

void match(int t) {
	if(lookahead == t) {
		//printf("old lookahead = %s\n", lexbuf);
		lookahead = lexan();
		//printf("new lookahead = %s  %d\n", lexbuf, lookahead);
	} else
		error();
}

int main(void){

	lookahead = lexan();
	//printf("lookahead = %d\n", lookahead);
	//int x = 0;
	
	while(lookahead != FILEND){
	//while(x < 10){
		//if(lookahead != -1){
		//printf("%d\n",lookahead);
		globaldeclaration();
		//expression();
		//}
	//	x++;
		
	//	lookahead = lexan();
	}
	free (lexbuf);
	return 0;
}
