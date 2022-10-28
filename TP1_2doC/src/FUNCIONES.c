#include <stdio.h>
#include <stdlib.h>

int getNumero(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if (pNumero != NULL && mensaje != NULL && mensajeError!= NULL && minimo<=maximo && reintentos>= 0)
	{
		do{
			fflush(stdin);
			printf("%s", mensaje);
			scanf("%d",&bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pNumero = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			 }
		 }while(reintentos >= 0);
	}
	return retorno;
}

int getFloat(float* pNumero,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	if (pNumero != NULL && mensaje != NULL && mensajeError!= NULL && minimo<=maximo && reintentos>= 0)
	{
		do{
			fflush(stdin);
			printf("%s", mensaje);
			scanf("%f",&bufferFloat);

			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pNumero = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			 }
		 }while(reintentos >= 0);
	}
	return retorno;
}

int cargarGastos(float* gastoH,float* gastoC,float* gastoT)
{
	int retorno;
	int retornoGastoH;
	int retornoGastoC;
	int retornoGastoT;

	retornoGastoH= getFloat(gastoH,"\nCosto de hospedaje-> ","\nERROR. Ingrese costo de hospedaje",1,999999,3);
	retornoGastoC= getFloat(gastoC,"\nCosto de comida-> ","\nERROR. Ingrese costo de comida",1,999999,3);
	retornoGastoT= getFloat(gastoT,"\nCosto de transporte-> ","\nERROR. Ingrese costo de transporte",1,999999,3);

	if(retornoGastoH!=-1&&retornoGastoC!=-1&&retornoGastoT!=-1)
	{
		retorno=0;
	}
	else{
		retorno=-1;
	}
	return retorno;
}

void asignarConfederacion(int confederacion,int* contadorAFC,int* contadorCAF,int* contadorConcacaf,int* contadorConmmebol,int* contadorUEFA,int* contadorOFC)
{
	switch(confederacion)
	{
		case 1:
				*contadorAFC+=1;
				break;

		case 2:
			*contadorCAF+=1;
						break;
		case 3:
			*contadorConcacaf+=1;
						break;

		case 4:
			*contadorConmmebol+=1;
						break;

		case 5:
			*contadorUEFA+=1;
						break;

		case 6:
			*contadorOFC+=1;
						break;



	}

}

int asignarPosicion(int posicion,int *cantidadJugadores,int* contadorArquero,int* contadorDefensor,int* contadorMedioCampista,int* contadorDelantero)
{

	int pudeCargar =0;

	if(*cantidadJugadores<22)
	{
		switch(posicion)
		{
				case 1:
						if(*contadorArquero<2)
						{
							*contadorArquero+=1;
							*cantidadJugadores+=1;
							pudeCargar =1;
						}
						else
						{
							printf("\nposiciones llenas");
						}
						break;

				case 2:
					if(*contadorDefensor<8)
					{
						*contadorDefensor+=1;
						*cantidadJugadores+=1;
						pudeCargar =1;
					}
					else
					{
						printf("\nposiciones llenas");
					}

						break;
				case 3:
					if(*contadorMedioCampista<8)
					{
						*contadorMedioCampista+=1;
						*cantidadJugadores+=1;
						pudeCargar =1;
					}
					else
					{
							printf("\nposiciones llenas");
					}

					break;

				case 4:
					if(*contadorDelantero<4)
					{
						*contadorDelantero+=1;
						*cantidadJugadores+=1;
						pudeCargar =1;
					}
					else
					{
							printf("\nposiciones llenas");
					}

								break;


			}

	}
	else
	{
		printf("Equipo completo, imposible agregar un nuevo jugador\n");
	}

	return pudeCargar;
}

void imprimirEquipo(int contadorArquero,int contadorDefensor,int contadorMedioCampista,int contadorDelantero)
{

	printf("\nArquero -> %d\n", contadorArquero);
	printf("Defensor -> %d\n", contadorDefensor);
	printf("MedioCampista -> %d\n", contadorMedioCampista);
	printf("Delantero -> %d\n", contadorDelantero);
}

void obtenerPromedios
(int cantidadJugadores,int contadorAFC,int contadorCAF,int contadorConcacaf,int contadorConmmebol,int contadorUEFA,int contadorOFC,float* promedioAFC,float* promedioCAF,float* promedioConcacaf,float* promedioConmmebol,float* promedioUEFA,float* promedioOFC)
{

	if(contadorAFC>0)
	{
		*promedioAFC = cantidadJugadores/ contadorAFC;
	}
	else
	{
		*promedioAFC=0;
	}

	if(contadorCAF>0)
	{

		*promedioCAF = cantidadJugadores / contadorCAF;
	}
	else
	{
		*promedioCAF =0;
	}

	if(contadorConcacaf>0){
		*promedioConcacaf =  cantidadJugadores / contadorConcacaf;
	}
	else
	{
		*promedioConcacaf=0;
	}

	if(contadorConmmebol>0)
	{
		*promedioConmmebol = cantidadJugadores / contadorConmmebol;
	}
	else
	{
		*promedioConmmebol=0;
	}

	if(contadorOFC>0)
	{
		*promedioOFC = cantidadJugadores / contadorOFC;
	}
	else
	{
		*promedioOFC=0;
	}

	if(contadorUEFA>0)
	{
			*promedioUEFA = cantidadJugadores / contadorUEFA;
		}
		else
		{
			*promedioUEFA=0;
		}


}



void imprimirPromedios
(float promedioAFC,float promedioCAF,float promedioConcacaf,float promedioConmmebol,float promedioUEFA,float promedioOFC)
{

	printf("\n\nPromedioAFC -> %.2f\n", promedioAFC);
	printf("promedioCAF -> %.2f\n", promedioCAF);
	printf("promedioConcacaf -> %.2f\n", promedioConcacaf);
	printf("promedioConmmebol -> %.2f\n", promedioConmmebol);
	printf("promedioOFC -> %.2f\n", promedioOFC);
	printf("promedioUEFA -> %.2f\n", promedioUEFA);
}

int calcularMayoriaUEFA(int contadorAFC,int contadorCAF,int contadorConcacaf,int contadorConmmebol,int contadorUEFA,int contadorOFC)
{

	int mayor=0;

	if(contadorUEFA>contadorAFC && contadorUEFA>contadorCAF && contadorUEFA>contadorConcacaf && contadorUEFA>contadorConmmebol && contadorUEFA>contadorOFC)
	{
		mayor=1;
	}

	return  mayor;
}

void calcularCostos(float *gastoMantenimiento,float *mantenimientoConIncremento,float* incremento,float gastoH,float gastoC,float gastoT,int mayoriaUEFA)
{
	float sumatoriaGastos=0;

	sumatoriaGastos= gastoC + gastoH + gastoT;
	*gastoMantenimiento= sumatoriaGastos;

	if(mayoriaUEFA==1)
	{
		*incremento= (sumatoriaGastos * 0.35);
		*mantenimientoConIncremento= sumatoriaGastos+(*incremento);
	}
}






