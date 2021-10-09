#ifndef BINOMIAL_HEAP
#define BINOMIAL_HEAP
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val;
    vector<node*>* childPtrs;
};

class binomial_heap
{
private:
    vector<node*>* _arrRoots;
    void _insertSpecific(int indice, node* nNode);
public:
    binomial_heap();
    ~binomial_heap();
    void insert(int);
    int find();
    void merge();
    void printBinomialH();
};

#endif