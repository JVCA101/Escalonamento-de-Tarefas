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

    void stop_running(std::mutex* mutex_running)
    {
        this->running = false;
    }

	void run(std::mutex* mutex_running, std::mutex* mutex_novo_processo) override
	{
        mutex_running->try_lock();
        running = true;
        mutex_running->unlock();
        while(true)
        {

            while(this->numero_processos_lista > 0)
            {
                this->numero_processos_lista--;
                std::thread thread_processo(&Processo::executar, &processos.front());
                thread_processo.join();
                processos.pop();
            }
            
            mutex_running->lock();
            // std::cout << "Lock Running:fifo\n";
            bool not_running = !this->running;
            // std::cout << "Unlock Running:fifo\n";
            mutex_running->unlock();
            if(not_running)
                break;
            
            mutex_novo_processo->lock();
            // std::cout << "Lock Novo Processo:fifo\n";
            mutex_novo_processo->unlock();
            // std::cout << "Unlock Novo Processo:fifo\n";
        }
        std::cout << "TERMINOU :D\n";
	}

};
