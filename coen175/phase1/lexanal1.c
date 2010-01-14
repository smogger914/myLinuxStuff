#include <stdio.h>
#include <ctype.h>
#include <string.h>


   FILE *fp;
   char ch;
   int asci;
   char storage[1000];

  // char operators[18] = {"-*/+=%&!()[]{};,<>"};
  // char operators[] = {'=','<','>','+','-','*','/','%','&','!','(',')','[',']','{','}',';',','};
 // char specialops[8][2]= {"||","&&","==","!=","<=",">=","/*","*/"};
  // void containsChar(char);
int main(int argc, char *argv[]){


   fp=fopen("fib.c","r");   //sourcepath
   if(fp==NULL)
   {
	 printf("Can't open input file!");
  	 return(0);
   }
   int counter = 0;
   //get input from file
   while(!feof(fp))  //While the file is not end.
   {
      

      ch = fgetc(fp);
      if(ch == EOF){
	 return(0);
      }
     // if (ch == ' '){ //space go to next one
     //    ch = fgetc(fp);
     //    counter = 0;
     // }
      if (isspace(ch)){ // space
         ch = fgetc(fp);
         counter = 0;
      }
      
      storage[counter] = ch;
      counter++;
       
      int k;
 //     for(k = 0; k < counter; k++){
//	if(strcmp(storage[],specialops[k][])) 
   //   }
   

//      int i; 
  //    for(i = 0; i<counter;i++){
    //     printf("%c",storage[i]);
     // }
     // printf("\n");

      
 //     containsChar(ch);
      /*
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
     */
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
