#include "LinkedList.h"
#include "input.h"


#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);
int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);
int jug_setEdad(Jugador* this,int edad);

int jug_getEdad(Jugador* this,int* edad);
int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this, int* idSeleccion);
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

int encontrarUltimoId(char* path, char* id);
int grabarId(char* path,char* id);

void jug_mostrarUn(Jugador* jugador, char confederacion[30]);

int jug_convocado(Jugador* jugador);
void imprimir_Jugador(Jugador* this);

int jug_OrdenarPorId(void* jugadorUno, void* jugadorDos);
int jug_OrdenarPorNombre(void* jugadorUno, void* jugadorDos);
int jug_OrdenarPorNacionalidad(void* jugadorUno, void* jugadorDos);
int jug_OrdenarPorEdad(void* jugadorUno, void* jugadorDos);





#endif // jug_H_INCLUDED
