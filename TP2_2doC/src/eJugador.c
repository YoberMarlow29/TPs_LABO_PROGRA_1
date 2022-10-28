#include "eJugador.h"

int JUG_inicializadorEstructura(eJugador listaJugador[], int tamJugador)
{
	int retorno;
	retorno=-1;
	if(listaJugador != NULL && tamJugador>0){

		for(int i=0;i<tamJugador;i++){
			listaJugador[i].isEmpty = LIBRE;
		}
		retorno =0;
	}

	return retorno;
}

int JUG_buscarIndiceLibre(eJugador listaJugador[],int tamJugador)
{
	 int retorno;
	 retorno=-1;

	 if(listaJugador != NULL && tamJugador>0){
	 		for(int i=0;i<tamJugador;i++){
	 			if(listaJugador[i].isEmpty == LIBRE){
	 				retorno=i;
	 				break;
	 			}
	 		}
	 	}
	 return retorno;
}
void JUG_mostrarUno(eJugador jugador)
{


	printf("\n|%-5d|%-24s|%-15s|%-15d|%-20.2f|%-18d|",jugador.idJugador,jugador.nombre,jugador.posicion,jugador.numeroCamiseta,jugador.salario,jugador.aniosContrato);

}

int JUG_buscarJugador(eJugador listaJugador[],int tamJugador, int id)
{
	 int retorno;
	 retorno=-1;

	 if(listaJugador != NULL && tamJugador>0){
	 		for(int i=0;i<tamJugador;i++){
	 			if(listaJugador[i].idJugador==id){
	 				retorno=i;
	 				break;
	 			}
	 		}
	 	}
	 return retorno;
}
