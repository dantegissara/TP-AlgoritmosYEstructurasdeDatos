#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "lista.h"

struct NodoE;
typedef struct NodoE * Nodo;

struct PilaE;
typedef struct PilaE * Pila;

Nodo crearNodop(Pila pila, void *data);
Pila crearPila(int tamDelDatoEnBytes);

void apilar(Pila pila,void* dato);

Pila apilarLista(Lista l);


#endif // PILA_H_INCLUDED
