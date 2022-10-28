#include "procesos.h"
float sumaTotal(eJugador listaJugador[],int tamJugador)
{
	float sumatoria=0;

	for(int i=0;i<tamJugador;i++)
	{

		if(listaJugador[i].idJugador!=0)
		{
			sumatoria+=listaJugador[i].salario;

		}
	}

	return sumatoria;
}
float promedioPorJugador(eJugador listaJugador[],int tamJugador)
{
	float promedio=0;
	int contador=0;

	for(int i=0;i<tamJugador;i++)
	{

		if(listaJugador[i].idJugador!=0)
		{
			contador++;

		}
	}

	promedio=sumaTotal(listaJugador, tamJugador)/contador;

	return promedio;
}

int contarJugadoresEnConfederacion(eJugador listaJugador[],int tamJugador, int idConfederacion)
{
	int  cantidadJugadores=0;

	for(int i=0;i<tamJugador;i++)
	{
		if(listaJugador[i].idConfederacion==idConfederacion)
		{
			cantidadJugadores++;

		}

	}
	return cantidadJugadores;
}

float calculoPorcentaje(int contadorPorConfederacion, int contadorJugadorTotal)
{
	float porcentaje;

		porcentaje=(contadorPorConfederacion*100)/contadorJugadorTotal;

	return porcentaje;
}

