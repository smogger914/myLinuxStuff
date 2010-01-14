#include <stdio.h>
#include <ctype.h>
#include <string.h>


   FILE *fp;
   char ch;
   int asci;
  // char operators[18] = {"-*/+=%&!()[]{};,<>"};
  // char operators[] = {'=','<','>','+','-','*','/','%','&','!','(',')','[',']','{','}',';',','};
  //char *specialops[] = {"||","&&","==","!=","<=",">=","/*","*/"};
  // void containsChar(char);
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
	 printf("end of file\n");
      }
     
        
    
      if (ch == ' ') //space go to next one
         ch = fgetc(fp);
      if (isspace(ch)) // space
         ch = fgetc(fp);

 //     containsChar(ch);
      
      if (ch == ';'){ //semicolon 
         printf("operator:;\n"); 
         ch = fgetc(fp);
      }
      if (ch ==','){
         printf("operator:,\n");
	 ch = fgetc(fp);
      }
      if (ch =='}'){
         printf("operator:}\n");
         ch = fgetc(fp);
      }
      if (ch =='{'){
         printf("operator:{\n");
         ch = fgetc(fp);
      }
       if (ch ==']'){
         printf("operator:]\n");
         ch = fgetc(fp);
      }
      if (ch =='['){
         printf("operator:[\n");
         ch = fgetc(fp);
      }
      if (ch ==')'){
         printf("operator:)\n");
         ch = fgetc(fp);
      }
      if (ch =='('){
         printf("operator:(\n");
         ch = fgetc(fp);
      }
       if (ch =='!'){
         printf("operator:!\n");
         ch = fgetc(fp);
      }
      if (ch =='&'){
         printf("operator:&\n");
         ch = fgetc(fp);
      }
      if (ch =='%'){
         printf("operator:%c\n",ch);
         ch = fgetc(fp);
      }
      if (ch =='/'){
         printf("operator:/\n");
         ch = fgetc(fp);
      }
      if (ch =='*'){
         printf("operator:*\n");
         ch = fgetc(fp);
      }
      if (ch =='-'){
         printf("operator:-\n");
         ch = fgetc(fp);
      }
      if (ch =='+'){
         printf("operator:+\n");
         ch = fgetc(fp);
      }
      if (ch =='='){
         printf("operator:=\n");
         ch = fgetc(fp);
      }
      if (ch =='<'){
         printf("operator:<\n");
         ch = fgetc(fp);
      }
      if (ch =='>'){
         printf("operator:>\n");
         ch = fgetc(fp);
      }

     // if (isspace(ch) && ch == ' ')
     //    ch = fgetc(fp);
     
     //printf("the char is: %c\n", toascii(ch));
     
   }
}  
/* 
void containsChar(char ch){
   int i;
   char * holder;
   
   for(i = 0; i < 19; i ++){
   holder = operators[i];
   if(strcmp(&ch,holder= 0))
	printf("operator%c\n",ch);
   }
   ch = fgetc(fp);



}*/   
