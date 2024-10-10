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
{ABREPARENTESIS} printf("-ABREPARENTESIS-");
{CIERRAPARENTESIS} printf("-CIERRAPARENTESIS-");
{LEER} printf("-LEER-");
{ESCRIBIR} printf("-ESCRIBIR-");
{INICIO} printf("-INICIO-");
{FIN} printf("-FIN-");
{PUNTOYCOMA} printf("-PUNTOYCOMA-");
{OPERADORASIGNACION} printf("-OPERADORASIGNACION-");
{TIPO} printf("-TIPO(%s)-", yytext);
{IDENTIFICADOR} printf("-IDENTIFICADOR(%s)-", yytext);
{CONSTANTELITERAL} printf("-CTELITERAL(%s)-",yytext);

%%

int main(){
    printf("Escriba en lenguaje MICRO");
    yylex();
    getch();
    return 0;
}


