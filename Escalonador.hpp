#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include "Processo.hpp"

class Escalonador
{
private:
    unsigned int numero_processos_maximo;
    unsigned int numero_processos_lista{};
    
public:
    std::queue<Processo> processos;
    Escalonador(const unsigned int n_processos_max)
    {
        this->numero_processos_maximo = n_processos_max;
    }

    void add_processo(Processo novo_processo)
    {
        if(numero_processos_lista > numero_processos_maximo)
        {
            std::cout << "Número máximo de processos\n";
            return;
        }
        std::cout << "Added processo " << novo_processo.getId() << "\n";
        processos.push(novo_processo);
    }

    // virtual void run() = 0;
};
