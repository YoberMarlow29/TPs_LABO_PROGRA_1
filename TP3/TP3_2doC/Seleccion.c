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
		strcpy(this->pais, pais);
		retorno= 1;
	 }
	 return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	 int retorno = -1;
	 if(this != NULL)
	 {
		strcpy(this->confederacion, confederacion);
		retorno= 1;
	 }
	 return retorno;
}
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados > 0)
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

		seleccion->id=0;

		if(paisStr!=NULL)
		{

			strcpy(seleccion->pais,paisStr);

			if(confederacionStr!=NULL)
			{

				strcpy(seleccion->confederacion,confederacionStr);

				if(selec_setConvocados(seleccion, atoi(convocadosStr)))
				{
					flagCampos=1;
				}

			}
		}

		if(flagCampos==0)
		{
			seleccion=NULL;
		}

	return seleccion;
}
