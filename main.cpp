#include <iostream>
#include <thread>
#include "Processo.hpp"
#include "FIFO.hpp"

int main()
{
    Processo p1(1, 10);
    Processo p2(2, 5);

    p1.exibir();
    p2.exibir();
    
    FIFO fifo(4);
    fifo.add_processo(p1);
    fifo.add_processo(p2);

    std::thread escalonador_fifo(&FIFO::run, &fifo);

    // Adicionar novos processos durante a execução
    long time;
    unsigned long new_ids = 3;
    while(true)
    {
        time = -1;
        std::cout << "Para adicionar novo processo dê o tempo dele em segundos(para parar dê -1):\n";
        std::cin >> time;
        if(time <= -1)
            break;

        fifo.add_processo(Processo(new_ids, time));
        new_ids++;
    }
    escalonador_fifo.join();
    return 0;
}

