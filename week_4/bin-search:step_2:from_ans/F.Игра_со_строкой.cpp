#include <iostream>
#include <vector>

using namespace std;

bool f(string t, string p, vector<int> &a, int mid){

    vector<bool> used(t.size(),0);

    for(size_t i=1; i <= mid; ++i){
        used[a[i-1]-1] = true;
    }
    int i = 0;
    int j = 0;

    vector<bool> check(p.size(), 0);

    while(i < t.size()){
        if(t[i] == p[j] && !used[i]){
            check[j] = true;
            j++;
        }
        i++;
    }
    bool isOkay = true;

    for(size_t i=0; i < check.size(); ++i)
        isOkay *= check[i];

    return isOkay;
}

int main(){

    ios::sync_with_stdio(false);

    string t,p;
    cin >> t >> p;

    vector<int> v(t.size());

    for(size_t i=0; i < t.size(); ++i)  cin >> v[i];

    long long l = 0;
    long long r = t.size() + t.size();

    while(r > l + 1){
        long long mid = l + (r-l)/2;

        if(f(t,p,v,mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}