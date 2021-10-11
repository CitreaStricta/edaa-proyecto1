#include <bits/stdc++.h>
#include "binary_heap.h"
#include "binomial_heap.h"
#include "fibonacci_heap.h"

using namespace std;

int main()
{
    /*  Pruebas binary  */
    cout << "elmankk la maska" << endl;
    BinaryHeap* bh1 = new BinaryHeap();
    BinaryHeap* bh2 = new BinaryHeap();
    BinaryHeap* elmergiado = new BinaryHeap();
    vector<int> hey;
    bh1->insert(5);
    bh1->insert(9);
    bh1->insert(4);
    bh1->insert(15);
    bh1->insert(18);
    bh2->insert(1);
    bh2->insert(13);
    bh2->insert(11);
    bh2->insert(7);
    bh2->insert(3);
    
    cout << "hola" << endl;

    hey = bh1->getArray();
    for(int i=0; i<hey.size(); i++)
        cout<<hey[i]<<" ";
    cout<<endl;

    hey = bh2->getArray();
    for(int i=0; i<hey.size(); i++)
        cout<<hey[i]<<" ";
    cout<<endl;

    cerr<<"antes de merge"<<endl;
    elmergiado = bh1->merge(*bh2);
    cerr<<"despues de merge"<<endl;
// hola error abajo
    hey = elmergiado->getArray();
    for(int i=0; i<hey.size(); i++)
        cout<<hey[i]<<" ";
    cout<<endl;
    //return 0;



    /*  Pruebas binomial  */
    srand(time(NULL));
    binomial_heap* bnmlh1 = new binomial_heap();

    for (int i = 0; i < 63; i++)
    {
        bnmlh1->insert(rand() % 1000);
    }
    bnmlh1->printBinomialH();

    cout << "El menor valor es: " << bnmlh1->find() << endl;

    binomial_heap* bnmlh2 = new binomial_heap();

    for (int i = 0; i < 63; i++)
    {
        bnmlh2->insert(rand() % 1000);
    }
    bnmlh2->printBinomialH();

    bnmlh1->merge(bnmlh2);

    cout << "El menor valor es: " << bnmlh2->find() << endl;
    //return 0;

    

    /*  Pruebas fibonacci  */
    FibonacciHeap *f1 = new FibonacciHeap();

	f1->insert(5);
	f1->insert(8);
	f1->insert(10);
	f1->insert(14);
	f1->insert(28);
	f1->insert(9);
	f1->insert(3);
	f1->insert(11);
	f1->insert(12);

	struct fiNode* lista = f1->getList();
	for(int i=0; i<15; i++){
		cout<<lista->tree[0]<<" ";
		lista = lista->sig;
	}
	cout<<endl;
	cout<<f1->searchMin()<<endl;

    return 0;
}