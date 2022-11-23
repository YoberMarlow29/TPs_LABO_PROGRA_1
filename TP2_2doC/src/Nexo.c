#include "Nexo.h"
int idAutoIncremental()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}
eJugador NEX_pedirDatosJugador(eConfederacion listaConfederacion[],int tamConfederacion)
{
	eJugador aux;

	aux.idJugador=idAutoIncremental();

	printf("\nid=%d",aux.idJugador);
	utn_getDescripcion(aux.nombre, TAM_NOMBRE,"\nIngrese el nombre del jugador: ", "\nERROR.Ingrese nuevamente el nombre del jugador: ", 5);

	utn_getNombre(aux.posicion, TAM_POSICION, "\nIngrese la posicion del jugador: (Arquero-Defensor-MedioCampista-Delantero)", "\nERROR.Ingrese nuevamente la posicion del jugador: (Arquero-Defensor-MedioCampista-Delantero)", 5);

	utn_getNumeroShort(&aux.numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "\nERROR.Ingrese nuevamente el numero de camiseta del jugador: ", 1, 126, 5);

	CONF_MostrarListaTipo(listaConfederacion, tamConfederacion);

	utn_getNumero(&aux.idConfederacion, "\nIngrese el id de confederacion del jugador: ", "\nERROR.Ingrese nuevamente el id de confederacion del jugador: ", 100, 105, 5);

	utn_getNumeroFlotante(&aux.salario, "\nIngrese el salario del jugador: ", "\nERROR.Ingrese nuevamente el salario del jugador: ", 0, 9999999, 5);


	utn_getNumeroShort(&aux.aniosContrato, "\nIngrese los años de contratacion del jugador: ", "\nERROR.Ingrese nuevamente los años de contratacion del jugador: ", 1, 126, 5);

	aux.isEmpty=OCUPADO;

	return aux;
}
void NEX_mostrarTodoJugadorConfederacion(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion)
{
	int confederacion;

	printf( "==================================================================================================================================\n"
			"|ID   |NOMBRE                  |POSICION       |N° CAMISETA    |SUELDO              |CONFEDERACION            |AÑOS DE CONTRATO  |\n"
			"==================================================================================================================================\n");

	if(listaJugador != NULL && tamJugador>0)
	{
		for(int i=0;i<tamJugador;i++)
		{
			confederacion=CONF_buscarConfederacion(listaConfederacion, tamConfederacion, listaJugador[i].idConfederacion);
			if(listaJugador[i].idJugador!=0)
			{
				printf("\n|%-5d|%-24s|%-15s|%-15d|%-20.2f|%-25s|%-18d|",listaJugador[i].idJugador,
						listaJugador[i].nombre,
						listaJugador[i].posicion,
						listaJugador[i].numeroCamiseta,
						listaJugador[i].salario,
						listaConfederacion[confederacion].region,
						listaJugador[i].aniosContrato);

			}

		}
	}
	printf("\n==================================================================================================================================");


}
int NEX_altaJugador(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[],int tamConfederacion)
{
	int retorno;
	int posicionLibre=0;

	eJugador jugadorUno;

	retorno=-1;

	if(listaJugador !=NULL&&tamJugador > 0){

		posicionLibre= JUG_buscarIndiceLibre(listaJugador, tamJugador);
		jugadorUno =NEX_pedirDatosJugador(listaConfederacion, tamConfederacion);


		if(posicionLibre!=-1){

			listaJugador[posicionLibre] = jugadorUno;
			retorno=0;
		}
	}

	return retorno;
}
int NEX_baja(eJugador listaJugador[], int tamJugador,eConfederacion listaConfederacion[],int tamConfederacion)
{
	int index = -1;
	int idIngresado;

	NEX_mostrarTodoJugadorConfederacion(listaJugador, tamJugador, listaConfederacion, tamConfederacion);
 	idIngresado = UTN_pedirEnteroRango("\nSeleccion un id de jugador a bajar: ", 0, 3000);


	for(int i=0; i<tamJugador; i++)
	{
		if(idIngresado == listaJugador[i].idJugador && listaJugador[i].isEmpty == OCUPADO)
		{
			listaJugador[i].isEmpty = LIBRE;
			listaJugador[i].idJugador = -1;
			index = 1;
			break;
		}
	}
	return index;
}
int NEX_modificar(eJugador listaJugador[ ], int tamJugador, eConfederacion listaConfederacion[],int tamConfederacion)
{
	int index = -1;
	int idIngresado;
	int confederacionBuscada;
	int jugadorBuscado;

	NEX_mostrarTodoJugadorConfederacion(listaJugador, tamJugador, listaConfederacion, tamConfederacion);
 	idIngresado = UTN_pedirEnteroRango("\nSeleccion un id a modificar: ", 0, 5000);
 	jugadorBuscado=JUG_buscarJugador(listaJugador, tamJugador, idIngresado);


		if(jugadorBuscado!=-1)
		{
			int opcion;
			opcion=UTN_pedirEnteroRango("\nSeleccion una opcion: "
										"\n1-NOMBRE DE JUGADOR:"
										"\n2-POSICION DEL JUGADOR: "
										"\n3-NUMERO DE CAMISETA DEL JUGADOR"
										"\n4-CONFEDERACION"
										"\n5-SALARIO DEL JUGADOR"
										"\n6-ANIOS DE CONTRATO DEL JUGADOR"
										"\n7-CANCELAR", 1, 7);

			switch(opcion)
			{
				case 1:
					utn_getDescripcion(listaJugador[jugadorBuscado].nombre, TAM_NOMBRE,"\nIngrese el nombre del jugador: ", "\nERROR.Ingrese nuevamente el nombre del jugador: ", 5);
					printf("Se modifico el nombre del jugador con exito");
					index = 1;
					break;
				break;
				case 2:
					utn_getNombre(listaJugador[jugadorBuscado].posicion, TAM_POSICION, "\nIngrese la posicion del jugador: ", "\nERROR.Ingrese nuevamente la posicion del jugador: ", 5);

					printf("Se modifico la posicion de jugador con exito");

					index = 1;
					break;
				break;
				case 3:
					utn_getNumeroShort(&listaJugador[jugadorBuscado].numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "\nERROR.Ingrese nuevamente el numero de camiseta del jugador: ", 1, 126, 5);
					printf("Se modifico el numero de camiseta del jugador con exito");

					index = 1;
					break;
				break;
				case 4:
					CONF_MostrarListaTipo(listaConfederacion, tamConfederacion);

					idIngresado=UTN_pedirEnteroRango("\nIngrese el Id de su nueva confederacion", 100, 105);

					confederacionBuscada=CONF_buscarConfederacion(listaConfederacion, tamConfederacion, idIngresado);
					 if(confederacionBuscada!=-1)
					 {
						 listaJugador[jugadorBuscado].idConfederacion=idIngresado;

					 }
					 else
					 {
						 printf("\nLa confederacion erronea");
					 }


					index = 1;
					break;
				break;
				case 5:
					utn_getNumeroFlotante(&listaJugador[jugadorBuscado].salario, "\nIngrese el salario del jugador: ", "\nERROR.Ingrese nuevamente el salario del jugador: ", 0, 9999999, 5);

					printf("Se modifico el salario del jugador con exito");

					index = 1;
					break;
				break;
				case 6:

					utn_getNumeroShort(&listaJugador[jugadorBuscado].aniosContrato, "\nIngrese los años de contratacion del jugador: ", "\nERROR.Ingrese nuevamente los años de contratacion del jugador: ", 1, 126, 5);

					printf("Se modifico el anio de contrato del jugador con exito");



				break;
				case 7:

				break;


			}
		}


	return index;
}
void ImpresionOrdenada(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion)
{
	int confederacion;
	printf( "==================================================================================================================================\n"
			"|ID   |NOMBRE                  |POSICION       |N° CAMISETA    |SUELDO              |CONFEDERACION            |AÑOS DE CONTRATO  |\n"
			"==================================================================================================================================\n");
	if(listaJugador !=NULL&&tamJugador>0)
	{
		for(int i=0;i<tamJugador;i++)
		{
			confederacion=CONF_buscarConfederacion(listaConfederacion, tamConfederacion, listaJugador[i].idConfederacion);
			if(listaJugador[i].idJugador!=0)
			{
				printf("\n|%-5d|%-24s|%-15s|%-15d|%-20.2f|%-25s|%-18d|",listaJugador[i].idJugador,
						listaJugador[i].nombre,
						listaJugador[i].posicion,
						listaJugador[i].numeroCamiseta,
						listaJugador[i].salario,
						listaConfederacion[confederacion].nombre,
						listaJugador[i].aniosContrato);

			}

		}
	}
	printf("\n==================================================================================================================================");


}
void NEX_listadoOrdenamientoDobleCriterio(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int tamTotal)
{
	eJugador auxJugador;
	int confederacionI;
	int confederacionJ;

	if(tamTotal>1){
		for(int i=0;i<tamTotal;i++)
			{
				for(int j=i+1;j<=tamTotal-1;j++)
				{
					confederacionI=CONF_buscarConfederacion(listaConfederacion, tamConfederacion, listaJugador[i].idConfederacion);
					confederacionJ=CONF_buscarConfederacion(listaConfederacion, tamConfederacion, listaJugador[j].idConfederacion);
					if(	strcmp(listaConfederacion[confederacionI].nombre,listaConfederacion[confederacionJ].nombre)>0 ||
							(confederacionI == confederacionJ && strcmp(listaJugador[i].nombre,listaJugador[j].nombre)>0))
					{
						auxJugador= listaJugador[i];
						listaJugador[i]= listaJugador[j];
						listaJugador[j]=auxJugador;
					}


				}

			}
	}

	ImpresionOrdenada(listaJugador, tamJugador, listaConfederacion, tamConfederacion);
}


