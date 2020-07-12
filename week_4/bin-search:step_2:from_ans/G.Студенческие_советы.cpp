#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool f(vector<ll> &a, int k, int x){
    vector<ll> t(a.size());

    for(size_t i=0; i < a.size(); ++i)
        t[i] = a[i];

    ll min = 0;
    for(size_t i=0; i < x; ++i){
        min = t[i];
        for(size_t j=i; j < t.size(); ++j)
            t[j] -= min; 
    }
    size_t cnt = 0;
    while(!t[cnt])
        cnt++;

    return a.size() - cnt + 1 >= k;
}

int main(){

    ios::sync_with_stdio(false);

    int k,n;
    cin >> k >> n;
    vector<ll> a(n);

    for(size_t i=0; i < a.size(); ++i) cin >> a[i];

    sort(begin(a), end(a));

    int l = -1;
    int r = n + n;
    while(r > l + 1){
        int mid = l + (r-l)/2;

        if(f(a,k,mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}