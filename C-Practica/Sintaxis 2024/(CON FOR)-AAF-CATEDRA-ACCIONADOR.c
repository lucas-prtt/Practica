//A partir del dado por la catedra, le cambio el while con dos variables con un for con solo una.




/* Ejemplo a - PruebaEsPalabra.C
Prueba la funci�n EsPalabra.*/
#include <stdio.h> /* printf */
#include <ctype.h> /* isdigit */


void Titulo (void);   /* funcion auxiliar */
int Valor (int) ; //transforma un char a su formato numerico
int Verifica (char *);  /* que los caracteres pertenezcan al alfabeto */
int Columna (int); /* dado un caracter, determina la columna  */
int ObtieneValor (const char *, long *);

int main ()
{
    int i;
    char s1[20] = "";
    printf("Ingrese una cadena \n");
    scanf("%s",s1);

    Titulo();
    if (! ObtieneValor(s1,&i))
        printf("No se pudo convertir el valor\n");
    else
        printf("El valor convertido es: %d\n", i);
    return 0;
} /* fin main */

void Titulo (void)
{
    printf("Este programa implementa un AFD como accionador.\n");
    printf("Si una cadena dada corresponde a un numero entero, no s�lo reconoce,\
           sino que ademas ejecuta la accion de convertir a formato numerico\n");

} /* fin Titulo */

int Valor (int c)
{
    return (c - '0');
} /* fin Valor */

int Verifica (char *s)
{
    unsigned i;
    for (i=0; s[i] != '\0'; i++)
        if (! (isdigit(s[i]) || s[i] == '+' || s[i] == '-'))
            return 0;
    return 1;
} /* fin Verifica */

int Columna (int c)
{
    switch (c)
    {
        case '+':
            return 1;
        case '-':
            return 2;
        default /* es digito */:
            return 0;
    }
} /* fin Columna */

int ObtieneValor (const char *cadena, long *p_numero)
{
    static int tt [4][3] = {{2,1,1},
                        {2,3,3},
                        {2,3,3},
                        {3,3,3}
                    };
    int e = 0; /* estado inicial */
    unsigned i = 0; /* recorre la cadena */
    long a = 0; /* contiene valor numerico absoluto de la cadena */
    int s = 1;   /* signo del n�mero: 1 = positivo; -1 = negativo */
    if (!Verifica(cadena))
        return 0;

    for(i=0;cadena[i]!='\0'||e==3; i++){
        e=tt[e][Columna(cadena[i])];
        
        switch (e)
        {
            case 1:
                if (cadena[i]=='-')
                s = -1;
            break;
            case 2:
                a = 10 * a + Valor(cadena[i]);
            break;
            default /* error */:
            break;
        }
    }
    if (e == 2)
    { /* estado final */
        *p_numero = s * a;
        return 1;
    }
    else
        return 0;
} /* fin ObtieneValor */
