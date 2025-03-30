#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Estruturas.h"


/*!
 * \brief Carrega a informação das antenas, existentes num ficheiro de texto para a estrutura de lista ligada.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param nomeFicheiro Nome do ficheiro de texto a ser lido.
 */
void carregarAntenasFile(Antena** listaAntenas, const char* nomeFicheiro);

/*!
 * \brief Cria uma nova antena.
 * \param frequencia Frequência de ressonância da antena.
 * \param linha Linha da antena.
 * \param coluna Coluna da antena.
 * \return Apontador para a nova antena criada.
 */
Antena* criarAntena(char frequencia, int linha, int coluna);

/*!
 * \brief Adiciona uma antena à lista ligada.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param antena Apontador para a antena a ser adicionada.
 */
void adicionarAntena(Antena** listaAntenas, Antena* antena);

/*!
 * \brief Remove uma antena da lista ligada.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param frequencia Frequência da antena a ser removida.
 * \param linha Linha da antena a ser removida.
 * \param coluna Coluna da antena a ser removida.
 * \return 1 se a antena foi removida, 0 se não foi removida
 */
int removerAntena(Antena** listaAntenas, char frequencia, int linha, int coluna);

/*!
 * \brief Listagem de forma tabular na consola as antenas e localizações com efeito nefasto.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 * \param listaLocalizacoes Apontador para a primeira posição da estrutura de localizações com efeito nefasto.
 */
void listarAntLocalNef(Antena* listaAntenas, Localizacao* listaLocalizacoes);

/*!
 * \brief Liberta a memória alocada para a lista ligada de antenas.
 * \param listaAntenas Apontador para a primeira posição da estrutura.
 */
void libertaMemoria(Antena** listaAntenas);