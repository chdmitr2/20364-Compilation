%{
#include <string.h>
#include <stdlib.h>
/* Keywords*/
#define BREAK 300
#define CASE 301
#define DEFAULT 302
#define ELSE 303
#define FLOAT 304
#define IF 305
#define INPUT 306
#define INT 307
#define OUTPUT 308
#define STATIC_CAST 309
#define SWITCH 310
#define WHILE 311
/*Symbols*/
#define LROUND 400
#define RROUND 401
#define LBRACE 402
#define RBRACE 403
#define COMMA 404
#define COLON 405
#define SEMICOLON 406
#define EQUAL 407
/*Operators*/
#define RELOP 500
#define ADDOP 501
#define MULOP 502
#define OR 503
#define AND 504
#define NOT 505
#define CAST 506
/*Tokens*/
#define ID 600
#define INUM 601
#define FNUM 602

int lineCount = 1;

extern int atoi (const char*);

extern double atof (const char*);

union {
    char op[3];
    char id[20];
    int inum;
    float fnum;
} yylval;
%}

%option noyywrap
%x COMMENT

%%

"break"                         { strcpy(yylval.id, yytext); return BREAK; }

"case"                           { strcpy(yylval.id, yytext); return CASE; }

"default"                       {strcpy(yylval.id, yytext); return DEFAULT; }

"else"                            { strcpy(yylval.id, yytext); return ELSE; }

"float"                            { strcpy(yylval.id, yytext); return FLOAT; }

"if"                                 { strcpy(yylval.id, yytext); return IF; }

"input"                          { strcpy(yylval.id, yytext); return INPUT; }

"int"                              { strcpy(yylval.id, yytext); return INT; }

"output"                        { strcpy(yylval.id, yytext); return OUTPUT; }

"static_cast"                 { strcpy(yylval.id, yytext); return STATIC_CAST; }

"switch"                        {strcpy(yylval.id, yytext); return SWITCH; }

"while"                          { strcpy(yylval.id, yytext); return WHILE; }


"("                             { strcpy(yylval.op, yytext); return LROUND; }

")"                             { strcpy(yylval.op, yytext); return RROUND; }

"{"                             {strcpy(yylval.op, yytext); return LBRACE; }

"}"                             { strcpy(yylval.op, yytext); return RBRACE; }

","                             { strcpy(yylval.op, yytext); return COMMA; }

":"                             { strcpy(yylval.op, yytext); return COLON; }

";"                             { strcpy(yylval.op, yytext); return SEMICOLON; }

"="                            { strcpy(yylval.op, yytext); return EQUAL; }


"/*"                            { BEGIN(COMMENT); }
<COMMENT>"*/"                   { BEGIN(0); }
<COMMENT>\n                     { lineCount++; }
<COMMENT>.


"=="|"!="|"<"|">"|">="|"<="                                                    { strcpy(yylval.id, yytext); return RELOP; }

"+"|"-"                                                                                    { strcpy(yylval.id, yytext); return ADDOP; }

"*"|"/"                                                                                     { strcpy(yylval.id, yytext); return MULOP; }

"||"                                                                                          { strcpy(yylval.id, yytext); return OR; }

"&&"                                                                                       { strcpy(yylval.id, yytext); return AND; }

"!"                                                                                          { strcpy(yylval.id, yytext); return NOT; }

"static_cast<int>"|"static_cast<float>"                                   { strcpy(yylval.id, yytext); return CAST; }


[a-zA-Z][a-zA-Z0-9]*                                                               { strcpy(yylval.id, yytext); return ID; } 
                                              
[0-9]+"."[0-9]+                                                                       { yylval.fnum = atof(yytext); return FNUM; }

[0-9]+                                                                                   { yylval.inum = atoi(yytext); return INUM; }



\n                                                                                        { lineCount++; }

[\t ]+

.                                                                                          { fprintf(stderr, "LINE:  %d\tERROR: \"%c\" unrecognized token\n", lineCount, yytext[0]); }

%%