void NEX_informarSalario(eJugador listaJugador[],int tamJugador)
{
	int contadorMayorPromedio=0;
	float promedioxJugador=promedioPorJugador(listaJugador, tamJugador);
	float sumatoria=sumaTotal(listaJugador, tamJugador);

	for(int i=0;i<tamJugador;i++)
	{
		if(listaJugador[i].idJugador!=0&&listaJugador[i].salario>promedioxJugador)
		{
			contadorMayorPromedio++;
		}
	}

	printf("\nEl total de los salario es %f",sumatoria);
	printf("\nEl promedio de los salarios por jugador es: %f",promedioxJugador );
	printf("\nLa cantidad de jugadores que cobran mas del salario promedio es: %d",contadorMayorPromedio);

}
void NEX_informeMayorCantidadConfederacion(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion)
{

	short mayorAnios=0;
	int posicionConfederacion=0;

	for(int i=0;i<tamJugador;i++)
	{

		if(listaJugador[i].aniosContrato>mayorAnios)
		{
			mayorAnios=listaJugador[i].aniosContrato;
			posicionConfederacion=listaJugador[i].idConfederacion;

		}
	}

	printf("La confederacion con mas años de contrato es: %s",listaConfederacion[CONF_buscarConfederacion(listaConfederacion, tamConfederacion, posicionConfederacion)].nombre);


}


