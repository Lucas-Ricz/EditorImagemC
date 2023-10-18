#include "libTrabalho.h"

void ruido(int **mat, int lin, int col)
{
   //Declando variáveis
   int i, j;
   //Atribui uma semente para gerar valores aleatórios
   srand(time(NULL));
   //Soma valores aleatórios de 0 até 100 nas posições da matriz com parametros pré-estabelecidos
   for (i = 0; i < lin; i++)
   {
      for (j = 0; j < col; j++)
      {
         mat[i][j] = mat[i][j] + rand() % 101;

         if (mat[i][j] > 255)
         {
            mat[i][j] = 255;
         }
      }
   }
}
