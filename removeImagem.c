#include "libTrabalho.h"

// Função para remover imagem com id da base arqFisicoImagensBase e do diretório corrente
void removeImagem(char arqFisicoImagensBase[], int id)
{
	FILE *arq = fopen(arqFisicoImagensBase, "a+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo - removeImagem\n");
		return;
	}
	// descola ponteiro para início do arquivo (a+ abre arquivo no final)
	rewind(arq);

	// Usa um arquivo temporário para copiar (da base) somente os arquivos
	// com id diferente do id a ser removido
	FILE *arqTmp = fopen("tmp.bin", "wb");

	int achou = 0;
	Imagem img;
	/*Percorre todas as imagens cadastradas na base copiando para o arquivo
	 * temporário as imagens com id != do id a ser removido.
	 * */
	while ((fread(&img, sizeof(Imagem), 1, arq) != 0))
	{
		// img.id não é a imagem a ser removida
		if (img.id != id)
		{
			// Copia imagem com img.id != id para o arquivo temporário
			fwrite(&img, sizeof(Imagem), 1, arqTmp);
		}
		else
		{
			// Encontrou a imagem com id a ser removido na base
			achou = 1;
			printf("\nImagem %s (id: %d) removida.", img.nome, img.id);
			// Remove a imagem com nome img.nome do diretório corrente
			remove(img.nome);
		}
	}

	fclose(arq);
	fclose(arqTmp);

	if (!achou)
	{
		printf("\nRemoção não realizada. Imagem com ID %d inexistente na base.\n", id);
		remove("tmp.bin");
		return;
	}

	// Remove o arquivo original (arqFisicoImagensBase) do diretório corrente
	remove(arqFisicoImagensBase);
	// Renomeia o arquivo temporário tmp.bin para arqFisicoImagensBase, ou seja, com imagem (img.id=id) já "removida"
	rename("tmp.bin", arqFisicoImagensBase);
}
