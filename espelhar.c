#include "libTrabalho.h"

void espelhar(int **mat, int lin, int col)
{
   //Declarando variáveis
   int i, j;
   //Espelhando matriz
   for (i = 0; i < lin; i++)
   {
      for (j = 0; j < col / 2; j++)
      {
         int temp = mat[i][j];
         mat[i][j] = mat[i][col - j - 1];
         mat[i][col - j - 1] = temp;
      }
   }
}
