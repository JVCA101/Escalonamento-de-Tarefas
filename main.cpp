#include <iostream>
#include <string>
#include "Processo.hpp"

int main()
{
    Processo p1(1, 10);
    Processo p2(2, 5);

    p1.exibir();
    p2.exibir();

    return 0;
}
