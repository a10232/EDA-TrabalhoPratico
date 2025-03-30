#pragma once

#include <stdio.h>
#include <stdlib.h>

/*!
 * \file Estruturas.h
 * \brief Estrutra para gestão de antenas de uma cidade.
 * \author Luís Leite
 * \email a10232@alunos.ipca.pt
 * \date 26/03/2025
 * \lastupdate 30/03/2025
 *
 * Neste ficheiro estão contidas as estruturas necessárias para a gestão de antenas de uma cidade 
 * através de uma lista ligada, como pretendido no enunciado do projeto.
 */



 /*!
 * \brief Estrutura de uma antena.
 */
typedef struct Antena {
    char frequencia; /*!< Frequência de ressonância da antena */
    int linha;       /*!< Linha da antena */
    int coluna;      /*!< Coluna da antena */
    struct Antena* next; /*!< Apontador para antena seguinte que está inserida na lista ligada */
} Antena;

/*!
 * \brief Estrutura da localização com efeito nefasto.
 */
typedef struct Localizacao {
    int linha;       /*!< Linha da localização */
    int coluna;      /*!< Coluna da localização */
    struct Localizacao* next; /*!< Apontador para a próxima localização inserida na lista ligada */
} Localizacao;