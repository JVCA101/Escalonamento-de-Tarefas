#pragma once

#include <iostream>
#include <thread>
#include "Escalonador.hpp"

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
                std::cout << "Lista de processos está vazia\n Saindo da execução(mas deveria esperar um processo aparecer)\n";
                break;
            }
            std::thread thread_processo(&Processo::executar, &processos.front());
            thread_processo.join();
            processos.pop();
        }
        std::cout << "TERMINOU :D\n";
	}

};
