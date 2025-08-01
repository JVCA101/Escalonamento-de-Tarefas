#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include "Escalonador.hpp"

class RoundRobin : public Escalonador
{
private:
public:
    RoundRobin(const unsigned int n_processos_max) : Escalonador(n_processos_max) {}

    void run() override
    {
        int quantum = 2;
        while (this->numero_processos_lista > 0)
        {
            if (processos.front().getTempoRestante() == 0)
            {
                this->numero_processos_lista--;
                processos.pop();
            }
            else
            {
                std::thread thread_processo(&Processo::executar_quantum, &processos.front(), quantum);
                thread_processo.join();

                processos.push(processos.front());
                processos.pop();

                int n = processos.size();
                while (n--)
                {
                    Processo p = processos.front();
                    processos.pop();

                    p.setTempoTotal(p.getTempoTotal() + quantum);

                    processos.push(p);
                }
            }
        }
        std::cout << "Fim da Execução com Round Robin.\n";
    }
};
