#include "input.h"
#include "eJugador.h"
#include "eConfederacion.h"
#ifndef PROCESOS_H_
#define PROCESOS_H_
/// @brief Realiza la suma total de los salarios de los jugadores.
///
/// @param listaJugador lista del jugador.
/// @param tamJugador tamaño de la lista.
/// @return  retorna la sumatoria.
float sumaTotal(eJugador listaJugador[],int tamJugador);
/// @brief Realiza el promedio por jugador.
///
/// @param listaJugador lista del jugador.
/// @param tamJugador tamaño de la lista.
/// @return retorna el promedio.
float promedioPorJugador(eJugador listaJugador[],int tamJugador);
/// @brief Cuenta los jugadores por confederacion.
///
/// @param listaJugador lista del jugador.
/// @param tamJugador tamaño de la lista.
/// @param idConfederacion Recibe el id de la confederacion a contar.
/// @return retorna la cantidad de jugadores por confederaicon.
int contarJugadoresEnConfederacion(eJugador listaJugador[],int tamJugador, int idConfederacion);
/// @brief Calcula el porcentaje.
///
/// @param contadorPorConfederacion  contador de la confederacion.
/// @param contadorJugadorTotal contador de los jugadores totales.
/// @return retorna el porcentaje.
float calculoPorcentaje(int contadorPorConfederacion, int contadorJugadorTotal);


#endif /* PROCESOS_H_ */
