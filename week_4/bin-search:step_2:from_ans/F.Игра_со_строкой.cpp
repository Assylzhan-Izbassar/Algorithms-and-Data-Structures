#include <iostream>
#include <vector>

using namespace std;

bool f(string t, string p, vector<int> &a, int mid){

    vector<bool> used(t.size(),0);

    for(size_t i=1; i <= mid; ++i){
        used[a[i-1]-1] = true;
    }

    vector<bool> check(p.size(), false);

    size_t i = 0;
    size_t j = 0;
    while(i < p.size()){
        while(j < t.size()){
            if(t[j] == p[i] && !used[j]){
                check[i] = true;
                break;
            }
            j++;
        }
        i++;
    }

    bool isOkay = true;

    for(size_t i=0; i < check.size(); ++i){
        isOkay *= check[i];
    }
    return isOkay;
}

int main(){

    ios::sync_with_stdio(false);

    string t,p;
    cin >> t >> p;

    vector<int> v(t.size());

    for(size_t i=0; i < t.size(); ++i)  cin >> v[i];

    int l = 0;
    int r = t.size()+1;

    while(r > l + 1){
        int mid = l + (r-l)/2;

        if(f(t,p,v,mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}