digito [0-9]
letra [a-fA-F]
hexadecimal 0[xX]({digito}|{letra}){1,8}

%option noyywrap
%%
{hexadecimal} {printf("---Hexadecimal(%s)---",yytext);}
%%

main(){
    printf("\nIngrese numeros hexadecimales:\n");
    yylex();
    return 0;
}