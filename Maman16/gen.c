#include "gen.h"

#define ERRLEN 100 /*Save place in memory for string*/
#define CHAR 1 /*Save place in memory for char*/
#define STR 4 /*Save place in memory for char*/

/*Type definition of string with error message 100 characters in string*/
typedef char genErrors[ERRLEN];

/*Type definition of string with error message 100 characters in string*/
typedef char chars[CHAR];

/*Type definition of string with error message 100 characters in string*/
typedef char strings[STR];


/*Definition of two errors messages*/
genErrors GENERR0, GENERR1;

/*Definition of five chars*/
chars CHAR0, CHAR1, CHAR2, CHAR3, CHAR4, CHAR5 ;

/*Definition of two chars*/
strings STR0, STR1, STR2, STR3, STR4, STR5, STR6, STR7, STR8, STR9, STR10, STR11, STR12, STR13;

/*Type definition of struct error message that have string with pointer to error message
and pointer to his address in memory that save place array of 100 index's*/
typedef struct
{
	char charCmd;
	chars* charAddress;
}charCmd;

/*Type definition of struct error message that have string with pointer to error message
and pointer to his address in memory that save place array of 100 index's*/
typedef struct
{
	char* stringCmd;
	strings* strAddress;
}strCmd;

/*Type definition of struct error message that have string with pointer to error message
and pointer to his address in memory that save place array of 100 index's*/
typedef struct
{
	char* genString;
	genErrors* genAddress;
}errGenMsg;

/*Error messages*/
errGenMsg genMessages[] = {
				   {"ERROR: unknown variable, not defined in the symbol table\n",&GENERR0},       /*message 0*/
				   {"ERROR: illegal assignment, from float to integer\n",&GENERR1},               /*message 1*/
				                                                        
};

/*Chars*/
charCmd genChars[] = {
				   {'I',&CHAR0},               /*char 0*/
				   {'R',&CHAR1},              /*char 1*/
				   {'N',&CHAR2},              /*char 2 */
				   {'E',&CHAR3},              /*char 3*/
				   {'*',&CHAR4},              /*char 4*/
				   {'J',&CHAR5}              /*char 5*/
};

/*Strings*/
strCmd genStrings[] = {
				   {"",&STR0},               /*string 0*/
				   {"1",&STR1},              /*string 1*/
				   {"TOR",&STR2},              /*string 2 */
				   {"ASN",&STR3},              /*string 3*/
				   {"TOI",&STR4},              /*string 4*/
				   {"ADD",&STR5},              /*string 5*/
				   {"SUB",&STR6},              /*string 6*/
				   {"DIV",&STR7},              /*string 7*/
				   {"MLT",&STR8},              /*string 8*/
				   {"EQL",&STR9},              /*string 9*/
				   {"NQL",&STR10},              /*string 10*/
				   {"GRT",&STR11},              /*string 11*/
				   {"LSS",&STR12},              /*string 12*/
	               {"MPZ",&STR13},              /*string 13*/            
};

int labelsCount = 0;

/*Accepts two pointers to heads of command lists
and merged them and return merged command list*/
commandList* mergeLists(commandList* head, commandList* tail)
{
	commandList* last = head;

	if (!head)
		return tail;
	while (last->next)
		last = last->next;
	last->next = tail;
	return head;
}

/*Accepts pointers to command list and row command heads,
merged them and return merged command list with this row command*/
commandList* addCommandToList(commandList* list, command* com)
{
	commandList* prevCommand;

	if (!list)
	{
		list = (commandList*)malloc(sizeof(commandList));
		list->next = NULL;
		list->com = com;
		return list;
	}
	prevCommand = (commandList*)malloc(sizeof(commandList));
	prevCommand->next = list;
	prevCommand->com = com;
	return prevCommand;
}

/*Accepts pointers two heads commands and merged them and
return merged command */
command* mergeCommands(command* head, command* tail)
{
	command* lastCommand;

	if (!head)
		return tail;
	lastCommand = getLastCommand(head);
	lastCommand->next = tail;
	return head;
}

/*Accepts pointer to head command and
return last element of command */
command *getLastCommand(command *head)
{
	command *lastCommand = head;
	while(lastCommand->next)
		lastCommand = lastCommand->next;
	return lastCommand;
}

