// libTrabalho.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos.
#include "libTrabalho.h"

int main()
{
	// Adaptando localidade do programa para ter a possibilidade de utilizar acentos
	setlocale(LC_ALL, "Portuguese");
	// Chama a struct getSystemTime no inicio do programa para não haver erros com a data de criação e data de modificação
	struct tm tm = getSystemTime();
	//=======Variáveis para cadastro na base
	// arqFisicoImagensBase.txt armazena todas as informações sobre as imagens cadastradas.
	char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
	int id;
	char nomeImagem[MAX_NAME];

	//======Variáveis para operações sobre imagens
	int opt = 1, lin, col, maxval, gravou;
	char *tipo, *nomeArqSaida;
	int **matImagem = NULL;
	char *auxNomeImagem, *auxNomeSaida;
	Imagem img;

	// Minhas variaveis
	int retornoCadastro, retornoAlteraImagem, retornoVerificaExistenciaDeImagem;
	int **matCopia = NULL;
	int tamanhoAuxNomeImagem = 0;

	do
	{
		// Função que mostra as opções para o usuário ao executar o programa
		menuOperacoes();
		/*Verificação que impede que o usuário digite uma letra ao input
		o que impede que o programa entre um um looping infinito*/
		printf("Digite a opção a ser lida: ");
		while (scanf("%d", &opt) != 1)
		{
			printf("Valor inválido! Digite a opção a ser lida: ");
			while (getchar() != '\n');
		}

		switch (opt)
		{
		case 0:
			// Case para sair do programa

			printf("Saindo do programa...\n");
			break;

		case 1:
			// listaImagens
			printf("\nListando imagens cadastradas na base!\n");
			listaImagens(arqFisicoImagensBase);
			break;

		case 2:
			//===cadastraImagem
			printf("\nDigite a imagem a ser cadastrada: ");
			scanf("%s", nomeImagem);
			// Obtem o valor retornado de cadastraImagem e a guarda em retornoCadastro
			retornoCadastro = cadastraImagem(arqFisicoImagensBase, nomeImagem);
			// Define se a imagem está ou não cadastrada na base
			if (retornoCadastro == 0)
			{
				printf("Imagem cadastrada com sucesso!\n");
			}
			else if (retornoCadastro == 1)
			{
				printf("Imagem já cadastrada na base!\n");
			}
			else
			{
				printf("Erro ao cadastrar! Verifique se existe a imagem no diretório!\n");
			}
			break;

		case 3:
			//===alteraImagem
			int idAlterado;
			printf("\nDigite o id a ser alterado: ");
			scanf("%d", &idAlterado);
			// Obtem o valor retornado de alteraImagem e a guarda em retornoAlteraImagem
			int retornoAlteraImagem = alteraImagem(arqFisicoImagensBase, idAlterado);
			// Define se a imagem foi encontrada ou não
			if (retornoAlteraImagem == 1)
			{
				printf("Imagem encontrada! \n");
			}
			if (retornoAlteraImagem == 0)
			{
				printf("Não há existência dessa imagem na base de dados!\n");
			}
			break;

		case 4:
			//===removeImagem
			printf("\nID da imagem a remover: ");
			scanf("%d", &id);
			// Remove uma imagem da base com o mesmo ID passado
			removeImagem(arqFisicoImagensBase, id);
			break;

		case 5:
			//===Binarizar
			// alocando strings
			auxNomeImagem = alocaString(20);
			tipo = alocaString(3);
			auxNomeSaida = alocaString(20);
			printf("Digite o nome da imagem a ser binarizada: ");
			scanf("%s", auxNomeImagem);
			// Chamando variáveis e obtendo o retorno das funções abaixo
			retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeImagem);
			retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			// Verifica se existe a imagem no diretório e no arqFisicoImagensBase, para a imagem poder ser binarizada
			if (retornoVerificaExistenciaDeImagem == 1 && retornoCadastro == 1)
			{
				matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
				do
				{
					printf("Digite o nome de saída da imagem binarizada: ");
					scanf("%s", auxNomeSaida);
					retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeSaida);
					retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeSaida);
				} while (retornoCadastro == 1 || retornoVerificaExistenciaDeImagem == 1); // Irá repetir o código enquanto auxNomeSaida for igual a uma imagem já cadastrada na base ou listada no diretório
			}
			else
			{
				printf("Imagem não cadastrada! Verifique se a imagem está no diretório e no ArquivoBase!\n");
				printf("Lembre-se, use o formato 'nomeImagem.pgm'\n ");
				break;
			}
			// Binariza imagem e a grava logo em seguida
			binarizar(matImagem, lin, col);
			// Verifica se a imagem foi gravada corretamente
			gravou = gravaImagem(auxNomeSaida, tipo, lin, col, maxval, matImagem);
			if (gravou == 0)
			{
				printf("Operação de binarização realizada com sucesso!\n");
			}
			else
			{
				printf("A operação de binarização não foi realizada com sucesso!\n");
				break;
			}
			/* Obtem informações da Imagem original e apenas modifica os campos de: Nome, ID, Size e data de criação -- Pelos testes que fizemos observamos que
			Dependendo a escolha o tamanho da imagem muda, então fica necessário alterar esse campo na nova imagem a ser gravada*/
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			stpcpy(img.nome, auxNomeSaida);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			img.size = getSize(auxNomeSaida);
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			// Grava informações da imagem modificada na base de arquivo
			gravaInfoImagem(arqFisicoImagensBase, img);
			// Desaloca matriz e strings utilizadas no case
			free(tipo);
			free(auxNomeImagem);
			free(auxNomeSaida);
			desalocaMatrizImagem(matImagem, lin);

			break;

		case 6:
			//===Ruído
			auxNomeImagem = alocaString(20);
			tipo = alocaString(3);
			auxNomeSaida = alocaString(20);
			printf("Digite o nome da imagem a utilizar ruído: ");
			scanf("%s", auxNomeImagem);
			// Chamando variáveis e obtendo o retorno das funções abaixo
			retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeImagem);
			retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			// Verifica se existe a imagem no diretório e no arqFisicoImagensBase, para a imagem poder utilizar ruído
			if (retornoVerificaExistenciaDeImagem == 1 && retornoCadastro == 1)
			{
				matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
				do
				{
					printf("Digite o nome de saída da imagem com ruído: ");
					scanf("%s", auxNomeSaida);
					retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeSaida);
					retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeSaida);
				} while (retornoCadastro == 1 || retornoVerificaExistenciaDeImagem == 1); // Irá repetir o código enquanto auxNomeSaida for igual a uma imagem já cadastrada na base ou listada no diretório
			}
			else
			{
				printf("Imagem não cadastrada! Verifique se a imagem está no diretório e o ArquivoBase!\n");
				printf("Lembre-se, use o formato 'nomeImagem.pgm'\n ");
				break;
			}
			// Faz o ruído imagem e a grava logo em seguida
			ruido(matImagem, lin, col);
			// Verifica se a imagem foi gravada corretamente
			gravou = gravaImagem(auxNomeSaida, tipo, lin, col, maxval, matImagem);
			if (gravou == 0)
			{
				printf("Operação de ruído realizada com sucesso!\n");
			}
			else
			{
				printf("A operação de ruído não foi realizada com sucesso!\n");
				break;
			}
			/* Obtem informações da Imagem original e apenas modifica os campos de: Nome, ID, Size e data de criação -- Pelos testes que fizemos observamos que
			Dependendo a escolha o tamanho da imagem muda, então fica necessário alterar esse campo na nova imagem a ser gravada*/
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			stpcpy(img.nome, auxNomeSaida);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			img.size = getSize(auxNomeSaida);
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			// Grava informações da imagem modificada na base de arquivo
			gravaInfoImagem(arqFisicoImagensBase, img);
			// Desaloca matriz e strings utilizadas no case
			free(tipo);
			free(auxNomeImagem);
			free(auxNomeSaida);
			desalocaMatrizImagem(matImagem, lin);

			break;

		case 7:
			//===Negativo
			auxNomeImagem = alocaString(20);
			tipo = alocaString(3);
			auxNomeSaida = alocaString(20);
			printf("Digite o nome da imagem a usar negativo: ");
			scanf("%s", auxNomeImagem);
			// Chamando variáveis e obtendo o retorno das funções abaixo
			retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeImagem);
			retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			// Verifica se existe a imagem no diretório e no arqFisicoImagensBase, para a imagem poder utilizar ruído
			if (retornoVerificaExistenciaDeImagem == 1 && retornoCadastro == 1)
			{
				matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
				do
				{
					printf("Digite o nome de saída da imagem com efeito negativo: ");
					scanf("%s", auxNomeSaida);
					retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeSaida);
					retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeSaida);
				} while (retornoCadastro == 1 || retornoVerificaExistenciaDeImagem == 1); // Irá repetir o código enquanto auxNomeSaida for igual a uma imagem já cadastrada na base ou listada no diretório
			}
			else
			{
				printf("Imagem não cadastrada! Verifique se a imagem está no diretório e o ArquivoBase!\n");
				printf("Lembre-se, use o formato 'nomeImagem.pgm'\n ");
				break;
			}
			// Faz o negativo imagem e a grava logo em seguida
			negativo(matImagem, lin, col);
			// Verifica se a imagem foi gravada corretamente
			gravou = gravaImagem(auxNomeSaida, tipo, lin, col, maxval, matImagem);
			if (gravou == 0)
			{
				printf("Operação negativa  realizada com sucesso!");
			}
			else
			{
				printf("A operação negativa não foi realizada com sucesso!");
				break;
			}

			/* Obtem informações da Imagem original e apenas modifica os campos de: Nome, ID, Size e data de criação -- Pelos testes que fizemos observamos que
			Dependendo a escolha o tamanho da imagem muda, então fica necessário alterar esse campo na nova imagem a ser gravada*/
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			stpcpy(img.nome, auxNomeSaida);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			img.size = getSize(auxNomeSaida);
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			// Grava informações da imagem modificada na base de arquivo
			gravaInfoImagem(arqFisicoImagensBase, img);
			// Desaloca matriz e strings utilizadas no case
			free(tipo);
			free(auxNomeImagem);
			free(auxNomeSaida);
			desalocaMatrizImagem(matImagem, lin);
			break;

		case 8:
			//====Espelhamento
			auxNomeImagem = alocaString(20);
			tipo = alocaString(3);
			auxNomeSaida = alocaString(20);
			printf("Digite o nome da imagem a ser espelhada: ");
			scanf("%s", auxNomeImagem);
			// Chamando variáveis e obtendo o retorno das funções abaixo
			retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeImagem);
			retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			// Verifica se existe a imagem no diretório e no arqFisicoImagensBase, para a imagem poder utilizar ruído
			if (retornoVerificaExistenciaDeImagem == 1 && retornoCadastro == 1)
			{
				matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
				do
				{
					printf("Digite o nome de saída da imagem espelhada: ");
					scanf("%s", auxNomeSaida);
					retornoCadastro = verificaCadastro(arqFisicoImagensBase, auxNomeSaida);
					retornoVerificaExistenciaDeImagem = verificaExistenciaDeImagem(auxNomeSaida);
				} while (retornoCadastro == 1 || retornoVerificaExistenciaDeImagem == 1); // Irá repetir o código enquanto auxNomeSaida for igual a uma imagem já cadastrada na base ou listada no diretório
			}
			else
			{
				printf("Imagem não cadastrada! Verifique se a imagem está no diretório e o ArquivoBase!\n");
				printf("Lembre-se, use o formato 'nomeImagem.pgm'\n ");
				break;
			}
			// Aloca dinâmicamente a matriz matCopia
			matCopia = alocaMatrizImagem(lin, col);
			// Verifica se existe memória suficiente
			if (matCopia == NULL)
			{
				printf("Falta de memória na matCopia!!\n");
				return 0;
			}
			// Copia a matriz original para matCopia
			copiaMatrizImagem(matImagem, matCopia, lin, col);
			// Faz o espelhando imagem e a grava logo em seguida
			espelhar(matCopia, lin, col);
			// Verifica se a imagem foi gravada corretamente
			gravou = gravaImagem(auxNomeSaida, tipo, lin, col, maxval, matCopia);
			if (gravou == 0)
			{
				printf("Operação de espelhamento realizada com sucesso!\n");
			}
			else
			{
				printf("A operação de espelhamento não foi realizada com sucesso!\n");
				break;
			}
			/* Obtem informações da Imagem original e apenas modifica os campos de: Nome, ID, Size e data de criação -- Pelos testes que fizemos observamos que
			Dependendo a escolha o tamanho da imagem muda, então fica necessário alterar esse campo na nova imagem a ser gravada*/
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			stpcpy(img.nome, auxNomeSaida);
			img.id = getLastId(arqFisicoImagensBase) + 1;
			img.size = getSize(auxNomeSaida);
			img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
			img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
			// Grava informações da imagem modificada na base de arquivo
			gravaInfoImagem(arqFisicoImagensBase, img);
			// Desaloca matriz e strings utilizadas no case
			free(auxNomeImagem);
			free(tipo);
			free(auxNomeSaida);
			desalocaMatrizImagem(matImagem, lin);
			desalocaMatrizImagem(matCopia, lin);

			break;
		default:
			// Se o usuário digita um valor fora do intervalo entre 0 e 8, é printado "Opção inválida"
			printf("\nOpção inválida");
		}

	} while (opt != 0);

	return 0;
}
