all: saida

	@echo " "
	@echo "Compilado sem problemas!"
	@echo " "

saida: alocaMatrizImagem.o alocaString.o alteraImagem.o binarizar.o cadastraImagem.o copiaMatrizImagem.o desalocaMatrizImagem.o espelhar.o getDimension.o getExtension.o getImage.o getLastId.o getSize.o getSystemTime.o gravaImagem.o gravaInfoImagem.o leArquivoImagem.o listaImagens.o main.o menuOperacoes.o negativo.o removeImagem.o ruido.o verificaCadastro.o verificaExistenciaDeImagem.o
	gcc -o saida alocaMatrizImagem.o alocaString.o alteraImagem.o binarizar.o cadastraImagem.o copiaMatrizImagem.o desalocaMatrizImagem.o espelhar.o getDimension.o getExtension.o getImage.o getLastId.o getSize.o getSystemTime.o gravaImagem.o gravaInfoImagem.o leArquivoImagem.o listaImagens.o main.o menuOperacoes.o negativo.o removeImagem.o ruido.o verificaCadastro.o verificaExistenciaDeImagem.o

alocaMatrizImagem.o: alocaMatrizImagem.c
	gcc -o alocaMatrizImagem.o -c alocaMatrizImagem.c

alocaString.o: alocaString.c
	gcc -o alocaString.o -c alocaString.c

alteraImagem.o: alteraImagem.c
	gcc -o alteraImagem.o -c alteraImagem.c

binarizar.o: binarizar.c
	gcc -o binarizar.o -c binarizar.c

cadastraImagem.o: cadastraImagem.c
	gcc -o cadastraImagem.o -c cadastraImagem.c

copiaMatrizImagem.o: copiaMatrizImagem.c
	gcc -o copiaMatrizImagem.o -c copiaMatrizImagem.c

desalocaMatrizImagem.o: desalocaMatrizImagem.c
	gcc -o desalocaMatrizImagem.o -c desalocaMatrizImagem.c

espelhar.o: espelhar.c
	gcc -o espelhar.o -c espelhar.c

getDimension.o: getDimension.c
	gcc -o getDimension.o -c getDimension.c

getExtension.o: getExtension.c
	gcc -o getExtension.o -c getExtension.c

getImage.o: getImage.c
	gcc -o getImage.o -c getImage.c

getLastId.o: getLastId.c
	gcc -o getLastId.o -c getLastId.c

getSize.o: getSize.c
	gcc -o getSize.o -c getSize.c

getSystemTime.o: getSystemTime.c
	gcc -o getSystemTime.o -c getSystemTime.c

gravaImagem.o: gravaImagem.c
	gcc -o gravaImagem.o -c gravaImagem.c

gravaInfoImagem.o: gravaInfoImagem.c
	gcc -o gravaInfoImagem.o -c gravaInfoImagem.c

leArquivoImagem.o: leArquivoImagem.c
	gcc -o leArquivoImagem.o -c leArquivoImagem.c

listaImagens.o: listaImagens.c
	gcc -o listaImagens.o -c listaImagens.c
	
main.o: main.c
	gcc -o main.o -c main.c

menuOperacoes.o: menuOperacoes.c
	gcc -o menuOperacoes.o -c menuOperacoes.c

negativo.o: negativo.c
	gcc -o negativo.o -c negativo.c

removeImagem.o: removeImagem.c
	gcc -o removeImagem.o -c removeImagem.c

ruido.o: ruido.c
	gcc -o ruido.o -c ruido.c

verificaCadastro.o: verificaCadastro.c
	gcc -o verificaCadastro.o -c verificaCadastro.c

verificaExistenciaDeImagem.o: verificaExistenciaDeImagem.c
	gcc -o verificaExistenciaDeImagem.o -c verificaExistenciaDeImagem.c

clean: 
	rm -f *.o

execClean:
	rm -f saida