#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include "Escalonador.hpp"

class FIFO : public Escalonador
{
private:
    bool running{false};
public:
	FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max){}

    bool is_running() const noexcept
    {
        return this->running;
    }

    void stop_running(std::mutex mutex_running)
    {
        this->running = false;
    }

	void run(std::mutex* mutex_running) override
	{
        mutex_running->lock();
        running = true;
        mutex_running->unlock();
        while(true)
        {
            while(processos.size() != 0)
            {
                std::thread thread_processo(&Processo::executar, &processos.front());
                thread_processo.join();
                processos.pop();
            }
            
            mutex_running->lock();
            if(!this->running)
            {
                mutex_running->unlock();
                break;
            }
            mutex_running->unlock();
        }
        std::cout << "TERMINOU :D\n";
	}

};
