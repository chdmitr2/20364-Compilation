#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*length of variable*/
#define VARLEN 20

/*States of variables:
FREE - variable not in use
SAVE - variable not in use but it will be in use
LOCK - variable in use*/
enum { FREE , SAVE , LOCK };

/*Type definition of struct symbol table that have variables.Every varible have a state
that say if we can use this variable or not.Data Structure of symbol table is 
search binary tree that give a simple search of variable what we need*/
typedef struct node{
	char name[VARLEN];
	char type;
	int state;
	int flag ;
	struct node *left;
	struct node *right;
} varNode;

/*Accepts type it can be float or integer and
create temporary variable like t1,t2...,return 
pointer to node in tree with new temporary variable*/
varNode *createTempVar(char);

/*Accepts name and type and add temporary variabele
to binary search tree or in other words to symbol table,
return pointer to node in tree with new temporary variable.*/
varNode *addTempVar(char*, char);

/*Accepts name  and add  variable to binary search tree
without type or in other words to symbol table,
return pointer to node in tree with new variable without type.*/
varNode *addVarName(char*);

/*Accepts type  and tree and add to all variables without
type in binary search tree type which function accept,
return pointer to node in tree to variable with type was added.*/
varNode *addVarType(char, varNode*);

/*Accepts name  and add  variable to binary search tree
without type or in other words to symbol table.*/
void setVarName(char*);

/*Accepts type  and tree and add to all variables without
type in binary search tree type which function accept.*/
void setVarType(char);

/*Accepts name and search this name in binary search tree
or in other words in symbol table,return pointer to node with
this variable name or if not exist null.*/
varNode *searchVar(char*);

/*Accepts type and pointer to the tree and search variable
with this type and state FREE in the tree pointer to node with
this variable if not found return null */
varNode *searchFreeVar(char, varNode*);

/*Accepts name and pointer to the tree and search location
for new variable and return pointer to this node where
will be this variable. */
varNode *searchLocation(char*, varNode*);

/*Accepts name of variable and him to state FREE*/
void freeState(char*);

/*Accept pointer to node and free this node*/
void freeVar(varNode*);

/*Free all tree of vaiables*/
void freeTree();

#endif