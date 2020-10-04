/***************************************************************************
 *   libleo.c                                 Version 20201002.222906      *
 *                                                                         *
 *   FUNCOES DA BIBLIOTECA PESSOAL PARA SEREM USADAS EM VARIOS PROGRAMAS   *
 *                                                                         *
 *   Copyright (C) 2020         by Leandro Dantas Lima                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Webpage: http://beco.poli.br/ldls3                                    *
 *   Phone: (81) 98861-9469                                                *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc libleo.c -o libleo.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h>  /* Time and date functions */
#include <unistd.h> /* UNIX standard function */
#include <stdbool.h>
#include <string.h>
#include "libleo.h"  /* To be created for this template if needed */

int main(void)
{
    libleo_init();

    return EXIT_SUCCESS;
}

/* ----------------------------------------------------------------------------------- */
void libleo_init(void)
{
    int quant_num = 0, max_interv = 0;
    int num_sort[quant_num];
    char *str[100];
    gerar_aleatorios(num_sort, quant_num, max_interv);
    substring();
    my_strlen(str);
}

/* ----------------------------------------------------------------------------------- *
 * Função gerar_aleatorios --> Função para gerar números aleatórios dentro de um       *
 *                             intervalo determinado.                                  *
 *                                                                                     *
 *      - num_sort[] --> vetor que contém todos os números sorteados aleatoriamente;   *
 *      - quant_num --> quantidade de números aleatórios gerados;                      *
 *      - max_interv --> limite superior (1 a max_interv) do intervalo de números que  *
 *                       se deseja sortear aleatoriamente.                             *
 * ----------------------------------------------------------------------------------- */
void gerar_aleatorios(int num_sort[], int quant_num, int max_interv)
{
    printf("\n Quantos numeros deseja sortear? ");
    scanf("%d", &quant_num);

    printf(" Numeros de 1 a quanto (max_interv)? ");
    scanf("%d", &max_interv);

    srand(time(NULL) + getpid());

    int i, v;
    
    for(i = 0; i < quant_num; i++)
    {
        v = rand() % max_interv + 1;
        num_sort[i] = v;
    }

    printf("\n ********************************************************************* ");
    printf("\n ********************     NUMEROS SORTEADOS     **********************\n ");
    printf("********************************************************************* \n\n");

    for(i = 0; i < quant_num; i++)
    {
        printf(" #%d ", num_sort[i]);
    }
    printf("\n");
    printf("\n ---------------------------------------------------------------------\n");

}

/* ----------------------------------------------------------------------------------- *
 * Função my_strlen --> Função que conta a quantidade de caracteres de uma string      *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
int my_strlen(char *str)
{
    setbuf(stdin, 0);  /* Limpa o buf do teclado */

    printf(" Digite um nome: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0'; /* Limpa o '\n' coletado do enter por fgets() */

    int tam = 0; /* Iniciando o tamanho da string */
    
    while(*str != '\0')
    {
        str++;
        tam++;
    }

    printf(" A string digitada possui %d caracteres\n\n", tam + 1);

    return tam + 1;
}




/* ----------------------------------------------------------------------------------- *
 * Função testar --> Função auxiliar para pesquisa.                                    *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
bool testar(int teste[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(teste[i] == 0)
        {
            return false;
        }
    }
    return true;
}

/* ----------------------------------------------------------------------------------- *
 * Função existe --> Função auxiliar para pesquisa.                                    *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
bool existe(char palavra[], char frase[])
{
    int teste[strlen(palavra)];
    int i, j, k, aux;

    if(strlen(palavra) > strlen(frase))
    {
        return false;
    }

    if(strcmp(palavra, frase) == 0)
    {
        return true;
    }

    for(i = 0; i <= strlen(frase) - strlen(palavra); i++)
    {
        if(frase[i] == palavra[0])
        {
            for(k = 0; k < strlen(palavra); k++)
                teste[k] = 0;

            aux = i;
            for(j = 0; j < strlen(palavra); j++)
            {
                if(palavra[j] == frase[aux])
                {
                    teste[j] = 1;
                    aux++;
                }
            }
            if(testar(teste, strlen(palavra)))
            {
                return true;
            }
        }
    }
    return false;
}


/* ----------------------------------------------------------------------------------- *
 * Função substring --> Função para localizar substrings em uma string                 *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
void substring(void)
{
    char frase[100];
    char palavra[100];

    setbuf(stdin, 0); /* Limpa o buffer do teclado */
    printf("\n Digite uma frase: ");
    fgets(frase, 100, stdin);
    frase[strlen(frase) - 1] = '\0';  /* Limpa o buffer do enter ('\n') */

    setbuf(stdin, 0); /* Limpa o buffer do teclado */
    printf(" Digite uma string: ");
    fgets(palavra, 100, stdin);
    palavra[strlen(palavra) - 1] = '\0';  /* Limpa o buffer do enter ('\n') */

    if(existe(palavra, frase))
    {
        printf("\n A string <%s> EXISTE na frase <%s>!\n\n", palavra, frase);
    }
    else
    {
        printf("\n A string <%s> NAO EXISTE na frase <%s>!\n\n", palavra, frase);
    }
    
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