void NEX_regionMasJugadores(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion)
{
	int contadorJugadorConmebol=0;
	int contadorJugadorUefa=0;
	int contadorJugadorAfc=0;
	int contadorJugadorCaf=0;
	int contadorJugadorConcacaf=0;
	int contadorJugadorOfc=0;



	contadorJugadorConmebol=contarJugadoresEnConfederacion(listaJugador, tamJugador, 100);
	contadorJugadorUefa=contarJugadoresEnConfederacion(listaJugador, tamJugador, 101);
	contadorJugadorAfc=contarJugadoresEnConfederacion(listaJugador, tamJugador, 102);
	contadorJugadorCaf=contarJugadoresEnConfederacion(listaJugador, tamJugador, 103);
	contadorJugadorConcacaf=contarJugadoresEnConfederacion(listaJugador, tamJugador, 104);
	contadorJugadorOfc=contarJugadoresEnConfederacion(listaJugador, tamJugador, 105);

	if(contadorJugadorConmebol>contadorJugadorUefa&&contadorJugadorConmebol>contadorJugadorAfc&&contadorJugadorConmebol>contadorJugadorCaf&&contadorJugadorConmebol>contadorJugadorConcacaf&&contadorJugadorConmebol>contadorJugadorOfc)
	{
		printf("\nLa region mayor es SUD AMERICA ");
		for(int i=0; i<tamConfederacion; i++)
		{
			for(int j=0; j<tamJugador; j++)
			{
				if(100==listaJugador[j].idConfederacion&&100 == listaConfederacion[i].idCondefederacion)
				{
					JUG_mostrarUno(listaJugador[j]);
				}
			}

		}
	}
	else if(contadorJugadorUefa>contadorJugadorAfc&&contadorJugadorUefa>contadorJugadorCaf&&contadorJugadorUefa>contadorJugadorConcacaf&&contadorJugadorUefa>contadorJugadorOfc)
	{
		printf("\nLa region mayor es EUROPA");
		for(int i=0; i<tamConfederacion; i++)
				{
					for(int j=0; j<tamJugador; j++)
					{
						if(101==listaJugador[j].idConfederacion&&101 == listaConfederacion[i].idCondefederacion)
						{
							JUG_mostrarUno(listaJugador[j]);
						}
					}

				}

	}
	else if(contadorJugadorAfc>contadorJugadorCaf&&contadorJugadorAfc>contadorJugadorConcacaf&&contadorJugadorAfc>contadorJugadorOfc)
	{
		printf("\nLa region mayor es ASIA");
		for(int i=0; i<tamConfederacion; i++)
				{
					for(int j=0; j<tamJugador; j++)
					{
						if(102==listaJugador[j].idConfederacion&&102 == listaConfederacion[i].idCondefederacion)
						{
							JUG_mostrarUno(listaJugador[j]);
						}
					}

				}
	}
	else if(contadorJugadorCaf>contadorJugadorConcacaf&&contadorJugadorCaf>contadorJugadorOfc)
	{
		printf("\nLa region mayor es AFRICA");
		for(int i=0; i<tamConfederacion; i++)
				{
					for(int j=0; j<tamJugador; j++)
					{
						if(103==listaJugador[j].idConfederacion&&103 == listaConfederacion[i].idCondefederacion)
						{
							JUG_mostrarUno(listaJugador[j]);
						}
					}

				}
	}
	else if(contadorJugadorConcacaf>contadorJugadorOfc)
	{
		printf("\nLa region mayor es NORTE Y CENTRO AMERICA ");
		for(int i=0; i<tamConfederacion; i++)
				{
					for(int j=0; j<tamJugador; j++)
					{
						if(104==listaJugador[j].idConfederacion&&104 == listaConfederacion[i].idCondefederacion)
						{
							JUG_mostrarUno(listaJugador[j]);
						}
					}

				}
	}
	else
	{
		printf("\nLa region mayor es OCEANIA");
		for(int i=0; i<tamConfederacion; i++)
				{
					for(int j=0; j<tamJugador; j++)
					{
						if(105==listaJugador[j].idConfederacion&&105 == listaConfederacion[i].idCondefederacion)
						{
							JUG_mostrarUno(listaJugador[j]);
						}
					}

				}
	}




}
void NEX_jugadoresListadoPorConfederacion(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion)
{
	for(int i=0; i<tamConfederacion; i++)
	{
		printf("\nListado de jugadores de la confederacion- %s",listaConfederacion[i].nombre);
		NEX_mostrarListaXConfederacion(listaJugador,tamJugador, listaConfederacion[i].idCondefederacion);

		printf("\n=======================================================================================================\n");


	}

}
void NEX_mostrarListaXConfederacion(eJugador listaJugador[],int tamJugador, int idConfederacion)
{
	printf( "\n========================================================================================================\n"
			"|ID   |NOMBRE                  |POSICION       |N° CAMISETA    |SUELDO              |AÑOS DE CONTRATO  |\n"
			"========================================================================================================\n");
	for(int i=0; i<tamJugador; i++)
	{
		if(listaJugador[i].idConfederacion==idConfederacion)
		{
			printf("\n|%-5d|%-24s|%-15s|%-15d|%-20.2f|%-18d|",listaJugador[i].idJugador,
									listaJugador[i].nombre,
									listaJugador[i].posicion,
									listaJugador[i].numeroCamiseta,
									listaJugador[i].salario,
									listaJugador[i].aniosContrato);
		}
	}

}
void NEX_porcentajePorConfederacion(eJugador listaJugador[],int tamJugador,int contadorJugadorTotal)
{

	int contadorJugadorConmebol=0;
	int contadorJugadorUefa=0;
	int contadorJugadorAfc=0;
	int contadorJugadorCaf=0;
	int contadorJugadorConcacaf=0;
	int contadorJugadorOfc=0;

	float porcentajeConmbeol=0;
	float porcentajeUefa=0;
	float porcentajeAfc=0;
	float porcentajeCaf=0;
	float porcentajeConcacaf=0;
	float porcentajeOfc=0;

	contadorJugadorConmebol=contarJugadoresEnConfederacion(listaJugador, tamJugador, 100);
	contadorJugadorUefa=contarJugadoresEnConfederacion(listaJugador, tamJugador, 101);
	contadorJugadorAfc=contarJugadoresEnConfederacion(listaJugador, tamJugador, 102);
	contadorJugadorCaf=contarJugadoresEnConfederacion(listaJugador, tamJugador, 103);
	contadorJugadorConcacaf=contarJugadoresEnConfederacion(listaJugador, tamJugador, 104);
	contadorJugadorOfc=contarJugadoresEnConfederacion(listaJugador, tamJugador, 105);


	porcentajeConmbeol= calculoPorcentaje(contadorJugadorConmebol, contadorJugadorTotal);
	porcentajeUefa= calculoPorcentaje(contadorJugadorUefa, contadorJugadorTotal);
	porcentajeAfc= calculoPorcentaje(contadorJugadorAfc, contadorJugadorTotal);
	porcentajeCaf= calculoPorcentaje(contadorJugadorCaf, contadorJugadorTotal);
	porcentajeConcacaf= calculoPorcentaje(contadorJugadorConcacaf, contadorJugadorTotal);
	porcentajeOfc= calculoPorcentaje(contadorJugadorOfc, contadorJugadorTotal);


	printf("\nEl porcentaje total de conmbeol es:  %.2f",porcentajeConmbeol);
	printf("\nEl porcentaje total de Uefa es:  %.2f",porcentajeUefa);
	printf("\nEl porcentaje total de AFC es:  %.2f",porcentajeAfc);
	printf("\nEl porcentaje total de CAF es: %.2f",porcentajeCaf);
	printf("\nEl porcentaje total de CONCACAF es:  %.2f",porcentajeConcacaf);
	printf("\nEl porcentaje total de OFC es:  %.2f",porcentajeOfc);


}