int main (int argc, char **argv) 
{
    int token;
       
   yyin = fopen(argv[1], "r");
  if (argc != 2)
    {
        printf("Usage: cla <input file name>.ou\n");
        exit(1);
    }
    else if(!(argv[1][strlen(argv[1]) - 3] == '.' &&
        (argv[1][strlen(argv[1]) - 2] == 'o' || argv[1][strlen(argv[1]) - 2] == 'O') &&
        (argv[1][strlen(argv[1]) - 1] == 'u' || argv[1][strlen(argv[1]) - 1] == 'U')))
    {
        printf("Unrecognized file extension (should be .ou)\n");
        exit(1);
    }
    
    yyin = fopen(argv[1], "r");
    if(yyin == NULL)
    {
        printf("ERROR: File \"%s\" does not exist\n", argv[1]); 
        exit(1);
    }

    char nameFile[strlen(argv[1])+1];
    strcpy(nameFile, argv[1]);
    int nameFilelen = strlen(nameFile);
    nameFile[nameFilelen+1] = 0;
    nameFile[nameFilelen] = 'k';
    nameFile[nameFilelen-1] = 'o';
    nameFile[nameFilelen-2] = 't';
    FILE *outputFile = fopen(nameFile, "w");
   
   fprintf(outputFile,"\n\nTOKEN TYPE\t\tLEXEME\t\t\tATTRIBUTE\n\n");

    while ((token = yylex()) != 0)
    {

     switch (token) 
        {

         /* Keywords*/

            case BREAK : 
                                    fprintf(outputFile,"BREAK\t\t\t%s\n", yylval.id);
                                    break;
            case CASE : 
                                    fprintf(outputFile,"CASE\t\t\t%s\n", yylval.id);
                                    break;
            case DEFAULT : 
                                    fprintf(outputFile,"DEFAULT\t\t\t%s\n", yylval.id);
                                    break;
            case ELSE :
                                    fprintf(outputFile,"ELSE \t\t\t%s\n", yylval.id);
                                    break;
            case FLOAT : 
                                    fprintf(outputFile,"FLOAT\t\t\t%s\n", yylval.id);
                                    break;
            case IF : 
                                    fprintf(outputFile,"IF\t\t\t%s\n", yylval.id);
                                    break;
            case INPUT : 
                                    fprintf(outputFile,"INPUT\t\t\t%s\n", yylval.id);
                                    break;
            case INT : 
                                    fprintf(outputFile,"INT\t\t\t%s\n", yylval.id);
                                    break;
            case OUTPUT :
                                    fprintf(outputFile,"OUTPUT\t\t\t%s\n", yylval.id);
                                    break;
            case STATIC_CAST : 
                                    fprintf(outputFile,"STATIC_CAST\t\t\t%s\n", yylval.id);
                                    break;
            case SWITCH : 
                                    fprintf(outputFile,"SWITCH\t\t\t%s\n", yylval.id);
                                    break;
            case WHILE :
                                    fprintf(outputFile,"WHILE\t\t\t%s\n", yylval.id);
                                    break;

         /*Symbols*/

            case LROUND : 
                                   fprintf(outputFile,"LROUND\t\t\t%s\n", yylval.op);
                                   break;
            case RROUND : 
                                   fprintf(outputFile,"RROUND\t\t\t%s\n", yylval.op);
                                   break;
            case LBRACE :
                                   fprintf(outputFile,"LBRACE\t\t\t%s\n", yylval.op);
                                   break;
            case RBRACE :
                                   fprintf(outputFile,"RBRACE\t\t\t%s\n", yylval.op);
                                   break;
            case COMMA :
                                   fprintf(outputFile,"COMMA\t\t\t%s\n", yylval.op);
                                   break;
            case COLON :
                                   fprintf(outputFile,"COLON\t\t\t%s\n", yylval.op);
                                   break;
            case SEMICOLON : 
                                   fprintf(outputFile,"SEMICOLON\t\t%s\n", yylval.op);
                                   break;
            case EQUAL :
                                   fprintf(outputFile,"EQUAL\t\t\t%s\n", yylval.op);
                                   break;

          /*Operators*/

            case RELOP : 
                                   fprintf(outputFile,"RELOP\t\t\t%s\t\t\t\"%s\"\n", yylval.id,yylval.id);
                                   break;
            case ADDOP :
                                   fprintf(outputFile,"ADDOP\t\t\t%s\t\t\t\"%s\"\n", yylval.id,yylval.id);
                                   break;
            case MULOP :
                                   fprintf(outputFile,"MULOP\t\t\t%s\t\t\t\"%s\"\n", yylval.id,yylval.id);
                                   break;
            case OR :

                                   fprintf(outputFile,"OR\t\t\t%s\n", yylval.id);
                                   break;
            case AND : 

                                   fprintf(outputFile,"AND\t\t\t%s\n", yylval.id);
                                   break;
            case NOT : 

                                   fprintf(outputFile,"NOT\t\t\t%s\n", yylval.id);
                                   break;
            case CAST :

                                   fprintf(outputFile,"CAST\t\t\t%s\t\t\"%s\"\n", yylval.id,yylval.id);
                                   break;

         /*Tokens*/

            case ID: 
                                   fprintf(outputFile,"ID\t\t\t%s\t\t\t\"%s\"\n", yylval.id,yylval.id);
                                   break;

            case FNUM: 
                                   
                                   fprintf(outputFile,"FNUM\t\t\t%.5f\t\t\t%.3f\n",yylval.fnum,yylval.fnum);
                                   break;

             case INUM: 
                                   
                                   fprintf(outputFile,"INUM\t\t\t%d\t\t\t%d\n",yylval.inum,yylval.inum);
                                   break;

            default:    
                                   fprintf(outputFile,"ERROR\n");
                                   exit(1);

        }
       
    }
 
    fprintf(outputFile, "\nLexical Analyzer to CPL Language\n\n Maman 12\n\n Question 1\n\n Chudnovsky Dmitriy\n\n 324793900");
    fprintf(stderr, "\nLexical Analyzer to CPL Language\n\n Maman 12\n\n Question 1\n\n Chudnovsky Dmitriy\n\n 324793900");
    fclose(yyin);
    fclose(outputFile);    
    exit(0);
}