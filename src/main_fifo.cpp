#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "../include/Processo.hpp"
#include "../include/FIFO.hpp"

int main()
{
    Processo p1(1, 3);
    Processo p2(2, 2);

    p1.exibir();
    p2.exibir();
    
    FIFO fifo(4);
    fifo.add_processo(p1);
    fifo.add_processo(p2);
    std::mutex mutex_running, mutex_novo_processo;
    std::condition_variable cv_novo_processo;
    std::thread escalonador_fifo(&FIFO::run, &fifo, &mutex_running, &cv_novo_processo, &mutex_novo_processo);

    // Adicionar novos processos durante a execução
    long time;
    unsigned long new_ids = 3;
    bool is_running;

    mutex_running.lock();
    is_running = fifo.is_running();
    mutex_running.unlock();

    do
    {
        time = -1;
        std::cout << "Para adicionar novo processo dê o tempo dele em segundos inteiros(para parar dê -1):\n";
        // std::cout << "Lock Novo Processo:main\n";
        
        std::cin >> time;
        cv_novo_processo.notify_one();

        if(time > 0)
        {
            fifo.add_processo(Processo(new_ids, time));
            new_ids++;
        }
        else
        {
            cv_novo_processo.notify_one();
        }
            fifo.stop_running(&mutex_running);
        
        // std::cout << "Unlock Novo Processo:main\n";
        
        // std::cout << "Lock Running:main\n";
        mutex_running.lock();
        is_running = fifo.is_running();
        // std::cout << "Unlock Running:main\n";
        mutex_running.unlock();
    } while(is_running);

    escalonador_fifo.join();
    return 0;
}

