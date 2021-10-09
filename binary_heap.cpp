#include <bits/stdc++.h>
#include "binary_heap.h"

using namespace std;

BinaryHeap::BinaryHeap()
{
}

BinaryHeap::~BinaryHeap()
{
}

void BinaryHeap::insert(const int num)
{
    vec.push_back(num);
    //Padre del nodo: (i-1)/2
    int pos = vec.size() - 1;
    while (pos != 0 && vec[pos] < vec[(pos - 1) / 2])
    {
        int aux = vec[pos];
        vec[pos] = vec[(pos - 1) / 2];
        vec[(pos - 1) / 2] = aux;
        pos = (pos - 1) / 2;
    }
}

int BinaryHeap::searchMin()
{
    return vec[0];
}

vector<int> BinaryHeap::getArray()
{
    return vec;
}

BinaryHeap *BinaryHeap::merge(BinaryHeap &h1)
{
    vector<int> v1 = this->getArray();
    vector<int> v2 = h1.getArray();
    vector<int> newVec = v1;

    newVec.insert(newVec.end(), v2.begin(), v2.end());
    BinaryHeap *merged = new BinaryHeap();
    while (!newVec.empty())
    {
        merged->insert(newVec.back());
        newVec.pop_back();
    }
    return merged;
}

// void *BinaryHeap::merge(BinaryHeap &h1)
// {
//     vector<int> v1 = this->getArray();
//     vector<int> v2 = h1.getArray();
//     vector<int> newVec = v1;

//     newVec.insert(newVec.end(), v2.begin(), v2.end());
//     BinaryHeap *merged = new BinaryHeap();
//     while (!newVec.empty())
//     {
//         merged->insert(newVec.back());
//         newVec.pop_back();
//     }
//     return merged;
// }