#ifndef PRACTICAS_LINKEDLIST_H
#define PRACTICAS_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// ESTRUCTURAS

struct process {
    int pid;
    int timea;
    int sizep;
    int timeex;
};

struct hole {
    int size;
    int full;
    struct process p;
};

// LINKED LIST

typedef struct nodo { //nodo es el nombre de la estructura
    int size;
    int full;
    struct process p;
    struct nodo *sig; //El puntero siguiente para recorrer la lista enlazada
} hnodo; //hnodo es el tipo de dato para declarar la estructura

typedef hnodo *hpuntero; //Puntero al tipo de dato hnodo para no utilizar punteros de punteros

int insertarEnLista(hpuntero *cabeza, struct process p);

void imprimirLista(hpuntero cabeza);

void borrarLista(hpuntero *cabeza);

int insertarEnLista(hpuntero *cabeza, struct process p) {
    hpuntero aux; //Creamos un aux nodo
    if ((*cabeza)->size >= p.sizep) {
        aux = malloc(sizeof(hnodo)); //Utilizamos malloc para reservar memoria para ese nodo
        aux->size = (*cabeza)->size;
        aux->full = (*cabeza)->full;
        (*cabeza)->p = p; //Le asignamos el proceso recibido a ese nodo
        (*cabeza)->size = p.sizep;
        (*cabeza)->full = 1;
        aux->sig = (*cabeza); //Le asignamos al siguiente el valor de cabeza
        aux->size -= p.sizep;
        (*cabeza) = aux;
        return 0;
    } else {
        aux = (*cabeza);
        do {
            if (aux->size >= p.sizep && aux->full == 0) {
                aux->p = p;
                return 0;
            }

            aux = aux->sig;
        } while (aux->sig != NULL);
        (*cabeza) = aux;
    }
    return 1;
}

void borrarProceso(hpuntero *cabeza, struct process p) {
    hpuntero actual; // Auxiliar para recorrer la lista

}

void borrarLista(hpuntero *cabeza) {
    hpuntero actual; //Puntero auxiliar para eliminar correctamente la lista

    while (*cabeza != NULL) { //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}

#endif //PRACTICAS_LINKEDLIST_H
