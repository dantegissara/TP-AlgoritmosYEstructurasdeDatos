#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "lista.h"
#include "cliente.h"

struct Banco;

typedef struct Banco * BancoPtr;

BancoPtr crearBanco(char n[15], char d[15]);

void mostrarBanco(BancoPtr b);

char *getNombre(BancoPtr b );

char * getDireccion(BancoPtr b);

void setNombre(BancoPtr b, char  nuevo[15]);

void setDireccion(BancoPtr b, char  nuevo[15]);

void destruirBanco(BancoPtr b);

void setListaBanco(BancoPtr,Lista lista);

void ordenarListaBanco(Lista lista);

int getDatoHora(BancoPtr b);

void ordenarBancoPorHora(BancoPtr banco);

Lista getListaBanco(BancoPtr b);

void mostrarCajaDeAhorro(BancoPtr b,char *c);

void insertarClienteEnBancoYArbol(BancoPtr banco, ClientePtr cliente);


#endif // BANCO_H_INCLUDED
