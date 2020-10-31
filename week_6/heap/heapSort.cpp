/*
    The (binary) heap data structure is an array object that we can view as a nearly complete binary tree.
Each node of the tree corresponds to an element of the array. There are two kinds of binary heaps: max-heaps and min-heaps. 
In both kinds, the values in the nodes satisfy a heap property, the specifics of which depend on the kind of heap.
In a max-heap, the max-heap property is that for every node i other than the root,
    A[parent(i)] ≥ A[i],
that is, the value of a node is at most the value of its parent.

*/

#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int* t = a;
    a = b;
    b = t;
}

class Heap{
    
    private:
        size_t largest;
        size_t heap_size;
    public:
        Heap(size_t n){
            largest = 0;
            heap_size = n;
        }
        size_t parent(size_t i){
            return i/2;
        }
        size_t left(size_t i){
            return 2*i;
        }
        size_t right(size_t i){
            return 2*i+1;
        }
        void max_heapify(int* arr, size_t i);// runs in O(lg(n)) time, is the key to maintaining the max-heap property.
        void build_max_heap(int* arr, size_t n);// runs in linear time, produces a max- heap from an unordered input array.
        void heap_sort(int* arr, size_t n);// runs in O(n*lg(n)) time, sorts an array in place.
};

void Heap::max_heapify(int* arr, size_t i){

    size_t l = left(i)+1;
    size_t r = right(i)+1;

    if(l < heap_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r < heap_size && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
        swap(arr[i], arr[largest]),
        max_heapify(arr,largest);
}

void Heap::build_max_heap(int* arr, size_t n){
    heap_size = n;
    for(int i = n/2-1; i >= 0; --i)
        max_heapify(arr, i);
}

void Heap::heap_sort(int* arr, size_t n){
    build_max_heap(arr, n);

    for(size_t i=0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    for(int i=n-1; i >= 1; --i){
        swap(arr[0], arr[i]);
        heap_size = heap_size - 1;
        max_heapify(arr, 0);
    }
}

int main(){

    int arr[] = {4,1,3,2,16,9,10,14,8,7};
    size_t n = sizeof(arr)/sizeof(int);
    Heap h = Heap(n);

    h.heap_sort(arr, n);

    for(size_t i=0; i < n; ++i)
        printf("%d ", arr[i]);
    
    return 0;
}