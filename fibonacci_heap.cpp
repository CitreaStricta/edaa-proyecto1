#include <vector>
#include "fibonacci_heap.h"
#include <algorithm>
#include <iostream>

using namespace std;

FibonacciHeap::FibonacciHeap(){
	roots = 0;
}

FibonacciHeap::~FibonacciHeap(){
	if(min!=nullptr){
		fiNode *temp, *actual;
		if(min == nullptr)
			return;
		actual = min->sig;
		while(actual!=min){
			temp = actual->sig;
			actual->sig = nullptr;
			actual->prev = nullptr;
			delete actual;
			actual = temp;
		}
		min->sig = nullptr;
		min->prev = nullptr;
		delete min;
	}
}

void FibonacciHeap::insert(const int num){
	fiNode *nuevo = new fiNode;
	nuevo->tree.push_back(num);
	if(roots==0){
		nuevo->prev = nuevo;
		nuevo->sig = nuevo;
		min = nuevo;
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
	//nuevo->sig = nullptr;
	//nuevo->prev = nullptr;
	//free(nuevo);
	return;
}

int FibonacciHeap::searchMin(){
	if(min == nullptr){
		cout<<"no tengo nada"<<endl;
		return -1;
	}
	return min->tree[0];
}

void FibonacciHeap::merge(FibonacciHeap* f1){
	//La idea es tomar la raiz del nuevo fibonacci heap (f1), e insertarla en la circular doubly linked list 
	//del fibonacci heap actual (this)
	fiNode* minF1 = f1->getList();
	fiNode* lastF1 = minF1->prev;
	min->prev->sig = minF1;
	lastF1->sig = min;
	minF1->prev = min->prev;
	min->prev = lastF1;

	auto ppmin = f1->_getList();
	if(minF1->tree[0] < min->tree[0]){
		min = minF1;
		(*ppmin) = nullptr;
	}else{
		(*ppmin) = nullptr;
	}
}

struct fiNode** FibonacciHeap::_getList(){
	auto PPmin = &min;
	return PPmin;
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