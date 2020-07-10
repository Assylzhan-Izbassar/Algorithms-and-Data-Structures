#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool f(vector<ll> &a, int k, ll S){
    ll sum = 0;
    int section = 0;

    for(size_t i=0; i < a.size(); ++i){
        if(sum > S)
            return false;
        if(sum + a[i] <= S){
            sum += a[i];
        }else{
            section++;
            sum = a[i];
        }
    }   
    return section + 1 <= k;
}

int main(){

    int n,k;
    scanf("%d %d", &n, &k);

    vector<ll> v(n);

    for(size_t i=0; i < n; ++i) scanf("%lld", &v[i]);

    ll l = 0;
    ll r = 1e18;

    while(r > l + 1){
        ll S = l + (r-l)/2;

        if(f(v, k, S)){
            r = S;
        }else{
            l = S;
        }
    }

    cout << r << endl;

    return 0;
}