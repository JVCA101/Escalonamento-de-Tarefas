#pragma once
#include "Escalonador.hpp"
#include <thread>

class FIFO : public Escalonador
{
private:

public:
	FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max){}

	void run() override
	{
        std::thread processo_(&Processo::executar, &processos.front());
	}

};
