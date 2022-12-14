#include <stdio.h>
#include <stdlib.h>
#define TAM 3

char jogo[TAM][TAM];

int verifica_igual(char caractere){
    if (caractere == 'x' || caractere == '0'){
        return 1;
    }else{
        return 0;
    }
}
int Linhas(){
    int i, j, cont = 1;
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM - 1; j++){
            if(verifica_igual(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
                cont++;
        }
        if(cont == TAM){
            return 1;
        }
        cont = 1;
    }
    return 0;
}
int Colunas(){
    int i, j, cont = 1;
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM - 1; j++){
            if(verifica_igual(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
                cont++;
        }
        if(cont == TAM){
            return 1;
        }
        cont = 1;
    }
    return 0;
}
int Diagonal_Principal() {
    int i, cont = 1;
    for(i = 0; i < TAM - 1; i++) {
        if(verifica_igual(jogo[i][i]) && jogo[i][i] == jogo[i+1][i+1])
            cont++;
    }
    if(cont == TAM){
        return 1;
    }  
    else{
        return 0;
    }
}
int Diagonal_Secundaria(){
    int i, cont = 1;
    for(i = 0; i < TAM - 1; i++){
        if(verifica_igual(jogo[i][3-i-1]) && jogo[i][3-i-1] == jogo[i+1][3-i-2])
            cont++;
    }
    if(cont == TAM){
        return 1;
    } 
    else{
        return 0;
    }
}
void imprimir(){
    int l,c;

    printf("\n\t    0  1  2\n");
    for(l = 0; l < TAM; l++){
        printf("\t%d ", l);
        for(c = 0; c < TAM; c++) {
            if(c < 2)
                printf(" %c |", jogo[l][c]);
            else
                printf(" %c ", jogo[l][c]);
        }
        if(l < 2)
            printf("\n\t   ---------\n");
    }
}

void jogar() {
    int x, y, contj = 0, win = 0, first = 1;

    do {
        imprimir();
        printf("\nDigite qual posicao voce deseja realizar sua jogada: ");
        scanf("%d%d", &x, &y);
          
        if(first == 1)
            jogo[x][y] = 'x';
        else
            jogo[x][y] = '0';
        contj++;
        first++;
        if(first == TAM)
            first = 1;
        win += Linhas();
        win += Colunas();
        win += Diagonal_Principal();
        win += Diagonal_Secundaria();
    } while(win == 0 && contj < 9);

    if(win != 0){
        imprimir();
        if(first - 1 == 1){
            printf("\n\nfirst player Win!\n");
        }else
            printf("\n\nfirst second Win!\n");
            }else
                printf("\n\nGamer Over!\n\n");
}
int main() {
        jogar();
    return 0;
    system("PAUSE");
}