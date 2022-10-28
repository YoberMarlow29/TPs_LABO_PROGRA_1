#include "input.h"
#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_
typedef struct{

	int idCondefederacion;
	char nombre[TAM_NOMBRE_CONFEDERACION];
	char region[TAM_REGION];
	int anioCreacion;
	short isEmpty;

}eConfederacion;
/// @brief Muestra una confederacion.
///
/// @param Recibe una confederacion a mostrar.
void CONF_mostrarUno(eConfederacion confederacion);
/// @brief Muestra la lista de la confederacion.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
void CONF_MostrarListaTipo(eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief Busca a alguna confederacion a traves del Id.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
/// @param id Id a buscar.
/// @return retorna 0 si es verdadero, -1 si es falso.
int CONF_buscarConfederacion(eConfederacion listaConfederacion[],int tamConfederacion, int id);
/// @brief Inicializa la estructura confederacion.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
/// @return retorna 0 si es verdadero, -1 si es falso.
int CONF_inicializadorEstructura(eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Busca si el id esta libre o ocupado.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
/// @return retorna 0 si es verdadero, -1 si es falso.
int CONF_buscarIndiceLibre(eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Pide datos de la confederacion.
///
/// @return retorna el jugador generado.
eConfederacion CONF_pedirDatos();
/// @brief Da de alta a la confederacion.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
/// @return retorna 0 si es verdadero, -1 si es falso.
int CONF_alta(eConfederacion listaConfederacion[],int tamConfederacion);
/// @brief Modifica a la confederacion.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
/// @return retorna 0 si es verdadero, -1 si es falso.
int CONF_modificar(eConfederacion listaConfederacion[], int tamConfederacion);
/// @brief da de baja a la confederacion.
///
/// @param listaConfederacion lista de la confederacion.
/// @param tamConfederacion tamaño de la confederaicon.
/// @return retorna 0 si es verdadero, -1 si es falso.
int CONF_baja(eConfederacion listaConfederacion[],int tamConfederacion);






#endif /* ECONFEDERACION_H_ */
