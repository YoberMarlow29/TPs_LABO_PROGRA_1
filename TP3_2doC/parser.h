
#ifndef PARSER_H_
#define PARSER_H_



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador, int* cantJugadores);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, int* cantJugadores);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion, int* cantSelecciones);
int parser_SeleccionFromBinary(FILE* pFile, LinkedList* pArrayListSeleccion, int* cantSelecciones);


#endif /* PARSER_H_ */
