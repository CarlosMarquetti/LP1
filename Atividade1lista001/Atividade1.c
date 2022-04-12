#include <stdio.h>

void semanaPorEscrito(int);

int main (void){
	int data, m, d, a, s;
	int ano, mes, diaDaSemana;


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
	
	printf("%02d/%02d/%d: " ,d ,mes ,ano);
	semanaPorEscrito(diaDaSemana);
}

void semanaPorEscrito(int diaDaSemana){
	
	
	if(diaDaSemana == 0)
		printf("Domingo");
	if(diaDaSemana == 1)
		printf("Segunda-Feira");
	if(diaDaSemana == 2)
		printf("Terça-Feira");
	if(diaDaSemana == 3)
		printf("Quarta-Feira");
	if(diaDaSemana == 4)
		printf("Quinta-Feira");
	if(diaDaSemana == 5)
		printf("Sexta-Feira");
	if(diaDaSemana == 6)
		printf("Sábado");
}