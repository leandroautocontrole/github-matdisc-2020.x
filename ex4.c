/***************************************************************************
 *   ex4.c                                    Version 20201002.001522      *
 *                                                                         *
 *   LAÇO PARA SORTEIO SEM REPETIÇÃO                                       *
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
 *   Webpage: http://beco.poli.br/leandroautocontrole@gmail.com            *
 *   Phone: (81) 98861-9469                                                *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex4.c -o ex4.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h>  /* Time and date functions */
#include <stdbool.h> /* Define as constantes inteiras true (0) e false (1) */
#include <unistd.h> /* Add getpid() para evitar repeticoes nas sementes */

/* ---------------------------------------------------------------------- */
/* prototypes */

bool numero_sorteado(int valores[], int tam, int valor);
void gerar_aleatorios(int num[], int quant_num, int max);

/* -------------------------------------------------------------------------------- * 
 * Este programa simula um laço para sorteio sem repetição;                         *
 *                                                                                  *
 * Recebe números inteiros associados a quantidade de números sorteados desejada e  *
 * ao limite superior (max) do intervalo de números do qual se deseja sortear       *
 * (números entre 1 e max);                                                         *
 *                                                                                  *
 * Retorna EXIT_SUCCESS.                                                            *
 *                                                                                  *
 * -------------------------------------------------------------------------------- */
int main(void)
{
    int i, j, n;

    printf("\n Sortear quantos numeros? ");
    scanf("%d", &j);

    do
    {
        printf(" MAX do intervalo (1 a MAX)?");
        scanf("%d", &n);
    }while(n<j);


    printf("\n ********************************************************************** ");
    printf("\n *********************     NUMEROS SORTEADOS     ********************** \n");
    printf(" ********************************************************************** \n\n");

    int num[j];

     gerar_aleatorios(num, j, n);
     for(i = 0; i < j; i++)
    {
        printf(" #%d ", num[i] + 1);
    }
    printf("\n\n");

    return EXIT_SUCCESS;
}

/* -------------------------------------------------------------------------------- * 
 * Função numero_sorteado --> Função para conferir se um número já foi sorteado     *
 *                                                                                  *
 *      - valores[] --> vetor que contém todos os números sorteados;                *
 *      - tam --> tamanho máximo do vetor valores;                                  *
 *      - valor --> se existe determinado número no vetor.                          *
 *                                                                                  *
 * -------------------------------------------------------------------------------- */

bool numero_sorteado(int valores[], int tam, int valor)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        if(valores[i] == valor)
            return true;
    }
    return false;
}

/* -------------------------------------------------------------------------------- * 
 * Função gerar_aleatorios --> Função para gerar os números aleatórios              *
 *                                                                                  *
 *      - num[] --> vetor que contém todos os números gerados pelo rand();          *
 *      - quant_num --> quantos números ela vai gerar;                              *
 *      - max --> limite superior do intervalo de números desejados para o sorteio. *
 *                                                                                  *
 * -------------------------------------------------------------------------------- */

void gerar_aleatorios(int num[], int quant_num, int max)
{
    srand(time(NULL) + getpid());

    int i, v;

    for(i = 0; i < quant_num; i++)
    {
        v = rand() % max;

        while(numero_sorteado(num, i, v))
        {
            v = rand() % max;
        }
        num[i] = v;
    }
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

