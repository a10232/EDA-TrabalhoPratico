
/*!
 * \file Main.c
 * \brief Ficheiro com a função principal do sistema de Gestão de Antenas.
 * \author Luís Leite
 * \email a10232@alunos.ipca.pt
 * \date 26/03/2025
 * \lastupdate 30/03/2025
 *
 * Este ficheiro contém a função principal do programa, que realiza as seguintes operações:
 * - Carrega as antenas de um ficheiro de texto para uma lista ligada.
 * - Adiciona uma nova antena manualmente.
 * - Remove uma antena específica.
 * - Lista as antenas e as localizações com efeito nefasto na consola.
 * - Liberta a memória alocada para as listas ligadas.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

int main() {
    Antena* listaAntenas = NULL;
    Localizacao* listaLocalizacoes = NULL;

    // Carregar antenas de um ficheiro de texto
    carregarAntenasFile(&listaAntenas, "C:\\Arquivos\\IPCA\\EDA\\EDA-TrabalhoPratico\\Gestao de Antenas\\x64\\Debug\\file-antenas.txt");

    // Adicionar uma nova antena manualmente (exemplo)
    Antena* novaAntena = criarAntena('B', 5, 5);
    adicionarAntena(&listaAntenas, novaAntena);

    // Remover uma antena (exemplo)
    removerAntena(&listaAntenas, 'A', 3, 3);

    // Listar antenas e localizações com efeito nefasto
    listarAntLocalNef(listaAntenas, listaLocalizacoes);

    // Libertar memória
    libertaMemoria(&listaAntenas);

    return 0;
}

