#include "libTrabalho.h"

void copiaMatrizImagem(int **mat, int **matCopia, int lin, int col)
{
   //Declarando variáveis
   int i, j;
   //Copia elementos da matriz original para matCopia
   for (i = 0; i < lin; i++)
   {
      for ( j = 0; j < col; j++)
      {
         
         matCopia[i][j] = mat[i][j];
      }
   }
}
