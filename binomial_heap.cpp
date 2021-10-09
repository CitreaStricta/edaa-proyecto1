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

void binomial_heap::inserting(int val)
{
    node* handlerPtr = new node();
    handlerPtr->val = val;
    handlerPtr->childPtrs = new vector<node*>();
    _insertSpecific(0, handlerPtr);
}

// funcion recursiva para insertar elementos
void binomial_heap::_insertSpecific(int indice, node* handlerPtr)
{
    vector<node*>::iterator it;
    it = _arrRoots->begin();
    // si en los punteros a raices no hay un puntero en [indice], lo creo
    if (_arrRoots->size() == indice)
    {
        //creo el puntero y lo inicializo en nullptr
        node* newPtrNode = nullptr;
        //lo meto al arreglo de raices
        _arrRoots->push_back(/*newPtrNode*/nullptr); // puedo?????
    }

    // insercion del nuevo nodo en el arreglo de las raices
    // if no hay un nodo en indice. Es decir, si el ptr [indice] en _arrRoots == nullptr
    if (_arrRoots->at(indice) == nullptr)
    {// meto el nodo en ese espacio y retorno
        _arrRoots->at(indice) = handlerPtr;
        handlerPtr = nullptr;
        //return;
    }
    else
    {// si hay un nodo en ese indice entonces hay que revisar cual tiene el menor valor
        if (_arrRoots->at(indice)->val < handlerPtr->val) // ojo, para los dos casos siguientes (el que sea) sera necesario meterle un puntero de nodo al vector del nodo menor
        {   // si el nodo viejo es menor que el nuevo
            // agrego el nodo nuevo en el vector de punteros del nodo viejo
            _arrRoots->at(indice)->childPtrs->push_back(handlerPtr);
            // hago que handlerPtr apunte al nodo viejo (el con el menor valor)
            handlerPtr = _arrRoots->at(indice);
            // desreferencio el puntero en _arrRoots que estaba apuntando al nodo viejo
            _arrRoots->at(indice) = nullptr;
            // ahora que los punteros estan todos en orden. En handlerPtr se encuentra un binomial tree de orden = k+1.
            // este mismo hace un tiempo atras estaba en el lugar de orden = k. Ahora necesito moverlo al lugar del vector
            // de raices que le corresponde segun su orden.
            _insertSpecific(indice + 1, handlerPtr);
            handlerPtr = nullptr;
            //return;
        }
        else // nodo nuevo es menor
        {
            // agrego el puntero al nodo viejo al vector de punteros del nodo nuevo
            handlerPtr->childPtrs->push_back(_arrRoots->at(indice));
            // handlerPtr ya esta apuntando al nodo con el menor valor
            // desreferencio el puntero en _arrRoots que estaba apuntando al nodo viejo
            _arrRoots->at(indice) = nullptr;
            // ahora que los punteros estan todos en orden. En handlerPtr se encuentra un binomial tree de orden = k+1.
            // este mismo hace un tiempo atras estaba en el lugar de orden = k. Ahora necesito moverlo al indice del vector
            // de raices que le corresponde segun su orden
            _insertSpecific(indice + 1, handlerPtr);
            handlerPtr = nullptr;
            //return;
        }
    }
    //return;
}

int binomial_heap::find()
{


    return -1; // -1 para que el compilador no tire warning
}

void binomial_heap::merge()
{
    
}

void intingTree(vector<node*>* s)
{
    auto itP = s->begin();

    while (itP != s->end())
    {
        cout << (*itP)->val << endl;
        intingTree((*itP)->childPtrs);
        itP++;
    }

}

void inting(vector<node*>* s,  int k)
{
    auto itP = s->begin();

    while (itP != s->end())
    {
        if ((*itP) == nullptr)
        {
            cout << "raiz nula " << k << endl;
            itP++;
            k++;
        }
        else
        {
            cout << "arbol con orden " << k << endl;
            cout << (*itP)->val << endl;
            intingTree((*itP)->childPtrs);
            itP++;
            k++;
        }
    }
}


void binomial_heap::printBnlH()
{
    inting(_arrRoots, 0);
}