#include <iostream>
#include <vector>

using namespace std;

class lenght
{   
    public:
    long long l,r;
    lenght(long long  _l, long long _r){
        l = _l;
        r = _r;
    }
};

long long count(long long x, long long l, long long r){
    if(x <= l)
        return 0;
    else if(x > r)
        return r - l + 1;
    else return min(r,x) - l;
}

bool f(vector<lenght> &a, long long x, long long k){
    long long index = 0;
    for(size_t i=0; i < a.size(); ++i){
        index += count(x, a[i].l, a[i].r);
    }
    return index <= k;
}

int main(){

    int n;
    cin >> n;
    long long k,l,r;
    cin >> k;

    vector<lenght> v;

    for(size_t i=0; i < n; ++i){
        cin >> l >> r;
        v.push_back(lenght(l,r));
    }
    
    l = -1e10;
    r = 1e10;

    while(r > l + 1){
        long long x = l + (r-l)/2;

        if(f(v, x, k)){
            l = x;
        }else{
            r = x;
        }
    }
    cout << l << endl;

    return 0;
}