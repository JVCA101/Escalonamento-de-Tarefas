# Escalonamento de Tarefas
Trabalho Prático da matéria DCC062 - Sistemas Operacionais na UFJF.

## Objetivo
Simular o escalonamento de processos dos escalonadores FIFO e Round-Robin em C++ com o compilador GCC utilizando Linux.

## Organização
O projeto possui 4 classes:

* Processo: possui métodos simples para a simulação de um processo sendo rodado por uma determinada quantidade de tempo
* Escalonador: classe base para as classes FIFO e RoundRobin, possui método simples de adicionar processos ao escalonador e um método abstrato para rodar o escalonador.
* FIFO: escalonador que funciona com a filosofia de Primeiro a Entrar, Primeiro a Sair.
* RoundRobin: escalonador que funciona com a filosofia de rodar uma quantidade pré-determinada de tempo para cada processo. Assim, permite uma justiça maior entre os processos.

## Como executar
Para compilar, é necessário utilizar a flag `pthread`:
```
g++ -pthread main.cpp -o escalonador
```

Para rodar o programa, basta:
```
./escalonador
```
