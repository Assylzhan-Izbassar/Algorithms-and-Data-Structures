#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int* t = a;
    a = b;
    b = t;
}

class Heap{

    private:
        size_t heap_size;
        size_t largest;
        size_t index;// index is must started with 1.
    public:
        Heap(size_t n){
            heap_size = n;
            largest = 0;
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

        void max_heapify(int* arr, size_t i);
        void build_max_heap(int* arr, size_t n);
        void heap_increase_key(int* arr, size_t n, size_t i, int key);
        void max_heap_insert(int* arr, int key);
        int heap_extract_max(int* arr, size_t n);

        int heap_maximum(int* arr){
            return arr[0];
        }
        void print(int* arr){
            for(size_t i=0; i < heap_size; ++i)
                printf("%d ", arr[i]);
            cout << endl;
        }
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
        max_heapify(arr, largest);
}

void Heap::build_max_heap(int* arr, size_t n){
    largest = n;
    for(int i = n/2-1; i >= 0; --i)
        max_heapify(arr,i);
}

void Heap::heap_increase_key(int* arr, size_t n, size_t i, int key){
    if(key < arr[i])
        return;
    arr[i] = key;
    while(i > 0 && arr[parent(i+1)-1] < arr[i]){
        swap(arr[i], arr[parent(i+1)-1]);
        i = parent(i+1)-1;
    }
}

void Heap::max_heap_insert(int* arr, int key){
    arr[heap_size++] = INT_MIN;
    heap_increase_key(arr, heap_size, heap_size-1, key);
}

int Heap::heap_extract_max(int* arr, size_t n){
    if(n < 1) 
        return 0;
    
    int max = arr[0];

        arr[0] = arr[n-1];
        heap_size = n - 1;
        max_heapify(arr, 0);

    return max;
}


int main(){

    int arr[50] = {4,16,2,1,6,7};

    size_t heap_size = 0;
    for(size_t i=0; i < 50; ++i)
        if(arr[i] != 0)
            heap_size++;

    Heap h = Heap(heap_size);

    h.build_max_heap(arr, heap_size);
    h.print(arr);

    cout << h.heap_extract_max(arr,heap_size) << endl;
    h.print(arr);
    h.heap_increase_key(arr, heap_size, 3, 8);
    h.print(arr);

    h.max_heap_insert(arr, 25);
    h.print(arr);

    return 0;
}