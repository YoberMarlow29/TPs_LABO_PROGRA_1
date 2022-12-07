#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "input.h"

int main() {
	setbuf(stdout, NULL);
	LinkedList *listaJugadores = ll_newLinkedList();
	int cantJugadores = 0;
	LinkedList *listaSelecciones = ll_newLinkedList();
	int cantSelecciones = 0;

	int cargaTextoJugadores = 0;
	int cargaTextoSelecciones = 0;

	int guardaBinario = 0;
	int cargaJugador = 0;

	int primeraCargaArchivos=0;
	int respuesta;
	int opcion;
	do {
		respuesta = utn_getNumero(&opcion, "\nSeleccione una opcion:(1-12) \n"
				"\n1-CARGA DE ARCHIVO TEXTO "
				"\n2-ALTA DE JUGADOR: "
				"\n3-MODIFICACION DE JUGADOR: "
				"\n4-BAJA DE JUGADOR: "
				"\n5-LISTADOS: "
				"\n6-CONVOCAR JUGADORES: "
				"\n7-ORDENAR Y LISTAR: "
				"\n8-GENERAR ARCHIVO BINARIO: "
				"\n9-CARGAR ARCHIVOS BINARIO "
				"\n10-GUARDAR ARCHIVOS .CSV: "
				"\n11-SALIR", "ERROR.OPCION INCORRECTA", 1, 11, 10);

		if (!respuesta) {
			switch (opcion) {
			case 1:
				if(primeraCargaArchivos<1){

					printf("\t\t***** CARGA DE ARCHIVO DE TEXTO *****\n");
					cargaTextoJugadores = controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores, &cantJugadores);
					cargaTextoSelecciones = controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones, &cantSelecciones);
					primeraCargaArchivos++;
				}else{
					printf("\nNO SE PUEDE CARGAR DOS VECES LOS ARCHIVOS \n");
				}
				break;

			case 2:
				if (cargaTextoJugadores == 1 && cargaTextoSelecciones == 1) {
					printf("\t\t***** ALTA DE JUGADOR *****\n");
					cargaJugador = controller_agregarJugador(listaJugadores,
							&cantJugadores);
					if (cargaJugador != -1) {
						printf("\nJUGADOR AGREGADO");
					} else {

						printf("\nNO SE PUDO AGREGAR AL JUGADOR");
					}
				} else {
					printf(
							"\nSE DEBE CARGAR LOS ARCHIVOS PARA PODER HACER LA CARGA DE UN JUGADOR\n");
				}

				break;

			case 3:
				printf("\t\t***** MODIFICACION DE JUGADOR *****\n");
				if (cargaTextoJugadores == 1 && cargaTextoSelecciones == 1) {
					controller_editarJugador(listaJugadores, listaSelecciones);
				} else {
					printf(
							"\nSE DEBE CARGAR LOS ARCHIVOS PARA PODER HACER LA CARGA DE UN JUGADOR\n");
				}
				break;

			case 4:
				printf("\t\t***** BAJA DE JUGADOR *****\n");
				if (cargaTextoJugadores == 1 && cargaTextoSelecciones == 1) {
					controller_removerJugador(listaJugadores, listaSelecciones);
				} else {
					printf(
							"\nSE DEBE CARGAR LOS ARCHIVOS PARA PODER HACER LA CARGA DE UN JUGADOR\n");
				}
				break;

			case 5:
				printf("\t\t***** LISTADOS *****\n");
				if (cargaTextoJugadores == 1 && cargaTextoSelecciones == 1) {
					controller_listados(listaJugadores, listaSelecciones);
				} else {
					printf(
							"\nSE DEBE CARGAR LOS ARCHIVOS PARA PODER HACER LA CARGA DE UN JUGADOR\n");
				}

				break;

			case 6:
				printf("\t\t***** CONVOCAR JUGADORES *****\n");
				if(cargaTextoJugadores==1 && cargaTextoSelecciones==1){
					controller_menuConvocar(listaJugadores , listaSelecciones, cantJugadores, cantSelecciones);
				}
				else {
					printf(
							"\nSE DEBE CARGAR LOS ARCHIVOS PARA PODER HACER LA CARGA DE UN JUGADOR\n");
				}
				break;

			case 7:
				printf("\t\t***** ORDENAR Y LISTAR *****\n");
				if(cargaTextoJugadores==1 && cargaTextoSelecciones==1){
					controller_menuOrdenar(listaJugadores, listaSelecciones);
				}
				else {
					printf(
							"\nSE DEBE CARGAR LOS ARCHIVOS PARA PODER HACER LA CARGA DE UN JUGADOR\n");
				}
				break;

			case 8:
				printf("\t\t***** GENERAR ARCHIVO BINARIO *****\n");

				if (cargaJugador != -1 || cargaTextoJugadores != -1) {
					guardaBinario = controller_saveAsBinary("jugadores.bin", listaJugadores, listaSelecciones, cantJugadores, cantSelecciones);
					if (guardaBinario != -1) {
						printf("\nSE HAN GUARDADO LOS DATOS \n");
					} else {
						printf(
								"\nHUBO UN ERROR Y NO SE GUARDO LA INFORMACION\n");

					}
				} else {
					printf("\nPRIMERO DEBE CARGAR/GUARDAR DATOS\n");
				}
				break;

			case 9:
				printf("\t\t***** CARGAR ARCHIVO BINARIO *****\n");
				if(guardaBinario==1){
					controller_cargarJugadoresDesdeBinario("jugadores.bin", listaSelecciones);

				}
				else{
					printf("\nDEBE GUARDAR PRIMERO UN ARCHIVO BINARIO\n");
				}

				break;

			case 10:
				printf("\t\t***** GUARDAR ARCHIVOS .CSV *****\n");
				int guardaTexto = controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores, primeraCargaArchivos);
				if(guardaTexto==1){
					printf("\nARCHIVO GUARDADO\n");
				}

				break;

			case 11:
				printf("\t\t***** SALIR *****\n");
				break;
			}
		}

	} while (opcion != 12);

	return 0;
}

