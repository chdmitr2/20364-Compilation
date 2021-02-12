%{
    #include <stdbool.h>
    #include <string.h>
    #define NUM 301
    #define ROMAN_NUM 302
    #define STR 303
    #define ODD_LINE 304
  
    union {
        int ival;
        char str[80];
    } yylval;

    int lineCount = 1;

    extern int atoi (const char *);    
%}

%option noyywrap

%%

[0-9][0-9]+          { yylval.ival = atoi(yytext); return NUM; }

[1-9]                   { yylval.ival = atoi(yytext); return ROMAN_NUM; }

[\n]                    { lineCount++; return ODD_LINE;}

.                       { strcpy(yylval.str, yytext); return STR; }

%%

void main (int argc, char **argv) 
{
    int token;
    bool flag = true;

    if (argc == 2)
        yyin = fopen(argv[1], "r");

    while ((token = yylex()) != 0)
    {
        if (flag == true)
        {
            if (lineCount % 2 != 0)
               {         
                printf("%d.\t", lineCount);
               }
            else
               {
                printf("\t");
               }
            flag = false;
         }
        if (token == ROMAN_NUM)
          {
            switch (yylval.ival)
            {
                case 1: printf("I");
                        break;
                case 2: printf("II");
                        break;
                case 3: printf("III");
                        break;
                case 4: printf("IV");
                        break;
                case 5: printf("V");
                        break;
                case 6: printf("VI");
                        break;
                case 7: printf("VII");
                        break;
                case 8: printf("VIII");
                        break;
                case 9: printf("IX");
                        break;
                default:printf("Error");
                        break;
            }
        }
        else if (token == NUM)
        {
           printf("%d",yylval.ival);
        }
        else if (token == STR)
        {
           printf("%s",yylval.str);
         }
        else if (token == ODD_LINE)
        {
            printf("\n");
            flag = true;
        }
        else
         {
           printf("Error");
         }
         
    }
    fclose(yyin);
    exit(0);
}