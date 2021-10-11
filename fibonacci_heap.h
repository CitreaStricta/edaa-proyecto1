#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP
#include <string>
#include <algorithm>
#include <vector>

	
using namespace std;

struct fiNode{
	vector<int> tree;
	struct fiNode *sig;
	struct fiNode *prev;
};

class FibonacciHeap{
	public: 
		FibonacciHeap();
		~FibonacciHeap();
		void insert(const int num);
		int searchMin();
		FibonacciHeap* merge(FibonacciHeap &f1);
		struct fiNode* getList();
	private:
		void heapify(struct fiNode x);
		vector<int> vec;
		int roots;
		struct fiNode* start;
		struct fiNode* min;
};

#endif