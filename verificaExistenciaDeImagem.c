#include "libTrabalho.h"

/*Esta função verifica se dentro do diretório corrente (.) existe um arquivo com nome imagem_a_verificar.
 * */
int verificaExistenciaDeImagem(char imagem_a_verificar[])
{
    DIR *diretorio;
    struct dirent *listarDiretorio;
    int existe = 0;

    // abre o diretório corrente (.)
    diretorio = opendir(".");

    // Pega cada arquivo/diretório dentro do diretório corrente (.)
    while ((listarDiretorio = readdir(diretorio)) != NULL)
    {
        // Verifica se o nome do arquivo/diretório é igual a imagem_a_verificar
        if (strcmp(listarDiretorio->d_name, imagem_a_verificar) == 0)
        {
            // printf ("%s\n existe \n", listarDiretorio->d_name);
            existe = 1;
        }
    }

    closedir(diretorio);

    return existe;
}
