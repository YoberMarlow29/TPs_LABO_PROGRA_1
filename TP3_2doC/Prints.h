/*
 * prints.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Yober
 */

#ifndef PRINTS_H_
#define PRINTS_H_

/**
 * @brief pregunta si se quiere guardar los cambios 1-si, 2-no pidiendo la opcion al usuario y validandola
 *
 * @param confirmar
 */
void guardarCambios(int* confirmar);


/**
 * @brief pregunta por la confirmacion de borrar el el pasajero o si el id es erroneo
 *
 * @param confirmar
 */
void borrarJugador(int* confirmar);

/**
 * @brief le pregunta al usuario si el correcto el id del pasjero que desea modificar
 *
 * @param confirmar
 */
void modificarJugador(int* confirmar);
/**
 * @brief pregunta si el usiario desea continuar modificando
 *
 * @param continuar
 */
void preguntaContinuar(int* continuar);

void cabecera();


#endif /* PRINTS_H_ */
