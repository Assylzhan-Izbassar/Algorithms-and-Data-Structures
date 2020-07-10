#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class section{
    public:
        long long l,r;
        section(long long _l, long long _r){
            l = _l;
            r = _r;
        }
};

double count(long long l, long long r, long long k, long long x){
    if(x <= l)
        return 0;
    else if(x > r)
        return (long long)r/l;
    else{
        if(min(r,x) % l == 0){
            return (long long)min(r,x)/l - 1;
        }else{
            return (long long)min(r,x)/l;
        }
    }
}

bool f(vector<section> &a, long long k, long long x){
    double index = 0;

    for(size_t i=0; i < a.size(); ++i){
        index += count(a[i].l, a[i].r, k, x);
    }

    return index < k;
}

int main(){

    int n;
    cin >> n;

    long long k;
    cin >> k;

    vector<section> v;

    for(size_t i=1; i <= n; ++i){
        v.push_back(section(i,i*n));
    }

    double l = -1;
    double r = n*n + 1;

    while(r != l){
        double x = (long long)(l + (r-l)/2);

        if(f(v,k,x)){
            l = x+1;
        }else{
            r = x;
        }
    }

    cout << setprecision(20) << l - 1  << endl;

    return 0;
}