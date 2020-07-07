#include <iostream>

using namespace std;

bool f(long long w, long long h, long long n, long long m){
    return (m/w) * (m/h) >= n;
}

int main(){

    long long w,h,n;
    cin >> w >> h >> n;

    long long l = 0;
    long long r = 1;

    while(!f(w,h,n,r)){
        r *= 2;
    }

    while(r > l+1){
        long long mid = l + (r-l)/2;
        if(f(w,h,n,mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;

    return 0;
}