#include "LinkedList.h"
#include "input.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this, char* confederacion);
//int selec_getIsEmpty(Seleccion* this,int* isEmpty);

int selec_setConvocados(Seleccion* this, int convocados);
int selec_getConvocados(Seleccion* this, int* convocados);
void selec_mostrarUno(Seleccion* seleccion);
void selec_mostrarParaConvocar(Seleccion* seleccion);
int selec_OrdenarPorConfederacion(void* seleccionUno, void* seleccionDos);
int selec_OrdenarPorId(void* seleccionUno, void* seleccionDos);


#endif // selec_H_INCLUDED
