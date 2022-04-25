//Aluno 1: Anderson Correia de Souza; RA: 0030482121036;
//Aluno 2: Carlos Eduardo Marquetti Correa da Silva; RA: 0030482121014;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char validarCPF(char[]);
void contrucaoCPF(char[]);
char digitosIguaisItemB(char[]);
short multiplicacaoESomaItemC();
void restoDivisaoDigitoVerificador1ItemD(short);
short multiplicarEsomarInversoItemE();
void multiplicaPor10DividePor11DigitoVerificador2ItemF(short);
void cpfNumerico(char[]);

unsigned char valoresNumericos[12];
const char cod0DaTabelaASCII = 48;

int main(void)
{
	char cpfInformado[15];
	char valido;

	printf("\n----------- VALIDACAO DE CPF -----------\n");

	do
	{
		printf("Informe o seu CPF (999.999.999-99): ");
		scanf("%s", cpfInformado);

		valido = validarCPF(cpfInformado);

		switch(valido)
		{
			case 's':
				printf("CPF valido");
				break;

			case 'n':
				printf("CPF invalido - esperado: ");
				printf("%d%d, ", valoresNumericos[9], valoresNumericos[10]);
				printf("encontrado: ");
				printf("%c%c", cpfInformado[12], cpfInformado[13]);
				break;

			case 'i':
				printf("CPF invalido");
		}

		printf("\n\n");
	}while(valido != 'p');

	printf("PROGRAMA FINALIZADO");

	return 0;
}

char validarCPF(char cpfInformado[])
{
	char valido;
	char dVerificador1Encontrado, dVerificador2Encontrado;

	valido = digitosIguaisItemB(cpfInformado);

	if(valido == 's')
	{
		contrucaoCPF(cpfInformado);

		dVerificador1Encontrado = valoresNumericos[9] + cod0DaTabelaASCII;
		dVerificador2Encontrado = valoresNumericos[10] + cod0DaTabelaASCII;

		if(cpfInformado[12] != dVerificador1Encontrado || cpfInformado[13] != dVerificador2Encontrado)
			valido = 'n';
	}

	return valido;
}

void contrucaoCPF(char cpfInformado[])
{
	cpfNumerico(cpfInformado);
	restoDivisaoDigitoVerificador1ItemD(multiplicacaoESomaItemC());
	multiplicaPor10DividePor11DigitoVerificador2ItemF(multiplicarEsomarInversoItemE());
}

//Itens Exigidos no Enunciado
char digitosIguaisItemB(char cpfInformado[])
{
	char valido = 'i';
	unsigned char caracterAnalisado;
	
	int indiceCaractere;
	for(indiceCaractere = 0; indiceCaractere < strlen(cpfInformado); indiceCaractere++)
	{
		if(indiceCaractere == 3 || indiceCaractere == 7 || indiceCaractere == 11)
			indiceCaractere++;

		if(indiceCaractere == 0)
			caracterAnalisado = cpfInformado[indiceCaractere];
		else if(caracterAnalisado != cpfInformado[indiceCaractere])
			valido = 's';		
	}
	
	if(valido == 'i' && caracterAnalisado == '0')
		valido = 'p';

	return valido;
}


short multiplicacaoESomaItemC()
{
	short resultado = 0;

	unsigned char indiceCpfNumerico;
	for(indiceCpfNumerico = 0; indiceCpfNumerico < 9; indiceCpfNumerico++)
	{
		resultado = resultado + ((indiceCpfNumerico + 1) * valoresNumericos[indiceCpfNumerico]);
	}

	return resultado;
}

void restoDivisaoDigitoVerificador1ItemD(short valorEntrada)
{
	char digitoVerificador1;

	digitoVerificador1 = valorEntrada % 11;

	if(digitoVerificador1 == 10)
		digitoVerificador1 = 0;

	valoresNumericos[9] = digitoVerificador1;
}

short multiplicarEsomarInversoItemE()
{
	short resultado = 0;

	unsigned char indiceCpfNumerico;
	for(indiceCpfNumerico = 0; indiceCpfNumerico < 10; indiceCpfNumerico++)
	{
		resultado = resultado + ((11 - indiceCpfNumerico) * valoresNumericos[indiceCpfNumerico]);
	}

	return resultado;
}

void multiplicaPor10DividePor11DigitoVerificador2ItemF(short valorEntrada)
{
	char digitoVerificador2;

	digitoVerificador2 = (valorEntrada * 10) % 11;

	if(digitoVerificador2 == 10)
		digitoVerificador2 = 0;

	valoresNumericos[10] = digitoVerificador2;
}

//Auxiliar
void cpfNumerico(char cpfInformado[])
{
	//unsigned char valoresNumericos[12];
	valoresNumericos[12] = '\0';

	unsigned char indiceCpfNumerico = 0;

	unsigned char indiceCaractere;
	for(indiceCaractere = 0; indiceCaractere < 11; indiceCaractere++)
	{
		if(indiceCaractere == 3 || indiceCaractere == 7 || indiceCaractere == 11)
			indiceCaractere++;

		valoresNumericos[indiceCpfNumerico] = cpfInformado[indiceCaractere] - cod0DaTabelaASCII;
		indiceCpfNumerico++;
	}
}