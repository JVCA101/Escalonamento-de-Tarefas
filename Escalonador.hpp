#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
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
        numero_processos_lista++;
        if(numero_processos_lista > numero_processos_maximo)
        {
            numero_processos_lista--;
            std::cout << "Número máximo de processos\n";
            return;
        }
        std::cout << "Added processo " << novo_processo.getId() << "\n";
        processos.push(novo_processo);
    }

    virtual void run(std::mutex* mutex_running, std::condition_variable* cv_novo_processo, std::mutex* mutex_novo_processo) = 0;

    friend class FIFO;
};
