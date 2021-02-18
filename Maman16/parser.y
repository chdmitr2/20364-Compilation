%{

#include <stdio.h>
#include <malloc.h>
#include "symtab.h"
#include "gen.h"

extern int yylex (void);
int yyerror(char *s);
extern int line;

int number = 0;
int errorExist = 0;
varNode *currentVar = NULL, *nextVar = NULL;
command *currentCommand = NULL;
commandList *tempList = NULL;
char *num = NULL;
int p = 0;
char casevalue[10] ;
%}
%error-verbose

%union
{
	struct number {
		          char value[VARLEN];
		          char type;
	                        } num;

               struct exp {
		    command *head;
                                     commandList *false;
		    char last[VARLEN];
		    char type;
	                 } expression;
	
	struct bool {
		       commandList *false;
		       command *head;
	                   } boolean;

	char id[VARLEN];	
	char type;
	char op; 
                char castOp;	
	 command *stmt;	
	int relop; 
}

%type <type> type

%type <expression> expression				
%type <expression> term			
%type <expression> factor

%type <boolean> boolfactor		
%type <boolean> boolexpr
%type <boolean> boolterm

%type <stmt> output_stmt
%type <stmt> assignment_stmt
%type <stmt> input_stmt
%type <stmt> stmt
%type <stmt> if_stmt
%type <stmt> break_stmt
%type <stmt> switch_stmt
%type <stmt> stmt_block
%type <stmt> while_stmt
%type <stmt> stmtlist
%type <stmt> caselist

%token <id> ID
%token CASE
%token <type>INT
%token <type>FLOAT
%token OUTPUT
%token INPUT
%token IF
%token ELSE
%token SWITCH
%token WHILE
%token DEFAULT
%token BREAK
%token <op>ADDOP
%token <num>NUM
%token <op>MULOP
%token  <castOp> CAST
%token OR
%token AND
%token NOT
%token <relop>RELOP


%%
program                                             :      declarations  stmt_block
                                                                                                               {
					                                  $2 = translateCommand($2,'H',"ALT","","","");
					                                   commandsPrint($2);
					                                   freeTree();
					                                   freeList($2);
				                                                }
                                                           ;

declarations                                       :      declarations  declaration 
                                                          |       /*empty*/
                                                          ;

declaration                                        :     idlist    ':'  type       { setVarType($3);}  ';'   ;
                                                                    

type                                                   :       INT {$$ = $1;}
                                                          |       FLOAT {$$ = $1;}
                                                          ;

idlist                                                  :       idlist  ','  ID { setVarName($3);}
                                                          |       ID { setVarName($1);}
                                                          ;

stmt                                                   :      assignment_stmt {$$ = $1;}
                                                          |       input_stmt {$$ = $1;}
                                                          |       output_stmt {$$ = $1;}
                                                          |       if_stmt {$$ = $1;}
                                                          |       while_stmt {$$ = $1;}
                                                          |       switch_stmt {$$ = $1;}
                                                          |       break_stmt {$$ = $1;}
                                                          |       stmt_block {$$ = $1;}
                                                          ;

assignment_stmt                                :  ID  '='  expression  ';' { $$ = addAssignmentCommand($1, $3.last, $3.type, $3.head);} 
                                                            ;

input_stmt                                          :      INPUT  '('  ID  ')'   ';'  
                                                                                                     {
					                       $$ = NULL;
					                        if(!(currentVar = searchVar($3)))
						                   fprintf(stderr,"ERROR: unknown variable, not defined in the symbol table");
					                        else
						            $$ = translateCommand(NULL,currentVar->type,"INP",currentVar->name,"","");
				                                      }
			          
                                                           ;

output_stmt                                        :     OUTPUT  '('  expression  ')'   ';'
                                                                                                                          {
					                                             $$ = translateCommand($3.head,$3.type,"PRT",$3.last,"","");		
					                                              freeState($3.last);
				                                                           }			          
			             ; 

if_stmt                                                  :    IF  '('  boolexpr  ')'  stmt  ELSE  stmt 
                                                                                           {	
						$$ = mergeCommands($3.head, $5);
						$$ = translateCommand($$,'J',"UMP","","","");
						tempList = addCommandToList(NULL, getLastCommand($$)); 
						$$ = addLabel($$);
						updateList($3.false,getLastCommand($$));
						$$ = mergeCommands($$, $7);
						$$ = addLabel($$);
						updateList(tempList, getLastCommand($$));
					           }
                                                           ;

