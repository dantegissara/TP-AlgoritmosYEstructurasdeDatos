#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "Arbol.h"

struct Arbol {
    NodoArbolPtr raiz;
};

struct NodoArbol {
    NodoArbolPtr izq;
    NodoArbolPtr der;
    void* data;
};



ArbolPtr crearArbolBinario() {
    ArbolPtr arbol = malloc(sizeof(struct Arbol));
    arbol->raiz = NULL;
    return arbol;
}

void insertarDatoArbol(ArbolPtr arbol, void* data, int (*comparar)(void*, void*)) {
    arbol->raiz = insertarNodoArbolHora(arbol->raiz, data, comparar);
}

NodoArbolPtr insertarNodoArbolHora(NodoArbolPtr nodo, void* data, int (*comparar)(void*, void*)) {
    if (nodo == NULL) {
        NodoArbolPtr nuevoNodo = (NodoArbolPtr)malloc(sizeof(struct NodoArbol));
        nuevoNodo->data = data;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        return nuevoNodo;
    }

    if (comparar(data, nodo->data) < 0) {
        nodo->izq = insertarNodoArbolHora(nodo->izq, data, comparar);
    } else if (comparar(data, nodo->data) > 0) {
        nodo->der = insertarNodoArbolHora(nodo->der, data, comparar);
    }

    return nodo;
}

void recorrerEnOrden(NodoArbolPtr nodo, void (*mostrar)(void*)) {
    if (nodo != NULL) {
        recorrerEnOrden(nodo->izq, mostrar);
        mostrar(nodo->data);
        recorrerEnOrden(nodo->der, mostrar);
    }
}

void mostrarDatosEnOrden(ArbolPtr arbol, void (*mostrar)(void*)) {
    recorrerEnOrden(arbol->raiz, mostrar);
}


int compararClientes(void* cliente1, void* cliente2) {
    int hora1 = getHora((ClientePtr)cliente1);
    int hora2 = getHora((ClientePtr)cliente2);
    return hora1 - hora2;
}
