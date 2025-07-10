#pragma once

#include "Escalonador.hpp"

class FIFO : public Escalonador
{
private:

public:
	FIFO(const unsigned int n_processos_max) : Escalonador(n_processos_max){}

	void run()
	{
		
	}
};
