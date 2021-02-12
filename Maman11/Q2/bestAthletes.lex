%{
    #include <string.h>
    #define TITLE 300
    #define NUMBER 301
    #define ATTRIBUTE 302
    #define LEFTSTRING 303
    #define RIGHTSTRING 304
    #define DATE 305
    #define TIME 306
  
    char yylval[80];

    int lineCount =1;

%}

%option noyywrap

%%

[a-zA-Z]*                                               { strcpy(yylval, yytext); return TITLE; }

"["[1-9][0-9]*"]"                                   { strcpy(yylval, yytext); return NUMBER; }

"<"[a-z]+">"                                        { strcpy(yylval, yytext); return ATTRIBUTE; }

\"[a-zA-Z^]+                                         { strcpy(yylval, yytext); return LEFTSTRING; }

[a-zA-Z^]*\"                                          { strcpy(yylval, yytext); return RIGHTSTRING; }
                                  
[0-9 ]{1,2}[a-zA-Z ]+[0-9]{4}                { strcpy(yylval, yytext); return DATE; }

[0-9]\.[0-9]{2}                                       {strcpy(yylval, yytext); return TIME; }

[\n]                                                        {lineCount++;}

[\t ]+

.                                                            { printf("line:  %d - unrecognized token %c\n",lineCount,yytext[0]); }

%%

int main (int argc, char **argv) 
{
    int token;

    if (argc != 2)
    {
        printf("Usage: mylex <input file name>\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");

    printf("TOKEN\t\t\tLEXEME\t\t\t\tATTRIBUTE\n\n\n");

    char temp[30];

    while ((token = yylex()) != 0)
        switch (token) 
        {
            case TITLE: 

                                    printf("TITLE\t\t\t%s\n", yylval);
                                    break;

            case NUMBER:

                                    strcpy(temp, yylval+1);
                                    temp[strlen(temp)-1] = '\0';
                                    printf("NUMBER\t\t\t%s\t\t\t%s\n",yylval, temp);
                                    break;

            case ATTRIBUTE: 

                                    strcpy(temp, yylval+1);
                                    temp[strlen(temp)-1] = '\0';
                                    printf("ATTRIBUTE\t\t%s\n", yylval, temp);
                                    break;

            case LEFTSTRING: 

                                    printf("LEFTSTRING\t\t%s\t\t\tfirst name of Country or Athlete\n", yylval);
                                    break;

            case RIGHTSTRING: 

                                    printf("RIGHTSTRING\t\t%s\t\t\tlast name of Country or Athlete\n", yylval);
                                    break;

            case DATE:

                                    printf("DATE\t\t\t%s\t\tdate\n", yylval);
                                    break;

            case TIME: 

                                    printf("TIME\t\t\t%s\t\t\trun time\n", yylval);
                                    break;

            default:    

                                    printf("ERROR\n");
                                    exit(1);

        }
    fclose(yyin);
    exit(0);
}