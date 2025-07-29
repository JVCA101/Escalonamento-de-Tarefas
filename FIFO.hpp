#pragma once

#include <iostream>
#include <thread>
#include "Escalonador.hpp"

class FIFO : public Escalonador
{
private:

public:
	FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max){}

	void run() override
	{
        while(this->numero_processos_lista > 0)
        {
            this->numero_processos_lista--;
            std::thread thread_processo(&Processo::executar, &processos.front());
            thread_processo.join();
            processos.pop();
        }
        std::cout << "TERMINOU :D\n";
	}

};
