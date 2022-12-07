#include "Seleccion.h"

Seleccion* selec_new()
{
	Seleccion* NuevaSeleccion=(Seleccion*) malloc(sizeof(Seleccion));

	return NuevaSeleccion;
}
void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int selec_getId(Seleccion* this,int* id){
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	 int retorno = -1;
	 if(this != NULL)
	 {
		strcpy(pais, this->pais);
		retorno= 1;
	 }
	 return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	 int retorno = -1;
	 if(this != NULL)
	 {
		strcpy(confederacion, this->confederacion);
		retorno= 1;
	 }
	 return retorno;
}
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		retorno= 1;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;

	if(this != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;

}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccion;
	seleccion=selec_new();
	int flagCampos = 0;




	if(idStr!=NULL)
		{
			seleccion->id=(atoi(idStr));
			if(paisStr!=NULL){
				strcpy(seleccion->pais,paisStr);

				if(confederacionStr!=NULL){
					strcpy(seleccion->confederacion,confederacionStr);

					if(convocadosStr!=NULL){
						seleccion->convocados=(atoi(convocadosStr));
						flagCampos=1;
					}
				}
			}
		}

		if(flagCampos==0)
		{
			seleccion=NULL;
		}

	return seleccion;
}

void selec_mostrarUno(Seleccion* seleccion)
{
	printf("\n|%-6d|%-15s|%-20s|%-14d|", seleccion->id ,seleccion->pais, seleccion->confederacion, seleccion->convocados);
}

void selec_mostrarParaConvocar(Seleccion* seleccion)
{
	printf("\n|%-6d|%-15s|", seleccion->id, seleccion->confederacion);
}

int selec_OrdenarPorId(void* seleccionUno, void* seleccionDos)
{
	int retorno = -1;
	int idSeleccion1;
	int idSeleccion2;


			if(seleccionUno != NULL && seleccionDos != NULL)
			{

				if(selec_getId(seleccionUno, &idSeleccion1) == 1)
				{

					if(selec_getId(seleccionDos, &idSeleccion2) == 1)
					{
						if(idSeleccion1 > idSeleccion2)
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


int selec_OrdenarPorConfederacion(void* seleccionUno, void* seleccionDos)
{
	int retorno = -1;
	char nombreConfederacionAuxUno[100];
	char nombreConfederacionAuxDos[100];


	if(seleccionUno != NULL && seleccionDos != NULL)
	{
		if(selec_getConfederacion(seleccionUno, nombreConfederacionAuxUno) == 1)
		{
			if(selec_getConfederacion(seleccionDos, nombreConfederacionAuxDos) == 1)
			{
				retorno = strcmp(nombreConfederacionAuxUno, nombreConfederacionAuxDos);
				if(retorno == 0)
				{
					retorno = selec_OrdenarPorId(seleccionUno, seleccionDos);
				}
			}
		}
	}

	return retorno;
}

