#include "libTrabalho.h"

int gravaImagem(char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat)
{
   //Abrindo arquivo texto em modo leitura/escrita, e declarando variáveis
   FILE *arq = fopen(nomeArqSaida, "a+");
   int i, j;
   //Verifica se arquivo abriu corretamente, se caso não tenha sido aberto corretamente retorna 1
   if (arq == NULL)
   {
      printf("Erro ao criar arquivo!\n"
             "Função gravaImagem\n");
      return 1;
   }
   //Escrevendo informações no arquivo com as respectivas variáveis
   fprintf(arq, "%s \n%d %d \n%d \n", tipo, col, lin, maxval);
   //Escrevendo valores da matriz no arquivo
   for (i = 0; i < lin; i++)
   {
      for (j = 0; j < col; j++)
      {
         fprintf(arq, "%d ", mat[i][j]);
      }
      fprintf(arq, "\n");
   }
   //Fechando arquivo
   fclose(arq);
   return 0;
}
