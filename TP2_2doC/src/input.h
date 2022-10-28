#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0
#define TAM_NOMBRE 50
#define TAM_POSICION 50
#define TAM_NOMBRE_CONFEDERACION 50
#define TAM_REGION 50



#ifndef INPUT_H_
#define INPUT_H_


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int UTN_pedirEnteroRango(char* mensaje, int min, int max);
int getNumeroCorto(short* pResultado);
int utn_getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);





#endif /* INPUT_H_ */
