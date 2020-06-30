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
    public:
        Heap(){
            largest = 0;
        }
        size_t parent(size_t i){
            return i/2;
        }
        size_t left(size_t i){
            return 2*i + 1;
        }
        size_t right(size_t i){
            return 2*i + 2;
        }
        void max_heapify(int arr[], size_t i, size_t n);
};

void Heap::max_heapify(int* arr, size_t i, size_t n){

    size_t l = Heap::left(i);
    size_t r = Heap::right(i);

    if(l <= n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r <= n && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
        swap(arr[i], arr[largest]),
        max_heapify(arr,largest,n);
}

int main(){

    int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    size_t n = sizeof(arr)/sizeof(int);
    Heap h;

    h.max_heapify(arr, 1, n);

    for(size_t i=0; i < n; ++i)
        printf("%d ", arr[i]);
    
    return 0;
}