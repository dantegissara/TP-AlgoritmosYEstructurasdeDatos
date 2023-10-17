#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "banco.h"
#include "lista.h"
#include "cliente.h"

struct NodoE{

    void * data;
    Nodo proximo;
};

struct PilaE{

    Nodo primero;
    int tamanio;
    int tamDelDatoEnBytes;
};

Nodo crearNodop(Pila pila, void *data){

    Nodo temp = malloc(sizeof(struct NodoE));

    temp->data = malloc(pila->tamDelDatoEnBytes);

    if(!temp->data){
        free(temp);
        return temp;
    }

    memcpy(temp->data,data,pila->tamDelDatoEnBytes);

    return temp;

}

Pila crearPila(int tamDelDatoEnBytes){

    Pila pila=malloc(sizeof(struct PilaE));

    pila->primero=NULL;
    pila->tamanio=0;
    pila->tamDelDatoEnBytes=tamDelDatoEnBytes;

    return pila;
}


void apilar(Pila pila,void* dato){

    Nodo aux=crearNodop(pila,dato);

    if(pila->tamanio==0){
        pila->primero= aux;
        aux->proximo=NULL;
        pila->tamanio++;
    }

    aux->proximo=pila->primero;
    pila->primero=aux;
    pila->tamanio++;

}

Pila apilarLista(Lista l){

    Pila apilada= crearPila(sizeof(obtenerDato(l,0)));
    Nodo aux= obtenerPrimerNodo(l);
    int i=0;

    while(aux != NULL){

        printf("cliente apilado");
        mostrarCliente(*(ClientePtr*)obtenerDato(l,i));

        apilar(apilada,obtenerDato(l,i));
        aux=aux->proximo;
        i++;

    }

    return apilada;
};



