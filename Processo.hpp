#include <iostream>
#include <chrono>
#include <thread>

class Processo
{
private:
    int id;
    unsigned long tempoDeExecucao; // em segundos

public:
    Processo(int id, unsigned long tempo)
    {
        this->id = id;
        this->tempoDeExecucao = tempo;
    }

    int getId() const
    {
        return id;
    }

    int getTempoDeExecucao() const
    {
        return tempoDeExecucao;
    }

    void setId(int novoId)
    {
        id = novoId;
    }

    // void setTempoDeExecucao(int novoTempo)
    // {
    //     tempoDeExecucao = novoTempo;
    // }

    void exibir() const
    {
        std::cout << "Processo ID: " << id
                  << " | Tempo de Execução: " << tempoDeExecucao
                  << " unidades\n";
    }

    void executar()
    {
        const auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::seconds(tempoDeExecucao));
        const auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Processo " << id << " terminou de executar em " << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << " segundos\n";
    }
};