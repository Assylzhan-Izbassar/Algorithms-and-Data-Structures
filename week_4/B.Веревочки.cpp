/*
Есть 𝑛 веревочек, нужно нарезать из них 𝑘 кусков одинаковой длины. Найдите максимальную длину кусков, которые можно получить.
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool f(vector<int> &a, int k, double mid){
    int sum = 0;
    for(size_t i=0; i < a.size(); ++i){
        sum += (int)(a[i]/mid);
    }
    return sum >= k;
}

int main(){

    ios::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    vector<int> v(n);

    for(size_t i=0; i < v.size(); ++i) cin >> v[i];

    double l = 0;
    double r = 1e8;

    for(size_t i=0; i <= 60; ++i){
        double mid = l + (r-l)/2;

        if(f(v, k, mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << setprecision(7) << l << endl;


    return 0;
}