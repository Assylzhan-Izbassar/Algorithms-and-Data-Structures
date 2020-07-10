#include <iostream>
#include <vector>

using namespace std;

bool f(vector<double> &x, long long T){

    long long l1,l2,r1,r2;

    l1 = x[0] - T;
    l2 = x[1] - T;
    r1 = x[0] + T;
    r2 = x[1] + T;

    if(max(l1,l2) > min(r1,r2))
        return false;
    else{
        l1 = max(l1,l2);
        r1 = min(r1,r2);
    }
    for(size_t i=2; i < x.size()-1; ++i){
        l2 = x[i] - T;
        r2 = x[i] + T;
        if(max(l1,l2) > min(r1,r2))
            return false;
        l1 = max(l1,l2);
        r1 = min(r1,r2);
    }
    return true;
}

int main(){

    int n, k;
    cin >> n >> k;

    vector<double> v(n);
    vector<bool> used(k,false);

    for(size_t i=0; i < n; ++i) cin >> v[i];

    long long l = -1;
    long long r = 1e9+1;

    while(r > l + 1){
        long long T = l + (r-l)/2;

        if(f(v,T)){
            l = T;
        }else{
            r = T;
        }
    }
    cout << l << endl;

    return 0;
}