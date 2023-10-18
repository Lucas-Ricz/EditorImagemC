#include "libTrabalho.h"

int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[])
{
   //Declara variável aux do tipo Imagem
   Imagem aux;
   //Abre arquivo binário no modo leitura/escrita
   FILE *arqImagens = fopen(arqFisicoImagensBase, "a+b");
   //Verifica se o arquivo abriu corretamente
   if (arqImagens == NULL)
   {
      printf("Falha ao abrir o arquivo!\n");
      return 0;
   }
   //Rebobina para o começo do arquivo
   rewind(arqImagens);

   /*Se existir uma imagem já cadastrada com um mesmo nome
   a função verificaCadastro retorna 1 caso contrário 0*/
   while (fread(&aux, sizeof(Imagem), 1, arqImagens) != 0)
   {
      if (strcmp(aux.nome, nomeImagem) == 0)
      {
         fclose(arqImagens);
         return 1;
      }
   }
   //Fecha arquivo
   fclose(arqImagens);
   return 0;
}
