#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct Cliente{

    char nombreYApellido[15];

    int hora;

    char turno[15];

};



ClientePtr crearCliente(char nyA[15], int hora, char t[15] ){


    ClientePtr cliente = (ClientePtr) malloc(sizeof(struct Cliente));


    strcpy(cliente->nombreYApellido, nyA);

    strcpy(cliente->turno, t);

    cliente->hora = hora;






    return cliente ;

};

void mostrarCliente(ClientePtr c){

    printf("\n\t-----------CLIENTE-------------\n");
    printf("\tNOMBRE: %s\n",c->nombreYApellido);
    printf("\tTURNO: %s\n",c->turno);
    printf("\tHORA: %d\n",c->hora);


};

char* getNombreYApellido(ClientePtr c){
    return c->nombreYApellido;

};

char* getTurno(ClientePtr c){
    return c->turno;
};

int getHora(ClientePtr c){
    return c->hora;
};

void setNombreYApellido(ClientePtr c, char nYA[15]){

    strcpy(c->nombreYApellido, nYA);

};

void setHora(ClientePtr c, int hora){

    c->hora = hora;

};

void setTurno(ClientePtr c, char turno[15]){

    strcpy(c->turno, turno);

};

void destruirCliente(ClientePtr c){


    free(c);

};


