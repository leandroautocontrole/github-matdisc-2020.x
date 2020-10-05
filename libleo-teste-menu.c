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
#include "libleo-teste-menu.h"  /* To be created for this template if needed */

/* ----------------------------------------------------------------------------------- */
/* Função principal */
int main(void)
{
    libleo_init();

    return EXIT_SUCCESS;
}

/* ----------------------------------------------------------------------------------- */
/* Função para inicialização e chamada */
void libleo_init(void)
{
    /* bug: ainda não consegui colocar gerar_aleatorios no menu() */
    printf("\n ---------------------------------------------------------------------\n");
    printf(" /* gerar_aleatorios */ \n");
    
    int quant_num = 0, max_interv = 0;
    int num_sort[quant_num];
    gerar_aleatorios(num_sort, quant_num, max_interv);
    system("pause");
    
    menu();
    
    printf("\n");
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
    setbuf(stdin, 0);  /* Limpa o buffer do teclado */

    printf("\n Digite um nome: ");
    fgets(str, SBUFF, stdin);
    str[strlen(str) - 1] = '\0'; /* Limpa o '\n' coletado do enter por fgets() */

    int tam = 0; /* Iniciando o tamanho da string */
    
    while(*str != '\0')
    {
        str++;
        tam++;
    }

    printf(" A string digitada possui <%d> caracteres", tam + 1);
    printf("\n");
    printf("\n ---------------------------------------------------------------------\n");
    
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
    char frase[SBUFF];
    char palavra[SBUFF];

    setbuf(stdin, 0); /* Limpa o buffer do teclado */
    printf("\n Digite uma frase: ");
    fgets(frase, SBUFF, stdin);
    frase[strlen(frase) - 1] = '\0';  /* Limpa o buffer do enter ('\n') */

    setbuf(stdin, 0); /* Limpa o buffer do teclado */
    printf(" Digite uma string: ");
    fgets(palavra, SBUFF, stdin);
    palavra[strlen(palavra) - 1] = '\0';  /* Limpa o buffer do enter ('\n') */

    if(existe(palavra, frase))
    {
        printf("\n A string <%s> EXISTE na frase <%s>!", palavra, frase);
    }
    else
    {
        printf("\n A string <%s> NAO EXISTE na frase <%s>!", palavra, frase);
    }
    printf("\n");
    printf("\n ---------------------------------------------------------------------\n");
    
}

/* ----------------------------------------------------------------------------------- *
 * Função manip_arq --> Função para manipulação de arquivo, criando ou adicionando     *
 *                      novas informações fornecidas.                                  *
 *                                                                                     *
 *      modos:                                                                         *
 *      - wt --> Gravação em arquivo de texto --> "write-txt" --> Nesse modo se o      *
 *               o arquivo não existir, ele é criado, mas sempre apaga o arquivo       *
 *               anterior e cria um novo em branco.                                    *
 *      - at --> Concatenação em arquivo de texto --> "append-txt" --> Nesse modo, se  *
 *               o arquivo não existir, ele é criado, mas apenas adiciona novas        *
 *               informações no arquivo anterior.                                      *
 *      - rt --> Leitura (apenas) de arquivo de texto --> "read-txt".                  *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
void manip_arq(void)
{
    setbuf(stdin, 0); /* Limpa o buffer do teclado */
    FILE *arquivo; /* Ponteiro apontando para o arquivo */

    arquivo = fopen("libleo.txt", "at");
    char texto[SBUFF] = "Tudo tranquilo!!!\n";

    if(arquivo == NULL)  /* Caso algum erro o ponteiro aponta para NULL */
    {
        printf("\n Nao foi possivel abrir o arquivo!\n");
        exit(0); /* Encerra a execução do programa pelo sistema */
    }

    fprintf(arquivo, texto);  /* Grava uma string num arquivo */
    printf("\n Texto adicionado ao arquivo: %s", texto);
    
    fclose(arquivo);  /* Fecha o arquivo */
    
    printf("\n");
    printf("\n ---------------------------------------------------------------------\n");
}

/* ----------------------------------------------------------------------------------- *
 * Função manip_arq_redir --> Função para leitura e escrita de um arquivo com uma      *
 *                            string fornecida pelo usuário.                           *
 * ----------------------------------------------------------------------------------- */
void manip_arq_redir(void)
{
    setbuf(stdin, 0); /* Limpa o buffer do teclado */
    FILE *arquivo; /* Ponteiro apontando para o arquivo */
    char texto[SBUFF];

    arquivo = fopen("libleo.txt", "a");

    if(arquivo == NULL)  /* Caso algum erro o ponteiro aponta para NULL */
    {
        printf("\n Erro na abertura do arquivo!\n");
        exit(0); /* Encerra a execução do programa pelo sistema */
    }
    
    printf("\n String a gravar no arquivo: ");
    fgets(texto, SBUFF, stdin);

    fprintf(arquivo, "%s", texto);  /* Grava uma string num arquivo */
    texto[strlen(texto) - 1] = '\0'; /* Limpa o buffer do <enter> ('\n') */
 
    fclose(arquivo);  /* Fecha o arquivo */

    printf("\n String <%s> gravada com sucesso!\n\n", texto);
}

/* ----------------------------------------------------------------------------------- *
 * Função limpa_tela --> Função para limpar a tela.                                    *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
void limpa_tela(void)
{
    system("CLS");
}

/* ----------------------------------------------------------------------------------- *
 * Função menu --> Menu interativo para navegar nas funções                            *
 *                                                                                     *
 * ----------------------------------------------------------------------------------- */
void menu(void)
{
    int opcao = 0; /* Opção escolhida pelo usuário */

    while(1)
    {
        limpa_tela();
        printf("\n\t >> Bem-vindo a libleo.h << \n\n");
        printf("\n 1 - Funcao substring ");
        printf("\n 2 - Funcao my_strlen ");
        printf("\n 3 - Funcao manip_arq ");
        printf("\n 4 - Funcao manip_arq_redir ");
        printf("\n 5 - Funcao gerar_aleatorios ");
        printf("\n 6 - Sair ");
        printf("\n\n Escolha uma opcao e tecle <ENTER>: ");

        scanf("%lc", &opcao); /* Faz a leitura da opção do usuário */
        fflush(stdin); /* Limpa o buffer do teclado */

        switch(opcao)
        {
            case '1':
                printf("\n ---------------------------------------------------------------------\n");
                printf(" /* substring */ \n");
                substring();
                system("pause");
                break;

            case '2':
                printf("\n ---------------------------------------------------------------------\n");
                printf(" /* my_strlen */ \n");
                char *str[SBUFF];
                my_strlen(str);
                system("pause");
                break;

            case '3':
                printf("\n ---------------------------------------------------------------------\n");
                printf(" /* manip_arq */ \n");
                manip_arq();
                system("pause");
                break;

            case '4':
                printf("\n ---------------------------------------------------------------------\n");
                printf(" /* manip_arq_redir */ \n");
                manip_arq_redir();
                system("pause");
                break;

            case '5':
                printf("\n ---------------------------------------------------------------------\n");
                printf(" /* gerar_aleatorios */ \n");
               /* int quant_num, max_interv; */
               /* int num_sort[quant_num]; */
               /* gerar_aleatorios(num_sort, quant_num, max_interv); */
               /* system("pause"); */
                break;

            case '6':
                printf("\n ---------------------------------------------------------------------\n");
                printf("\n Saindo...\n");
                exit(0);

            default:
                break;
        }
    }
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

