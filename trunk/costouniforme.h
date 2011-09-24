#ifndef COSTOUNIFORME_H
#define COSTOUNIFORME_H

#include "algoritmos.h"
#include "priorityqueue.cpp"

class CostoUniforme : public Algoritmos
{
private:
    bool *direcciones;
public:
    CostoUniforme(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
};

#endif // COSTOUNIFORME_H
