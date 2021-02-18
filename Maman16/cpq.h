#ifndef CPQ_H
#define CPQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENEXT 3 /*Lenght of file extension*/
#define LEN 100 /*Save place in memory for string*/

/*Numbers '0' and '1'*/
enum { true, false };

/*Type definition of string with error message 100 characters in string*/
typedef char errors[LEN];

/*Definition of four errors messages*/
errors ERR0, ERR1, ERR2, ERR3;

/*Type definition of struct error message that have string with pointer to error message
and pointer to his address in memory that save place array of 100 index's*/
typedef struct
{
	char* string;
	errors* address;
}errMsg;

/*the input stream pointer (i.e it points to an input file which is to be
scanned or tokenised).*/
extern FILE* yyin;

/*it parses function (i.e builds the linked list) of lexeme.*/
extern int yyparse();

/*Variable that check if file .ou have errors*/
extern int errorExist;

FILE* quadFile;/*QUAD file*/

/*Error messages*/
 errMsg messages[] = {
					{"ERROR: cannot open file\n",&ERR0},                              /*message 0*/
					{"ERROR: missing arguments\n",&ERR1},                             /*message 1*/
					{"ERROR: parser error\n",&ERR2},                                  /*message 2*/
					{"ERROR: extension error, must be \".ou\"\n",&ERR3},              /*message 3*/
};

FILE* openFile(char* name, char* type);/*Open file function*/

#endif