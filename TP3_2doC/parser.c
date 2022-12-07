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
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador, int* cantJugadores)
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
        					*cantJugadores= *cantJugadores+1;
        					retorno = 1;
        				}

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

int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, int* cantJugadores){

    int retorno=-1;
    int lectBinario;
    Jugador* jugador=NULL;

    if(pFile != NULL)
    	{
    		while(!feof(pFile))
    		{
				jugador = jug_new();

    				if(jugador!= NULL)
    				{
        				lectBinario= fread(jugador, sizeof(Jugador), 1, pFile);

        				if(lectBinario!= 0){
        					ll_add(pArrayListJugador, jugador);
        					*cantJugadores= *cantJugadores+1;
        					retorno = 1;
        				}
    				}
    		}
    	}
    	else
    	{
    		printf("Lo sentimos!Hubo un ror al cargar el archivo modo bin.\n");
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
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion, int*cantSelecciones)

{
    int retorno=-1;

    char idAux[4];
    char paisAux[30];
    char confederacionAux[30];
    char convocadosAux[25];

    Seleccion* seleccion;

    if(pFile != NULL)
    {
    	if(pArrayListSeleccion != NULL)
    	{
    		do
    		{

    			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,paisAux,confederacionAux,convocadosAux)==4)
    			{
    				seleccion= selec_newParametros(idAux, paisAux, confederacionAux, convocadosAux);

    				if(seleccion !=NULL)
    				{
    					ll_add(pArrayListSeleccion, seleccion);
    					*cantSelecciones= *cantSelecciones+1;
    					retorno=1;
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

int parser_SeleccionFromBinary(FILE* pFile, LinkedList* pArrayListSeleccion, int*cantSelecciones){
	 int retorno=-1;
	    int lectBinario;
	    Seleccion* seleccion=NULL;

	    if(pFile != NULL)
	    	{
	    		while(!feof(pFile))
	    		{
	    			seleccion = selec_new();

	    				if(seleccion!= NULL)
	    				{
	        				lectBinario= fread(seleccion, sizeof(seleccion), 1, pFile);

	        				if(lectBinario!= 0)
	        				{
	        					ll_add(pArrayListSeleccion, seleccion);
	        					*cantSelecciones= *cantSelecciones+1;
	        					retorno = 1;
	        				}
	    				}
	    		}
	    	}
	    	else
	    	{
	    		printf("Lo sentimos!Hubo un ror al cargar el archivo modo bin.\n");
	    	}





	return retorno;
}
