/*!
 * \file Funcoes.c
 * \brief Implementação das funções para gestão de antenas de uma cidade.
 * \author Luís Leite
 * \email a10232@alunos.ipca.pt
 * \date 26/03/2025
 * \lastupdate 30/03/2025
 *
 * Neste ficheiro estão implementadas as funções necessárias para a gestão de antenas de uma cidade,
 * ao utilizar uma lista ligada, como pretendido no enunciado do projeto.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

#pragma region carregarAntenasFile

 /*!
 * \brief Carrega as antenas de um ficheiro de texto para uma lista ligada.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param nomeFicheiro Nome do ficheiro de texto a ser lido.
 */
void carregarAntenasFile(Antena** listaAntenas, const char* nomeFicheiro) {
    //Testar se o ficheiro abre, problemas na abertura do ficheiro.
    printf("Tentando abrir o ficheiro: %s\n", nomeFicheiro);  // Mensagem de depuração
    FILE* ficheiro = fopen(nomeFicheiro, "r");
    if (ficheiro == NULL) {
        perror("Erro ao abrir o ficheiro");  // Mensagem de depuração com perror
        return;
    }

    char linha[256];
    int linhaNum = 0;

    while (fgets(linha, sizeof(linha), ficheiro)) {
        for (int coluna = 0; linha[coluna] != '\0'; coluna++) {
            if (linha[coluna] != '.' && linha[coluna] != '\n') {
                Antena* novaAntena = (Antena*)malloc(sizeof(Antena));
                if (novaAntena == NULL) {
                    printf("Erro ao alocar memória\n");
                    fclose(ficheiro);
                    libertaMemoria(listaAntenas);
                    return;
                }
                novaAntena->frequencia = linha[coluna];
                novaAntena->linha = linhaNum;
                novaAntena->coluna = coluna;
                novaAntena->next = *listaAntenas;
                *listaAntenas = novaAntena;
            }
        }
        linhaNum++;
    }

    fclose(ficheiro);
}


#pragma endregion

#pragma region criarAntena

/*!
 * \brief Cria uma nova antena.
 * \param frequencia Frequência de ressonância da antena.
 * \param linha Linha da antena.
 * \param coluna Coluna da antena.
 * \return Apontador para a nova antena criada.
 */
Antena* criarAntena(char frequencia, int linha, int coluna) {
    Antena* novaAntena = (Antena*)malloc(sizeof(Antena));
    if (novaAntena == NULL) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    novaAntena->frequencia = frequencia;
    novaAntena->linha = linha;
    novaAntena->coluna = coluna;
    novaAntena->next = NULL;
    return novaAntena;
}

#pragma endregion

#pragma region adicionarAntena

/*!
 * \brief Adiciona uma antena à lista ligada.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param antena Apontador para a antena a ser adicionada.
 */
void adicionarAntena(Antena** listaAntenas, Antena* antena) {
    antena->next = *listaAntenas;
    *listaAntenas = antena;
}

#pragma endregion

#pragma region removerAntena

/*!
 * \brief Remove uma antena da lista ligada.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param frequencia Frequência da antena a ser removida.
 * \param linha Linha da antena a ser removida.
 * \param coluna Coluna da antena a ser removida.
 * \return 1 se a antena foi removida, 0 caso contrário.
 */
int removerAntena(Antena** listaAntenas, char frequencia, int linha, int coluna) {
    Antena* atual = *listaAntenas;
    Antena* anterior = NULL;

    while (atual != NULL) {
        if (atual->frequencia == frequencia && atual->linha == linha && atual->coluna == coluna) {
            if (anterior == NULL) {
                *listaAntenas = atual->next;
            }
            else {
                anterior->next = atual->next;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->next;
    }
    return 0;
}

#pragma endregion

#pragma region listarAntLocalNef

/*!
 * \brief Lista de forma tabular na consola as antenas e localizações com efeito nefasto.
 * \param listaAntenas Apontador para a cabeça da lista de antenas.
 * \param listaLocalizacoes Apontador para a cabeça da lista de localizações com efeito nefasto.
 */
void listarAntLocalNef(Antena* listaAntenas, Localizacao* listaLocalizacoes) {
    printf("Antenas:\n");
    printf("Frequência\tLinha\tColuna\n");
    for (Antena* antena = listaAntenas; antena != NULL; antena = antena->next) {
        printf("%c\t\t%d\t%d\n", antena->frequencia, antena->linha, antena->coluna);
    }

    printf("\nLocalizações com efeito nefasto:\n");
    printf("Linha\tColuna\n");
    for (Localizacao* loc = listaLocalizacoes; loc != NULL; loc = loc->next) {
        printf("%d\t%d\n", loc->linha, loc->coluna);
    }
}

#pragma endregion

#pragma region libertaMemoria

/*!
 * \brief Libertar a memória alocada para a lista ligada de antenas.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 */
void libertaMemoria(Antena** listaAntenas) {
    while (*listaAntenas != NULL) {
        Antena* temp = *listaAntenas;
        *listaAntenas = (*listaAntenas)->next;
        free(temp);
    }
}

#pragma endregion