/*Accepts data of command and create quad command that add to
command list and return pointer to head of this command*/
command *translateCommand(command *head, char type, char *com, char *firstArg, char* secondArg, char *thirdArg)
{
	command *newCommand, *prevCommand;

  if( !head )
	{
		head = (command *)malloc(sizeof(command));
		newCommand = head;
	}
	else
	{
		prevCommand = getLastCommand( head );
		newCommand = (command *)malloc(sizeof(command));
		prevCommand->next = newCommand;
	}
	sprintf(newCommand->com, "%c%s", type, com);
	sprintf(newCommand->firstArg, "%s", firstArg);
	sprintf(newCommand->secondArg, "%s", secondArg);
	sprintf(newCommand->thirdArg, "%s", thirdArg);
	newCommand->next = NULL;
	return head;
}

/*Accepts data of assignment command and create quad command that add to
command list and return pointer to head of this command*/
command* addAssignmentCommand(char* var, char* exp, char expType, command* expHead)
{
	varNode* symbol = NULL;
	command* head = NULL;
	freeState(exp);
	if (!(symbol = searchVar(var)))
		printf(genMessages[0].genString);
	else if (symbol->type == genChars[0].charCmd && expType == genChars[1].charCmd)
		printf(genMessages[1].genString);
	else
	{
		if (symbol->type == genChars[1].charCmd && expType == genChars[0].charCmd)
			return translateCommand(expHead, genChars[0].charCmd, genStrings[2].stringCmd, var, exp, genStrings[0].stringCmd);
		if (!expHead)
			return translateCommand(NULL, symbol->type, genStrings[3].stringCmd, var, exp, genStrings[0].stringCmd);
		renameArg(getLastCommand(expHead), var);
		return expHead;
	}
	return NULL;
}

/*Accepts data of arithmetic command and create quad command that add to
command list and return pointer to head of this command*/
command* addArithmeticCommand(char op, char type, char* last, char* firstArgLast, char* secondArgLast, char firstType, char secondType, command* firstHead, command* secondHead)
{
	command* head = NULL;
	varNode* symbol;
	if (firstType == genChars[0].charCmd && secondType == genChars[1].charCmd) 
		firstHead = floatConvert(firstHead, firstArgLast);
	else if (secondType == genChars[0].charCmd && firstType == genChars[1].charCmd)
		secondHead = floatConvert(secondHead, secondArgLast);
	freeState(firstArgLast);
	freeState(secondArgLast);
	head = mergeCommands(firstHead, secondHead);
	symbol = createTempVar(type);
	strcpy(last, symbol->name);
	return addAddopMulopCommand(op, head, type, symbol->name, firstArgLast, secondArgLast);

}

/*Accepts data of addop or mulop command and create quad command that add to
command list and return pointer to head of this command*/
command* addAddopMulopCommand(char op, command* head, char type, char* firstArg, char* secondArg, char* thirdArg)
{
	switch (op)
	{
	case '+':
		return translateCommand(head, type, genStrings[5].stringCmd, firstArg, secondArg, thirdArg);
	case '-':
		return translateCommand(head, type, genStrings[6].stringCmd, firstArg, secondArg, thirdArg);
	case '/':
		return translateCommand(head, type, genStrings[7].stringCmd, firstArg, secondArg, thirdArg);
	default:
		return translateCommand(head, type, genStrings[8].stringCmd, firstArg, secondArg, thirdArg);
	}
}

/*Accepts data of relop command and create quad command that add to
command list and return pointer to head of this command*/
command* addRelopCommand(int relopType, char* firstVar, char* secondVar, command* firstHead, command* secondHead, char compareType)
{
	command* head;
	varNode* var;
	head = mergeCommands(firstHead, secondHead);
	freeState(firstVar);
	freeState(secondVar);
	var = createTempVar(genChars[0].charCmd);
	switch (relopType)
	{
	case equal:
		head = translateCommand(head, compareType, genStrings[9].stringCmd, var->name, firstVar, secondVar);
		break;
	case notEqual:
		head = translateCommand(head, compareType, genStrings[10].stringCmd, var->name, firstVar, secondVar);
		break;
	case bigger:
		head = translateCommand(head, compareType, genStrings[11].stringCmd, var->name, firstVar, secondVar);
		break;
	case smaller:
		head = translateCommand(head, compareType, genStrings[12].stringCmd, var->name, firstVar, secondVar);
		break;
	case biggerOrEqual:
		head = translateCommand(head, compareType, genStrings[12].stringCmd, var->name, firstVar, secondVar);
		head = reverseCommand(head, var->name);
		break;
	case smallerOrEqual:
		head = translateCommand(head, compareType, genStrings[11].stringCmd, var->name, firstVar, secondVar);
		head = reverseCommand(head, var->name);
		break;
	}
	head = translateCommand(head, genChars[5].charCmd, genStrings[13].stringCmd, genStrings[0].stringCmd, var->name, genStrings[0].stringCmd);
	freeState(var->name);
	return head;
}

