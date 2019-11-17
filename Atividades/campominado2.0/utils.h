#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prepara_campo(int**, int, int, int);
void prepara_exibicao(char**, int, int);
void imprime_tabuleiro(char**, int, int);
void imprime_campo(int**, int, int);
void mostra_mina(int**, char**, int, int);
void checa_mina(int, int, int**, char**, int, int);