/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * vector.c - Define funções para manipulação de uma TAD    *
 * vetor implementada com array de inteiros.                *
 * ======================================================== */

#include <stdlib.h>
#include <limits.h>
#include "vector.h"

#define INIT_CAPACITY 4096

/*
* Struct da TAD encapsulada.
*
* Membros:
*   * capacity - inteiro que armazena o capacidade atual do vetor
*   * size     - inteiro que armazena o tamanho atual do vetor
*   * array    - Vetor em si que armazena os elementos do tipo int
*/
struct vector_t {

	int capacity;
	int size;

	type* array;
};

/*
* Aumenta o tamanho do array que contém os elementos.
*
* Parâmetros:
*   * v - vetor
*   * m - tamanho desejado do vetor
*/
void reserveVector( vector v, int m ) {

	if ( m > v->capacity ) {

		v->capacity = m;

		type* aux = ( type* ) malloc( sizeof( type ) * v->capacity );

		for ( int i = 0; i < v->size; i++ )
			aux[i] = v->array[i];

		free( v->array );

		v->array = aux;
	}
}

vector new_vector() {

	vector v = ( vector ) malloc ( sizeof( struct vector_t ) );

	v->size = 0;
	v->capacity = INIT_CAPACITY;

	v->array = ( type* ) malloc( INIT_CAPACITY * sizeof( type ) );

	return v;
}

void delete_vector( vector v ) {
	free(v->array);
	free(v);
}

void add( vector v, type k ) {

	if ( v->size == v->capacity )
		reserveVector( v, 2*v->capacity );

	v->array[v->size] = k;
	v->size++;
}

type get ( vector v, int pos ) {

	type k = NULL;

	if ( pos < v->size && pos >= 0 )
		k = v->array[pos];

	return k;
}

int vectorSize( vector v ) {
	return v->size;
}

int capacity( vector v ) {
    return v->capacity;
}

bool isVectorEmpty( vector v ) {
	return v->size == 0;
}
