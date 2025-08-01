#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class Processo
{
private:
    int id;
    unsigned long tempoDeExecucao; // em segundos
    unsigned long tempoRestante;
    unsigned long tempoTotal;

public:
    Processo(const int id, const unsigned long tempo)
    {
        this->id = id;
        this->tempoRestante = this->tempoDeExecucao = tempo;
        tempoTotal = 0;
    }

    int getId() const noexcept
    {
        return this->id;
    }

    unsigned long getTempoDeExecucao() const noexcept
    {
        return this->tempoDeExecucao;
    }

    unsigned long getTempoRestante() const noexcept
    {
        return this->tempoRestante;
    }

    void setId(const int novoId)
    {
        this->id = novoId;
    }

    int getTempoTotal() const noexcept
    {
        return this->tempoTotal;
    }

    void setTempoTotal(const int novoTempoTotal)
    {
        this->tempoTotal = novoTempoTotal;
    }

    // void setTempoDeExecucao(int novoTempo)
    // {
    //     tempoDeExecucao = novoTempo;
    // }

    void exibir() const
    {
        std::cout << "Processo ID: " << this->id
                  << " | Tempo de Execução: " << this->tempoDeExecucao
                  << " segundos\n";
    }

    void executar()
    {
        std::cout << "Executando processo " << this->id << "\n";
        const auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::seconds(this->tempoDeExecucao));
        const auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Processo " << this->id << " terminou de executar (tempo total: " << tempoTotal + this->getTempoDeExecucao() << ")" << std::endl;
    }

    void executar_quantum(const unsigned long quantum)
    {
        unsigned long time_to_run;
        if (tempoRestante < quantum)
        {
            time_to_run = tempoRestante;
            tempoTotal += tempoRestante;
            tempoRestante = 0;
        }
        else
        {
            time_to_run = quantum;
            tempoRestante = tempoRestante - quantum;
        }

        std::this_thread::sleep_for(std::chrono::seconds(time_to_run));

        bool still_running = true;
        if (tempoRestante == 0)
        {
            std::cout << "Processo " << this->id << " terminou de executar (tempo total: " << tempoTotal << ")" << std::endl;
            return;
        }
        else
        {
            std::cout << "Executando quantum de " << quantum << "seg (processo " << this->id << ")"
                      << "\nTempo restante: " << tempoRestante << "/" << tempoDeExecucao << std::endl;
            return;
        }
    }
};
