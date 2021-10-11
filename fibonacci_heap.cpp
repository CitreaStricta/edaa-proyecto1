#include <vector>
#include "fibonacci_heap.h"
#include <algorithm>
#include <iostream>

using namespace std;

FibonacciHeap::FibonacciHeap(){
	roots = 0;
	//start = new fiNode; //Para tener una referencia a la circular doubly linked list
	//start = NULL;
	min = new fiNode; //Se debe mantener una referencia al nodo menor
	min = NULL;
}

FibonacciHeap::~FibonacciHeap(){
	//delete start;
	delete min;
}

void FibonacciHeap::insert(const int num){
	struct fiNode* nuevo = new fiNode;
	nuevo->tree.push_back(num);
	if(roots==0){
		nuevo->prev = nuevo;
		nuevo->sig = nuevo;
		min = nuevo;
		//start = nuevo;
		//cerr<<"me caigo"<<endl;
		roots++;
		return;
	}
	/*
		Supongamos que tenemos esta lista:
		------------------v
		5 <-> 6 <-> 7 <-> 8
		^-----------------'
	*/
	//struct fiNode* last = start->prev; //el ultimo nodo es el 8
	nuevo->sig = min->sig; //Antes, el puntero al siguiente nodo del ultimo era el inicio. Ahora, sera el nuevo nodo
	nuevo->prev = min; //Ahora, el puntero al nodo anterior del nuevo nodo, sera el que antes era el ultimo (8)
	min->sig->prev = nuevo; //Antes, el puntero al nodo anterior del primer nodo, era el ultimo nodo. Ahora es el nuevo nodo (que pasa a ser el ultimo)
	min->sig = nuevo; //Finalmente, el nuevo nodo tiene como puntero al siguiente, el primer nodo
	if(nuevo->tree[0]<min->tree[0])
		min = nuevo;
	roots++;
	return;
}

int FibonacciHeap::searchMin(){
	return min->tree[0];
}

void FibonacciHeap::merge(FibonacciHeap &f1){
	//La idea es tomar la raiz del nuevo fibonacci heap (f1), e insertarla en la circular doubly linked list 
	//del fibonacci heap actual (this)
	struct fiNode* minF1 = f1.getList();
	struct fiNode* lastF1 = minF1->prev;
	min->prev->sig = minF1;
	lastF1->sig = min;
	minF1->prev = min->prev;
	min->prev = lastF1;

	if(minF1->tree[0] < min->tree[0])
		min = minF1;
}

struct fiNode* FibonacciHeap::getList(){
	return min;
}

void FibonacciHeap::heapify(struct fiNode x){
	/*
		No es necesario implementar delete, pero cuando se borre un elemento, se debe reordenar el Fibonacci Heap
		para que cumpla la propiedad de heap. En este caso, Min-Heap
	*/
}