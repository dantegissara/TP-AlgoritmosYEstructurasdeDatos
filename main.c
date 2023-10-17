#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#include "cliente.h"
#include "banco.h"
#include "pila.h"
#include "Arbol.h"

void mostrarListaCliente(Lista lista);
void mostrarClienteArbol(void* cliente);

int main()
{
    printf("TP AYED - Dante - Gissara - 44544372\n");
    printf("ARBOLES BINARIOS: Creacion de Estructuras para trabajar con arboles binarios del tipo VOID\nQue me va a servir para ordenar de manera mas directa a los clientes\ncon respecto a los horarios que tienen asignados en el banco\n");


    BancoPtr b1 = crearBanco("Santander","EVA PERON 1111");

    ClientePtr c1 = crearCliente("Ruben Fernandez",11, "Caja de ahorro");
    ClientePtr c2 = crearCliente("Lucia Pascuale",9, "Inversiones");
    ClientePtr c3 = crearCliente("Brenda Benitez",7, "Moneda extranjera");
    ClientePtr c4 = crearCliente("Luana Szpyrka",13, "Caja de ahorro");

    Lista nuevaLista = NULL;
    ArbolPtr arbol1 = NULL;



    int opcion;
    do {
        printf("\n----------- Menu -----------\n");
        printf("1. Opcion 1: MOSTRAR BANCO\n");
        printf("2. Opcion 2: INSERTAR CLIENTES EN LA LISTA DEL BANCO\n");
        printf("3. Opcion 3: ORDENAR BANCO(por hora)\n");
        printf("4. Opcion 4: DUPLICAR LISTA DEL BANCO\n");
        printf("5. Opcion 5: MOSTRAR CLIENTES CON CAJA DE AHORROS\n");
        printf("6. Opcion 6: APILAR CLIENTES\n");
        printf("7. Opcion 7: (NUEVO) CREAR ARBOL Y CARGAR LOS CLIENTES EN ORDEN(horario)\n");
        printf("8. Opcion 8: (NUEVO) RECORRER Y MOSTRAR LOS DATOS DEL ARBOL CREADO)\n");
        printf("9. Opcion 9: MOSTRAR LISTA CLIENTES(del banco)\n");
        printf("10. Opcion 10: (NUEVO) INSERTAR EN LISTA DEL BANCO Y EN ARBOL DEL BANCO A MEDIDA QUE ENTRAN LOS CLIENTES\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarBanco(b1);
                break;
            case 2:
                insertarFinal(getListaBanco(b1),&c1);
                insertarFinal(getListaBanco(b1),&c2);
                insertarFinal(getListaBanco(b1),&c3);
                insertarFinal(getListaBanco(b1),&c4);
                break;
            case 3:
                ordenarBancoPorHora(b1);
                break;
            case 4:
                nuevaLista = duplicarLista(getListaBanco(b1));
                break;
            case 5:
                mostrarCajaDeAhorro(b1,"Caja de ahorro");
                break;
            case 6:
                apilarLista(nuevaLista);
                break;
            case 7:
                arbol1 = crearArbolBinario();
                insertarDatoArbol(arbol1, c1, compararClientes);
                insertarDatoArbol(arbol1, c2, compararClientes);
                insertarDatoArbol(arbol1, c3, compararClientes);
                insertarDatoArbol(arbol1, c4, compararClientes);
                break;
            case 8:
                mostrarDatosEnOrden(arbol1,mostrarClienteArbol);
                break;
            case 9:
                mostrarListaCliente(getListaBanco(b1));
                break;
            case 10:
                insertarClienteEnBancoYArbol(b1,c1);
                insertarClienteEnBancoYArbol(b1,c2);
                insertarClienteEnBancoYArbol(b1,c3);
                insertarClienteEnBancoYArbol(b1,c4);

                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 0);

    return 0;
}


void mostrarListaCliente(Lista lista){
    int t = obtenerTamanio(lista);
    for(int i = 0; i<t ; i++){
        mostrarCliente(*(ClientePtr*)obtenerDato(lista,i));
    }
}
void mostrarClienteArbol(void* cliente) {
        mostrarCliente((ClientePtr)cliente);
    }









