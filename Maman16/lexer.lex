%option noyywrap
%{
#include <stdio.h>
#include "symtab.h"
#include "gen.h"
#include "parser.tab.h" 
int line = 1;
%}
%x COMMENT
%%

"{"                                              	{ return '{'; }
"}"            	                                                { return '}';}
"("                                              	{ return '(';}
")"                                              	{ return ')';}
","                                             	{ return ',';}
":"                                               	{ return ':';}
"="				{return '=';}
";"				{ return ';';}

"float"			                {
					yylval.type = 'R';
					return FLOAT;
				}
"int"			                {	
					yylval.type = 'I';
					return INT;
				}
				
"break"			               { return BREAK;}
"if"			               { return IF;}
"case"		                               { return CASE;}
"else"			               { return ELSE;}
"default"		                               { return DEFAULT;}
"output"			               { return OUTPUT;}
"input"			               { return INPUT;}
"switch"			               { return SWITCH;}
"while"			               { return WHILE;}

"=="			                {
					yylval.relop = equal;
					return RELOP;
				}
"!="			                {
					yylval.relop = notEqual;
					return RELOP;
				}
"<"				{
					yylval.relop = smaller;
					return RELOP;
				}
">"				{
					
					yylval.relop = bigger;
					return RELOP;
				}
">="			                {
					
					yylval.relop = biggerOrEqual;
					return RELOP;
				}
"<="			                {
					
					yylval.relop = smallerOrEqual;
					return RELOP;
				}						
"+"				{
					
					yylval.op = '+';
				 	return ADDOP;
				}
"-"				{	
					
					yylval.op = '-';
				 	return ADDOP;
				}
"*"				{	
					
					yylval.op = '*';
					return MULOP;
				}
"/"				{	
					
					yylval.op = '/';
					return MULOP;
				}

"static_cast<int>"			{	
					
					yylval.castOp = castToInt;
					return CAST;
				}
"static_cast<float>"			{	
					
					yylval.castOp = castToFloat;
					return CAST;
				} 

"!"			                { return NOT; }
"||"			                { return OR; }
"&&"			                { return AND; }

[0-9]+"."[0-9]*	                                {
					 
					strncpy(yylval.num.value, yytext, VARLEN);
					yylval.num.type = 'R';
					return NUM;
				}
[0-9]+			                {
					
					strncpy(yylval.num.value, yytext, VARLEN);
					yylval.num.type = 'I';
				 	return NUM;
				}
[a-zA-Z][0-9a-zA-Z]*	                {
					
					if(strlen(yytext) < VARLEN)
						strcpy(yylval.id, yytext);
					else
						printf("illegal identifier, the maximum length of the identifier is 9 characters");
					return ID;
		                              }

"/*"         			            {BEGIN(COMMENT);}
<COMMENT>[^*\n]*                               
<COMMENT>"*"+[^*/\n]*                        
<COMMENT>\n                                      { ++line; }
<COMMENT>"*"+"/"                              {BEGIN(0);}
[ \t]			            
"\n" 			             {line++;  }
. 	    	   	             { fprintf(stderr,"%s unknown token",yytext); }

%%