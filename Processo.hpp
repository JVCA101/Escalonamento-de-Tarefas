#include <iostream>

class Processo
{
private:
    int id;
    int tempoDeExecucao;

public:
    Processo(int id, int tempo)
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

    void setTempoDeExecucao(int novoTempo)
    {
        tempoDeExecucao = novoTempo;
    }

    void exibir() const
    {
        std::cout << "Processo ID: " << id
                  << " | Tempo de Execução: " << tempoDeExecucao
                  << " unidades\n";
    }
};