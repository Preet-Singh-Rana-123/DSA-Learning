#include <iostream>
#include <utility>

using namespace std;

// Heap is type of Complete Binary Tree.
// Complete Binary Tree is a Binary Tree which follow 2 conditions:-
// 1. All levels of tree should be completely filled, except for last level.
// 2. At last node, nodes should be filled from left node.
//
// Heap is of two type:-
// 1. Max Heap:- Parent node should be gerater than or equal to child nodes, for
// all nodes.
// 2. Min Heap:- Parent node should be less than or equal to child nodes, for
// all nodes.
//
// We implement Heap using array because accessing parents and childs detail in
// heap using array will be simple and easy.
//
// Accessing child from Parent index "i":-
// 1. left child:- 2*i+1
// 2. right child:- 2*i+2
//
// Accessing Parent from child index "i":- (i+1)/2

class MaxHeap{
public:
    int *arr;
    int size;  // total elements in heap
    int total_size; // total size of array

    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value){
        if(size==total_size){
            cout<<"Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void heapify(int index){
        int largest = index;
        int left = 2*index + 1;  // get left child to compare if parent node is greater than it or not
        int right = 2*index - 1; // get right child to compare if parent node is greater than it or not

        if(left<size && arr[left]>arr[index]){
            largest = left;
        }
        if(right<size && arr[right]>arr[index]){
            largest = right;
        }

        if(largest!=index){
            swap(arr[index],arr[largest]);
            heapify(largest);
        }
    }

    void Delete(){
        if(size == 0){
            cout<<"Heap Underflow\n";
            return;
        }

        arr[0] = arr[size-1];
        size--;

        if(size==0){
            return;
        }
    }
};

class MinHeap{
public:
    int *arr;
    int size;  // total elements in heap
    int total_size; // total size of array

    MinHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value){
        if(size==total_size){
            cout<<"Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while(index>0 && arr[(index-1)/2]>arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void heapify(int index){
        int smallest = index;
        int left = 2*index + 1;
        int right = 2*index - 1;

        if(left<size && arr[left]<arr[index]){
            smallest = left;
        }
        if(right<size && arr[right]<arr[index]){
            smallest = right;
        }

        if(smallest!=index){
            swap(arr[index],arr[smallest]);
            heapify(smallest);
        }
    }

    void Delete(){
        if(size == 0){
            cout<<"Heap Underflow\n";
            return;
        }

        arr[0] = arr[size-1];
        size--;

        if(size==0){
            return;
        }
    }
};
