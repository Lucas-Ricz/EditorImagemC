#include "libTrabalho.h"

int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img)
{
   //Abrindo arquivo binário em modo de leitura/escrita
   FILE *arq = fopen(arqFisicoImagensBase, "a+b");
   //Verifica se arquivo abriu corretamente, se caso contrário retorna -1
   if (arq == NULL)
   {
      printf("Erro ao abrir o arquivo!\n"
               "Função gravaInfoImagem\n");
      return -1;
   }
   //Gravando um bloco de informações sobre a Imagem passada
   fwrite(&img, sizeof(Imagem), 1, arq);
   //Fechando arquivo
   fclose(arq);
   return 0;
}
