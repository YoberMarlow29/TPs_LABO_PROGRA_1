#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
    int retorno=-1;

    char idAux[100];
    char nombreCompletoAux[100];
    char edadAux[100];
    char posicionAux[100];
    char nacionalidadAux[100];
    char idSelccionAux[100];
    Jugador* jugador=NULL;
    if(pFile != NULL)
    	{

    		if(pArrayListJugador != NULL)
    		{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSelccionAux);

    			do{

    				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSelccionAux)== 6)
    				{

        				jugador =  jug_newParametros(idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSelccionAux);

        				if(jugador != NULL)
        				{
        					ll_add(pArrayListJugador, jugador);
        					retorno = 1;
        				}

    				}
    				else
    				{
    					printf("\nERROR DOS");

    				}



    			}while(!feof(pFile));
    		}
    	}
    	else
    	{
    		printf("Lo sentimos!Hubo urror al cargar el archivo modo txt.\n");
    	}
    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
    int retorno=-1;

    char idAux[4];
    char paisAux[25];
    char confederacionAux[4];
    char convocadosAux[25];

    Seleccion* seleccion;
    printf("entre al parser\n");
    if(pFile != NULL)
    {
    	printf("valide el archivo\n");
    	if(pArrayListSeleccion != NULL)
    	{

    		printf("%d",fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]",idAux,paisAux,confederacionAux,convocadosAux));

    		do
    		{
    			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]",idAux,paisAux,confederacionAux,convocadosAux)==6)
    			{
    				seleccion= selec_newParametros(idAux, paisAux, confederacionAux, convocadosAux);
    				if(seleccion !=NULL)
    				{
    					ll_add(pArrayListSeleccion, seleccion);
    				}
    				else
    				{
    					printf("ERROR, intentelo nuevamente\n");
    				}
    			}

    		}while(!feof(pFile));

    	}
    }
    else
    {
    	printf("ERROR al cargar archivo modo txt.\n");
    }

	return retorno;
}

