#include "libTrabalho.h"

void binarizar(int **mat, int lin, int col)
{
	//Declando variáveis necessárias para modificar matriz
	int i, j;
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			//Se valor em mat[i][j] for maior que 127 seu valor é alterado para 255 == branco
			if (mat[i][j] > 127)
			{
				mat[i][j] = 255;
			}
			//Se valor em mat[i][j] for menor ou igual a 127 seu valor é alterado para 0 == preto
			else
			{
				mat[i][j] = 0;
			}
		}
	}
}
