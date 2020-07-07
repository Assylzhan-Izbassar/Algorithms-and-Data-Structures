#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int> &a, int x){
    int l = 0;
    int r = a.size() - 1;

    while(r >= l){
        int mid = l + (r-l)/2;

        if(a[mid] == x)
            return true;
        else if(a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int find_lower(vector<int> &a, int x){ //max i: a[i] <= x
    int l = -1; //a[l] <= x
    int r = (int)a.size(); // a[r] > x 

    while(r > l + 1){
        int mid = l + (r-l)/2;
        if(a[mid] <= x){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}

int find_upper(vector<int> &a, int x){ // min i: a[i] >= x
    int l = -1; // a[l] < x
    int r = a.size(); // a[r] >= x

    while(r > l + 1){
        int mid = l + (r - l)/2;
        if(a[mid] < x){
            l = mid;
        }else{
            r = mid;
        }
    }
    return r;
}

int main(){

    ios::sync_with_stdio(false);

    size_t n,k;
    scanf("%ld %ld", &n, &k);

    vector<int> v(n);

    for(size_t i=0; i < n; ++i) cin >> v[i];

    int x;

    while(k--){
        cin >> x;
        cout << find_upper(v,x) + 1 << endl;
    }
    return 0;
}