#include "eConfederacion.h"
#include <string.h>

void CONF_mostrarUno(eConfederacion confederacion)
{

	printf("\n|%-6d|%-10s|%-25s|%-14d|", confederacion.idCondefederacion,confederacion.nombre,confederacion.region,confederacion.anioCreacion);

}
void CONF_MostrarListaTipo(eConfederacion listaConfederacion[], int tamConfederacion)
{
	printf( "============================================================\n"
			"|ID    |NOMBRE    |REGION                   |AÑO CREACION  |\n"
			"============================================================\n");
	for(int i=0; i<tamConfederacion; i++)
	{
		CONF_mostrarUno(listaConfederacion[i]);
	}
	 printf( "\n============================================================");

}
int CONF_buscarConfederacion(eConfederacion listaConfederacion[],int tamConfederacion, int id)
{
	 int retorno;
	 retorno=-1;

	 if(listaConfederacion != NULL && tamConfederacion>0){
	 		for(int i=0;i<tamConfederacion;i++){
	 			if(listaConfederacion[i].idCondefederacion==id){
	 				retorno=i;
	 				break;
	 			}
	 		}
	 	}
	 return retorno;
}


int CONF_inicializadorEstructura(eConfederacion listaConfederacion[],int tamConfederacion)
{
	int retorno;
	retorno=-1;
	if(listaConfederacion != NULL && tamConfederacion>0){

		for(int i=0;i<tamConfederacion;i++){
			listaConfederacion[i].isEmpty = LIBRE;
		}
		retorno =0;
	}

	return retorno;
}

int CONF_buscarIndiceLibre(eConfederacion listaConfederacion[],int tamConfederacion)
{
	 int retorno;
	 retorno=-1;

	 if(listaConfederacion != NULL && tamConfederacion>0){
	 		for(int i=0;i<tamConfederacion;i++){
	 			if(listaConfederacion[i].isEmpty == LIBRE){
	 				retorno=i;
	 				break;
	 			}
	 		}
	 	}
	 return retorno;
}
eConfederacion CONF_pedirDatos()
{
	eConfederacion aux;
	utn_getNumero(&aux.idCondefederacion, "\nIngrese el id de la confederacion", "\nERROR.Ingrese el id de la confederacion", 100, 105, 5);
	utn_getDescripcion(aux.nombre, TAM_NOMBRE_CONFEDERACION, "\nIngrese el nombre de la confederacion: ", "\nERROR.Ingrese nuevamente el nombre de la confederacion: ", 3);
	utn_getDescripcion(aux.region, TAM_REGION, "\nIngrese la region de la confederacion: ", "\nERROR.Ingrese nuevamente la region de la confederacion: ", 3);
	utn_getNumero(&aux.anioCreacion, "\nIngrese  el anio de creacion: ", "\nERROR.Ingrese nuevamente el anio: ", 1, 999999, 3);
	aux.isEmpty=OCUPADO;

	return aux;
}
int CONF_alta(eConfederacion listaConfederacion[],int tamConfederacion)
{
	int retorno;
	int posicionLibre;

	eConfederacion confederacionUno;

	retorno=-1;

	if(listaConfederacion !=NULL&&tamConfederacion > 0){

		posicionLibre= CONF_buscarIndiceLibre(listaConfederacion, tamConfederacion);

		confederacionUno =CONF_pedirDatos();

		if(posicionLibre!=-1){

			listaConfederacion[posicionLibre] = confederacionUno;
			retorno=0;
		}
	}

	return retorno;
}
int CONF_modificar(eConfederacion listaConfederacion[], int tamConfederacion)
{
	int index = -1;
	int idIngresado;

	CONF_MostrarListaTipo(listaConfederacion, tamConfederacion);
 	idIngresado = UTN_pedirEnteroRango("\nSeleccion un id a modificar: ", 100, 105);

	for(int i=0; i<tamConfederacion; i++)
	{
		if(idIngresado == listaConfederacion[i].idCondefederacion && listaConfederacion[i].isEmpty == OCUPADO)
		{
			int opcion;
			opcion=UTN_pedirEnteroRango("\nSeleccion una opcion: "
										"\n1-ID CONFEDERACION:"
										"\n2-NOMBRE CONFEDERACION: "
										"\n3-REGION CONFEDERACION:"
										"\n4-AÑO CREACION CONFEDERACION:"
										"\n5-CANCELAR", 1, 5);

			switch(opcion)
			{
				case 1:
					utn_getNumero(&listaConfederacion[i].idCondefederacion, "\nIngrese el id de la confederacion", "\nERROR.Ingrese el id de la confederacion", 100, 105, 5);
					index = 1;
					break;
				case 2:
					utn_getDescripcion(listaConfederacion[i].nombre, TAM_NOMBRE_CONFEDERACION, "\nIngrese el nombre de la confederacion: ", "\nERROR.Ingrese nuevamente el nombre de la confederacion: ", 3);

					index = 1;
					break;
				case 3:
					utn_getDescripcion(listaConfederacion[i].region, TAM_REGION, "\nIngrese la region de la confederacion: ", "\nERROR.Ingrese nuevamente la region de la confederacion: ", 3);
				break;
				case 4:
					utn_getNumero(&listaConfederacion[i].anioCreacion, "\nIngrese  el anio de creacion: ", "\nERROR.Ingrese nuevamente el anio: ", 1, 999999, 3);
				break;
				case 5:
					printf("\nCANCELAR");
					break;


			}
		}
	}

	return index;
}
int CONF_baja(eConfederacion listaConfederacion[],int tamConfederacion)
{
	int index = -1;
	int idIngresado;

	CONF_MostrarListaTipo(listaConfederacion, tamConfederacion);

	idIngresado = UTN_pedirEnteroRango("\nSeleccion un id de confederacion a bajar: ", 1, 3000);


	for(int i=0; i<tamConfederacion; i++)
	{
		if(idIngresado == listaConfederacion[i].idCondefederacion && listaConfederacion[i].isEmpty == OCUPADO)
		{
			listaConfederacion[i].isEmpty = LIBRE;
			listaConfederacion[i].idCondefederacion = -1;
			index = 1;
			break;
		}
	}
	return index;
}

