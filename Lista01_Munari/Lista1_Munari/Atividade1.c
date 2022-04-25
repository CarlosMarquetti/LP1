//Aluno 1: Anderson Correia de Souza; RA: 0030482121036;
//Aluno 2: Carlos Eduardo Marquetti Correa da Silva; RA: 0030482121014;

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void semanaPorEscrito(int);

int main (void){
	int data, m, d, a, s;
	int ano, mes, diaDaSemana;


	while (data != 0)
	{
		printf("informe a data em (ddmmaaaa): ");
		scanf("%d", &data);

		ano = data % 10000;
		mes = (data % 1000000) / 10000;

		if(mes < 3){
			m = mes + 10;
			ano = ano - 1;
		}
		else
			m = mes - 2;

		d = data / 1000000;
		s = ano / 100;
		a = ano % 100;

		diaDaSemana = ((int)(2.6 * m - 0.1) + d + a + (a / 4) + (s / 4) - 2 * s) % 7;

		if(diaDaSemana < 0)
			diaDaSemana = diaDaSemana + 7;

		if(mes < 3) 
			ano = ano + 1;
		if (data == 0)
		{
			printf("\nPrograma Encerrado...");

			break;
		}
		
		printf("%02d/%02d/%d: " ,d ,mes ,ano);
		semanaPorEscrito(diaDaSemana);
		printf("\n");
	}
	return 0;
}

void semanaPorEscrito(int diaDaSemana){
	
	
	if(diaDaSemana == 0)
		printf("Domingo");
	if(diaDaSemana == 1)
		printf("Segunda-Feira");
	if(diaDaSemana == 2)
		printf("Terca-Feira");
	if(diaDaSemana == 3)
		printf("Quarta-Feira");
	if(diaDaSemana == 4)
		printf("Quinta-Feira");
	if(diaDaSemana == 5)
		printf("Sexta-Feira");
	if(diaDaSemana == 6)
		printf("Sabado");
}