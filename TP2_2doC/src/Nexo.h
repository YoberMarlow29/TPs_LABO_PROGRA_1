#include "eJugador.h"
#include "eConfederacion.h"
#include "input.h"
#include "procesos.h"
#ifndef NEXO_H_
#define NEXO_H_
/// @brief Recibe el id y lo autoincrementa.
///
/// @return retorna el id autoincrementado.
int idAutoIncremental();
/// @brief Pide los datos de los jugadores y confederacion.
///
/// @param listaConfederacion lista de confederacion.
/// @param tamConfederacion tamaño de la confederacion.
/// @return retorna el jugador generado.
eJugador NEX_pedirDatosJugador(eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Realiza el alta del jugador.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
/// @return retorna 0 si es verdadero, -1 si es falso.
int NEX_altaJugador(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Realiza la baja del jugador pidiendole un Id.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
/// @return retorna 1 si funciono, -1 si no funciono.
int NEX_baja(eJugador listaJugador[], int tamJugador,eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Modifica el jugador pidiendole un id y muestra la lista de lo que se puede modificar.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
/// @return retorna 1 si funciono, -1 si no funciono.
int NEX_modificar(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Muestra lo que es la lista de todos los jugadores con la region de la confederacion.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
void NEX_mostrarTodoJugadorConfederacion(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief Imprime la lista de jugadores con el nombre de confederacion.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
void ImpresionOrdenada(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief Muestra la lista de los jugadores y nombre de la confederacion ordenamos alfabeticamente.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
void NEX_listadoOrdenamientoDobleCriterio(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief Muestra el salario de los jugadores.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
void NEX_informarSalario(eJugador listaJugador[],int tamJugador);
/// @brief Informa la confederacion con mayor año de contrato.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
void NEX_informeMayorCantidadConfederacion(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief Informa la region con mas jugadores con el listado de los mismos.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
void NEX_regionMasJugadores(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief  Informa el listado de los jugadores por confederacion.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param listaConfederacion lista de las confederaciones.
/// @param tamConfederacion tamaño de la lista de las confederaciones.
void NEX_jugadoresListadoPorConfederacion(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief Muestra el porcentaje de cada confederacion.
///
/// @param listaJugador lista de los jugadores.
/// @param tamJugador tamaño de la lista de jugadores.
/// @param contadorJugadorTotal numero de jugadores ingresados a traves del alta.
void NEX_porcentajePorConfederacion(eJugador listaJugador[],int tamJugador,int contadorJugadorTotal);





#endif /* NEXO_H_ */
