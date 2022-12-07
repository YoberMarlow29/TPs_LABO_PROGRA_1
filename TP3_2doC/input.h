#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

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


void getNumeroValidarMaxMin(int* numero, char mensaje[],char mensajeError[], int max, int min);
void ponerMayusculas(char* nombre);
int pedirString(char* string, char* mensaje, char* mensajeError);
int validarCadenaDeNumeros(char* cadena);
int pedirNumeros(int* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo);
int pedirNumerosFloat(float* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo);
void getNumeroValidarMaxMinFloat(float *numero, char mensaje[],char mensajeError[], int max, int min);


#endif /* INPUT_H_ */
