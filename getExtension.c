#include "libTrabalho.h"

void getExtension(char nomeImagem[], char extension[])
{
   //Declarando variáveis
   int i, j, k = 0;
   //Percorre o nome do arquivo e a partir do ponto, acrescenta o restante em "extension"
   for (i = 0; nomeImagem[i] != '\0'; i++)
   {
      if (nomeImagem[i] == '.')
      {
         extension[k] = nomeImagem[i];
         i++;
         k++;
         for (j = i; nomeImagem[j] != '\0'; j++)
         {
            extension[k] = nomeImagem[j];
            k++;
         }
         i = j;
      }
   }
   //Finaliza a string com '\0'
   extension[k] = '\0';
}