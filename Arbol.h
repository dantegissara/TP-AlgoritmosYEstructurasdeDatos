#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct Arbol;

typedef struct Arbol * ArbolPtr;

struct NodoArbol;

typedef struct NodoArbol * NodoArbolPtr;


ArbolPtr crearArbolBinario();

void insertarDatoArbol(ArbolPtr arbol, void* data, int (*comparar)(void*, void*));



NodoArbolPtr insertarNodoArbolHora(NodoArbolPtr nodo, void* data, int (*comparar)(void*, void*));

void recorrerEnOrden(NodoArbolPtr nodo, void (*mostrar)(void*));
void mostrarDatosEnOrden(ArbolPtr arbol, void (*mostrar)(void*));

int compararClientes(void* cliente1, void* cliente2);


void mostrarClientesEnOrden(ArbolPtr arbol);


#endif // ARBOL_H_INCLUDED
