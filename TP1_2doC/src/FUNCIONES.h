/*
 * FUNCIONES.h
 *
 *  Created on: 16 sep. 2022
 *      Author: Yober
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// \brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
/// \param pNumero Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje de error a ser mostrado
/// \param minimo Es el numero maximo a ser aceptado
/// \param maximo Es el numero maximo a ser aceptado
/// \param reintentos Es el numero de intentos que se iran terminando
/// \return Retorna 0 si se obtuvo el numero y -1 si no
int getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
/// \param pNumero Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje de error a ser mostrado
/// \param minimo Es el numero maximo a ser aceptado
/// \param maximo Es el numero maximo a ser aceptado
/// \param reintentos Es el numero de intentos que se iran terminando
/// \return Retorna 0 si se obtuvo el numero y -1 si no
int getFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
/// \brief Solicita los tipo de gastos al usuario, luego de verificarlo devuelve el resultado
/// \param gastoH Puntero al espacio de memoria donde se dejara el gasto de Hospedaje
/// \param gastoC Puntero al espacio de memoria donde se dejara el gasto de Comida
/// \param gastoT Puntero al espacio de memoria donde se dejara el gasto de Transporte
/// \return Retorna 0 si se obtuvo el numero y -1 si no
int cargarGastos(float* gastoH, float* gastoC, float* gastoT);
/// \brief Asigna la confederacion y los va guardando dependiendo su eleccion
/// \param confederacion Es la confederacion a ingresar
/// \param contadorAFC Puntero al espacio de memoria donde se guarda el contador de AFC y va almacenando a medida de que lo elijan
/// \param contadorCAF Puntero al espacio de memoria donde se guarda el contador de CAF y va almacenando a medida de que lo elijan
/// \param contadorConcacaf Puntero al espacio de memoria donde se guarda el contador de Concacaf y va almacenando a medida de que lo elijan
/// \param contadorConmmebol Puntero al espacio de memoria donde se guarda el contador de Conmmebol y va almacenando a medida de que lo elijan
/// \param contadorUEFA Puntero al espacio de memoria donde se guarda el contador de UEFA y va almacenando a medida de que lo elijan
/// \param contadorOFC Puntero al espacio de memoria donde se guarda el contador de OFC y va almacenando a medida de que lo elijan
void asignarConfederacion(int confederacion, int* contadorAFC, int* contadorCAF, int* contadorConcacaf, int* contadorConmmebol, int* contadorUEFA, int* contadorOFC);
/// \brief Asigna la posicion y los va guardando dependiendo la eleccion
/// \param posicion Es la posicion a ingresar
/// \param cantidadJugadores Puntero al espacio de memoria de cantidad de jugadores que es 22
/// \param contadorArquero Puntero al espacio de memoria donde se guarda el contador de Arquero
/// \param contadorDefensor Puntero al espacio de memoria donde se guarda el contador de Defensor
/// \param contadorMedioCampista Puntero al espacio de memoria donde se guarda el contador de MedioCampista
/// \param contadorDelantero Puntero al espacio de memoria donde se guarda el contador de Delantero
/// \return Retorno 1 si se pudo cargar y 0 si no
int asignarPosicion(int posicion, int *cantidadJugadores, int* contadorArquero, int* contadorDefensor, int* contadorMedioCampista, int* contadorDelantero);
/// \brief Imprime las posiciones que se fueron ingresando
/// \param contadorArquero numero a imprimir de contador Arquero
/// \param contadorDefensor numero a imprimir de contador Defensor
/// \param contadorMedioCampista numero a imprimir de contador MedioCampista
/// \param contadorDelantero numero a imprimir de contador Delantero
void imprimirEquipo(int contadorArquero, int contadorDefensor, int contadorMedioCampista, int contadorDelantero);
/// \brief Calcula los promedios  de las asignaturas
/// \param cantidadJugadores Contiene la cantidad de jugadores que es 22
/// \param contadorAFC Contiene la posicion AFC ingresada
/// \param contadorCAF Contiene la posicion CAF ingresada
/// \param contadorConcacaf Contiene la posicion CONCACAF ingresada
/// \param contadorConmmebol Contiene la posicion CONMEBOL ingresada
/// \param contadorUEFA Contiene la posicion UEFA ingresada
/// \param contadorOFC Contiene la posicion OFC ingresada
/// \param promedioAFC Contiene el promedio de AFC que es el resultado de de la cantidad de jugadores / el contador AFC
/// \param promedioCAF Contiene el promedio de CAF que es el resultado de de la cantidad de jugadores / el contador CAF
/// \param promedioConcacaf Contiene el promedio de CONCACAF que es el resultado de de la cantidad de jugadores / el contador CONCACAF
/// \param promedioConmmebol Contiene el promedio de CONMEBOL que es el resultado de de la cantidad de jugadores / el contador CONMEBOL
/// \param promedioUEFA Contiene el promedio de UEFA que es el resultado de de la cantidad de jugadores / el contador UEFA
/// \param promedioOFC Contiene el promedio de OFC que es el resultado de de la cantidad de jugadores / el contador OFC
void obtenerPromedios(int cantidadJugadores, int contadorAFC, int contadorCAF, int contadorConcacaf, int contadorConmmebol, int contadorUEFA, int contadorOFC, float* promedioAFC, float* promedioCAF, float* promedioConcacaf,float* promedioConmmebol, float* promedioUEFA, float* promedioOFC);
/// \brief Imprime los promedios obetenidos
/// \param promedioAFC numero a imprimir del resultado promedio AFC
/// \param promedioCAF numero a imprimir del resultado promedio CAF
/// \param promedioConcacaf numero a imprimir del resultado promedio CONCACAF
/// \param promedioConmmebol numero a imprimir del resultado promedio CONMEBOL
/// \param promedioUEFA numero a imprimir del resultado promedio UEFA
/// \param promedioOFC numero a imprimir del resultado promedio OFC
void imprimirPromedios(float promedioAFC, float promedioCAF, float promedioConcacaf,float promedioConmmebol, float promedioUEFA, float promedioOFC);
/// \brief Calcula la mayoria de jugadores ingresados en UEFA
/// \param contadorAFC contiene el numero de jugadores dentro de AFC
/// \param contadorCAF contiene el numero de jugadores dentro de CAF
/// \param contadorConcacaf contiene el numero de jugadores dentro de CONCACAF
/// \param contadorConmmebol contiene el numero de jugadores dentro de CONMEBOL
/// \param contadorUEFA contiene el numero de jugadores dentro de UEFA
/// \param contadorOFC contiene el numero de jugadores dentro de OFC
/// \return retorna 1 en el caso de que el mayor sea UEFA sino no
int calcularMayoriaUEFA(int contadorAFC, int contadorCAF, int contadorConcacaf, int contadorConmmebol, int contadorUEFA, int contadorOFC);
/// \brief Calcula los costos y tambien calcula el incremento si se llega a dar
/// \param gastoMantenimiento Puntero al espacio de memoria donde se almacena el gasto de mantenimiento
/// \param mantenimientoConIncremento Puntero al espacio de memoria donde se almacena el gasto de mantenimiento con un %35 en el caso de que los jugadores sean de la UEFA en mayoria
/// \param incremento donde se almacena el gasto de mantenimiento donde esta el incremento del %35
/// \param gastoH gasto ingresado de gasto de Hospedaje
/// \param gastoC gasto ingresado de gasto de Comida
/// \param gastoT gasto ingresado de gasto de Transporte
/// \param mayoriaUEFA en el caso de que mayoriaUEFA sea ==1 hace el calculo con el incremento
void calcularCostos(float *gastoMantenimiento,float *mantenimientoConIncremento, float* incremento, float gastoH, float gastoC, float gastoT, int mayoriaUEFA);



#endif /* FUNCIONES_H_ */
