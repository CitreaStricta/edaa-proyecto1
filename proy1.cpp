#include <bits/stdc++.h>
#include "binary_heap.h"
#include "binomial_heap.h"
//#include "fibonacci_heap.h"

using namespace std;

int main()
{
    binomial_heap* bmlh = new binomial_heap();
    bmlh->inserting(0);
    bmlh->inserting(1);
    bmlh->inserting(2);
    bmlh->inserting(3);
    bmlh->inserting(4);
    bmlh->inserting(10);
    bmlh->inserting(3);
    bmlh->inserting(20);
    bmlh->inserting(5);
    bmlh->inserting(13);
    bmlh->inserting(50);
    bmlh->inserting(212);
    bmlh->printBnlH();

    return 0;

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
    return 0;
}