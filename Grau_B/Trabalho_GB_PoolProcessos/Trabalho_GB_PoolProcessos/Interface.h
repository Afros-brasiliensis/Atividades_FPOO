#pragma once
#include "Sistema.h"

class Interface {
private:
    Sistema sistema;

    void mostrarMenu();
    void opcaoCriarProcesso();
    void opcaoExecutarProximo();
    void opcaoExecutarEspecifico();
    void opcaoSalvarFila();
    void opcaoCarregarFila();

public:
    Interface();
    void executar(); 
};

