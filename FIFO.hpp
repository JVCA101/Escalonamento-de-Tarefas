#pragma once

#include "Escalonador.hpp"
#include <thread>

class FIFO : Escalonador
{
private:

public:
	FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max){}

	void run()
	{
    Processo processo = processos.front();
    std::thread processo_(processo.executar);
	}
};
