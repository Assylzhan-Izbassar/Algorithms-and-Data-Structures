#include <iostream>
#include <vector>

using namespace std;

bool f(vector<int> &x, int k, int d){
    int cows = 1;
    int i = 0;
    for(int j=1; j < x.size(); ++j){
        if(x[j] - x[i] >= d){
            cows++;
            i = j;
        }
    }
    if(cows >= k)
        return true;
    return false;
}

int main(){

    int n,k;
    cin >> n >> k;

    vector<int> v(n);

    for(int i=0; i < n; ++i) cin >> v[i];

    int l = 0;
    int r = 1e9;

    while(r > l + 1){
        int d = l + (r-l)/2;

        if(f(v, k, d)){
            l = d;
        }else{
            r = d;
        }
    }
    cout << l << endl;

    return 0;
}