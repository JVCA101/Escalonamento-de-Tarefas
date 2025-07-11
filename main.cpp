#include "Processo.hpp"
#include "FIFO.hpp"

int main()
{
    Processo p1(1, 10);
    Processo p2(2, 5);

    p1.exibir();
    // p1.executar();
    p2.exibir();
    // p2.executar();
    
    FIFO fifo(4);
    fifo.add_processo(p1);
    fifo.add_processo(p2);
    return 0;
}

