
#include <stdio.h>

#include <stdlib.h>

#include <math.h>


const double PI = 3.14159265359;


int main(int argc, const char *argv[]){



printf("Digite o comprimento das agulhas (entre 0.1 e 1.0): ");

float comprimento;

scanf("%f",&comprimento);

printf("Digite um valor inteiro aleatorio: ");

int N;

scanf("%d",&N);

FILE *file;

file = fopen("results.dat","w");

fprintf(file,"n\tapprox\tapprox-pi\n");

int Nhit = 0;

for(int i=0; i<N; i++) {

double a = 2*PI*rand()/RAND_MAX; // angle

double x = (double)rand()/RAND_MAX - 0.5; // middle

double x1 = x - (comprimento/2)*cos(a);

double x2 = x + (comprimento/2)*cos(a);

if(x1*x2 <= 0){Nhit++;}

double pi = 2 * comprimento * (i+1)/Nhit;

fprintf(file,"%d\t%f\t%f\n",i,pi,pi-PI);

}

fclose(file);

double pi = 2 * comprimento * N/Nhit;

printf("\n---resultados------------------------\n\n");

printf("Aproximacao:\npi = %f\n\n",pi);

printf("Resultado exato:\npi = %f\n",PI);

return 0;


}