while_stmt                                         :     WHILE  '('  boolexpr  ')'  stmt
                                                                                 {
						$$ = addLabel(NULL);
						$$ = mergeCommands($$, $3.head);
						$$ = mergeCommands($$, $5);
						$$ = translateCommand($$,'J',"UMP","","","");
			                                                tempList = addCommandToList(NULL, getLastCommand($$));
						updateList(tempList, $$);
						$$ = addLabel($$);
						updateList($3.false, getLastCommand($$));
					}
                                                                ;

switch_stmt                                       :    SWITCH  '('  expression  ')'   '{'  caselist  DEFAULT  ':'  stmtlist  '}'
                                                                               {  
                                                                                          
                                                                                     nextVar = createTempVar( currentVar->type );
                                                                                    currentCommand =  translateCommand(currentCommand, 'J', "MPZ", "",  nextVar->name, "");                                                                                                   
                                                                                    $3.head = mergeCommands(currentCommand  , $3.head);
                                                                                     tempList = addCommandToList(NULL, getLastCommand($3.head)); 
				                     $3.head = addLabel($3.head);
				                     updateList(tempList, getLastCommand($3.head)); 
                                                                                     currentCommand = NULL;
                                                                                       *num = casevalue[0];
                                                                                     currentCommand =  translateCommand(currentCommand, currentVar->type, "EQL", currentVar->name, nextVar->name, num);                                                                                    
                                                                                      $3.head =mergeCommands(currentCommand , $3.head);  
                                                                                      $$ = mergeCommands($3.head , $6);  
                                                                                      $$ = translateCommand($$,'J',"UMP","","","");   
                                                                                      tempList = addCommandToList(NULL, getLastCommand($$));                                                                                                   
				                      $$ = mergeCommands($$, $9);
				                                  $$ = addLabel($$);
						                updateList(tempList, getLastCommand($$));   
					}  
                                                                              
                                                           ;

caselist                                              :     caselist  CASE  NUM  ':'  stmtlist {                                                                                                                          
					                                          num = $3.value;                                                                                                                        
                                                                                                                         casevalue[p] = *num;                                                                                                                     
					                                           p++ ;		                                                                                                      
                                                                                                                        nextVar= createTempVar( currentVar->type ); 
                                                                                                                      $$ = translateCommand($$, currentVar->type, "EQL", currentVar->name, nextVar->name, num);                                                                                                     
                                                                                                                      $$ = translateCommand($$, 'J', "MPZ", "", nextVar->name, "");   
                                                                                                                              tempList  = addCommandToList(NULL, getLastCommand($$)); 
					                       	$$ = addLabel($$);
						                updateList(tempList, getLastCommand($$));                                                 
                                                                                                                       $$ = mergeCommands($1, $5);                                                                             
						                       $$ = translateCommand($$,'J',"UMP","","","");
						                       tempList = addCommandToList(NULL, getLastCommand($$));
                                                                                                                      $$ = addLabel($$);
						                updateList(tempList, getLastCommand($$));    
						                      
                          
                                                                                                                                           } 
                                                           |     /*empty*/  {$$ = NULL;}

                                                           ;

break_stmt                                         :     BREAK  ';' {$$ = NULL;} ; 

stmt_block                                         :     '{'  stmtlist  '}'  {$$ = $2;}
                                                           ; 

stmtlist                                               :      stmtlist  stmt    {$$ = mergeCommands($1, $2);} 
                                                          |       /*empty*/          {$$ = NULL;}

        
                                                          ;

boolexpr                                            :      boolexpr  OR  boolterm
                                                                                                       {
					                         $$.head = translateCommand($1.head,'J',"UMP","","","");
					                          tempList = addCommandToList(NULL, getLastCommand($$.head));
					                         $$.head = addLabel($$.head);
					                         updateList($1.false, getLastCommand($$.head));
					                         $$.head = mergeCommands($$.head, $3.head);
					                         addLabel($$.head);
					                         updateList(tempList, getLastCommand($$.head));
					                         $$.false = $3.false;
				                                        }
                                                          |      boolterm
                                                                               {
					 $$.head = $1.head;
					 $$.false = $1.false;
				               }
                                                          ;

