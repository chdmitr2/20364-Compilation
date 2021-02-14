%{
#include <stdio.h>

extern int yylex (void);
void copy_array(int[],int[]);
void add(int[],int);
int sum_odd(int[]);
int sum_even(int[]) ;
void yyerror (char*);

%}

%code requires {
    struct treelist {
         int nodeCount ;
         int list[100] ; 
    };
}

%code requires {
    struct tree {
          int value; 
          int size; 
    };
}

%union{
               int ival;
               int treeAttr;
               struct tree tree ;
               struct treelist treelist ;                          
             }

%start S
%token <treeAttr> SUM_ODD
%token <treeAttr> SUM_EVEN
%token <treeAttr> SIZE
%token  <treeAttr> IGNORE
%token <ival> NUMBER
%type <tree> tree;
%type <treelist> treelist;

%error-verbose

%%

S          :           tree  { 
                                    if($1.value==0)   printf ("Wrong tree built!!!\n");
                                   else printf ("value of tree is %d\n", $1.value);
                                 }
                       ;

tree      :            SUM_ODD '(' treelist ')'    {  if ($1 == SUM_ODD) 
                                                                                 {                                                                                   
                                                                                   $$.size = $3.nodeCount ;
                                                                                   $$.value = sum_odd($3.list);
                                                                                  } 
                                                                   }
 
                       | SUM_EVEN '(' treelist ')'   {  if ($1 == SUM_EVEN) 
                                                                     {                                                                                        
                                                                                 $$.size = $3.nodeCount ;
                                                                                 $$.value = sum_even($3.list);   
                                                                      }
                                                                   }

                       | SIZE '('  treelist ')'          {  if ($1 == SIZE) 
                                                                     {                                                                            
                                                                            $$.size = $3.nodeCount + 1 ;
                                                                            $$.value = $$.size ;                                                                                                                                          
                                                                     } 
                                                               }

                       | IGNORE '(' treelist ')'      {  if ($1 == IGNORE) 
                                                                    {                                                                                  
                                                                            $$.size =  0;
                                                                            $$.value =  0;                                                                            
                                                                    }
                                                               }

                       | NUMBER                       {  if ($1 == NUMBER) 
                                                                    {                                                                              
                                                                            $$.size = 1;
                                                                            $$.value = $1;
                                                                    }   
                                                               }
                       ;

treelist  :        treelist  tree                 
                                                               {                                                                        
                                                                     $$.nodeCount =  $1.nodeCount + $2.size +1 ;
                                                                     add($1.list,$2.value);
                                                                     copy_array($1.list,$$.list);                                                                                                    
                                                              } 

                       | tree                              {                                                                          
                                                                      $$.nodeCount =  $1.size + 1 ;  
                                                                       $$.list[0] = $1.value;                                                        
                                                              } 
                       ;

%%

void yyerror (char *s)
{
fprintf (stderr, "%s\n", s);
}

int yywrap()
{
return 1;
}

void copy_array(int arr1[],int arr2[])
{
int i;
 for(i =0;i<100;i++)
      {
        arr2[i] = arr1[i];
       i++;
      }
}
void add(int list[], int input){
  int i ;
  for(i =0;i<100;i++)
      {
       if(list[i] == 0)
          {
           list[i] = input;
           break;
          }      
       i++;                
      }
}

int sum_odd(int list[])
  {
     int i;
     int sum = 0;
     for(i =0;i<100;i++)
      {
        if((list[i]) % 2 != 0) sum += list[i];
        i++;
      }
   return sum;
  }

int sum_even(int list[])
  {
     int i;
     int sum = 0;
     for(i =0;i<100;i++)
      {
        if((list[i]) % 2 == 0) sum += list[i];
        i++;
      }
   return sum;
  }


int main (int argc , char **argv)
{
extern FILE *yyin;
yyin = fopen (argv [1], "r");
yyparse();
fclose(yyin);
return 0;
}