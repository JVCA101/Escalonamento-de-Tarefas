#include "include/Processo.hpp"
#include "include/FIFO.hpp"
#include "include/RoundRobin.hpp"
#include <chrono>
#include <thread>

void execute_in_fifo(const Processo *processos);
void execute_in_round_robin(const Processo *processos);

int main(int argc, char *argv[])
{
    // processos
    const Processo processos[] = {Processo(1, 3),
                                  Processo(2, 4),
                                  Processo(3, 7),
                                  Processo(4, 1),
                                  Processo(5, 10),
                                  Processo(6, 2)};

    execute_in_fifo(processos);

    execute_in_round_robin(processos);

    return 0;
}

void execute_in_fifo(const Processo *processos)
{
    std::cout << std::endl
              << "-------RODANDO COM FIFO-------" << std::endl
              << std::endl;
    FIFO fifo{10};

    // 0 segundos
    fifo.add_processo(processos[0]);
    fifo.add_processo(processos[1]);
    fifo.add_processo(processos[2]);

    std::cout << std::endl
              << std::endl;

    std::thread fifo_thread(&FIFO::run, &fifo);


    // 5 segundos
    std::this_thread::sleep_for(std::chrono::seconds(5));
    fifo.add_processo(processos[3]);

    // 7 segundos
    std::this_thread::sleep_for(std::chrono::seconds(2));
    fifo.add_processo(processos[4]);

    // 10 segundos
    std::this_thread::sleep_for(std::chrono::seconds(3));
    fifo.add_processo(processos[5]);


    fifo_thread.join();
}

void execute_in_round_robin(const Processo *processos)
{
    std::cout << std::endl
              << "-------RODANDO COM ROUND ROBIN-------" << std::endl
              << std::endl;
    RoundRobin rr{10};

    // 0 segundos
    rr.add_processo(processos[0]);
    rr.add_processo(processos[1]);
    rr.add_processo(processos[2]);

    std::cout << std::endl
              << std::endl;

    std::thread rr_thread(&RoundRobin::run, &rr);
    
    
    // 5 segundos
    std::this_thread::sleep_for(std::chrono::seconds(5));
    rr.add_processo(processos[3]);

    // 7 segundos
    std::this_thread::sleep_for(std::chrono::seconds(2));
    rr.add_processo(processos[4]);

    // 10 segundos
    std::this_thread::sleep_for(std::chrono::seconds(3));
    rr.add_processo(processos[5]);


    rr_thread.join();
}