boolterm                                            :      boolterm  AND  boolfactor
                                                                                                            {
					                              $$.head = mergeCommands($1.head,$3.head);
					                              $$.false = mergeLists($1.false, $3.false);
				                                             }
                                                          |       boolfactor
                                                                                   {
					     $$.false = $1.false;
					     $$.head = $1.head;
				                   }
                                                          ;

boolfactor                                          :       NOT  '('  boolexpr  ')'
                                                                                                                 {
					                                    $$.head = translateCommand($3.head,'J',"UMP","","","");
					                                    $$.false = addCommandToList(NULL,  getLastCommand($$.head));
					                                    addLabel($$.head);
					                                    updateList($3.false,  getLastCommand($$.head));
				                                                 }

                                                          |       expression  RELOP  expression
                                                                                                                                 {
					                                                    if($1.type == 'I' && $3.type == 'R') 
						                                    $1.head = floatConvert($1.head, $1.last);
					                                                    else if($3.type == 'I' && $1.type == 'R')
						                                    $3.head = floatConvert($3.head, $3.last);
					                                                    $$.head = addRelopCommand($2, $1.last, $3.last, $1.head, $3.head, typeUpdate($1.type, $3.type));
					                                                    $$.false = addCommandToList(NULL, getLastCommand($$.head));
				                                                                  }
                                                          ;

expression                                         :       expression  ADDOP  term
                                                                                                                 {				
					                                   $$.type = typeUpdate($1.type, $3.type);
					                                   $$.head = addArithmeticCommand($2, $$.type, $$.last, $1.last, $3.last, $1.type, $3.type, $1.head, $3.head);
				                                                 }
                                                          |       term
                                                                                                                {
					                                  $$.type = $1.type;
					                                  $$.head = $1.head;
					                                  strcpy($$.last, $1.last);
				                                                }
                                                          ;

term                                                   :       term  MULOP  factor
                                                                                                      {
					                         $$.type = typeUpdate($1.type, $3.type);
					                         $$.head = addArithmeticCommand($2, $$.type, $$.last, $1.last, $3.last, $1.type, $3.type, $1.head, $3.head);
				                                      }

                                                          |       factor
                                                                           {
				              $$.type = $1.type;
				              $$.head = $1.head;
				               strcpy($$.last, $1.last);
				           }
                                                          ;

factor                                                 :       '('  expression  ')'
                                                                                              {

					                  $$.type = $2.type;
					                  $$.head = $2.head;
					                   strcpy($$.last,$2.last);
				                              } 

                                                          |      CAST  '('  expression  ')' {
                                                                                                            number = cast($1);
                                                                                                            if(number == 1 && $3.type == 'R'){
                                                                                                                     $$.head = intConvert($3.head, $3.last);                                                                                                                     
                                                                                                                      $$.type == 'I';
                                                                                                               } else if (number == 2 && $3.type == 'I') {
                                                                                                                     $$.head = floatConvert($3.head, $3.last);                                                                                                                    
                                                                                                                       $$.type == 'R';

                                                                                                               } 
                                                                                                                  else { 
                                                                                                                           $$.type = $3.type;                                                                                                             
					                                           $$.head = $3.head; 
                                                                                                                          }
					                              strcpy($$.last,$3.last);
				                                          } 

                                                          |       ID
                                                                      {
				         $$.head = NULL;
			                         if(!(currentVar = searchVar($1))) 
			                           {
				             fprintf(stderr,"ERROR: unknown variable, not defined in the symbol table");
				             $$.type = 0;
			                            }
				         else
				            {
						strcpy($$.last, $1);
						$$.type = currentVar->type;
				             }
				       }

                                                          |       NUM
                                                                           {
					strcpy($$.last, $1.value);
					$$.type = $1.type;
					$$.head = NULL;
				           }
                                 	
%%

int yyerror(char *err)
{
	fprintf(stderr, "ERROR: line %d: %s\n", line,  err);
	errorExist = 1;
	return 1;
}
