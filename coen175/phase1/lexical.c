#include <stdio.h>
#include <ctype.h>
#include <string.h>

char operators[] = {'=','<','>','+','-','*','/','%','&','!','(',')','[',']','{','}',';',','};
char specialops[9][2] = {"||","&&","==","!=","<=",">=","/*","*/"};
 
char keywords[32][8] = {"auto", "break", "case", "char", "const", "continue", "default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short",
"signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};


char holder[9];
char buffer[1000];

FILE *fp;
char ch;

int count = 0;
int incomment = 0;// 0 when not in comment 1 when in
int ignoreFirstSlash = 0; // 0 when normal
int isSpecial = 0;
int isInQuote = 0; 
int isPeeking = 0; //0 when normal
int isOperator(char ch);
int isSpecialOp(char ch);//returns one if special
int isKeyWord(char ch[]);
void startComment();
void stopComment();

int main(int argc, char *argv[]){

	fp=fopen("fib.c","r");   //sourcepath
	if(fp==NULL)
	{
		printf("Can't open input file!");
		return(0);
	}
	//get input from file
	while(!feof(fp))  //While the file is not end.
	{
		ch = fgetc(fp);
		
		if(ch == EOF){
			
			return(0);
     		}
	  //removes comments
	  
	  char peek = fgetc(fp);
	  if(ch == '/' && peek == '*' ){
			startComment();
	  }
	  if(ch == '*' && peek == '/' ){
			stopComment();
			
			ch = fgetc(fp);
			peek = fgetc(fp);
			if(ch == '/' && peek == '*')
			startComment();
			peek = ungetc(peek,fp);
			ch = ungetc(ch,fp);
			ignoreFirstSlash = 1;
			
		}
		//quotes
			if(ch == '"')
		{
			if(isInQuote == 0){
				startComment();
				isInQuote = 1;			
			}
			if(isInQuote == 1){
				stopComment();
				isInQuote = 0; 
		}
	

	   
		peek = ungetc(peek, fp);
	
		count = 0;
		int l = 0;

		//while no white space, not incomment and next does not = op then make buffer, 
		while(!isspace(ch) && incomment == 0){
	
			
			//is operator
			if(isOperator(ch)){
			
				if(isSpecialOp(ch)){
					peek = fgetc(fp);
					if(ch == '&' && peek == '&'){
						printf("operator:&&\n");
						ch = peek;
					}
					else if(ch == '|' && peek == '|'){
						printf("operator:||\n");
						ch = peek;
					}
					else if(ch == '=' && peek == '='){
						printf("operator:==\n");
						ch = peek;
					}
					else if(ch == '!' && peek == '='){
						printf("operator:!=\n");
						ch = peek;
					}
					else if(ch == '<' && peek == '='){
						printf("operator:<=\n");
						ch = peek;
					}
					else if(ch == '>' && peek == '='){
						printf("operator:>=\n");
						ch = peek;
					}
					peek = ungetc(peek, fp);
			}
			else if(ignoreFirstSlash == 1 && ch == '/'){
					
					ignoreFirstSlash = 0;
			}
			else{
					
					printf("operator:%c\n",ch);

					
				}
			
				ch = fgetc(fp);

			}
			//printf("%c\n", buffer[count]);	
			//makes the buffer
			else{
			//	printf("chB:%c\n", ch);
				buffer[count] = ch;
							
				ch = fgetc(fp);
				buffer[count+1] = '\0';
				count++;	
			}
			if(isKeyword(buffer)){
			//	if(buffer != "in")
			//	printf("found keyword:%s\n" , buffer);
			}
			
		}
	
		

	}


}
int isKeyword(char ch[]){
	int i,j;
	if(!strcmp(buffer,"auto")){
		printf("keyword:auto\n");
	}
	else if(!strcmp(buffer,"break")){
		printf("keyword:break\n");
	}
	else if(!strcmp(buffer,"case")){
		printf("keyword:case\n");
	}
	else if(!strcmp(buffer,"char")){
		printf("keyword:char\n");
	}
	else if(!strcmp(buffer,"const")){
		printf("keyword:const\n");
	}
	else if(!strcmp(buffer,"continue")){
		printf("keyword:continue\n");
	}
	else if(!strcmp(buffer,"default")){
		printf("keyword:default\n");
	}
	else if(!strcmp(buffer,"do")){
		printf("keyword:do\n");
	}
	else if(!strcmp(buffer,"double")){
		printf("keyword:double\n");
	}
	else if(!strcmp(buffer,"else")){
		printf("keyword:else\n");
	}
	else if(!strcmp(buffer,"enum")){
		printf("keyword:enum\n");
	}
	else if(!strcmp(buffer,"extern")){
		printf("keyword:extern\n");
	}
	else if(!strcmp(buffer,"float")){
		printf("keyword:float\n");
	}
	else if(!strcmp(buffer,"for")){
		printf("keyword:for\n");
	}
	else if(!strcmp(buffer,"goto")){
		printf("keyword:goto\n");
	}
	else if(!strcmp(buffer,"if")){
		printf("keyword:if\n");
	}
	else if(!strcmp(buffer,"int")){
		printf("keyword:int\n");
	}
	else if(!strcmp(buffer,"long")){
		printf("keyword:long\n");
	}
	else if(!strcmp(buffer,"register")){
		printf("keyword:register\n");
	}
	else if(!strcmp(buffer,"return")){
		printf("keyword:return\n");
	}
	else if(!strcmp(buffer,"short")){
		printf("keyword:short\n");
	}
	else if(!strcmp(buffer,"signed")){
		printf("keyword:signed\n");
	}
	else if(!strcmp(buffer,"sizeof")){
		printf("keyword:sizeof\n");
	}
	else if(!strcmp(buffer,"static")){
		printf("keyword:static\n");
	}
	else if(!strcmp(buffer,"struct")){
		printf("keyword:struct\n");
	}
	else if(!strcmp(buffer,"switch")){
		printf("keyword:switch\n");
	}
	else if(!strcmp(buffer,"typedef")){
		printf("keyword:typedef\n");
	}
	else if(!strcmp(buffer,"union")){
		printf("keyword:union\n");
	}
	else if(!strcmp(buffer,"unsigned")){
		printf("keyword:unsigned\n");
	}
	else if(!strcmp(buffer,"void")){
		printf("keyword:void\n");
	}
	else if(!strcmp(buffer,"volatile")){
		printf("keyword:volatile\n");
	}
	else if(!strcmp(buffer,"while")){
		printf("keyword:while\n");
	}
	
	return(0);	
}
//returns 1 if the character is in the list operators
int isOperator(char ch){
	int i = 0;
	for(i;i<20;i++){
		if(ch == operators[i])
			return(1);
		
	}
	
	return(0);
}
int isSpecialOp(char ch){
	if(ch == '|' || ch == '=' || ch == '<' || ch == '>' || ch == '!' || ch == '&')
		return(1);
	else
		return(0);
}
//starts a comment
void startComment(){
	incomment = 1;
} 
//stop comment
void stopComment(){
	incomment = 0;
}

