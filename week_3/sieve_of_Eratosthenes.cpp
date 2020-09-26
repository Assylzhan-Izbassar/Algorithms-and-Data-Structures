#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> p;

void print(vector<ll> &a){
    for(int i=0; i < (int)a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

void sieve_of_eratosthenes(ll n){
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;

    for(int i=2; i <= n; ++i){
        if(primes[i]){
            if(i*1ll*i <= n){
                for(int j=i*i; j <= n; j+=i){
                    primes[j] = false;
                }
            }
        }
    }
    for(int i=0; i < (int)primes.size(); ++i){
        if(primes[i])
            p.push_back(i);
    }
    print(p);
}
int main(){

    int n; 
    cin >> n;

    sieve_of_eratosthenes(n);
    
    return 0;
}