/*Accepts pointer to head command and temp variable.If command smaller or equal
	program do reverse and to do command bigger and then doing -1 so we accepts 
	reverse command smaller or equal what we need*/
command* reverseCommand(command* head, char* lastVar)
{
	command* last = NULL;

	last = getLastCommand(head);
	if (!strcmp(last->com + 1, genStrings[9].stringCmd))
	{
		*((last->com) + 1) = genChars[2].charCmd;
	}
	else if (!strcmp(last->com + 1, genStrings[10].stringCmd))
	{
		*((last->com) + 1) = genChars[3].charCmd;
	}
	else
	{
		head = translateCommand(head, genChars[0].charCmd, genStrings[6].stringCmd, lastVar, genStrings[1].stringCmd, lastVar);
	}
	return head;
}

/*Accepts pointer to head of command and create ladel and
	return pointer to command with created label*/
command *addLabel(command *head)
{
	char buffer[ARGLEN];
	
	labelsCount++;
	itoa(labelsCount,buffer,ARGLEN);
	return translateCommand(head,genChars[4].charCmd, buffer, genStrings[0].stringCmd, genStrings[0].stringCmd, genStrings[0].stringCmd);
}

/*Accept pointer to command head take last element and convert this
	command to float command and return and converted command*/
command* floatConvert(command* head, char* last)
{
	varNode* commandName;

	commandName = createTempVar(genChars[1].charCmd);
	head = translateCommand(head, genChars[0].charCmd, genStrings[2].stringCmd, commandName->name, last, genStrings[0].stringCmd);
	freeState(last);
	strcpy(last, commandName->name);
	return head;
}

/*Accept pointer to command head take last element and convert this
	command to integer command and return and converted command*/
command* intConvert(command* head, char* last)
{
	varNode* commandName;

	commandName = createTempVar(genChars[0].charCmd);
	head = translateCommand(head, genChars[1].charCmd, genStrings[4].stringCmd, commandName->name, last, genStrings[0].stringCmd);
	freeState(last);
	strcpy(last, commandName->name);
	return head;
}

/*	Accepts two types and decides which type need to return*/
char typeUpdate(char type1, char type2)
{
	if (type1 == genChars[1].charCmd || type2 == genChars[1].charCmd)
		return genChars[1].charCmd;
	return genChars[0].charCmd;
}

/*Accepts number and by this number function tell as if cast is
float or int.Return number which that point what kind of cast.*/
int cast(int castOp)
{
	int number = 0;
	switch (castOp)
	{
	case castToInt:
		number = 1;
		break;
	case castToFloat:
		number = 2;
		break;
	}
	return number;
}

/*Accept pointer to list of commands and pointer of label command and
rename first argument of all commands list according to label*/
void updateList(commandList* head, command* label)
{
	commandList* next;

	while (head)
	{
		next = head->next;
		renameArg(head->com, label->com);
		free(head);
		head = next;
	}
}

/*Accept pointer to command and
rename his first argument*/
void renameArg(command* com, char* newArg)
{
	freeState(com->firstArg);
	sprintf(com->firstArg, "%s", newArg);
}

/*Accept pointer to head of linked list and
prints all list of commands to file.qud*/
void commandsPrint(command* head)
{
	int commandsCounter = 1;
	int lables[LABELS];
	command* start = head;

	while (start)
	{
		if (*(start->com) == genChars[4].charCmd)
		{
			lables[atoi(1 + start->com)] = commandsCounter;
		}
		else
			++commandsCounter;
		start = start->next;
	}
	while (head)
	{
		if (*(head->com) != genChars[4].charCmd)
		{
			if (*(head->firstArg) == genChars[4].charCmd)
				sprintf(head->firstArg, "%d", lables[atoi(1 + head->firstArg)]);
			fprintf(quadFile, "%s\t%s\t%s\t%s\n", head->com, head->firstArg, head->secondArg, head->thirdArg);
		}
		head = head->next;
	}
}

/*Accept pointer to head of linked list and
free all list of commands*/
void freeList(command *head)
{
	command *current = head;
	
	while(head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}