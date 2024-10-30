%{
    #define ABREPARENTESIS "ABREPARENTESIS"
    #define CIERRAPARENTESIS "CIERRAPARENTESIS"
    #define LEER "LEER"
    #define ESCRIBIR "ESCRIBIR"
    #define INICIO "INICIO"
    #define FIN "FIN"
    #define PUNTOYCOMA "PUNTOYCOMA"
    #define OPERADORASIGNACION "OPERADORASIGNACION"
    #define TIPO "TIPO"
    #define IDENTIFICADOR "IDENTIFICADOR"
    #define CTELITERAL "CTELITERAL"
%}






IDENTIFICADOR ({LETRA}|_)({LETRA}|{DIGITO}|_)*
LETRA [a-zA-Z]
DIGITO [0-9]
CONSTANTELITERAL ({ENTEROLITERAL}|{CADENALITERAL})
ENTEROLITERAL {DIGITO}+
CADENALITERAL \".{0,255}\"
OPERADORASIGNACION \:\=
TIPO (int)|(string)
LEER leer
ESCRIBIR escribir
INICIO inicio
FIN fin
PUNTOYCOMA \;
ABREPARENTESIS \(
CIERRAPARENTESIS \)


%option noyywrap

%%
{ABREPARENTESIS}           { return (ABREPARENTESIS); }
{CIERRAPARENTESIS}         { return (CIERRAPARENTESIS); }
{LEER}                     { return (LEER); }
{ESCRIBIR}                 { return (ESCRIBIR); }
{INICIO}                   { return (INICIO); }
{FIN}                      { return (FIN); }
{PUNTOYCOMA}               { return (PUNTOYCOMA); }
{OPERADORASIGNACION}       { return (OPERADORASIGNACION); }
{TIPO}                     { sscanf(yytext, "%s", yylval.contenido); return (TIPO); }
{IDENTIFICADOR}            { sscanf(yytext, "%s", yylval.contenido); return (IDENTIFICADOR); }
{CONSTANTELITERAL}         { sscanf(yytext, "%s", yylval.contenido); return (CTELITERAL); }
.                          { printf("ERROR LEXICO en %s", yylval);}

%%

int main(){
    printf("Escriba en lenguaje MICRO");
    yylex();
    getch();
    return 0;
}


