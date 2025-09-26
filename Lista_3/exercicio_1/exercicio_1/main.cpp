#include "Atleta.h"
#include "Nadador.h"
#include "Corredor.h"
#include "InformacoesAtleta.h"
#include <iostream>

int main() {
    Atleta atletaGenerico("Joao", 30);
    Nadador nadador("Michael Phelps", 38, "Profissional");
    Corredor corredor("Usain Bolt", 37, 94.0, "Olimpiadas", 25, 7, 2024);

    InformacoesAtleta info;

    std::cout << "--- Informacoes de Atleta Generico ---" << std::endl;
    info.imprime_informacoes_atleta(&atletaGenerico);
    info.imprime_exclusivos_atleta(&atletaGenerico);
    std::cout << std::endl;

    std::cout << "--- Informacoes de Nadador ---" << std::endl;
    info.imprime_informacoes_atleta(&nadador);
    info.imprime_exclusivos_atleta(&nadador);
    std::cout << std::endl;

    std::cout << "--- Informacoes de Corredor ---" << std::endl;
    info.imprime_informacoes_atleta(&corredor);
    info.imprime_exclusivos_atleta(&corredor);
    std::cout << std::endl;

    return 0;
}