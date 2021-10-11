#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP
#include <string>
#include <algorithm>
#include <vector>

	
using namespace std;

struct fiNode{
	vector<int> tree; //arbol del nodo actual
	struct fiNode *sig;
	struct fiNode *prev;
};

class FibonacciHeap{
	public: 
		FibonacciHeap();
		~FibonacciHeap();
		void insert(const int num);
		int searchMin();
		void merge(FibonacciHeap* f1);
		struct fiNode* getList();
	private:
		fiNode** _getList();
		void heapify(struct fiNode x);
		vector<int> vec;
		int roots;
		struct fiNode* min;
};

#endif