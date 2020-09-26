#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int *t = a;
    a = b;
    b = t;
}

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){

    int a,b;
    cin >> a >> b;

    cout << gcd(a,b) << endl;

    return 0;
}