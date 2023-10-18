#include "libTrabalho.h"

int alteraImagem(char arqFisicoImagensBase[], int id)
{
   //Abrindo arquivo binário no modo leitura e escrita e declarando uma string
   FILE *arq = fopen(arqFisicoImagensBase, "r+b");
   char novoProprietario[MAX_NAME];

   //Verificação de memória suficiente
   if (arq == NULL)
   {
      printf("\nFalha ao abrir o arquivo!\n"
             "Função alteraImagem\n");
      return 0;
   }
   //Declarando uma variável do tipo Imagem e definindo para "encontrou"
   Imagem img;
   int encontrou = 0;
   //Repete a estrutura enquanto fread for diferente de 0 e "encontrou" for diferente de 1
   while (fread(&img, sizeof(Imagem), 1, arq) != 0 && !encontrou)
   {
      if (img.id == id)
      {
         encontrou = 1;
      }
   }
   //Se encontrou for igual a 0, não existe o id na base de imagens
   if (!encontrou)
   {
      printf("\nID %d não encontrado na base de imagens!\n", id);
      fclose(arq);
      //Retorna 0 se não existe o ID informado na base de dados
      return 0;
   }
   //Usuário define um novo comentário para o campo do ID passado
   printf("Digite uma nova descrição para a imagem:  ");
   scanf("\n%[^\n]s", novoProprietario);
   //Copia comentário feito pelo usuário para o campo da imagem
   strcpy(img.proprietario, novoProprietario);
   //Altera a data para o momento da modificação do campo "Data de modificação"
   struct tm tm = getSystemTime();
   img.data_modificacao.dia = tm.tm_mday;
   img.data_modificacao.mes = tm.tm_mon + 1;
   img.data_modificacao.ano = tm.tm_year + 1900;
   //Altera a posição de leitura/escrita no arquivo 
   fseek(arq, -1 * sizeof(Imagem), SEEK_CUR);
   //Gravando mudança
   fwrite(&img, sizeof(Imagem), 1, arq);
   //Fechando arquivo
   fclose(arq);

   //Retorna 1 se existe o ID informado na base de dados
   return 1;
}