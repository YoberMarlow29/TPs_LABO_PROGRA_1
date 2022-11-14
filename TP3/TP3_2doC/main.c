#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "input.h"


int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaJugadores = ll_newLinkedList();

    int respuesta;
    int opcion;
    do{
    				respuesta= utn_getNumero(&opcion,"\nSeleccione una opcion:(1-11) \n"
    						"\n1-CARGA DE ARCHIVOS: "
    						"\n2-ALTA DE JUGADOR: "
    						"\n3-MODIFICACION DE JUGADOR: "
    						"\n4-BAJA DE JUGADOR: "
    						"\n5-LISTADOS: "
    						"\n6-CONVOCAR JUGADORES: "
    						"\n7-ORDENAR Y LISTAR: "
    						"\n8-GENERAR ARCHIVO BINARIO: "
    						"\n9-CARGAR ARCHIVO BINARIO"
    						"\n10-GUARDAR ARCHIVOS .CSV: "
    						"\n11-SALIR"
    						, "ERROR.OPCION INCORRECTA", 1, 9, 10);

    				if(!respuesta)
    				{
    					switch(opcion)
    					{
    					case 1:

    						printf("\t\t***** CARGA DE ARCHIVOS *****\n");
    						controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);


    						break;

    					case 2:
    						printf("\t\t***** ALTA DE JUGADOR *****\n");

    						if(controller_agregarJugador(listaJugadores)!=1)
    						{
    						}
    						break;
    					case 3:
    						printf("\t\t***** MODIFICACION DE JUGADOR *****\n");


    						break;
    					case 4:
    						printf("\t\t***** BAJA DE JUGADOR *****\n");


    						break;
    					case 5:
    						printf("\t\t***** LISTADOS *****\n");
    						controller_listarJugadores(listaJugadores);

    						break;
    					case 6:
    						printf("\t\t***** CONVOCAR JUGADORES *****\n");

    						break;
    					case 7:
    						printf("\t\t***** ORDENAR Y LISTAR *****\n");

    						break;
    					case 8:
    						printf("\t\t***** GENERAR ARCHIVO BINARIO *****\n");


    						break;
    					case 9:
    						printf("\t\t***** CARGAR ARCHIVO BINARIO *****\n");

    						break;
    					case 10:
    						printf("\t\t***** GUARDAR ARCHIVOS .CSV *****\n");

    						break;
    					case 11:
    						printf("\t\t***** SALIR *****\n");

    						break;
    					}
    				}

    			}while(opcion!=11);




    return 0;
}

