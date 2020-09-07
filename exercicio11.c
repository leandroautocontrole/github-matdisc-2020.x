/***************************************************************************
 *   exercicio11.c                            Version 20200907.124853      *
 *                                                                         *
 *   Criacao do repositorio ex11 no GitHub pelo Hydra                      *
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

/* ---------------------------------------------------------------------- */
/*
 * Instrucoes para compilar:
 * $gcc exercicio11.c -o exercicio11.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* 
 * Este programa é apenas uma mensagem de teste para o Git e GitHub.
 * 
 * Ele não recebe nenhuma variável do usuário, apenas imprime uma mensagem
 * já definida através da função printf().
 *
 * Retorna EXIT_SUCCESS;
 */
/* ---------------------------------------------------------------------- */

int main(void)
{
    printf("\n*************************************************");
    printf("\n Hello Dr. Beco.\n\tI am ready to learn a lot from you in");
    printf("\n\tthis period and I am working hard fot it.\n");
    printf("*************************************************\n\n");

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

