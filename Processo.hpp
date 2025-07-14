#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class Processo
{
private:
    int id;
    unsigned long tempoDeExecucao; // em segundos

public:

    Processo(const int id, const unsigned long tempo)
    {
        this->id = id;
        this->tempoDeExecucao = tempo;
    }

    int getId() const noexcept
    {
        return this->id;
    }

    unsigned long getTempoDeExecucao() const noexcept
    {
        return this->tempoDeExecucao;
    }

    void setId(const int novoId)
    {
        this->id = novoId;
    }

    // void setTempoDeExecucao(int novoTempo)
    // {
    //     tempoDeExecucao = novoTempo;
    // }

    void exibir() const
    {
        std::cout << "Processo ID: " << this->id
                  << " | Tempo de Execução: " << this->tempoDeExecucao
                  << " unidades\n";
    }

    void executar()
    {
        std::cout << "Executando processo " << this->id << "\n";
        // const auto start = std::chrono::high_resolution_clock::now();
        // std::this_thread::sleep_for(std::chrono::seconds(tempoDeExecucao));
        // const auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Processo " << this->id 
                  // << " terminou de executar em " << std::chrono::duration_cast<std::chrono::seconds>(end-start).count()
                  << " segundos\n";
    }
};
