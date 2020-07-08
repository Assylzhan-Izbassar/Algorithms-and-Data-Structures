#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f(vector<long long> &a, int k, int mid){

    int count_zeros = 0;   
    int total_needs = k * mid;

    for(size_t i=0; i < a.size(); ++i){
        if(total_needs == 0)
            break;
        if(total_needs > 0 && a[i] > 0){
            total_needs--;
            a[i]--;
        }
        if(a[i] == 0){
            count_zeros++;
        }
    }

    return (a.size() - count_zeros) >= k;
}

int main(){

    ios::sync_with_stdio(false);

    int k,n;
    cin >> k >> n;
    vector<long long> a(n);

    for(size_t i=0; i < a.size(); ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int l = -1;
    int r = n + 1;
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