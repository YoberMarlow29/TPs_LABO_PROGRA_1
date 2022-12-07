#include "Jugador.h"
#include "Seleccion.h"

Jugador* jug_new()
{
	Jugador* NuevoJugador=(Jugador*) malloc(sizeof(Jugador));

	return NuevoJugador;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int jug_setId(Jugador* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;

	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto !=NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno= 1;
	}

	return retorno;
}
int jug_getNombreCompleto(Jugador*this,char* nombreCompleto)
{
	 int retorno = -1;
	 if(this != NULL)
	 {
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno= 1;

	 }

	 return retorno;
}
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion !=NULL)
	{
		strcpy(this->posicion, posicion);
		retorno= 1;
	}

	return retorno;

}
int jug_getPosicion(Jugador* this,char* posicion)
{
	 int retorno = -1;
	 if(this != NULL)
	 {
		strcpy(posicion, this->posicion);
		retorno= 1;

	 }

	 return retorno;
}
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad !=NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno= 1;
	}

	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	 int retorno = -1;
	 if(this != NULL)
	 {
		strcpy(nacionalidad, this->nacionalidad);
		retorno= 1;
	 }
	 return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno= 1;
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->idSeleccion = idSeleccion;

		retorno= 1;
	}

	return retorno;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL)
	{
		*idSeleccion=this->idSeleccion;
		retorno= 1;
	}

	return retorno;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* jugador;
	jugador = jug_new();
	int flagCampos = 0;

	if(jug_setId(jugador, atoi(idStr)))
	{
		if(jug_setNombreCompleto(jugador, nombreCompletoStr))
		{
			if(jug_setEdad(jugador, atoi(edadStr)))
			{
				if(jug_setPosicion(jugador, posicionStr))
				{
					if(jug_setNacionalidad(jugador, nacionalidadStr))
					{
						if(jug_setIdSeleccion(jugador, atoi(idSelccionStr)))
						{
							flagCampos = 1;
						}
					}
				}
			}
		}

	}
	if(flagCampos == 0)
	{
		jugador = NULL;
	}

	return jugador;
}

int encontrarUltimoId(char* path, char* id)
{
	int retorno=0;
	int idAux;
	FILE* pFile;

	pFile= fopen(path,"r");
	if(pFile != NULL && id !=NULL)
	{
		fscanf(pFile,"%[^\n]\n",id);

		retorno=1;
		do
		{
			fscanf(pFile,"%[^,]",id);

		}while(!feof(pFile));
	}

	fclose(pFile);

	if(id != NULL)
	{
		idAux=atoi(id);
		idAux++;

		itoa(idAux,id,10);
	}

	retorno =idAux;

	printf("Numero retornador %d", retorno);
	return retorno;
}
int grabarId(char* path,char* id)
{
	int retorno=0;
	FILE* pFile;

	pFile=fopen(path,"w");
	if(pFile != NULL)
	{
		fprintf(pFile,"%s\n",id);
		retorno=1;
	}

	fclose(pFile);

	return retorno;
}

void jug_mostrarUn(Jugador* jugador, char confederacion[30])
{
	int idSeleccion;

	jug_getSIdSeleccion(jugador, &idSeleccion);

	if(idSeleccion>=1){
		printf("\n|%-5d|%-24s|%-5d|%-24s|%-24s|%-30s|",jugador->id,jugador->nombreCompleto,jugador->edad, jugador->posicion, jugador->nacionalidad, confederacion);
	} else{
		printf("\n|%-5d|%-24s|%-5d|%-24s|%-24s|%-30s|",jugador->id,jugador->nombreCompleto,jugador->edad, jugador->posicion, jugador->nacionalidad, confederacion);
	}


}

int jug_convocado(Jugador* jugador){
	int retorno=-1;

	if(jugador->idSeleccion>0){
		retorno =0;
	}

	return retorno;
}
int jug_OrdenarPorId(void* jugadorUno, void* jugadorDos)
{
	int retorno = -1;
	int idJugador1;
	int idJugador2;


			if(jugadorUno != NULL && jugadorDos != NULL)
			{

				if(jug_getId(jugadorUno, &idJugador1) == 1)
				{

					if(jug_getId(jugadorDos, &idJugador2) == 1)
					{
						if(idJugador1 > idJugador2)
						{
							retorno = 1;

						}
						else
						{
							retorno = -1;
						}
					}
				}
			}

			return retorno;
}


int jug_OrdenarPorNombre(void* jugadorUno, void* jugadorDos)
{
	int retorno = -1;
	char nombreCompletoAuxUno[100];
	char nombreCompletoAuxDos[100];


	if(jugadorUno != NULL && jugadorDos != NULL)
	{
		if(jug_getNombreCompleto(jugadorUno, nombreCompletoAuxUno) == 1)
		{
			if(jug_getNombreCompleto(jugadorDos, nombreCompletoAuxDos) == 1)
			{
				retorno = strcmp(nombreCompletoAuxUno, nombreCompletoAuxDos);
				if(retorno == 0)
				{
					retorno = jug_OrdenarPorId(jugadorUno, jugadorDos);
				}
			}
		}
	}

	return retorno;
}
int jug_OrdenarPorNacionalidad(void* jugadorUno, void* jugadorDos)
{
	int retorno = -1;
		char nacionalidadAuxUno[100];
		char nacionalidadAuxDos[100];


		if(jugadorUno != NULL && jugadorDos != NULL)
		{
			if(jug_getNacionalidad(jugadorUno, nacionalidadAuxUno) == 1)
			{
				if(jug_getNacionalidad(jugadorDos, nacionalidadAuxDos) == 1)
				{
					retorno = strcmp(nacionalidadAuxUno, nacionalidadAuxDos);
					if(retorno == 0)
					{
						retorno = jug_OrdenarPorId(jugadorUno, jugadorDos);
					}
				}
			}
		}

		return retorno;
}


int jug_OrdenarPorEdad(void* jugadorUno, void* jugadorDos)
{
	int retorno = -1;
		int edadJugadorUno;
		int edadJugadorDos;


		if(jugadorUno != NULL && jugadorDos != NULL)
		{

			if(jug_getEdad(jugadorUno, &edadJugadorUno) == 1)
			{

				if(jug_getEdad(jugadorDos, &edadJugadorDos) == 1)
				{
					if(edadJugadorUno > edadJugadorDos)
					{
						retorno = 1;

					}
					else
					{
						retorno = -1;
					}
				}
			}
		}

		return retorno;
}
