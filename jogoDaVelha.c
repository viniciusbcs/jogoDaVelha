#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void boasVindas();
void jogar();
void pontos();
void desenha(char *s);
char marcaPosicao(char *s, char ch);
char pegaPosicao();
void marcaPosicaoDois(char *s, char ch);
int verificaVitoria(char *s);
void mensagemVencedor();

int main(int argc, char *argv[]){
    boasVindas();
    char ch;
    printf("Digite a opção: ");
    scanf("%c", &ch);
    printf(" \n");
    
    switch(ch) {
        case '1':
            jogar();
            break;
        case '2':
            pontos();
            break;
        case '3':
            exit(1);
            break;
        default:
            printf("Comando não encontrado!\n");
    }

    return 0;
}

void boasVindas(){
    printf("\nBem vindo ao Jogo da Velha! \n\n");
    printf("Menu: \n");
    printf("(1) Jogar \n");
    printf("(2) Ver pontuação \n");
    printf("(3) Sair \n\n");
}

void jogar(){
    char s[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    char posicao, posicaoDois, novo[9];
    desenha(s);
    int contador = 0;
    while(contador < 9) {
        printf("Vez do 'X' \n");
        posicao = pegaPosicao();
        marcaPosicao(s, posicao);
        desenha(s);
        if(verificaVitoria(s)) exit(1);
        printf("Vez do 'O' \n");
        posicaoDois = pegaPosicao();
        marcaPosicaoDois(s, posicaoDois);
        desenha(s);
        if(verificaVitoria(s)) exit(1);
        contador++;
    }  
}

void pontos(){
    printf("\n Não há nenhum registro. \n");
}

void desenha(char *s){
    printf("  %c  | %c |  %c  \n", s[0], s[1], s[2]);
    printf("----------------\n");
    printf("  %c  | %c |  %c  \n", s[3], s[4], s[5]);
    printf("----------------\n");
    printf("  %c  | %c |  %c  \n\n", s[6], s[7], s[8]);
}

char marcaPosicao(char *s, char ch){
    switch(ch) {
        case 'a':
            s[0] = 'X';
            break;
        case 'b':
            s[1] = 'X';
            break;
        case 'c':
            s[2] = 'X';
            break;
        case 'd':
            s[3] = 'X';
            break;
        case 'e':
            s[4] = 'X';
            break;
        case 'f':
            s[5] = 'X';
            break;
        case 'g':
            s[6] = 'X';
            break;
        case 'h':
            s[7] = 'X';
            break;
        case 'i':
            s[8] = 'X';
            break;
        default:
            printf("Opção inválida! \n");
    }
    return *s;
}

void marcaPosicaoDois(char *s, char ch){
    switch(ch) {
        case 'a':
            s[0] = 'O';
            break;
        case 'b':
            s[1] = 'O';
            break;
        case 'c':
            s[2] = 'O';
            break;
        case 'd':
            s[3] = 'O';
            break;
        case 'e':
            s[4] = 'O';
            break;
        case 'f':
            s[5] = 'O';
            break;
        case 'g':
            s[6] = 'O';
            break;
        case 'h':
            s[7] = 'O';
            break;
        case 'i':
            s[8] = 'O';
            break;
        default:
            printf("Opção inválida! \n");
    }
}

char pegaPosicao(){
    char ch;
    printf("Digite a posição: \n");
    scanf(" %c", &ch);
    return ch;
}

int verificaVitoria(char *s){
    //printf("%c", s[0]);
    if(s[0] == s[4] && s[4] == s[8]){
        mensagemVencedor();
        return 1;
    }else if(s[2] == s[5] && s[5] == s[8]){
        mensagemVencedor();
        return 1;
    }else if(s[1] == s[4] && s[4] == s[7]){
        mensagemVencedor();
        return 1;
    }else if(s[0] == s[3] && s[3] == s[6]){
        mensagemVencedor();
        return 1;
    }else if(s[6] == s[7] && s[7] == s[8]){
        mensagemVencedor();
        return 1;
    }else if(s[3] == s[4] && s[4] == s[5]){
        mensagemVencedor();
        return 1;
    }else if(s[0] == s[1] && s[1] == s[2]){
        mensagemVencedor();
        return 1;
    }else if(s[2] == s[4] && s[4] == s[6]){
        mensagemVencedor();
        return 1;
    }else {
        return 0;
    }
}

void mensagemVencedor(){
    printf("Temos um ganhador! \n");
}