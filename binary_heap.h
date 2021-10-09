#ifndef BINARY_HEAP
#define BINARY_HEAP

using namespace std;

class BinaryHeap{
    public:
        BinaryHeap();
        ~BinaryHeap();
        void insert (const int num);
        int searchMin();
		vector<int> getArray();
        BinaryHeap* merge (BinaryHeap &h1);
    private:
        vector<int> vec;		
};

#endif