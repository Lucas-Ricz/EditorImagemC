#include "libTrabalho.h"

int getDimension(char nomeImagem[], int *pAltura)
{
	//Declarando variaveis e abrindo o arquivo
	int largura;
	char tipoImagem[10];
	*pAltura = 0;
	FILE *leituraArquivo = fopen(nomeImagem, "r");

	//Verificando se o arquivo abriu corretamente
	if (leituraArquivo == NULL)
	{
		printf("n\nErro ao abrir arquivo %s na função printFile.\n", leituraArquivo);
		return 0;
	}
	//Lê informações do arquivo passado
	fscanf(leituraArquivo, "%s %d %d", tipoImagem, &largura, pAltura);
	//Fecha arquivo e retorna a largura
	fclose(leituraArquivo);
	return largura;
}
