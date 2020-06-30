#include <iostream>

using namespace std;

int Sum(int n, int sum){
    if(n < 0){
        return sum;
    }
    return Sum(n-1,sum+n);
}
int main(){

    cout << Sum(3, 0) << endl;

    return 0;
}