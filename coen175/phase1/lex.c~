#include <stdio.h>
#include <ctype.h>
#include <string.h>


FILE *fp;
char ch;
//int counter = 0;
// char operators[18] = {"-*/+=%&!()[]{};,<>"};
// char operators[] ={'=','<','>','+','-','*','/','%','&','!','(',')','[',']','{','}',';',','};

char specialops[9][2] = {"||","&&","==","!=","<=",">=","/*","*/"};
char buffer[1000];

void main(int argc, char *argv[]){


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
		int count = 0;
		//reads chars into buffer until theres a whitespace
      while(!isspace(ch)){
      	buffer[count] = ch;
			count++;
      }
		

	//	int i;
//		for(i = 0;i < count; i++){
	//		printf("%c", buffer[count]);
	//	}
	//	printf("\n");
     
	//	count = 0;
   }
}  
 
