#ifndef GEN_H
#define GEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

#define COMLEN 5    /*Length for command like ISUB,RASN,...*/
#define ARGLEN 20   /*Length for first,second and third argument*/
#define LABELS 100  /*Number of labels (for jumps) that can use in program*/

/*Pointer to output file.qud*/
extern FILE *quadFile;

/*Type definition of struct command row that have main command and
three arguments.Data Structure of command row is linked list that
collected then yyparse read from file.ou*/
typedef struct commandRow
{
	char com[COMLEN];
	char firstArg[ARGLEN];
	char secondArg[ARGLEN];
	char thirdArg[ARGLEN];
	struct commandRow *next;
} command;

/*Type definition of struct plist collected all commands rows that 
yyparse read from file.ou.Data Structure of plist is linked list too*/
typedef struct plist
{
	command *com;
	struct plist *next;
} commandList;

/*Relop and cast operators*/
enum {equal,notEqual,bigger,smaller,biggerOrEqual,smallerOrEqual,castToInt,castToFloat};

/*Accepts two pointers to heads of command lists
and merged them and return merged command list*/
commandList* mergeLists(commandList*, commandList*);

/*Accepts pointers to command list and row command heads,
merged them and return merged command list with this row command*/
commandList* addCommandToList(commandList*, command*);

/*Accepts pointers two heads commands and merged them and
return merged command */
command* mergeCommands(command*, command*);

/*Accepts pointer to head command and 
return last element of command */
command* getLastCommand(command*);

/*Accepts data of command and create quad command that add to
command list and return pointer to head of this command*/
command* translateCommand(command*, char, char*, char*, char*, char*);

/*Accepts data of assignment command and create quad command that add to
command list and return pointer to head of this command*/
command *addAssignmentCommand(char*, char*, char, command*);

/*Accepts data of arithmetic command and create quad command that add to
command list and return pointer to head of this command*/
command *addArithmeticCommand(char, char, char*, char*, char*, char, char, command*, command*);

/*Accepts data of addop or mulop command and create quad command that add to
command list and return pointer to head of this command*/
command *addAddopMulopCommand(char, command*, char, char*, char*, char*);

/*Accepts data of relop command and create quad command that add to
command list and return pointer to head of this command*/
command *addRelopCommand(int, char*, char*,command*, command*, char);

/*Accepts pointer to head command and temp variable.If command smaller or equal
	program do reverse and to do command bigger and then doing -1 so we accepts
	reverse command smaller or equal what we need*/
command* reverseCommand(command*, char*);

/*Accepts pointer to head of command and create ladel and
	return pointer to command with created label*/
command *addLabel(command*);

/*Accept pointer to command head take last element and convert this
	command to float command and return and converted command*/
command* floatConvert(command*, char*);

/*Accept pointer to command head take last element and convert this
	command to integer command and return and converted command*/
command* intConvert(command*, char*);

/*	Accepts two types and decides which type need to return*/
char typeUpdate(char, char);

/*Accepts number and by this number function tell as if cast is 
float or int.Return number which that point what kind of cast.*/
int cast(int);

/*Accept pointer to list of commands and pointer of label command and
rename first argument of all commands list according to label*/
void updateList(commandList*, command*);

/*Accept pointer to command and
rename his first argument*/
void renameArg(command*, char*);

/*Accept pointer to head of linked list and
prints all list of commands to file.qud*/
void commandsPrint(command*);

/*Accept pointer to head of linked list and
free all list of commands*/
void freeList(command*);

#endif