#include "libTrabalho.h"

int getLastId(char arqFisicoImagensBase[])
{
   //Declarando variáveis do tipo int e Imagem
   int lastId = 0;
   Imagem img;
   //Abrindo arquivo binário em modo de leitura
   FILE *arq = fopen(arqFisicoImagensBase, "rb");
   //Verifica se arquivo abriu corretamente
   if (arq == NULL)
   {
      printf("Falha ao abrir o arquivo!\n");
      return 0;
   }
   //Lê o arquivo até o fim, e obtém o valor do último ID cadastrado
   while (fread(&img, sizeof(img), 1, arq) != 0)
   {
      lastId = img.id;
   }
   //Fecha arquivo e retorna o último ID
   fclose(arq);
   return lastId;
}
