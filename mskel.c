/* 
 ** Universidade Federal de São Carlos
 ** Departamento de Computação
 ** Prof. Hélio Crestana Guardia
 ** Programação Paralela e Distribuída
 */

/*
 ** Programa : multiplicação de matrizes
 ** Objetivo: paralelização 
 */

#include <math.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include <unistd.h>
#include <time.h>

float *A, *B, *C;

int
main(int argc, char *argv[])
{
    int lin_a,col_a,lin_b,col_b,lin_c,col_c;
    int i,j,k;

    // Definindo tamanho
    printf("Linhas A: ");
    scanf("%d",&lin_a);
    printf("Colunas A / Linhas B: ");
    scanf("%d",&col_a);
    lin_b=col_a;
    printf("Colunas B: ");
    scanf("%d",&col_b);
    printf("\n");
    lin_c=lin_a;
    col_c=col_b;

    // Alocação dinâmica das matrizes, com linhas em sequência 
    A=(float *)malloc(lin_a*col_a*sizeof(float));
    B=(float *)malloc(lin_b*col_b*sizeof(float));
    C=(float *)malloc(lin_c*col_c*sizeof(float));

    // Atribuição de valores iniciais às matrizes 
    srandom(time(NULL));

    for(i=0; i < lin_a * col_a; i++) 
        A[i]=(float)rand() / (float)RAND_MAX; 

    for(i=0; i < lin_b * col_b; i++) 
        B[i]=(float)rand() / (float)RAND_MAX; 


    // cálculo da multiplicação

    for(i=0; i < lin_c; i++) 

        for(j=0; j < col_c; j++) {

            C[i*col_c+j]=0;

            for(k=0; k < col_a; k++) 
                C[i*col_c+j] = C[i*col_c+j] + A[i*col_a+k] * B[k*col_b+j];
        }

    /*
    // verificacao de consistencia da operacao paralela
    float *AB = (float *)malloc(lin_c*col_c*sizeof(float));
    float soma;

    for(i=0; i < lin_c; i++) 
    for(j=0; j < col_c; j++) {
    soma=0;
// AB[i*col_c+j]=0;
for(k=0; k < col_a; k++) 
soma += A[i*col_a+k] * B[k*col_b+j];
// AB[i*col_c+j] += A[i*col_a+k] * B[k*col_b+j];
AB[i*col_c+j] = soma;
}
int erros=0;
for(i=0; i < lin_c * col_c; i++) 
if(AB[i]!=C[i])
erros++;
if(erros)
printf("Erros no calculo: %d\n",erros);
*/

/*
   for(i=0;i<lin_c;i++) {
   for(j=0;j<col_c;j++) 
   printf("%2.2f ",C[i*col_c+j]);
   printf("          ");
   for(j=0;j<col_c;j++) 
   printf("%2.2f ",AB[i*col_c+j]);
   printf("\n");
   }
   */

return(0);
}



