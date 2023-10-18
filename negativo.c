#include "libTrabalho.h"

void negativo(int **mat, int lin, int col)
{
   //Declarando variáveis
   int i, j;
   //Inverte o branco(255) com o preto(0), e vice versa. E por ultimo uma posição x, vira 255 - x
   for (i = 0; i < lin; i++)
   {
      for (j = 0; j < col; j++)
      {
         if (mat[i][j] == 255)
         {
            mat[i][j] = 0;
         }
         else if (mat[i][j] == 0)
         {
            mat[i][j] = 255;
         }
         else
         {
            mat[i][j] = 255 - mat[i][j];
         }
      }
   }
}
