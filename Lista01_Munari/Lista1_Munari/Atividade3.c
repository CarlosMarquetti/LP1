//Aluno 1: Anderson Correia de Souza; RA: 0030482121036;
//Aluno 2: Carlos Eduardo Marquetti Correa da Silva; RA: 0030482121014;

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char isVogal(char);
char verificacao(char[], char[]);

int main(void)
{
    char nome1[21], nome2[21];
    int quantidade;

    printf("Quantidade de testes: ");
    scanf("%d", &quantidade);

    char contador;
	for(contador = 1; contador <= quantidade; contador++)
	{
		printf("Insira o primeiro nome: ");
		scanf("%s", nome1);

		printf("Insira o segundo nome: ");
		scanf("%s", nome2);
		
	    char nomesIguais;
	    nomesIguais = verificacao(nome1, nome2);

	    if(nomesIguais == 's')
	    	printf("Yes\n");
	    else
	    	printf("No\n");
	}
    return 0;
}


char verificacao(char nome1[], char nome2[])
{
	char valido = 's';
	char caractereNome1, caractereNome2;

	if(strlen(nome1) != strlen(nome2))
		valido = 'n';
	else
	{
		unsigned char indiceCaractere;
		for(indiceCaractere = 0; indiceCaractere < strlen(nome2); indiceCaractere++)
		{
			caractereNome1 = nome1[indiceCaractere];
			caractereNome2 = nome2[indiceCaractere];

			if(caractereNome1 != caractereNome2)
			{
				if(isVogal(caractereNome1) == 'n' || isVogal(caractereNome2) == 'n')
				{
					valido = 'n';
					break;
				}
			}
		}
	}

	return valido;
}

char isVogal(char caractereDoNome)
{
	char continua = 'n';

	char vogais[6];
	vogais[0] = 'a';
	vogais[1] = 'e';
	vogais[2] = 'i';
	vogais[3] = 'o';
	vogais[4] = 'u';
	vogais[5] = '\0';

	caractereDoNome = tolower(caractereDoNome);	

	int contadorVogal;
	for(contadorVogal = 0; contadorVogal < strlen(vogais); contadorVogal++)
	{
		if(caractereDoNome == vogais[contadorVogal])
		{
			continua = 's';
			break;
		}
	}
	
	return continua;
}