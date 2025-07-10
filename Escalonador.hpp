#pragma once

#include <queue>
#include "Processo.hpp"

class Escalonador
{
private:
    unsigned int numero_processos_maximo;
    unsigned int numero_processos_lista{};
    std::queue<Processo> processos;

public:
    Escalonador(const unsigned int n_processos_max)
    {
        this->numero_processos_maximo = n_processos_max;
    }

    void add_processo(Processo novo_processo)
    {
        if(numero_processos_lista > numero_processos_maximo)
        {
            std::cout << "Número máximo de processos\n";
            exit(1);
        }
        
        processos.push(novo_processo);
    }

    virtual void run() = 0;
};
