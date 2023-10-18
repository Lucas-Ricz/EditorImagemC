#include "libTrabalho.h"

void listaImagens(char arqFisicoImagensBase[])
{
   // Abrindo arquivo para listar imagens no modo leitura
   FILE *arqListaImagens = fopen(arqFisicoImagensBase, "rb");
   // Verifica se existe algum problema no arquivo
   if (arqListaImagens == NULL)
   {
      printf("Falha ao abrir o arquivo! - Função listaImagens\n");
      printf("Verifique se existe base de Cadastro!\n");
      return;
   }
   //Declara uma variável tmp do tipo Imagem, e lê os blocos de informações das imagens
   Imagem tmp;
   while (fread(&tmp, sizeof(Imagem), 1, arqListaImagens) != 0)
   {
      printf("Nome: %s\n"
             "Id: %d\n"
             "Tipo: %s\n"
             "Tamanho: %d bytes\n"
             "Dimensão: Altura = %d | Largura = %d \n"
             "Proprietário: %s\n"
             "Data de criação: %d/%d/%d\n"
             "Data de modificação: %d/%d/%d\n",
             tmp.nome, tmp.id, tmp.tipo, tmp.size, tmp.dimensao.altura, tmp.dimensao.largura,
             tmp.proprietario, tmp.data_criacao.dia, tmp.data_criacao.mes, tmp.data_criacao.ano,
             tmp.data_modificacao.dia, tmp.data_modificacao.mes, tmp.data_modificacao.ano);
      printf("\n");
   }
   //Fecha arquivo
   fclose(arqListaImagens);
}
