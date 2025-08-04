#pragma once

#include <iostream>
#include <thread>
#include "Escalonador.hpp"

class FIFO : public Escalonador
{
private:
public:
    FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max) {}

    void run() override
    {
        while (this->numero_processos_lista > 0)
        {
            this->numero_processos_lista--;
            std::thread thread_processo(&Processo::executar, &processos.front());
            thread_processo.join();

            int tempoDecorrido = processos.front().getTempoDeExecucao();
            int n = processos.size();
            while (n--)
            {
                Processo p = processos.front();
                processos.pop();

                p.setTempoTotal(p.getTempoTotal() + tempoDecorrido);

                processos.push(p);
            }

            processos.pop();
        }
        std::cout << "Fim da Execução com FIFO.\n";
    }
};
