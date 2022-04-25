//Aluno 1: Anderson Correia de Souza; RA: 0030482121036;
//Aluno 2: Carlos Eduardo Marquetti Correa da Silva; RA: 0030482121014;

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){

    int l, c;
    int ValorPecaMes;
    int ValorGranaPeca;
    int matrizMes[3][3];
    int matrizGrana[3][2];
    int GranaMes[3][2];

    printf("Escreva as quantidades de Pecas \n\n");

    //Matriz PecaMes
    for(l = 0; l < 3 ; l++) {
        for(c = 0 ; c < 3 ; c++){
            ValorPecaMes = 0;
            if (l == 0)
            {
                printf("JAN P%d: ", c + 1);
                scanf("%d", &ValorPecaMes);
                matrizMes[l][c] = ValorPecaMes;
            }if(l == 1)
            {
                printf("FEV P%d: ", c + 1);
                scanf("%d", &ValorPecaMes);
                matrizMes[l][c] = ValorPecaMes;
            }if(l == 2)
            {
                printf("MAR P%d: ", c + 1);
                scanf("%d", &ValorPecaMes);
                matrizMes[l][c] = ValorPecaMes;
            }
        }
        printf("\n");
    }

    //Matriz GranaPeca
    for(l = 0; l < 3; l++) {
        for(c = 0; c < 2; c++){
            ValorGranaPeca = 0;
            if (c == 0)
            {
                printf("CUSTO P%d: ", l + 1);
                scanf("%d", &ValorGranaPeca);
                matrizGrana[l][c] = ValorGranaPeca;
            }
            if (c == 1)
            {
                printf("LUCRO P%d: ", l + 1);
                scanf("%d", &ValorGranaPeca);
                matrizGrana[l][c] = ValorGranaPeca;
            }
        }
        printf("\n");
    }

    //Matriz GranaMes == Calculo

    GranaMes[0][0] = (matrizMes[0][0] * matrizGrana[0][0]) + (matrizMes[0][1] * matrizGrana[1][0]) + (matrizMes[0][2] * matrizGrana[2][0]);
    GranaMes[0][1] = (matrizMes[0][0] * matrizGrana[0][1]) + (matrizMes[0][1] * matrizGrana[1][1]) + (matrizMes[0][2] * matrizGrana[2][1]);
    
    GranaMes[1][0] = (matrizMes[1][0] * matrizGrana[0][0]) + (matrizMes[1][1] * matrizGrana[1][0]) + (matrizMes[1][2] * matrizGrana[2][0]);
    GranaMes[1][1] = (matrizMes[1][0] * matrizGrana[0][1]) + (matrizMes[1][1] * matrizGrana[1][1]) + (matrizMes[1][2] * matrizGrana[2][1]);
    
    GranaMes[2][0] = (matrizMes[2][0] * matrizGrana[0][0]) + (matrizMes[2][1] * matrizGrana[1][0]) + (matrizMes[2][2] * matrizGrana[2][0]);
    GranaMes[2][1] = (matrizMes[2][0] * matrizGrana[0][1]) + (matrizMes[2][1] * matrizGrana[1][1]) + (matrizMes[2][2] * matrizGrana[2][1]);
    
    //Saida

    printf("Matriz PecaMes:\n     P1  P2  P3 \n Jan %d   %d   %d \n Fev %d   %d   %d \n Mar %d   %d   %d \n\n"
    , matrizMes[0][0], matrizMes[0][1], matrizMes[0][2], matrizMes[1][0], matrizMes[1][1], matrizMes[1][2], matrizMes[2][0],
     matrizMes[2][1], matrizMes[2][2]);

    printf("Matriz GranaPeca:\n   Cus Luc \n P1 %d  %d \n P2 %d  %d \n P3 %d  %d  \n\n", matrizGrana[0][0], matrizGrana[0][1],
    matrizGrana[1][0], matrizGrana[1][1], matrizGrana[2][0], matrizGrana[2][1]);

    printf("Matriz GranaMes:\n    Cus Luc \n P1 %d  %d \n P2 %d  %d \n P3 %d  %d  \n\n", GranaMes[0][0], GranaMes[0][1],
    GranaMes[1][0], GranaMes[1][1], GranaMes[2][0], GranaMes[2][1]);

    return 0;
}