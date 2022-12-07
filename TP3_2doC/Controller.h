int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pArrayListJugador, int *cantJugadores);
int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *pArrayListSeleccion);
int controller_saveAsBinary(char *path, LinkedList *pArrayListJugador, LinkedList* pArrayListSeleccion ,int cantJugadores, int cantSelecciones);
int controller_agregarJugador(LinkedList *pArrayListJugador, int *cantJugadores);
int controller_editarJugador(LinkedList *pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_removerJugador(LinkedList *pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadoresConvocados(LinkedList pArrayListJugador);
void controller_listados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion);

int controller_ordenarJugadores(LinkedList *pArrayListJugador);
int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador,  int abiertoPreviamente);
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion, int *cantSelecciones);
int controller_editarSeleccion(LinkedList *pArrayListSeleccion);
int controller_listarSelecciones(LinkedList *pArrayListSeleccion);
int controller_encontrarSeleccionPorId(LinkedList* pArrayListSelecciones, int id);
int controller_listarSeleccionesParaConvocar(LinkedList* pArrayListSeleccion);
int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador);
int controller_menuOrdenar(LinkedList *pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion);
int controller_encontrarJugadorPorId(LinkedList *pArrayListJugador, int id);
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int cantJugadores, int cantSelecciones);
int controller_quitarDeLaSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int cantJugadores, int cantSelecciones);
int controller_menuConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int cantJugadores, int cantSelecciones);
int controller_listarSeleccionesParaGuardarBin(LinkedList* pArrayListSeleccion,int cantiSeleccion ,char* confederacionElegida);
int controller_encontrarJugadorPorSeleccion(LinkedList* pArrayListJugador, int confederacion);
int controller_crearListaSeleccionadosPorConfederacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char confederacionBuscada[30], LinkedList* pSeleccionados);

