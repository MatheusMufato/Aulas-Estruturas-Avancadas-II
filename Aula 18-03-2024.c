//Código desenvolvido por Matheus P. Mufato - 05221-015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char nome[100];
    int indice;
} pessoa;

pessoa variavel[1299];

void buscaSequencialIndice(pessoa *p, int n, int indice){

    FILE *arquivo = fopen("NomesDesordenados.txt","r");

    int i;
    int contador = 0;
    pessoa pessoaArquivo;
    for(i = 0; i < n; i++){
        fscanf(arquivo,"%s %d", pessoaArquivo.nome, &pessoaArquivo.indice);
        contador++;
        if(pessoaArquivo.indice == indice){
            printf("Nome encontrado: %s; Seu indice : %d\n", pessoaArquivo.nome, pessoaArquivo.indice);
            printf("Numero de interacoes: %d\n", contador);
            return;
        }
    }

    printf("Indice nao encontrado\n");
    printf("Numero de iteracoes: %d\n", contador);
}

void buscaSequencialNome(pessoa *p, int n, char *nome){

    FILE *arquivo = fopen("NomesDesordenados.txt","r");

    int i;
    int contador = 0;
    pessoa pessoaArquivo;
    for(i = 0; i < n; i++){
        fscanf(arquivo,"%s %d", pessoaArquivo.nome, &pessoaArquivo.indice);
        contador++;
        if(strcmp(pessoaArquivo.nome, nome) == 0){
            printf("Nome encontrado: %s; Seu indice : %d\n", pessoaArquivo.nome, pessoaArquivo.indice);
            printf("Numero de interacoes: %d\n", contador);
            return;
        }
    }

    printf("Nome nao encontrado!\n");
    printf("Numero de interacoes: %d\n", contador);
}

void desordena(pessoa *p, int n){

    FILE *arquivo = fopen("..//Nomes.txt","r");
    FILE *arquivoDesordenado = fopen("..//NomesDesordenados.txt","w");

    if (arquivoDesordenado == NULL)
        return;

    if (arquivo == NULL)
        return;

    int i=0;

    for (i = 0; i < 1299; i++) {
        fscanf(arquivo, "%s", variavel[i].nome);
    }

    srand(time(NULL));
    for(i = 0; i < 1299; i++){
        int j = rand() % 1299;
        pessoa temp = variavel[i];
        variavel[i] = variavel[j];
        variavel[j] = temp;
    }
    for(i = 0; i < 1299; i++){
        variavel[i].indice = i+1;
    }

    for(i = 0; i < 1299; i++){
        fprintf(arquivoDesordenado,"%s %d\n",variavel[i].nome,variavel[i].indice);
    }

    fclose(arquivo);
    fclose(arquivoDesordenado);
}

int main() {

    desordena(variavel,1299);

    char nome[100];
    printf("Digite o nome a ser buscado: ");
    scanf("%s",nome);

    buscaSequencialNome(variavel,1299,nome);

    int indice;
    printf("Digite o indice a ser buscado: ");
    scanf("%d",&indice);

    if(indice < 1 || indice > 1299){
        printf("Indice invalido!\n");
        return 0;
    }
    buscaSequencialIndice(variavel,1299,indice);

    return 0;
}