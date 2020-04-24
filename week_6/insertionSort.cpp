/*
INSERTION SORT. Working time O(f(n)) = c*n^2
Time complexity of Insertion-Sort beats time complexity of merge sort for n ∈ [0, 43], n ∈ Z.
*/

#include <iostream>

using namespace std;

void insertionSort(int *arr, int n){

    int key, i;

    for(int j=1; j < n; ++j){
        key = arr[j];
        //insert arr[j] into the sorted sequence arr[0..j-1]
        i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i=0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for(size_t i=0; i < n; ++i){
        printf("%d ", arr[i]);
    }

    cout << endl;

    return 0;
}