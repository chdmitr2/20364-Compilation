%{
#include "parse.tab.h"
#include <stdbool.h> 
extern int atoi (const char *);
extern void exit (int);
%}

%%
 
[0-9]+                { yylval.ival = atoi(yytext) ; return NUMBER;}

[\n\t ]+                /*skip white space */

"sum_odd"         {yylval.treeAttr = SUM_ODD; return SUM_ODD;}

"sum_even"       {yylval.treeAttr = SUM_EVEN; return SUM_EVEN;}

"size"                 {yylval.treeAttr = SIZE; return SIZE;}

"ignore"                {yylval.treeAttr = IGNORE; return IGNORE;}

"("                      {return '(' ; }

")"                      {return ')' ; }

.                        { fprintf (stderr, "unrecognized token %c\n", yytext[0]); }

%%



