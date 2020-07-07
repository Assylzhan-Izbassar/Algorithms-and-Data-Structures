#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool f(double mid, double c){
    return mid*mid + sqrt(mid) <= c;
}

int main(){

    double c;
    cin >> c;

    double l = 0;
    double r = 1e11;

    for(size_t i=0; i <= 60; ++i){
        double mid = l + (r-l)/2;

        if(f(mid, c)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout<< setprecision(20) << l << endl;

    return 0;
}