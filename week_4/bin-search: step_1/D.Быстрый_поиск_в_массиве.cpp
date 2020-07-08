#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_upper(vector<long long> &a, int x){ // Если встречается последовательность с равными между собой числами,
    int l = -1;                             // то функция find_upper() возвращает самое левое крайное число
    int r = a.size();

    while(r > l + 1){
        int mid = l + (r-l)/2;
        if(a[mid] < x){
            l = mid;
        }else{
            r = mid;
        }
    }
    return r;
}

int find_lower(vector<long long> &a, int x){// Если встречается последовательность с равными между собой числами,
    int l = -1;                             // то функция find_lower() возвращает самое правое крайное число
    int r = a.size(); 

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

int main(){

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> a(n);

    for(size_t i=0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int k;
    cin >> k;

    long long l,r;

    while(k--){
        cin >> l >> r;
        cout << find_lower(a,r) - find_upper(a,l) + 1 << " ";
    }

    cout << endl;

    return 0;
}