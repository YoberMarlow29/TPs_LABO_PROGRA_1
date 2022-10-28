#ifndef EJUGADOR_H_
#define EJUGADOR_H_
#include "input.h"

typedef struct{
	int idJugador;
	char nombre[TAM_NOMBRE];
	char posicion[TAM_POSICION];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;
/// @brief Inicializa la estructura, funcion que tenemos que llamar al main para que funcione.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de los jugadores.
/// @return retorna 0 si es verdadero, -1 si es falso.
int JUG_inicializadorEstructura(eJugador listaJugador[], int tamJugador);
/// @brief  Buscaa si el id esta libre o ocupado.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de los jugadores.
/// @return retorna 0 si es verdadero, -1 si es falso.
int JUG_buscarIndiceLibre(eJugador listaJugador[],int tamJugador);
/// @brief Muestra la lista de un jugador.
///
/// @param jugador Recibe un jugador a mostrar.
void JUG_mostrarUno(eJugador jugador);
/// @brief Busca a algun jugador a traves del Id del mismo.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño del jugador.
/// @param id indice al que desea buscar.
/// @return retorna 0 si es verdadero, -1 si es falso.
int JUG_buscarJugador(eJugador listaJugador[],int tamJugador, int id);


#endif /* EJUGADOR_H_ */
