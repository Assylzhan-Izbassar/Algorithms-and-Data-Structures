#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool f(vector<int> &a, int k, ll x){
    ll sum = 0;

    for(int i=0; i < a.size(); ++i){
        if(a[i] >= x){
            sum += x;
        }else{
            sum += (a[i] % x);
        }
    }

    return sum  >= (k * x);
}

int main(){

    ios::sync_with_stdio(false);

    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    
    for(size_t i=0; i < n; ++i) cin >> a[i];

    ll l = -1;
    ll r = 1e11;

    while(r > l + 1){
        ll mid = l + (r-l)/2;

        if(f(a,k,mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}