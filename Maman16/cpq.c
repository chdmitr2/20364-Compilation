#include "cpq.h"

/*This program accepts from stdin (file.ou) commands
which translates from CPL language to QUAD language.
It is take from file "input" each command and check 
if command of CPL language correntness in file by
parser and lexer (flex & bison).If it not, 
program send error message .The program  exit when accept  
command "HALT" from the file which writed in end of file input.
In this file the program is starts and take from file 
command if command exist it's going to function
of this command execute operation which translate to QUAD
 language and print this commands to output file .qud.*/
int main(int argc, char* argv[])
{
	char* name, *ext = NULL; 
    if(argc != 2)
    {
        fprintf(stderr, messages[1].string);
		return false;
    }
	name = argv[1];
	ext = argv[1] + strlen(argv[1]) - LENEXT;
	if (!strcmp(ext, ".ou") || !strcmp(ext, ".OU"))
	{
		if(!(yyin = openFile(argv[1], "r")))
			return false;
		
		strcpy(ext,".qud");
		
		if(!(quadFile = openFile(name, "w")))
			return false;
			
		if(yyparse() || errorExist)
		{
			fclose(quadFile);
			remove(name);
			fprintf(stderr, messages[2].string);
		}
		fclose(yyin);
		fclose(quadFile);
		
		
		return true;
	}
	fprintf(stderr, messages[3].string);
    return false;
}

/*Open file function*/
FILE* openFile(char* name, char* type)
{
	FILE* file = NULL;
	file = fopen(name, type);
	if (file == NULL)
	{
		fprintf(stderr, messages[0].string);
	}
	return file;
}

