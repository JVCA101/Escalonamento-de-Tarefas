#pragma once

#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include "Processo.hpp"

class Escalonador
{
public:
    unsigned int numero_processos_maximo;
    unsigned int numero_processos_lista{};
    std::queue<Processo> processos;

    Escalonador(const unsigned int n_processos_max)
    {
        this->numero_processos_maximo = n_processos_max;
    }

    void add_processo(Processo novo_processo)
    {
        numero_processos_lista++;
        if (numero_processos_lista > numero_processos_maximo)
        {
            numero_processos_lista--;
            std::cout << "Número máximo de processos\n";
            return;
        }
        std::cout << "Processo " << novo_processo.getId() << " adicionado (tempo do processo: " << novo_processo.getTempoDeExecucao() << ")" << "\n";
        processos.push(novo_processo);
    }

    virtual void run() = 0;

    friend class FIFO;
};
