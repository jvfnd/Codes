#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){

int ** matriz;
int escolha, num_jogador, num_sorteado;
int tamanho = 0;


//Dando opção para o usuário escolher a dificuldade
printf("1 - Facil\n2 - Medio\n3 - Dificil\n\n");
scanf("%d", &escolha);

switch(escolha){
case 1:
    tamanho = 3;
    break;
case 2:
    tamanho = 5;
    break;
case 3:
    tamanho = 10;
    break;
default:
    printf("Opcao Invalida");
    break;
}


//Declarando Matriz de ponteiros
matriz = (int **)malloc(tamanho * sizeof(int**));
if(matriz == NULL){
    printf("ERRO");
    return 0;}

for(int linhas = 0; linhas <tamanho; linhas++){
    matriz[linhas] = (int *)malloc(tamanho * sizeof(int));
    if(matriz == NULL){
    printf("ERRO");
    return 0;}
}
srand(time(NULL));

//Inserido números aleatórios na Matriz
for(int linhas = 0; linhas <tamanho; linhas ++){
    for(int colunas = 0; colunas <tamanho; colunas ++){
        matriz[linhas][colunas] = rand() % 99;
    }
}

printf("\n\n");

//Imprimindo na tela a Matriz
for(int linhas = 0; linhas <tamanho; linhas ++){
    printf("|");
    for(int colunas = 0; colunas <tamanho; colunas ++){
        printf(" %d |", matriz[linhas][colunas]);
    }
    printf("\n");
}

printf("\nQual Numero da Matriz voce acha que sera sorteado?\n");
scanf("%d", &num_jogador);

srand(time(NULL));
num_sorteado = matriz[rand() % tamanho][rand() % tamanho];

if(num_jogador == num_sorteado){
    printf("\nVoce Acertou o numero sorteado foi %d", num_sorteado);
}
else{
    printf("\nVoce Errou o numero sorteado foi %d", num_sorteado);
}
for(int linhas; linhas<tamanho; linhas++){
    free(matriz[linhas]);
}    
free(matriz);
}
