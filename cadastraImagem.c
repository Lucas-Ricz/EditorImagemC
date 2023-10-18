#include "libTrabalho.h"

int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[])
{
   //Declara uma variável do tipo Imagem e três do tipo inteiro e inicializa as variáveis com suas respectivas funções
   Imagem img;
   int verificaExistenciaImagem, verificaCadastroImagem, saida;
   verificaExistenciaImagem = verificaExistenciaDeImagem(nomeImagem);
   verificaCadastroImagem = verificaCadastro(arqFisicoImagensBase, nomeImagem);
   /*
   ---------------------------------------------------------------------------------------------------------------------
   verificaExistenciaImagem e retorna 1 se existir uma imagem com o nome especificado,
   ou seja, para cadastrar informações sobre uma imagem deve-se garantir que ela exista
   ---------------------------------------------------------------------------------------------------------------------
   verificaCadastroImagem retorna 1 se já houver alguma imagem cadastrada o que nao
   permite o cadastro
   ---------------------------------------------------------------------------------------------------------------------
   */
   if (verificaExistenciaImagem == 1 && verificaCadastroImagem == 0)
   {
      //Declarando as variáveis necessárias para as funções abaixo
      char extensaoImagem[7];
      int pAltura;
      int larguraImagem = getDimension(nomeImagem, &pAltura);
      char comentarioProprietario[MAX_NAME];
      //Copia nome para campo nome da imagem e define o ID da respectiva imagem
      strcpy(img.nome, nomeImagem);
      img.id = getLastId(arqFisicoImagensBase) + 1;
      /*
      obtem a extensao da imagem e a guarda em "extensaoImagem"
      depois a copia para img.tipo
      */
      getExtension(img.nome, extensaoImagem);
      strcpy(img.tipo, extensaoImagem);
      //Obtem o tamanho da imagem através da função getSize, que tem como parâmetro o nome da imagem
      img.size = getSize(nomeImagem);
      img.dimensao.altura = pAltura;
      img.dimensao.largura = larguraImagem;
      //Usuário define comentário sobre a imagem cadastrada
      printf("\nDigite um comentário para a imagem cadastrada: ");
      scanf("\n%[^\n]s", comentarioProprietario);
      //Copia comentário para campo proprietario da imagem
      strcpy(img.proprietario, comentarioProprietario);
      //Definindo data e hora de acordo com horário do computador no cadastro
      struct tm tm = getSystemTime();
      img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
      img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
      img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
   }
   //verificaCadastroImagem com valor igual a 1, retorna 1 se já houver alguma imagem cadastrada
   else if (verificaCadastroImagem == 1)
   {
      return 1;
   }
   //se não atender aos casos definidos acima retorna -1 para a main
   else
   {
      return -1;
   }
   //Saida recebe o cadastro da imagem na base
   saida = gravaInfoImagem(arqFisicoImagensBase, img);
   return saida;
}
