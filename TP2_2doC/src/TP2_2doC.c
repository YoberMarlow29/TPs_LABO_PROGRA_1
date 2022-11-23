#include "input.h"
#include "Nexo.h"
#define MAX_JUGADOR 3000
#define MAX_CONF 6
eJugador listaJugador[MAX_JUGADOR];
eConfederacion listaConfederacion[MAX_CONF]={{100,"CONMEBOL","SUDAMERICA",1916},
											{101,"UEFA","EUROPA",1954},
											{102,"AFC","ASIA",1954},
											{103,"CAF","AFRICA",1957},
											{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
											{105,"OFC","OCEANIA",1966}};
int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int respuesta;
	int retorno;
	int flagAvanzar=0;
	int respuestaInforme;
	int opcionInforme;
	int contadorJugadorTotal=0;
	JUG_inicializadorEstructura(listaJugador, MAX_JUGADOR);
	//CONF_inicializadorEstructura(listaConfederacion, MAX_CONF);
	do{
			respuesta= utn_getNumero(&opcion,"\nSeleccione una opcion: (1-5)\n"
					"\n1-ALTA DE JUGADOR: "
					"\n2-BAJA DE JUGADOR: "
					"\n3-MODIFICACION DE JUGADOR: "
					"\n4-INFORMAR: "
					"\n5-SALIR."
					, "\nERROR.Seleccione nuevamente una opcion: (1-5)", 1, 5, 3);

			if(!respuesta)
			{
				switch(opcion)
				{
				case 1:
					printf("\t\t***** ALTA DE JUGADOR *****\n");
					if((NEX_altaJugador(listaJugador, MAX_JUGADOR, listaConfederacion, MAX_CONF))!=-1)
					{

						contadorJugadorTotal++;
						flagAvanzar=1;
					}
					else
					{
						printf("Carga de jugador con exito");
					}
					break;
				case 2:
					printf("\t\t***** BAJA DE JUGADOR *****\n");
					if(flagAvanzar==1)
					{
						retorno=NEX_baja(listaJugador, MAX_JUGADOR, listaConfederacion, MAX_CONF);
						switch(retorno)
						{
							case -1:
								printf("No se ha podido bajar el jugador");
							break;
							default:
								printf("Se ha dado de baja correctamente el jugador");
							break;
						}
					}
					else
					{
						printf("Haga al menos una carga de jugador");
					}
					break;
				case 3:
					printf("\t\t***** MODIFICACION DE JUGADOR *****\n");
					if(flagAvanzar==1)
					{
						retorno=NEX_modificar(listaJugador, MAX_JUGADOR, listaConfederacion,MAX_CONF);
						switch(retorno)
						{
							case -1:
								printf("No se ha podido modificar el jugador");
							break;
							default:
								printf("Se ha modificado correctamente el jugador");
							break;
						}
					}
					else
					{
						printf("Haga al menos una carga de jugador");
					}

					break;
				case 4:
					printf("\t\t***** INFORMAR *****\n");
					if(flagAvanzar==1)
					{

						do
						{
							respuestaInforme= utn_getNumero(&opcionInforme,"\nSeleccione una opcion:(1-7) \n"
									"\n1-LISTADO DE LOS JUGADORES ORDENADOS ALFABETICAMENTE POR NOMBRE DE CONFEDERACION Y NOMBRE DE JUGADOR: "
									"\n2-LISTADO DE CONFEDERACIONES CON SUS JUGADORES: "
									"\n3-TOTAL Y PROMEDIO DE TODOS LOS SALARIOS Y CUANTOS JUGADORES COBRAN MAS DEL SALARIO PROMEDIO: "
									"\n4-INFORMAR LA CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL: "
									"\n5-INFORMAR PORCENTAJE DE JUGADORES POR CADA CONFEDERACION:"
									"\n6-INFORMAR CUAL ES LA REGION CON MAS JUGADORES Y EL LISTADO DE LOS MISMOS:"
									"\n7-SALIR."

									, "ERROR.OPCION INCORRECTA", 1, 7, 10);
								if(!respuestaInforme)
								{
									switch(opcionInforme)
									{
										case 1:
											NEX_listadoOrdenamientoDobleCriterio(listaJugador, MAX_JUGADOR, listaConfederacion, MAX_CONF,contadorJugadorTotal);
											break;
										case 2:
											NEX_jugadoresListadoPorConfederacion(listaJugador, MAX_JUGADOR, listaConfederacion, MAX_CONF);

											break;
										case 3:
											NEX_informarSalario(listaJugador, MAX_JUGADOR);

											break;
										case 4:

											NEX_informeMayorCantidadConfederacion(listaJugador, MAX_JUGADOR, listaConfederacion, MAX_CONF);

											break;
										case 5:
											NEX_porcentajePorConfederacion(listaJugador, MAX_JUGADOR, contadorJugadorTotal);

											break;
										case 6:
											NEX_regionMasJugadores(listaJugador, MAX_JUGADOR, listaConfederacion, MAX_CONF);

											break;
										case 7:
											printf("\t\t***** SALIR *****\n");

											break;

									}

								}


						}while(opcionInforme!=7);
					}
					else
					{
						printf("Haga al menos una carga de jugador");
					}
					break;
				case 5:
					printf("\t\t***** SALIR *****\n");

					break;


				}
			}


		}while(opcion!=5);


	return 0;
}
