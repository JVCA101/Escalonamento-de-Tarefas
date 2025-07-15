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
    escalonador_fifo.join();
    return 0;
}

