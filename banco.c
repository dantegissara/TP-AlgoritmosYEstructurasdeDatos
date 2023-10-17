#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "lista.h"
#include "cliente.h"
#include "Arbol.h"

struct Banco{

    char nombre[15];

    char direccion[15];

    Lista listaClientes;

    ArbolPtr arbolClientes;

};



BancoPtr crearBanco(char n[15], char d[15]){

    BancoPtr b = (BancoPtr) malloc(sizeof(struct Banco));

    strcpy(b->direccion, d);

    strcpy(b->nombre, n);

    b->listaClientes = crearLista(sizeof(ClientePtr));

    b->arbolClientes = crearArbolBinario();

    return b;

};

void mostrarBanco(BancoPtr b){

    printf("\n\n-----------BANCO-------------\n");
    printf("NOMBRE: %s\n", b->nombre);
    printf("DIRECCION: %s\n", b->direccion);
    int t = obtenerTamanio(getListaBanco(b));
    printf("MUESTRO LISTA:\n\n");
    for(int i = 0; i<t ; i++){
        mostrarCliente(*(ClientePtr*)obtenerDato(getListaBanco(b),i));
    }
    printf("\nMUESTRO ARBOL:\n\n");
    mostrarDatosEnOrden(b->arbolClientes,*mostrarCliente);

};

char *getNombre(BancoPtr b ){
    return b->nombre;
};

char * getDireccion(BancoPtr b){
    return b->direccion;
};

void setNombre(BancoPtr b, char nuevo[15]){

    strcpy(b->nombre, nuevo);

};

void setDireccion(BancoPtr b, char  nuevo[15]){
    strcpy(b->direccion, nuevo);
};

void destruirBanco(BancoPtr b){

    free(b);
};

void setListaBanco(BancoPtr b,Lista lista){
    b->listaClientes = lista;
}



Lista getListaBanco(BancoPtr b){
    return b->listaClientes;
}

void ordenarBancoPorHora(BancoPtr b){

    Lista listAux=getListaBanco(b);
    Nodo aux=obtenerPrimerNodo(listAux);
    int i=0;
    int cambio=1;
    void* auxDato;

    do{
        aux=obtenerPrimerNodo(listAux);
        i=0;
        cambio=0;

        while(getProximo(aux) != NULL){

            ClientePtr cliente1 = *(ClientePtr*)obtenerDato(listAux,i);
            ClientePtr cliente2 = *(ClientePtr*)obtenerDato(listAux,i+1);

            if(getHora(cliente1)> getHora(cliente2)){

                auxDato= getDato(aux);
                setDato(aux,getDato(getProximo(aux)));
                setDato(getProximo(aux),auxDato);
                cambio=1;
            }
            aux=getProximo(aux);
            i++;
        }
    }while(cambio);

};

void mostrarCajaDeAhorro(BancoPtr b,char *c){

    Lista listaAux = getListaBanco(b);
    Nodo aux= obtenerPrimerNodo(listaAux);
    int i=0;
    while(aux != NULL){
        ClientePtr cliente1 =*(ClientePtr*)obtenerDato(listaAux,i);
        if(strcmp(getTurno(cliente1),c)==0){

            mostrarCliente(cliente1);
        }

        aux=getProximo(aux);
        i++;
    }

};

void insertarClienteEnBancoYArbol(BancoPtr banco, ClientePtr cliente) {
    // Inserta en el árbol (asegurando que se inserte en orden por hora)
    insertarDatoArbol(banco->arbolClientes, cliente, compararClientes);

    insertarFinal(banco->listaClientes, &cliente);
}
