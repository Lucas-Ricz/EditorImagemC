/** @file   libTrabalho
    @author Juliana de Santi
*/

#ifndef _LIBTRABALHO_H_
#define _LIBTRABALHO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
//Adicionando biblioteca que permite utilizar acentos da língua portuguesa
#include <locale.h>

//=============== Constantes =======================
#define MAX_NAME 50 // número máximo de caracteres usado para nome do proprietario da imagem

//=============== Registros/structs =======================
// Registro para a definição do tipo Data
typedef struct data
{
  int dia, mes, ano;
} Data;

// Registro para definicão do tipo Dimension
typedef struct dimension
{
  int altura;
  int largura;
} Dimension;

// Registro para a definição do tipo Imagem
typedef struct imagem
{
  char nome[40];
  int id;
  // Neste trabalho, o tipo considerado é PGM
  char tipo[7];
  // em bytes
  int size;
  Dimension dimensao;
  char proprietario[MAX_NAME];
  Data data_criacao;
  Data data_modificacao;
} Imagem;

////=============== Menu de operações possíveis ==========================
void menuOperacoes();

//=============== Protótipos da parte de cadastros =======================
void listaImagens(char arqFisicoImagensBase[]);

int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]);
int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]);
int verificaExistenciaDeImagem(char imagem_a_verificar[]);
struct tm getSystemTime();
int getLastId(char arqFisicoImagensBase[]);
void getExtension(char nomeImagem[], char extension[]);
int getSize(char nomeImagem[]);
int getDimension(char nomeImagem[], int *pAltura);

int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img);
int alteraImagem(char arqFisicoImagensBase[], int id);
void removeImagem(char arqFisicoImagensBase[], int id);

//=============== Protótipos das operações sobre as imagens =============

char *alocaString(int size);
int **alocaMatrizImagem(int lin, int col);
void desalocaMatrizImagem(int **mat, int lin);

int **leArquivoImagem(char *nomeArq, char *tipo, int *lin, int *col, int *maxval);
void copiaMatrizImagem(int **mat, int **matCopia, int lin, int col);
int gravaImagem(char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat);
Imagem getImage(char arqFisicoImagensBase[], char auxNomeImagem[]);

void espelhar(int **mat, int lin, int col);
void binarizar(int **mat, int lin, int col);
void negativo(int **mat, int lin, int col);
void ruido(int **mat, int lin, int col);

#endif
