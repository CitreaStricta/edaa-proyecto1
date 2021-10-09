#include "binomial_heap.h"

binomial_heap::binomial_heap()
{
    _arrRoots = new vector<node*>();
}

binomial_heap::~binomial_heap()
{
    delete _arrRoots;
    // faltan los delete para los nodos en el array (y los de cada nodo)
    // el delete de esto va a ser una real paja
}

void binomial_heap::insert(int val)
{
    node* handlerPtr = new node();
    handlerPtr->val = val;
    handlerPtr->ptrs = new vector<node*>();
    _insertSpecific(0, handlerPtr);
}

// funcion recursiva para insertar elementos
void binomial_heap::_insertSpecific(int indice, node* handlerPtr)
{
    // si en los punteros a raices no hay un puntero en [indice], lo creo
    if (_arrRoots->size() == indice)
    {
        //creo el puntero y lo inicializo en nullptr
        node* newPtrNode = nullptr;
        //lo meto al arreglo de raices
        _arrRoots->push_back(newPtrNode);
    }

    // insercion del nuevo nodo en el arreglo de las raices
    // if no hay un nodo en indice. Es decir, si el ptr [indice] en _arrRoots == nullptr
    if (_arrRoots->at(indice) == nullptr)
    {// meto el nodo en ese espacio y retorno
        _arrRoots->at(indice) = handlerPtr;
    }
    else
    {
        if (_arrRoots->at(indice)->val < handlerPtr->val) // ojo, para los dos casos siguientes (el que sea) sera necesario meterle un puntero de nodo al vector del nodo menor
        { // si el nodo viejo es menor que el nuevo
            // (manejo de punteros indicado)
            // me aseguro de que los nodos queden en una var auxiliar
            // para que sean manejados por la funcion
        }
    //     else // nodo nuevo es menor
    //         (manejo de punteros indicado)
    //         // me aseguro de que los nodos queden en una var auxiliar
    //         // para que sean manejados por la funcion
    }
    
// toi canzao. Son demaciadas las consideraciones que hay que hacer. Voy a ir a comer
// voy a necesitar algo asi como un "raiz handeler"
}

int binomial_heap::find()
{


    return -1; // -1 para que el compilador no tire warning
}

void binomial_heap::merge()
{
    
}