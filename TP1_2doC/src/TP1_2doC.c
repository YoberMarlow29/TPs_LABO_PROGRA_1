#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int respuesta;

	float gastoH;
	float gastoC;
	float gastoT;
	float gastoMantenimiento;
	float mantenimientoConIncremento;
	float incremento;

	int flagCargaDatos=0;
	int flagCargaPosicion=0;
	int flagCalcularCostos;
	int mayoriaUEFA;


	int contadorAFC=0;
	int contadorCAF=0;
	int contadorConcacaf=0;
	int contadorConmmebol=0;
	int contadorUEFA=0;
	int contadorOFC=0;

	int contadorArquero=0;
	int contadorDefensor=0;
	int contadorMedioCampista=0;
	int contadorDelantero=0;
	int cantidadJugadores=0;

	float promedioAFC;
	float promedioCAF;
	float promedioConcacaf;
	float promedioConmmebol;
	float promedioUEFA;
	float promedioOFC;





	int confederacion;

	int tipoDeJugador;

	int camiseta;

		do
		{
			respuesta= getNumero(&opcion,
					"\nSeleccione una opcion: \n"
					"\n1-Ingreso de los costos de Mantenimiento:"
					"\n2-Carga de jugadores:"
					"\n3-Realizar todos los calculos:"
					"\n4-Informar todos los resultados"
					"\n5-Salir.",
					"ERROR!!!. Elija una opcion correcta",1,5,3);

			if(!respuesta)
			{
				switch(opcion)
				{
					case 1:
						cargarGastos(&gastoH,&gastoC,&gastoT);
						flagCargaDatos=1;
						break;
					case 2:

						if(flagCargaDatos==1)
						{
							 getNumero(&confederacion,
									 "\nSeleccione una opcion:"
									 "\n1-AFC"
									 "\n2-CAF"
									 "\n3-CONCACAF"
									 "\n4-CONMEBOL"
									 "\n5-UEFA"
									 "\n6-OFC",
									 "\nERROR!!!. Elija una opcion correcta\n",1,6,3);

							 asignarConfederacion(confederacion, &contadorAFC, &contadorCAF, &contadorConcacaf, &contadorConmmebol, &contadorUEFA, &contadorOFC);

							 getNumero(&tipoDeJugador,
									 "\nSeleccione una opcion:"
									 "\n1-Arqueros"
									 "\n2-Defensor"
									 "\n3-Mediocampista"
									 "\n4-Delantero",
									 "\nERROR!!!. Elija una opcion correcta\n",1,4,3);

							 flagCargaPosicion= asignarPosicion(tipoDeJugador, &cantidadJugadores, &contadorArquero, &contadorDefensor, &contadorMedioCampista, &contadorDelantero);


							 printf("\n");
							 imprimirEquipo(contadorArquero, contadorDefensor, contadorMedioCampista, contadorDelantero);

							 getNumero(&camiseta,
									 "\nSeleccione el numero de camiseta: ",
									 "\nERROR!!!. Elija una opcion correcta\n",1,100,3);
						}
						else
						{
							printf("\nINGRESAR A OPCION 1!\n");
						}

						break;

					case 3:

						if(flagCargaDatos==1 && flagCargaPosicion==1)
						{

							obtenerPromedios(cantidadJugadores, contadorAFC, contadorCAF, contadorConcacaf, contadorConmmebol, contadorUEFA,  contadorOFC, &promedioAFC, &promedioCAF, &promedioConcacaf, &promedioConmmebol, &promedioUEFA, &promedioOFC);

							mayoriaUEFA= calcularMayoriaUEFA(contadorAFC, contadorCAF, contadorConcacaf, contadorConmmebol, contadorUEFA, contadorOFC);

							calcularCostos(&gastoMantenimiento, &mantenimientoConIncremento, &incremento, gastoH, gastoC, gastoT, mayoriaUEFA);

							flagCalcularCostos=1;

							printf("\nCalculos realizados\n");

						}else
						{
							printf("\nPor favor debe realizar las opciones anteriores\n");
						}

						break;
					case 4:

						if(flagCargaDatos==1 && flagCargaPosicion==1 && flagCalcularCostos==1)
						{
							imprimirPromedios(promedioAFC, promedioCAF,promedioConcacaf,promedioConmmebol, promedioUEFA, promedioOFC);

							if(mayoriaUEFA==1)
							{
								printf("El costo del mantenimiento era $ %.2f y recibio un aumento de $ %.2f y el total es de$  %.2f", gastoMantenimiento, incremento, mantenimientoConIncremento);
							}
							else
							{
								printf("\nEl costo de mantenimiento es $ %.2f ", gastoMantenimiento);
							}
						}else
						{
							printf("\nPor favor debe realizar las opciones anteriores\n");
						}

						break;
					case 5:
							printf("\nGRACIAS POR USAR NUESTRO SISTEMA.\n");
						break;
					}
					}
		}while(opcion!=5);

	return 0;
}
