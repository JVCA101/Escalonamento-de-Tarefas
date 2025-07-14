#include "Processo.hpp"
#include "FIFO.hpp"
#include <thread>

int main()
{
    Processo p1(1, 10);
    Processo p2(2, 5);

    p1.exibir();
    // p1.executar();
    p2.exibir();
    // p2.executar();
    
    FIFO fifo(4);
    std::cout << "Add processos\n";
    fifo.add_processo(p1);
    // fifo.add_processo(p2);
    std::cout << "FIFO:\n";
    std::thread escalonador_fifo(&FIFO::run, &fifo);
    return 0;
}

