/***************************************************************************
 *   libleo.h                                 Version 20201002.222432      *
 *                                                                         *
 *   BIBLIOTECA PESSOAL PARA SER USADA EM VÁRIOS OUTROS PROGRAMAS          *
 *                                                                         *
 *   Copyright (C) 2020         by Leandro Dantas Lima                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
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
 *   Webpage: beco.poli.br/leandroautocontrole@gmail.com                   *
 *   Phone: (81) 98861-9469                                                *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */

#ifndef _LIBLEO_H
#define _LIBLEO_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h>  /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h>  /* Time and date functions */
#include <unistd.h>  /* UNIX standard function */

/* ---------------------------------------------------------------------- */
/* definitions */


/* ---------------------------------------------------------------------- */
/* prototypes */

void libleo_init(void);  /**< Initializes some operations before start */
//void libleo_update(void); /**< Updates values during program cycle */

void gerar_aleatorios(int num_sort[], int quant_num, int max_interv);
int my_strlen(char *str);
bool testar(int teste[], int tam);
bool existe(char palavra[], char frase[]);
void substring(void);


#endif /* NOT def _LIBLEO_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

