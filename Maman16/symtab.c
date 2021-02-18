#include "symtab.h"

int varCounter = 1;
varNode *head = NULL;
char* symtabError = "ERROR: This ame of variable exist in symbol table\n";

/*Accepts type it can be float or integer and
create temporary variable like t1,t2...,return
pointer to node in tree with new temporary variable*/
varNode* createTempVar(char type)
{
	char name[VARLEN];
	varNode* newTemp;

	newTemp = searchFreeVar(type, head);
	if (!newTemp || newTemp->state == FREE)
	{
		sprintf(name, "t%d", varCounter);
		newTemp = addTempVar(name, type);
		++varCounter;
	}
	newTemp->state = SAVE;
	return newTemp;
}

/*Accepts name and type and add temporary variabele
to binary search tree or in other words to symbol table,
return pointer to node in tree with new temporary variable.*/
varNode* addTempVar(char* name, char type)
{
	varNode* newTemp, *prev;

	if (!head)
	{
		head = (varNode*)malloc(sizeof(varNode));
		newTemp = head;
	}
	else
	{
		newTemp = (varNode*)malloc(sizeof(varNode));
		prev = searchLocation(name, head);
		if (strcmp(prev->name, name) < 0)
			prev->right = newTemp;
		else
			prev->left = newTemp;
	}
	sprintf(newTemp->name, "%s", name);
	newTemp->left = NULL;
	newTemp->right = NULL;
	newTemp->type = type;
	newTemp->state = LOCK;
	newTemp->flag = 1;
	return newTemp;
}

/*Accepts name  and add  variable to binary search tree
without type or in other words to symbol table,
return pointer to node in tree with new variable without type.*/
varNode *addVarName(char* name)
{
	varNode *newVarName, *prev;

	if (!head)
	{
		head = (varNode*)malloc(sizeof(varNode));
		newVarName = head;
	}
	else
	{
		newVarName = (varNode*)malloc(sizeof(varNode));
		prev = searchLocation(name, head);
		if (strcmp(prev->name, name) < 0)
			prev->right = newVarName;
		else
			prev->left = newVarName;
	}
	sprintf(newVarName->name, "%s", name);
	newVarName->left = NULL;
	newVarName->right = NULL;
	newVarName->state = LOCK;
	newVarName->flag = 0;
	return newVarName;
}

/*Accepts type  and pointer to node in tree and add to all variables without
type in binary search tree type which function accept,
return pointer to node in tree to variable with type was added.*/
varNode* addVarType(char type, varNode* curr)
{

	if (curr)
	{
		addVarType(type, curr->left);
		if (curr->flag == 0) {
			curr->type = type;
			curr->flag = 1;
		}
		addVarType(type, curr->right);
	}
	return curr;
}

/*Accepts name  and add  variable to binary search tree
without type or in other words to symbol table.*/
void setVarName(char *name)
{
	if(!searchVar(name))
		addVarName(name); 
	else
		printf(symtabError);
}

/*Accepts type  and tree and add to all variables without
type in binary search tree type which function accept.*/
void setVarType(char type)
{
	varNode* curr = head;
    addVarType(type, curr);		
}

/*Accepts name and search this name in binary search tree
or in other words in symbol table,return pointer to node with
this variable name or if not exist null.*/
varNode *searchVar(char *name)
{
	varNode *curr = head;
	
	while(curr)
	{
		if(!strcmp(curr->name, name))
			return curr;
		else if(strcmp(curr->name, name) < 0)
			curr=curr->right;
		else
			curr=curr->left;
	}
	return NULL;
}

/*Accepts type and pointer to the tree and search variable
with this type and state FREE and return tree pointer to node with
FREE state variable if not found return null */
varNode *searchFreeVar(char type, varNode *curr)
{
	varNode *freeVar;
	
	if(!curr)
		return NULL;
	if(curr->state == FREE && curr->type == type)
		return curr;
	if((freeVar = searchFreeVar(type,curr->left)))
		return freeVar;
	return searchFreeVar(type,curr->right);
}

/*Accepts name and pointer to the tree and search location
for new variable and return pointer to this node where
will be this variable. */
varNode *searchLocation(char *name, varNode *curr)
{	
	if(!curr)
		return NULL;
	if(strcmp(curr->name, name) < 0)
	{
		if(curr->right)
			return searchLocation(name,curr->right);
		return curr;
	}
	if(curr->left)
		return searchLocation(name,curr->left);
	return curr;
}

/*Accepts name of variable and him to state FREE*/
void freeState( char *name )
{
	varNode *curr = NULL;
		
	if( (curr = searchVar(name)) && curr->state == SAVE )
			curr->state = FREE;
}

/*Accept pointer to node and free this node*/
void freeVar(varNode* curr)
{
	if (curr)
	{
		freeVar(curr->right);
		freeVar(curr->left);
		free(curr);
	}
}

/*Free all tree of vaiables*/
void freeTree()
{	
	freeVar(head);
}


