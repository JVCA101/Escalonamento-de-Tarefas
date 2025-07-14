#pragma once
#include "Escalonador.hpp"
#include <thread>

class FIFO : public Escalonador
{
private:

public:
	FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max){}

	void run()
	{
        while(true)
        {
            if(processos.size() == 0)
            {
                std::cout << "Tamanho = 0\n";
                break;
            }
            std::thread thread_processo(&Processo::executar, &processos.front());
            std::cout << "while\n";
            thread_processo.join();
            processos.pop();
        }
        std::cout << "TERMINOU :D\n";
	}

};
