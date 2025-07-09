#include <iostream>
#include <string>
#include "Processo.hpp"

int main()
{
    Processo p1(1, 10);
    Processo p2(2, 5);

    p1.exibir();
    p1.executar();
    p2.exibir();
    p2.executar();

    return 0;
}
