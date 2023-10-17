#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


struct Cliente;

typedef struct Cliente * ClientePtr;


ClientePtr crearCliente(char nyA[15], int hora, char t[15] );

void mostrarCliente(ClientePtr c);

char* getNombreYApellido(ClientePtr c);

char* getTurno(ClientePtr c);

int getHora(ClientePtr c);

void setNombreYApellido(ClientePtr c, char nYA[15]);

void setHora(ClientePtr c, int hora);

void setTurno(ClientePtr c, char  turno[15]);

void destruirCliente(ClientePtr c);



#endif // CLIENTE_H_INCLUDED
